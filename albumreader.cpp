#include "albumreader.h"

#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QCoreApplication>

#include "album.h"
#include "photo.h"

AlbumReader::AlbumReader(QObject *parent) : QObject(parent)
{
}

bool AlbumReader::read()
{
    printf("AlbumReader::read() starting\n");
    fflush(stdout);

    // TODO: This function blocks the UI.
    //       Use QThread or QtConcurrent here to do loading in worker thread?

    mAlbums.clear();

    QFile photosFile(":/photos.json");

    if (!photosFile.open(QIODevice::ReadOnly)) {
        qWarning("Couldn't open photos file.");
        return false;
    }

    QByteArray photosData = photosFile.readAll();
    QJsonDocument loadDoc = QJsonDocument::fromJson(photosData);

    if (!loadDoc.isArray()) {
        qWarning("Photos file didn't contain an array as expected");
        return false;
    }

    QJsonArray photosArray = loadDoc.array();

    for (int i = 0; i < photosArray.size(); i++) {
        Photo photo;
        photo.read(photosArray.at(i).toObject());

        Album& album = mAlbums[photo.albumId()];
        if (album.albumId() == 0)
            album.setAlbumId(photo.albumId());

        album.addPhoto(photo);

        // TODO: Remove when this funcion is run in worker thread
        QCoreApplication::processEvents();

    }

    printf("AlbumReader::read() done\n");
    fflush(stdout);

    emit done();

    return true;
}
