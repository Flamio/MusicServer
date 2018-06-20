#ifndef IMUSICFINDER_H
#define IMUSICFINDER_H

#include <QList>

class IMusicFinder
{
public:
    virtual QList<QString>* getMusicFiles() = 0;
    virtual void setPath(const QString &value) = 0;
};

#endif // IMUSICFINDER_H
