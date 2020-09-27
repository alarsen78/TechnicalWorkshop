#ifndef ALBUMREADER_H
#define ALBUMREADER_H

#include <QObject>
#include "album.h"

class AlbumReader : public QObject
{
    Q_OBJECT

public:
    explicit AlbumReader(QObject *parent = nullptr);

    Q_INVOKABLE bool read();

signals:
    void done();

private:
    QMap<int, Album> mAlbums;
};

#endif // ALBUMREADER_H
