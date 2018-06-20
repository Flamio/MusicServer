#ifndef IPLAYER_H
#define IPLAYER_H

#include <QList>

class IPlayer
{
public:
   virtual void play(int id) = 0;
   virtual void setList(QList<QString>*) = 0;
};

#endif // IPLAYER_H
