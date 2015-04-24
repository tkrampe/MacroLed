import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2
import org.tyler.macroled 1.0

ApplicationWindow {
    title: qsTr("LED Controller")
    width: 640
    height: 480
    visible: true
    color: "#888888"

    MainForm {
        anchors.fill: parent
        btnOff.onClicked: Ctrl.turnOff();
        btnSelectClr.onClicked: colorDialog.open();
    }

    ColorDialog {
        id: colorDialog
        title: "Please choose a color"
        currentColor: "#555555"
        Component.onCompleted: {
            Ctrl.color = Qt.binding(function() {
                return colorDialog.currentColor;
            })
        }
    }
}
