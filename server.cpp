#include "server.h"
#include <QDebug>
#include <QDirIterator>
#include <QStringList>
#include <QJsonDocument>
#include <QJsonArray>

Server::Server(QObject *parent) : QObject(parent)
{
    server.listen(QHostAddress::Any, 5050);
    connect(&server, &QTcpServer::newConnection, this, &Server::onNewConnection);
}

void Server::run()
{

}

void Server::setPlayer(IPlayer *value)
{
    player = value;
}

void Server::onReadyRead()
{
    auto socket = dynamic_cast<QTcpSocket*>(sender());
    auto query = socket->readAll();



    socket->write("lol");
    socket->waitForBytesWritten();

    /*auto headers = parseHeaders(query);

    for (auto socket : sockets)
    {
        socket->close();
        delete socket;
    }

    sockets.clear();*/
}

void Server::onNewConnection()
{
    auto socket = server.nextPendingConnection();
    sockets.append(socket);
    connect(socket, &QTcpSocket::readyRead, this, &Server::onReadyRead);

    clientConnected = true;
}

QMap<QByteArray, QByteArray> Server::parseHeaders(QByteArray httpHeaders)
{
    QMap<QByteArray, QByteArray> headers;

    // Discard the first line
    httpHeaders = httpHeaders.mid(httpHeaders.indexOf('\n') + 1).trimmed();

    foreach(QByteArray line, httpHeaders.split('\n')) {
        int colon = line.indexOf(':');
        QByteArray headerName = line.left(colon).trimmed();
        QByteArray headerValue = line.mid(colon + 1).trimmed();

        headers.insertMulti(headerName, headerValue);
    }

    return headers;
}
