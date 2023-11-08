import QtQuick 2.15
import QtQuick.Window 2.15

Window {
    width: 1024
    height: 600
    visible: true
    title: qsTr("Hello World")
    color: "gray"

    Item{
        id: box
        width: 400
        height: 1280
        anchors.centerIn: parent
        rotation: 0
        scale: 0.5

        Text {
            id: name
            text: qsTr("HEllo HU")
            font.pointSize: 30
            color: "blue"
            anchors.centerIn: parent
        }
    }

}
