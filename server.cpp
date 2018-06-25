#include "server.h"
#include <QDebug>
#include <QDirIterator>
#include <QStringList>

Server::Server(QObject *parent) : QObject(parent)
{

}

void Server::setSettings(ISettings *value)
{
    settings = value;
}

void Server::run()
{
    if (!settings)
    {
        qDebug() << "settings.json not found";
        return;
    }

    filesList = musicFinder->getMusicFiles();

    int counter = 0;
    for(auto filepath = filesList->begin(); filepath != filesList->end(); filepath++)
    {
        static QString previousAlbum;
        QStringList folders = filepath->remove(settings->getSettings()->value("music_folder").toString()).split("/");

        auto artist = folders.at(0);
        auto album = folders.at(1);
        auto track = folders.last();

        artists.insert(artist);

        if (previousAlbum != album)
            albums.insertMulti(artist, album);

        tracks.insertMulti(album, QPair<int, QString>(counter, track));

        previousAlbum = album;

        counter++;
    }

    player->setList(filesList);

    auto it = albums.values("Maks");

    qDebug() << it;

    //player->play(15);
}

void Server::setMusicFinder(IMusicFinder *value)
{
    musicFinder = value;

    auto settingsObject = settings->getSettings();
    auto musicFolder = settingsObject->value("music_folder").toString();
    musicFinder->setPath(musicFolder);
}

void Server::setPlayer(IPlayer *value)
{
    player = value;
}
