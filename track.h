#ifndef TRACK_H
#define TRACK_H

#include <QObject>

class MusicTrack
{    
public:

    int getId() const;
    void setId(int value);

    QString getArtist() const;
    void setArtist(const QString &value);

    QString getAlbum() const;
    void setAlbum(const QString &value);

    QString getName() const;
    void setName(const QString &value);

private:
    int id;
    QString artist;
    QString album;
    QString name;
};

#endif // TRACK_H
