import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.12


Item {
    visible: true
    width: 1024
    height: 600
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

        gradient: Gradient {
            GradientStop { position: redSlider.value; color: "lime" }
            GradientStop { position: greenSlider.value; color: "magenta" }
            GradientStop { position: blueSlider.value; color: "blue" }
        }


    }

    Rectangle {
        id:rightb
        x: 974
        width: 50
        height: 600

        gradient: Gradient {
            GradientStop { position: redSlider.value; color: "magenta" }
            GradientStop { position: greenSlider.value; color: "lime" }
            GradientStop { position: blueSlider.value; color: "blue" }
        }
    }

    Rectangle {
        id:topb
        anchors.top: parent.top
        x: 50
        width: 924
        height: 50

        gradient: Gradient {
            GradientStop { position: redSlider.value; color: "magenta" }
            GradientStop { position: greenSlider.value; color: "lime" }
            GradientStop { position: blueSlider.value; color: "blue" }
        }
    }

    Rectangle {
        id:bottomb
        anchors.bottom: parent.bottom
        x: 50
        width: 924
        height: 50

        gradient: Gradient {
            GradientStop { position: greenSlider.value; color: "lime" }
            GradientStop { position: redSlider.value; color: "magenta" }

            GradientStop { position: blueSlider.value; color: "blue" }
        }
    }
    Column {
        spacing: 5
        x: 460
        y: 420


        Slider {
            id: redSlider
            value: 0.3
            orientation: Qt.Horizontal
            onValueChanged: updateGradient()
            Image {
                width:20
                height:20
                anchors.right:redSlider.left

                source: "magenta.png"
            }
        }

        Slider {
            id: greenSlider
            value: 0.5
            orientation: Qt.Horizontal
            onValueChanged: updateGradient()
            Image {
                width:20
                height:20
                anchors.right:greenSlider.left

                source: "lime.png"
            }
        }

        Slider {
            id: blueSlider
            value: 0.4
            orientation: Qt.Horizontal
            onValueChanged: updateGradient()
            Image {
                width:20
                height:20
                anchors.right:blueSlider.left

                source: "blue.png"
            }
        }

    }


    function updateGradient() {
        // Update the gradient based on the slider values
        // The gradient is defined in the Rectangle's gradient property.
    }



}

