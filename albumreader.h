#ifndef ALBUMREADER_H
#define ALBUMREADER_H

#include <QThread>
#include "album.h"

class AlbumReader : public QThread
{
    Q_OBJECT

public:
    explicit AlbumReader(QObject *parent = nullptr);

    void run() override;

signals:
    void done();
    void failed(const QString& msg);

private:
    QMap<int, Album> mAlbums;
};

#endif // ALBUMREADER_H
