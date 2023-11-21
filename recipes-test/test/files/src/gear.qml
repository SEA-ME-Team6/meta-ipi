import QtQuick 2.15
import QtQuick.Controls 2.15


Item {
    width:1024
    height:600


    Rectangle {

        width: parent.width
        height: parent.height
        Image{
               id:gearImage
               anchors.fill:parent
               source: "background.jpg"
               }
        Button{
            id:backButton
            width:70
            height:70



            Image {
                width: parent.width
                height: parent.height
                source: "back.jpg"
                           }
            /*text:"Back"
            contentItem: Text {
                    text: parent.text
                    color: "white"
                    horizontalAlignment: Text.AlignHCenter // Center text horizontally
                    verticalAlignment: Text.AlignVCenter // Center text vertically
                }
            background: Rectangle{
                color:"black"
            }*/

            anchors{
                bottom:parent.bottom
                left: parent.left
                margins: 40

            }



            onClicked: mainLoader.source="stackViewPage.qml"

        }

        Column {
            anchors.centerIn: parent
            spacing: 10

            Text {
                text: "Select Gear:"
                color: "white"
                font.pixelSize: 38
                horizontalAlignment: Text.AlignHCenter
            }


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
                width: 100 // Set the width of the button
                height:100 // Set the height of the button

                onClicked: {
                    gearState = "Park"
                }
                background: Rectangle {
                    width: 100 // Set the width of the button
                    height:100
                    color: gearState === "Park" ? "green" : "black"
                    radius: 5
                    z:1
                    opacity: (gearState === "Park") ? 1 : 0
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
                width: 100 // Set the width of the button
                height:100 // Set the height of the button

                onClicked: {
                    gearState = "Reverse"
                }
                background: Rectangle {
                    color: gearState === "Reverse" ? "green" : "black"
                    radius: 5
                    width:100
                    height:100
                    z:1
                    opacity: (gearState === "Reverse") ? 1 : 0
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
                width: 100 // Set the width of the button
                height:100 // Set the height of the button

                onClicked: {
                    gearState = "Neutral"
                }
                background: Rectangle {
                    color: gearState === "Neutral" ? "green" : "black"
                    radius: 5
                    width:100
                    height:100
                    z:1
                    opacity: (gearState === "Neutral") ? 1 : 0
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
                width: 100 // Set the width of the button
                height:100 // Set the height of the button
                font.pixelSize: 18 // Set the font size of the button text
                onClicked: {
                    gearState = "Drive"
                }
                background: Rectangle {
                    color: gearState === "Drive" ? "green" : "black"
                    radius: 5
                    width:100
                    height:100
                    z:1
                    opacity: (gearState === "Drive") ? 1 : 0
                }

            }
        }
    }

    property string gearState: "Park"
}
