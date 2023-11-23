// USBManager.h
#ifndef USBMANAGER_H
#define USBMANAGER_H

#include <QObject>
#include <QStringList>
#include <QDir>
#include <QMediaPlayer>
#include <QFileSystemWatcher>

class USBManager : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QStringList fileList READ fileList NOTIFY fileListChanged)



public:
    explicit USBManager(QObject *parent = nullptr);
    QStringList fileList() const;

    Q_INVOKABLE void startUSBScan();



signals:
    void usbInserted();
    void usbRemoved();
    void fileListChanged();


private:
    QStringList m_fileList;
    QMediaPlayer m_mediaPlayer;
    QString m_usbDrivePath;
    QFileSystemWatcher usbWatcher;
    QString usbDirPath;

    void loadSongsFromUSB();
    void mountUSB();
    bool isUSBDriveMounted();
    QString findUSBDevice();
    void umountUSB();
    void removeUsbDirectory();
    void handleDirectoryChange(const QString &path);
};

#endif // USBMANAGER_H
