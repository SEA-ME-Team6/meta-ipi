import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.12
import QtQuick.Extras 1.4

import "."
Item {
    id:griditem
    visible: true
    width: 1024
    height: 600




    function updateColor() {

                // Update the color based on the sliders
                color = Qt.rgba(redSlider.value / 255, greenSlider.value / 255, blueSlider.value / 255, opacitySlider.value / 100);
            }
    Text {
            id: timeText
            color: "white"
            anchors.right: parent.right
            anchors.top: parent.top
            font.pixelSize: 20

            function updateTime() {
                timeText.text = Qt.formatDateTime(new Date(), "dd.MM.yyyy     hh:mm:ss");
            }

            Timer {
                interval: 1000 // Update every 1 second
                running: true
                repeat: true
                onTriggered: timeText.updateTime()
            }

            Component.onCompleted: timeText.updateTime()
        }














            Rectangle {


                id:leftb
                width: 50
                height: 600
                property color colorFromLight: "transparent"

                       function updateColor() {
                           colorFromLight = Qt.rgba(redSlider.value / 255, greenSlider.value / 255, blueSlider.value / 255, opacitySlider.value / 100);
                           // Emit a signal to notify the color change
                           colorChanged(colorFromLight);
                       }
                color: Qt.rgba(redSlider.value / 255, greenSlider.value / 255, blueSlider.value / 255, opacitySlider.value / 100)




            }

            Rectangle {
                id:rightb
                x: 974
                width: 50
                height: 600
                color: Qt.rgba(redSlider.value / 255, greenSlider.value / 255, blueSlider.value / 255, opacitySlider.value / 100)


            }

            Rectangle {
                id:topb
                anchors.top: parent.top
                x: 50
                width: 924
                height: 50
                color: Qt.rgba(redSlider.value / 255, greenSlider.value / 255, blueSlider.value / 255, opacitySlider.value / 100)


            }

            Rectangle {
                id:bottomb
                anchors.bottom: parent.bottom
                x: 50
                width: 924
                height: 50
                color: Qt.rgba(redSlider.value / 255, greenSlider.value / 255, blueSlider.value / 255, opacitySlider.value / 100)


            }
            property bool slidersVisible: false
            Column {

                anchors.bottom: bottomb.top
                anchors.right:rightb.left
                spacing:1




                Slider {
                    id: redSlider
                    from: 0
                    to: 255
                    value: 128
                    visible: slidersVisible
                    onValueChanged: {
                                    updateColor();
                                    colorChanged(color);
                                }
                    Image {
                        width:20
                        height:20
                        anchors.right:redSlider.left

                        source: "red.png"
                    }
                }


                Slider {
                    id: greenSlider
                    from: 0
                    to: 255
                    value: 128
                    visible: slidersVisible
                    onValueChanged: {
                                    updateColor();
                                    colorChanged(color);
                                }
                    Image {
                        width:20
                        height:20
                        anchors.right:greenSlider.left

                        source: "lime.png"
                    }
                }


                Slider {
                    id: blueSlider
                    from: 0
                    to: 255
                    value: 128
                    visible: slidersVisible
                    onValueChanged: {
                                    updateColor();
                                    colorChanged(color);
                                }
                    Image {
                        width:20
                        height:20
                        anchors.right:blueSlider.left

                        source: "blue.png"
                    }
                }


                // Slider to control opacity
                Slider {
                    id: opacitySlider
                    from: 0
                    to: 100
                    value: 0

                    visible: slidersVisible
                    onValueChanged: {
                                    updateColor();
                                    colorChanged(color);
                                }
                }

            }
            Button {
                width:120
                height:120
                x:400
                y:200


                Image {
                    width: parent.width
                    height: parent.height

                    source: "light.jpg"

                }
                            onClicked: {
                                // Toggle the visibility of the sliders
                                slidersVisible = !slidersVisible;
                            }
                        }









        Column {
            id:gearbutton
            x:5
            y:20
            anchors.left: leftb.right
            anchors.top:topb.bottom
            anchors.bottom:bottomb.top
            spacing: 10
            Button {
                //text: "P"

                Image {
                    width: parent.width
                    height: parent.height
                    source: "pg.jpg"
                               }

                /*contentItem: Text {
                        text: parent.text
                        color: "white" // Set the text color to red
                        font.pixelSize: 50
                        horizontalAlignment: Text.AlignHCenter // Center text horizontally
                        verticalAlignment: Text.AlignVCenter // Center text vertically
                                   }*/
                width: 115 // Set the width of the button
                height:115 // Set the height of the button

                onClicked: {
                    gearState = "Park"
                }
                background: Rectangle {
                    width: 115 // Set the width of the button
                    height:115
                    color: gearState === "Park" ? "lime" : "black"
                    radius: 5
                    opacity: (gearState === "Park")?0.5:0
                    z:1
                }
            }

            Button {
                //text: "P"

                Image {
                    width: parent.width
                    height: parent.height
                    source: "rg.jpg"
                               }

                /*contentItem: Text {
                        text: parent.text
                        color: "white" // Set the text color to red
                        font.pixelSize: 50
                        horizontalAlignment: Text.AlignHCenter // Center text horizontally
                        verticalAlignment: Text.AlignVCenter // Center text vertically
                                   }*/
                width: 115 // Set the width of the button
                height:115// Set the height of the button

                onClicked: {
                    gearState = "Reverse"
                }
                background: Rectangle {
                    width: 115 // Set the width of the button
                    height:115
                    z:1
                    color: gearState === "Reverse" ? "lime" : "black"
                    opacity: (gearState === "Reverse")?0.5:0
                    radius: 5
                }
            }

            Button {
                //text: "P"

                Image {
                    width: parent.width
                    height: parent.height
                    source: "NG.jpg"
                               }

                /*contentItem: Text {
                        text: parent.text
                        color: "white" // Set the text color to red
                        font.pixelSize: 50
                        horizontalAlignment: Text.AlignHCenter // Center text horizontally
                        verticalAlignment: Text.AlignVCenter // Center text vertically
                                   }*/
                width: 115 // Set the width of the button
                height:115 // Set the height of the button

                onClicked: {
                    gearState = "Neutral"
                }
                background: Rectangle {
                    z:1
                    width: 115 // Set the width of the button
                    height:115
                    color: gearState === "Neutral" ? "lime" : "black"
                    opacity: (gearState === "Neutral")?0.6:0
                    radius: 5
                }
            }

            Button {
                //text: "P"

                Image {
                    width: parent.width
                    height: parent.height
                    source: "dg.jpg"
                               }

                /*contentItem: Text {
                        text: parent.text
                        color: "white" // Set the text color to red
                        font.pixelSize: 50
                        horizontalAlignment: Text.AlignHCenter // Center text horizontally
                        verticalAlignment: Text.AlignVCenter // Center text vertically
                                   }*/
                width: 115 // Set the width of the button
                height:115 // Set the height of the button
                font.pixelSize: 18 // Set the font size of the button text
                onClicked: {
                    gearState = "Drive"
                }
                background: Rectangle {
                    width: 115 // Set the width of the button
                    height:115
                    color: gearState === "Drive" ? "lime" : "black"
                    opacity: (gearState === "Drive")?0.6:0
                    radius: 5
                    z:1
                }

            }
        }


    property string gearState: "Park"



        ListModel {
            id: listModel
            //ListElement { page: "light.qml"; iconSource: "light.jpg" }
            ListElement { page: "musicPlayer.qml"; iconSource: "musicPlayer.jpg" }
            ListElement { page: "video.qml"; iconSource: "video.jpg" }

        }

        GridView {
            id: gridView
            //x:600
            //y:200
            x:200
            y:70
            width:600
            height:100

            model: listModel
            cellHeight:300
            cellWidth: 200


            delegate: Rectangle {
                width: 120
                height: 120

                radius: 5

                Image {
                    source: iconSource
                    width: parent.width
                    height: parent.height
                    anchors.centerIn: parent
                }



                MouseArea {
                    anchors.fill: parent
                    onClicked: mainLoader.source = page
                }
            }
        }





}

