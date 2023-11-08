import QtQuick 2.15
import QtQuick.Window 2.15

Window {
    width: 400
    height: 1280
    visible: true
    title: qsTr("Hello World")


    Item{
        id: box
        width: 400
        height: 1280
        anchors.centerIn: parent
        rotation: 0
        scale: 0.5

        Text{
            text: "HEllo IC"
            font.pointSize: 30
            color: "red"
            anchors.centerIn: parent
        }
    }

}
