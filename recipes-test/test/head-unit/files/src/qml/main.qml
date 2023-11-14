import QtQuick 2.2
import QtQuick.Window 2.1
import QtQuick.Controls 2.2

Window {
    id:root
    width: 1024
    height: 600
    visible: true
    color: "black"

    StackView{
        id:stackview
        x: -256
        y: -150
        anchors{
            left: parent.left
            top: parent.top
        }
        initialItem: "qrc:/qml/home.qml"
    }
}
