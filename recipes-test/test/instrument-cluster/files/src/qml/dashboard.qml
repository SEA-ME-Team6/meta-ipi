import QtQuick 2.2
import QtQuick.Window 2.1
import QtQuick.Controls 1.4
import QtQuick.Extras 1.4

Window {
    id: root
    visible: true
    width: 1280
    height: 400
    color: "#161616"
    title: "INSTRUMENT CLUSTER"
    visibility: Window.FullScreen

    ValueSource {
        id: valueSource
    }

    Item {
        rotation: -90
        id: container
        width: root.width
        height: Math.min(root.width, root.height)
        anchors.centerIn: parent

        Row {
            id: gaugeRow
            spacing: container.width * 0.02
            anchors.centerIn: parent

            Item {
                width: height
                height: container.height * 0.25 - gaugeRow.spacing
                anchors.verticalCenter: parent.verticalCenter

                CircularGauge {
                    id: fuelGauge
                    value: valueSource.fuel
                    minimumValue: 0
                    maximumValue: 100
                    y: parent.height / 2 - height / 2 - container.height * 0.01
                    width: parent.width
                    height: parent.height

                    style: IconGaugeStyle {
                        icon: "qrc:/images/battery.png"
                        minWarningColor: Qt.rgba(0.5, 0, 0, 1)
                    }

                    Behavior on value {
                        NumberAnimation {
                            duration: 200
                        }
                    }
                }
            }

            CircularGauge {
                id: speedometers
                value: valueSource.kph
                anchors.verticalCenter: parent.verticalCenter
                maximumValue: 100
                width: height
                height: container.height * 0.5

                style: DashboardGaugeStyle {}

                Behavior on value {
                    NumberAnimation {
                        duration: 200
                    }
                }
            }

            CircularGauge {
                id: tachometer
                width: height
                height: container.height * 0.25 - gaugeRow.spacing
                value: valueSource.rpm
                maximumValue: 8
                anchors.verticalCenter: parent.verticalCenter

                style: TachometerStyle {}

                Behavior on value {
                    NumberAnimation {
                        duration: 200
                    }
                }
            }
        }
        
        Item {
            anchors{
                horizontalCenter: parent.horizontalCenter
                top: parent.top
                topMargin: parent.width * 0.08
            }

            Image {
                id: p_gear
                source: "qrc:/images/p.png"
                visible: valueSource.gear === 0
            }

            Image {
                id: r_gear
                source: "qrc:/images/r.png"
                visible: valueSource.gear === 1
            }

            Image {
                id: n_gear
                source: "qrc:/images/n.png"
                visible: valueSource.gear === 2
            }

            Image {
                id: d_gear
                source: "qrc:/images/d.png"
                visible: valueSource.gear === 3
            }
        }

    }

}
