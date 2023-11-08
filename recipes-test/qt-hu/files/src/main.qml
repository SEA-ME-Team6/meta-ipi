import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 1.2
import QtQuick.Layouts 1.0



import"."



Window {
    id:root
    width: 1024
    height: 600
    visible: true
    title: qsTr("Head Unit")
    Image{
        id:backgroundImage
        anchors.fill:parent
        source: "backgr.png"
        }
    Rectangle {
        id:statusBar

        anchors{
            left:parent.left
            top: parent.top
            right:parent.right
        }
        color:Qt.rgba(0,0,0,0)
        RowLayout{
            id:buttonRow
            height:statusBar.height
            width:statusBar.width/3
            spacing: 0
            anchors{
                left:statusBar.left
                top:statusBar.top
            }

            }

        }
    Loader{
        id: mainLoader
        anchors{
                    left:parent.left
                    right: parent.right
                    top: statusBar.bottom
                    bottom:parent.bottom
        }
        source: "stackViewPage.qml"

    }



}
