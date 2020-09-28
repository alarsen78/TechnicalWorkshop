#include "albumreader.h"

#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QCoreApplication>

#include "album.h"
#include "photo.h"

AlbumReader::AlbumReader(QObject *parent) : QThread(parent)
{
}

void AlbumReader::run()
{
    printf("AlbumReader::run() starting\n");
    fflush(stdout);

    mAlbums.clear();

    printf("AlbumReader::run() reading JSON\n");
    fflush(stdout);

    QFile photosFile(":/photos.json");

    if (!photosFile.open(QIODevice::ReadOnly)) {
        emit failed("Couldn't open photos file!");
        return;
    }

    QByteArray photosData = photosFile.readAll();
    QJsonDocument loadDoc = QJsonDocument::fromJson(photosData);

    if (!loadDoc.isArray()) {
        emit failed("Photos file didn't contain an array as expected!");
        return;
    }

    QJsonArray photosArray = loadDoc.array();

    for (int i = 0; i < photosArray.size(); i++) {
        Photo photo;
        photo.read(photosArray.at(i).toObject());

        Album& album = mAlbums[photo.albumId()];
        if (album.albumId() == 0)
            album.setAlbumId(photo.albumId());

        album.addPhoto(photo);
    }

    printf("AlbumReader::run() pretending to load photos\n");
    fflush(stdout);

    std::this_thread::sleep_for (std::chrono::seconds(3));

    printf("AlbumReader::run() done\n");
    fflush(stdout);

    emit done();
}

