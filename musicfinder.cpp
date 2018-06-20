#include "musicfinder.h"
#include <QDirIterator>
#include <QVariant>

MusicFinder::MusicFinder(QObject *parent) : QObject(parent)
{
}

bool variantLessThan(const QVariant &v1, const QVariant &v2)
{
    return v1.toString() < v2.toString();
}

QList<QString>* MusicFinder::getMusicFiles()
{
    QDirIterator it(path, QStringList() << "*.flac", QDir::Files, QDirIterator::Subdirectories);
    while (it.hasNext())
        list.append(it.next());

     qSort(list.begin(), list.end(), variantLessThan);
     return &list;
}

void MusicFinder::setPath(const QString &value)
{
    path = value;
}


