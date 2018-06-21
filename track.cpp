#include "track.h"

int MusicTrack::getId() const
{
    return id;
}

void MusicTrack::setId(int value)
{
    id = value;
}

QString MusicTrack::getArtist() const
{
    return artist;
}

void MusicTrack::setArtist(const QString &value)
{
    artist = value;
}

QString MusicTrack::getAlbum() const
{
    return album;
}

void MusicTrack::setAlbum(const QString &value)
{
    album = value;
}

QString MusicTrack::getName() const
{
    return name;
}

void MusicTrack::setName(const QString &value)
{
    name = value;
}
