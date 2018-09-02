#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include "iplayer.h"
#include <QMediaPlayer>

class Player : public QObject, public IPlayer
{
    Q_OBJECT
public:
    explicit Player(QObject *parent = nullptr);
    virtual ~Player();

    virtual void play(int id);
    virtual void setList(QList<QString> *value);

signals:

public slots:
private:
    QList<QString>* list;
    QMediaPlayer player;
};

#endif // PLAYER_H
