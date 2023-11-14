import QtQuick 2.2
import QtQuick.Window 2.1
import QtQuick.Controls 2.2

Item {
    id:home
    width: 1024
    height: 600
    scale: 0.5
    x: -256
    y: -150
    
    Image{
        id:background
        source: "qrc:/images/benz.jpg"
        anchors{
            right: parent.right
            bottom: parent.bottom
        }
        Image{
            id:head_light_left
            anchors{
                verticalCenter: parent.verticalCenter
                left: parent.left
            }
            source: "qrc:/images/head_light.png"
            visible: husystem.light
        }

        Image {
            id:head_light_right
            anchors{
                verticalCenter: parent.verticalCenter
                right: parent.right
            }
            source: "qrc:/images/head_light.png"
            visible: husystem.light
        }

        Image {
            anchors{
                horizontalCenter: parent.horizontalCenter
                top: head_light_right.bottom
            }
            source: "qrc:/images/ground_shadow.png"
            fillMode: Image.PreserveAspectFit
        }

    }
    Row{
        anchors{
            right: parent.right
            top: parent.top
            topMargin: 52
            rightMargin: 180
        }
        spacing: 200
        Button {
            id: music_icon
            background: Image {
                source: "qrc:/images/music.jpeg"
                anchors.fill: parent
                fillMode: Image.PreserveAspectFit
            }
            onClicked: {
                stackview.push(Qt.resolvedUrl("/music.qml"))
            }
        }

        Button {
            id: light_icon
            background: Image {
                source: "qrc:/images/setting.jpeg"
                anchors.fill: parent
                fillMode: Image.PreserveAspectFit
            }
            onClicked: {
                stackview.push(Qt.resolvedUrl("/light.qml"))
            }
        }

        Button {
            id: video_icon
            background: Image {
                source: "qrc:/images/video.png"
                anchors.fill: parent
                fillMode: Image.PreserveAspectFit
            }
            onClicked: {
                stackview.push(Qt.resolvedUrl("/video.qml"))
            }
        }
    }

    Column{
        anchors{
            verticalCenter: parent.verticalCenter
            left: parent.left
            leftMargin: 32
        }
        spacing: 50
        Button {
            id: p_gear
            background: Image {
                source: "qrc:/images/p.png"
                anchors.fill: parent
            }
            onClicked: {
                husystem.changegear(0);
            }
        }

        Button {
            id: r_gear
            background: Image {
                source: "qrc:/images/r.png"
                anchors.fill: parent
            }
            onClicked: {
                husystem.changegear(1);
            }
        }

        Button {
            id: n_gear
            background: Image {
                source: "qrc:/images/n.png"
                anchors.fill: parent
            }
            onClicked: {
                husystem.changegear(2);
            }
        }
        Button {
            id: d_gear
            background: Image {
                source: "qrc:/images/d.png"
                anchors.fill: parent
            }
            onClicked: {
                husystem.changegear(3);
            }
        }
    }

}
