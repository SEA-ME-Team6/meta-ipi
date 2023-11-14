import QtQuick 2.2

Item {
    id: valueSource
    property real kph:  icsystem.speed
    property real rpm:  icsystem.rpm
    property real fuel: icsystem.battery
    property real gear: icsystem.gear
}

