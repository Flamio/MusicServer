#include "server.h"
#include <QDebug>
#include <QDirIterator>

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

}

void Server::setMusicFinder(IMusicFinder *value)
{
    musicFinder = value;

    auto settingsObject = settings->getSettings();
    auto musicFolder = settingsObject->value("music_folder").toString();
    musicFinder->setPath(musicFolder);
}
