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

    for(auto filepath = filesList->begin(); filepath != filesList->end(); filepath++)
    {
        QStringList folders = filepath->remove(settings->getSettings()->value("music_folder").toString()).split("/");

        MusicTrack track;
        track.setAlbum(folders.at(1));
        track.setArtist(folders.at(0));
        track.setName(folders.last());

        tracks.append(track);
    }

    player->setList(filesList);



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
