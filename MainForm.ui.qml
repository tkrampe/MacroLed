import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Layouts 1.1

Item {
    width: 640
    height: 480

    property alias btnSelectClr: btnSelectClr
    property alias btnOff: btnOff

    RowLayout {
        spacing: 15
        anchors.verticalCenterOffset: 1
        anchors.horizontalCenterOffset: 1
        anchors.centerIn: parent


        Button {
            id: btnSelectClr
            text: qsTr("Select Color")
        }
        Button {
            id: btnOff
            text: qsTr("Off")
        }
    }
}
