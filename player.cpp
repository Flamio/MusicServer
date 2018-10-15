#include "player.h"
#include <QMediaContent>

Player::Player(QObject *parent) : QObject(parent), player(nullptr)
{
}

Player::~Player()
{
    delete player;
}

void Player::play(int id)
{
    if (player != nullptr)
        delete player;
    auto filename = list->at(id);

    player = new GstreamerPlayer(filename);

    player->start();
}

void Player::setList(QList<QString> *value)
{
    list = value;
}
