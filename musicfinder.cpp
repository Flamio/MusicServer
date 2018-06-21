#include "musicfinder.h"
#include <QDirIterator>
#include <QVariant>

MusicFinder::MusicFinder(QObject *parent) : QObject(parent)
{
}

QList<QString>* MusicFinder::getMusicFiles()
{
    QDirIterator it(path, QStringList() << "*.flac", QDir::Files, QDirIterator::Subdirectories);
    while (it.hasNext())
        list.append(it.next());

     return &list;
}

void MusicFinder::setPath(const QString &value)
{
    path = value;
}
