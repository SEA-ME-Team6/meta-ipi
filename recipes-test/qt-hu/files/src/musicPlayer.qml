import QtQuick 2.15
import QtQuick.Controls 2.15
import QtMultimedia 5.15
import QtQuick.Dialogs 1.3
import QtQuick.Layouts 1.0


Item {
    id:music
    visible: true
    width: 1024
    height: 600


    Image {
                id: backgroundImage1
                anchors.fill: parent
                source: "background.png"

            }



    Button{
        id:backButton3
        width:100
        height:100



        Image {
            width: parent.width
            height: parent.height
            source: "back.jpg"
                       }



        onClicked: mainLoader.source="stackViewPage.qml"


        anchors{
            bottom:parent.bottom
            right: parent.right
            margins: 40

        }
    }
    ListView {
        id: playlistView

        width: parent.width/3
        height: parent.height/2
        model: ListModel {
            id: playlistModel
        }

        delegate: Item {
            x:100

            width: 924

        //onClicked: mainLoader.source="stackViewPage.qml"
            height: 50
            Rectangle {


                width: parent.width
                height: 50
                color: "lightblue"
                border.color: "blue"
                Text {
                    anchors.centerIn: parent
                    text: model.title
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

    MediaPlayer {
        id: mediaPlayer
        autoPlay: false
    }

    Button {
        id:addbutton
        text: "Add Songs"
        onClicked: {
            fileDialog.open()
        }
    }

    FileDialog {
        id: fileDialog
        title: "Select Songs"
        folder: "D:/"  // Set your initial folder here

        onAccepted: {
            var files = fileDialog.fileUrls
            for (var i = 0; i < files.length; i++) {
                var selectedFile = files[i].toString()
                var fileName = selectedFile.substring(selectedFile.lastIndexOf("/") + 1)
                var isDuplicate = false
                for (var j = 0; j < playlistView.model.count; j++) {
                    if (playlistView.model.get(j).source === selectedFile) {
                        isDuplicate = true
                        break
                    }
                }
                if (!isDuplicate) {
                    playlistView.model.append({ title: fileName, source: selectedFile })
                }
            }
        }

        onRejected: {
            // User canceled the file selection
        }
    }

    // Define a ListModel for your playlist
  /*  ListModel {
        id: playlistModel


        ListElement { title: "Song 1"; source: "file:///E:/song1.mp3" }
        ListElement { title: "Song 2"; source: "file:///E:/song2.mp3" }
        ListElement { title: "Song 3"; source: "file:///E:/song3.mp3" }
        // Add more songs as needed

    }

    MediaPlayer {
        id: mediaPlayer
    }

    ListView {
        id: playlistView
        width: parent.width/3
        height: parent.height/3
        model: playlistModel
        currentIndex: -1 // Start with no song selected

        delegate: Item {
            width: parent.width
            height: 50
            Image {
                       source: "white.jpg" // Replace 'title' with 'imageSource' property
                       width: 100
                       height: 50 // Set the width and height as needed
                   }

            Rectangle {

                color: (playlistView.currentIndex === index) ? "lightblue" : "transparent"
                width: 100
                height: 50
                opacity: (playlistView.currentIndex === index) ? 0.6 : 0

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
    }*/
    Slider {
                id:s1
                x:250
                y:400



                width :600
                from: 0
                to: mediaPlayer.duration
                value: mediaPlayer.position




                onValueChanged: {
                    mediaPlayer.position = value
                }
            }



    Column {
        anchors {
            bottom: parent.bottom
            left: playlistView.right
            right: parent.right
        }

        Row {
            spacing: 10

            Button {
                width:100
                height:100



                Image {
                    width: parent.width
                    height: parent.height
                    source: "b.jpg"
                               }

                onClicked: {
                    var newIndex = playlistView.currentIndex - 1
                    if (newIndex >= 0) {
                        mediaPlayer.stop()
                        mediaPlayer.source = playlistModel.get(newIndex).source
                        mediaPlayer.play()
                        playlistView.currentIndex = newIndex
                    }
                }
            }

            Button {
                width:100
                height:100


                Image {
                    width: parent.width
                    height: parent.height
                    source: mediaPlayer.playbackState === MediaPlayer.PlayingState ? "ps.jpg" : "p.jpg"
                               }

                onClicked: {
                    if (mediaPlayer.playbackState === MediaPlayer.PlayingState) {
                        mediaPlayer.pause()
                    } else {
                        mediaPlayer.play()
                    }
                }
            }

            Button {
                width:100
                height:100


                Image {
                    width: parent.width
                    height: parent.height
                    source: "s.jpg"
                               }
                onClicked: mediaPlayer.stop()
            }

            Button {
                id:next
                width:100
                height:100


                Image {
                    width: parent.width
                    height: parent.height
                    source: "f.jpg"
                               }
                onClicked: {
                    var newIndex = playlistView.currentIndex + 1
                    if (newIndex < playlistModel.count) {
                        mediaPlayer.stop()
                        mediaPlayer.source =playlistModel.get(newIndex).source
                        mediaPlayer.play()
                        playlistView.currentIndex = newIndex
                    }
                }
            }
        }

        Slider {
                id:s2



                   width:430
                   // Adjust the width as needed
                   from: 0
                   to: 1
                   value: mediaPlayer.volume

                   onValueChanged: {
                       mediaPlayer.volume = value
                   }
               }
    }








}
