import QtQuick 2.0

Rectangle {
    property int startDelay: 0

    x: 0
    y: 240
    height: 64
    width: 64
    color: "skyblue"
    radius: 16

    Timer {
        interval: startDelay; running: true; repeat: false
        onTriggered: yAnim.running = true
    }

    SequentialAnimation on y {
        id: yAnim
        running: false
        loops: Animation.Infinite
        NumberAnimation { from: 240; to: 112; duration: 1500; easing.type: Easing.InOutQuad }
        NumberAnimation { from: 112; to: 240; duration: 1500; easing.type: Easing.InOutQuad }
        PauseAnimation { duration: 1000 }
    }
}
