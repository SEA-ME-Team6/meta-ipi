import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.2

Window {
    width: 1024
    height: 600
    visible: true
    title: qsTr("Hello World")

    Column{
        Button {
            text: "0"
            font.family: "Arial"
            onClicked: {
                server.buttonPressed(0)
            }
        }

        Button {
            text: "1"
            font.family: "Arial"
            onClicked: {
                server.buttonPressed(1)
            }
        }

        Button {
            text: "2"
            font.family: "Arial"
            onClicked: {
                server.buttonPressed(2)
            }
        }

        Button {
            text: "3"
            font.family: "Arial"
            onClicked: {
                server.buttonPressed(3)
            }
        }
    }

}
