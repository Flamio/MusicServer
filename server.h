#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include "isettings.h"
#include "imusicfinder.h"
#include "iplayer.h"
#include "track.h"
#include <QList>

class Server : public QObject
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = nullptr);

    void setSettings(ISettings *value);

    void run();

    void setMusicFinder(IMusicFinder *value);

    void setPlayer(IPlayer *value);

signals:

public slots:

private:
    ISettings* settings;
    IMusicFinder* musicFinder;
    IPlayer* player;
    QList<QString>* filesList;

    QList<MusicTrack> tracks;

};

#endif // SERVER_H
