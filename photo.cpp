#include "photo.h"

Photo::Photo(int id, int albumId, const QString &title, const QString &url, const QString &thumbnailUrl)
    : mId(id), mAlbumId(albumId), mTitle(title), mUrl(url), mThumbnailUrl(thumbnailUrl)
{
}

int Photo::albumId() const
{
    return mAlbumId;
}

int Photo::id() const
{
    return mId;
}

QString Photo::title() const
{
    return mTitle;
}

void Photo::read(const QJsonObject &json)
{
    if (json.contains("albumId") && json["albumId"].isDouble())
        mAlbumId = json["albumId"].toInt();
    if (json.contains("id") && json["id"].isDouble())
        mId = json["id"].toInt();
    if (json.contains("title") && json["title"].isString())
        mTitle = json["title"].toString();
    if (json.contains("url") && json["url"].isString())
        mUrl = json["url"].toString();
    if (json.contains("thumbnailUrl") && json["thumbnailUrl"].isString())
        mThumbnailUrl = json["thumbnailUrl"].toString();
}
