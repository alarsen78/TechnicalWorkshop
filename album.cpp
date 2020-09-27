#include "album.h"

Album::Album(int albumId)
    : mAlbumId(albumId)
{
}

int Album::albumId() const
{
 return mAlbumId;
}

void Album::setAlbumId(int albumId)
{
    mAlbumId = albumId;
}

const QMap<int, Photo>& Album::photos() const
{
    return mPhotos;
}

void Album::addPhoto(const Photo& photo)
{
    mPhotos.insert(photo.id(), photo);
}
