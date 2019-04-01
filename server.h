#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include "isettings.h"
#include "imusicfinder.h"
#include "iplayer.h"
#include <QList>
#include <QMultiHash>
#include <QTcpServer>
#include <QTcpSocket>

class Server : public QObject
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = nullptr);
    void run();
    void setPlayer(IPlayer *value);

signals:

public slots:

private:
    IPlayer* player;
    QTcpServer server;
    QList<QTcpSocket*> sockets;
    bool clientConnected = false;

    void onReadyRead();
    void onNewConnection();

    QMap<QByteArray, QByteArray> parseHeaders(QByteArray httpHeaders);
};

#endif // SERVER_H
