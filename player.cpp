#include "player.h"
#include <QMediaContent>

Player::Player(QObject *parent) : QObject(parent)
{

}

Player::~Player()
{
    player.stop();
}

void Player::play(int id)
{
    QMediaContent content(QUrl::fromLocalFile(list->at(id)));
    player.setMedia(content);
    player.play();
}

void Player::setList(QList<QString> *value)
{
    list = value;
}
