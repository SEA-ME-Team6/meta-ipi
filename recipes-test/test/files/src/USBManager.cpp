// USBManager.cpp
#include "USBManager.h"
#include <QDebug>
#include <QFileInfo>
#include <QStorageInfo>
#include <QProcess>


USBManager::USBManager(QObject *parent) : QObject(parent)
{
    startUSBScan();
    usbWatcher.addPath("/media/"); // for yocto, change it to "/media/"
    connect(&usbWatcher, &QFileSystemWatcher::directoryChanged, this, &USBManager::handleDirectoryChange);

    connect(this, &USBManager::usbInserted, this, &USBManager::loadSongsFromUSB);

}

QStringList USBManager::fileList() const
{
    return m_fileList;
}

void USBManager::startUSBScan()
{
    qDebug() << "USB scan initiated";

    // umount /media/usb
    umountUSB();
    qDebug() << "umount 'media/usb'";
    // Remove /media/usb
    removeUsbDirectory();
    qDebug() << "remove 'media/usb'";



    mountUSB();

    qDebug() << "isUSBDriveMounted: " << isUSBDriveMounted();

    // if mounted well, get the path of device
    if(isUSBDriveMounted()) {
        // Get a list of available storage devices
        QList<QStorageInfo> drives = QStorageInfo::mountedVolumes();

        // Check each drive for a USB drive
        for (const QStorageInfo &drive : drives) {
            if (drive.isValid() && drive.isReady() && drive.device().startsWith("/dev/sd")) {
                m_usbDrivePath = drive.rootPath();
                // Emit the signal indicating that the file list has changed
                //qDebug() << "USB scan completed, path: " << m_usbDrivePath;
                emit usbInserted();
                return; // Stop scanning once a USB drive is found
            }
        }
        usbStatus = true;
    }
    else {
        qDebug() << "No USB drive found";
        usbStatus = false;
    }
}

void USBManager::mountUSB()
{

    // Make Directory for mount target
    QString mkdirCommand = "mkdir /media/usb";
    QProcess process1;
    QStringList arguments1 = mkdirCommand.split(' ', Qt::SkipEmptyParts);
    QString program1 = arguments1.takeFirst();
    process1.start(program1, arguments1);
    process1.waitForFinished();

    //qDebug() << "process1: " << process1.exitCode();
    //qDebug() << "에러:" << process1.errorString();
    //qDebug() << "세부 정보:" << process1.readAllStandardError();
    // if making dircetro finished well, start mount
    if (process1.exitCode() == 0) {
        qDebug() << "Directory(/media/usb) is maked!";

        QString usbname = findUSBDevice();
        // Mount the USB drive using a system command
        QString mountCommand = "mount " + findUSBDevice() + " /media/usb";  // Replace /dev/sdX with the appropriate device name for your USB drive
        QProcess process;
        QStringList arguments = mountCommand.split(' ', Qt::SkipEmptyParts);
        QString program = arguments.takeFirst();  // Extract the program (udisksctl in this case)
        process.start(program, arguments);

        process.waitForFinished();

        if (process.exitCode() == 0) {
            qDebug() << "USB drive mounted successfully";
            //emit usbInserted();

        } else {
            qDebug() << "Failed to mount USB drive";
            qDebug() << "Standard Output:" << process.readAllStandardOutput();
            qDebug() << "Standard Error:" << process.readAllStandardError();
        }
    }
    else {
        qDebug() << "Failed making Directory(/media/usb).";
    }


}

bool USBManager::isUSBDriveMounted()
{
    // Get a list of mounted file systems
    QList<QStorageInfo> drives = QStorageInfo::mountedVolumes();
    //qDebug() << "drives: " << drives;

    // Specify the device name for your USB drive

    QString usbDevice = findUSBDevice();

    // Check if the USB drive is in the list of mounted drives
    for (const QStorageInfo& drive : drives) {
        if (drive.device() == usbDevice) {
            qDebug() << "USB Drive is mounted";
            return true;
        }
    }

    qDebug() << "USB Drive is not mounted";
    return false;
}


void USBManager::loadSongsFromUSB()
{
    m_fileList.clear();

    QDir usbDir(m_usbDrivePath);
    QStringList nameFilters;

    nameFilters << "*.mp3" << "*.mp4";

    QStringList files = usbDir.entryList(nameFilters, QDir::Files | QDir::NoDotAndDotDot);
    for (const QString &file : files) {
        QFileInfo fileInfo(usbDir.filePath(file));
        m_fileList.append(fileInfo.absoluteFilePath());
    }

    emit fileListChanged();
    //qDebug() << "File list loaded from USB:" << m_fileList;


    // You can perform further actions with the loaded file list
}

QString USBManager::findUSBDevice()
{
    QDir devDir("/dev");
    QStringList nameFilter;
    nameFilter << "sd[a-z][0-9]";

    // Filter files based on the regular expression
    QRegExp regExp(nameFilter.join('|'), Qt::CaseSensitive, QRegExp::Wildcard);
    QStringList fileList = devDir.entryList(nameFilter, QDir::System);

    // Iterate through the filtered file list
    for (const QString &fileName : fileList) {
        if (regExp.exactMatch(fileName)) {
            return "/dev/" + fileName;
        }
    }

    // No matching file found
    return "";
}

void USBManager::umountUSB()
{
    // Make Directory for mount target
    QString mkdirCommand = "umount /media/usb";
    QProcess process;
    QStringList arguments = mkdirCommand.split(' ', Qt::SkipEmptyParts);
    QString program = arguments.takeFirst();
    process.start(program, arguments);
    process.waitForFinished();
}


void USBManager::removeUsbDirectory()
{
    // Specify the path of the directory to be removed
    QString usbDirPath = "/media/usb";

    // Check if the directory exists
    if (QDir(usbDirPath).exists()) {
        // Create a QDir object for the directory
        QDir usbDir(usbDirPath);

        // Remove the directory and its contents recursively
        if (usbDir.removeRecursively()) {
            qDebug() << "Directory removed successfully";
        } else {
            qDebug() << "Failed to remove directory";
        }
    } else {
        qDebug() << "Directory does not exist";
    }
}

void USBManager::handleDirectoryChange(const QString &path)
{
    qDebug() << "handle Directory Changed!";

    // change detected path
    QDir usbRootDir(path);
    qDebug() << "usbRootDir: " << usbRootDir;

    if (usbRootDir.exists()) {
        QStringList usbSubDirs = usbRootDir.entryList(QDir::Dirs | QDir::NoDotAndDotDot);

        for (const QString &subDir : usbSubDirs) {
            usbDirPath = "/media/" + subDir;
        }
    }

    //qDebug() << "usbDirPath: " << usbDirPath;

    //path(ex. /media/usb/
    QDir usbDir(usbDirPath);


    if(usbDir.exists()) {
        //emit usbInserted();

        //loadMP3Files(usbDirPath);
    } else {
        //emit usbRemoved();
        qDebug() << "USB REMOVED@@@@@@@@@@@@@@@@@@@@@@@@@@@@"
    }
}
