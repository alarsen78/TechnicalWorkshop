import QtQuick 2.9
import QtQuick.Window 2.2
import com.gmail.larand78 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Albums")

    LoaderAnimation {
        id: loaderAnimation
    }

    Text {
        id: imagePlaceholder
        text: "Albums UI placeholder..."
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        visible: false
    }

    Text {
        id: errorMessage
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        visible: false
    }

    AlbumReader {
        id: albumReader
        onDone: {
            loaderAnimation.visible = false
            imagePlaceholder.visible = true
        }
        onFailed: {
            loaderAnimation.visible = false
            errorMessage.text = "Failed to load albums: " + msg
            errorMessage.visible = true
        }
    }

    Component.onCompleted: {
        albumReader.start()
    }
}
