#ifndef ALBUM_H
#define ALBUM_H

#include <QString>
#include <QJsonObject>

#include "photo.h"

class Album
{
public:
    Album() = default;
    Album(int albumId);

    int albumId() const;
    void setAlbumId(int albumId);

    void addPhoto(const Photo& photo);

    const QMap<int, Photo>& photos() const;

private:
    int mAlbumId;
    QMap<int, Photo> mPhotos;
};

#endif // ALBUM_H
