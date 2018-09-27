#include "server.h"
#include <QDebug>
#include <QDirIterator>
#include <QStringList>
//#include <QNetworkDatagram>
#include <QJsonDocument>
#include <QJsonArray>

Server::Server(QObject *parent) : QObject(parent)
{
    socket.bind(QHostAddress::Any,5050);
    connect(&socket, &QUdpSocket::readyRead, this, &Server::onReadyRead);
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

    qSort(filesList->begin(),filesList->end(),[](QString& a, QString& b) { return a > b; });

    int counter = 0;
    for(auto filepath = filesList->begin(); filepath != filesList->end(); filepath++)
    {
        static QString previousAlbum;
        auto path = *filepath;
        QStringList folders = path.remove(settings->getSettings()->value("music_folder").toString()).split("/");

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

     auto it =  tracks.values("2018 - План Ломоносова IV").first();

    qDebug() << it.first;
    qDebug() << it.second;

    player->play(it.first);
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

void Server::onReadyRead()
{
  /*  while (socket.hasPendingDatagrams())
    {
        auto datagram = socket.receiveDatagram();
        auto data = datagram.data();

        auto address = datagram.destinationAddress();
        auto port = datagram.destinationPort();

        auto json = QJsonDocument::fromJson(data).object();

        auto query = json.value("query").toString();

        if (query == "artist")
        {
            QJsonObject jsonObject;
            QJsonArray array;
            for(auto artist = artists.begin(); artist != artists.end(); artist++)
            {
                array.push_back(*artist);
            }
            jsonObject.insert("artists", array);
            QJsonDocument doc(jsonObject);
            auto answer = doc.toJson();
            qDebug() << answer;

            socket.writeDatagram(answer, address, 5051);

            qDebug() << address;
            qDebug() << port;

            break;
        }
    }*/
}
