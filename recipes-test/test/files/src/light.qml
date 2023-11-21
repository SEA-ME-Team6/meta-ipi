import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.12


Item {
    id:ambient
    visible: true
    width: 1024
    height: 600
    signal colorChanged(color newColor) // Define the signal
    function updateColor() {

                // Update the color based on the sliders
                color = Qt.rgba(redSlider.value / 255, greenSlider.value / 255, blueSlider.value / 255, opacitySlider.value / 100);
            }


        Image {

            source: "white.jpg"
            anchors.fill: parent
        }

        anchors.fill: parent
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



            //onClicked: mainLoader.source="stackViewPage.qml"

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
        Column {
            anchors.bottom: bottomb.top
            spacing:1


            x: 460
            y: 350

            Slider {
                id: redSlider
                from: 0
                to: 255
                value: 128
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
                value: 100
                onValueChanged: {
                                updateColor();
                                colorChanged(color);
                            }
            }
            Label {
                text: "Opacity: " + opacitySlider.value
            }




        }









}

