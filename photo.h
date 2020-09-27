#ifndef PHOTO_H
#define PHOTO_H

#include <QString>
#include <QJsonObject>

class Photo
{
public:
    Photo() = default;
    Photo(int id, int albumId, const QString &title, const QString &url, const QString &thumbnailUrl);

    void read(const QJsonObject &json);
    int albumId() const;
    int id() const;
    QString title() const;

private:
    int mId;
    int mAlbumId;
    QString mTitle;
    QString mUrl;
    QString mThumbnailUrl;
};

#endif // PHOTO_H
