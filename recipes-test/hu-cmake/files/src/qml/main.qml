import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.2

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Column{
        Button {
            text: "0"
            onClicked: {
                server.buttonPressed(0)
            }
        }

        Button {
            text: "1"
            onClicked: {
                server.buttonPressed(1)
            }
        }

        Button {
            text: "2"
            onClicked: {
                server.buttonPressed(2)
            }
        }

        Button {
            text: "3"
            onClicked: {
                server.buttonPressed(3)
            }
        }
    }

}
