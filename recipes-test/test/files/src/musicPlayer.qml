import QtQuick 2.15
import QtQuick.Controls 2.15
import QtMultimedia 5.15
import QtQuick.Dialogs 1.3
import QtQuick.Layouts 1.0
import USBManager 1.0
// import Qt.labs.folderlistmodel 2.1

Item {
    id: music
    visible: true
    width: 1024
    height: 600

    Image {
        id: backgroundImage1
        anchors.fill: parent
        source: "black.jpg"
    }
    USBManager {
            id: usbManager

            property bool usbStatus: true;
        }
    Connections {
        target: usbManager

        onFileListChanged: {
                   var files = usbManager.fileList;
                   console.log("File list changed. New list1:", files);
                   console.log("File list changed", usbManager.fileList.filePath);
                   playlistModel.clear();

                        // Add songs to the playlistModel
                        for (var i = 0; i < files.length; i++) {
                            var source ="file://" + files[i];

                            var title = source.substring(source.lastIndexOf("/") + 1);

                            playlistModel.append({ title: title, source: source });
                        }

               }

        onUsbRemoved: {
            usbManager.usbStatus = status
            console.log("i: ", usbManager.usbStatus);
            playlistModel.clear();
        }

    }


    Button {
        id: music_list_button
        width: 80
        height: 80
        background: Image {
            anchors.fill: parent
            source: "queue-music.png"
        }

        onClicked:
        {
            usbManager.startUSBScan();
            console.log("button clicked");
        }

        anchors {
            top: parent.top
            left: parent.left
            margins: 40
        }
    }






    Button {
        id: backButton
        width: 70
        height: 70
        background: Image {
            source: "back_icon.png"
        }

        onClicked: mainLoader.source = "stackViewPage.qml"
        anchors {
            bottom: parent.bottom
            left: parent.left
            margins: 40
        }
    }


    Text {
        visible: !usbManager.usbStatus
        id: usbStatusText
        text: "USB device is not detected!"
        color: "white"
        font.pixelSize: 20
        anchors {
            top: parent.top
            left: parent.left
            margins: 150
        }
    }


    ListView {
        id: playlistView

        visible: usbManager.usbStatus

        width: parent.width / 3
        height: parent.height * 0.8

        anchors {
            top: parent.top
            left: parent.left
            margins: 50
        }

        model: ListModel {
            id: playlistModel

        }
        delegate: Item {
            width: 400
            height: 50
            Rectangle {
                width: parent.width
                height: 50
                color: "black"
                border.color: "#a1a1a3"
                Text {
                    anchors.centerIn: parent
                    text: model.title
                    color: "white"
                }
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        mediaPlayer.stop()
                        mediaPlayer.source = model.source
                        mediaPlayer.play()
                        playlistView.currentIndex = index
                    }
                }
            }
        }
    }


    Rectangle {
        anchors {
            bottom: parent.bottom
            right: parent.right
            //horizontalCenter: parent.horizontalCenter
            rightMargin: 80
            bottomMargin: 85
        }
        width: 400
        height: 470
        color: "#a1a1a3"
        opacity: 0.4
        border.color: "black"
        border.width: 0.5
        radius: 10
    }

    MediaPlayer {
        id: mediaPlayer
        autoPlay: false
    }


    Slider {
        anchors {
            bottom: parent.bottom
            right: parent.right
            //horizontalCenter: parent.horizontalCenter
            bottomMargin: 30
            rightMargin: 120
        }
        id: volume_slider
        width: 340
        from: 0
        to: 1
        value: mediaPlayer.volume
        onValueChanged: {
            mediaPlayer.volume = value
        }
    }



    Column {

        anchors {
            bottom: parent.bottom
            right: parent.right
            margins: 100
        }

        Image {

            id: playingimg
            scale: 0.65
            source: "musicplaying.jpg"
            visible: currentlyPlayingText.text !== ""
            anchors {
                horizontalCenter: parent.horizontalCenter
            }
        }

        Text {
            id: currentlyPlayingText
            text: (playlistModel.get(playlistView.currentIndex) ? playlistModel.get(playlistView.currentIndex).title : "")
            color: "white"
            font.pixelSize: 16
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            wrapMode: Text.WrapAtWordBoundaryOrAnywhere
            anchors {
                horizontalCenter: parent.horizontalCenter
            }
        }


        Slider {
            id: playerPosition
            width: 340
            from: 0
            to: mediaPlayer.duration
            value: mediaPlayer.position
            onValueChanged: {
                mediaPlayer.seek(value)
            }
            anchors {
                horizontalCenter: parent.horizontalCenter
            }
        }


        Row {
            spacing: 57
            anchors {
                horizontalCenter: parent.horizontalCenter
            }

            Button {
                width: 80
                height: 80
                background: Image {
                    source: "skip-previous_icon.png"
                }
                onClicked: {
                    var newIndex = playlistView.currentIndex - 1;
                    if (newIndex >= 0) {
                        mediaPlayer.stop();
                        mediaPlayer.source = playlistModel.get(newIndex).source;
                        mediaPlayer.play();
                        playlistView.currentIndex = newIndex;
                    }
                }
            }
            Button {
                width: 80
                height: 80
                background: Image{
                    source: mediaPlayer.playbackState === MediaPlayer.PlayingState ? "pause_icon.png" : "play_icon.png"
                }

                onClicked: {
                    if (mediaPlayer.playbackState === MediaPlayer.PlayingState) {
                        mediaPlayer.pause();
                    } else {
                        mediaPlayer.play();
                    }
                }
            }

            Button {
                id: next
                width: 80
                height: 80
                background: Image {
                    source: "skip-next_icon"
                }

                onClicked: {
                    var newIndex = playlistView.currentIndex + 1;
                    if (newIndex < playlistModel.count) {
                        mediaPlayer.stop();
                        mediaPlayer.source = playlistModel.get(newIndex).source;
                        mediaPlayer.play();
                        playlistView.currentIndex = newIndex;
                    }
                }
            }
        }
    }
}
