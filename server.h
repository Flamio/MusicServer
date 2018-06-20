#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include "isettings.h"
#include "imusicfinder.h"

class Server : public QObject
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = nullptr);

    void setSettings(ISettings *value);

    void run();

    void setMusicFinder(IMusicFinder *value);

signals:

public slots:

private:
    ISettings* settings;
    IMusicFinder* musicFinder;
    QList<QString>* filesList;
};

#endif // SERVER_H
