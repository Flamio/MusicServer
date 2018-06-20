#ifndef MUSICFINDER_H
#define MUSICFINDER_H

#include <QObject>
#include "imusicfinder.h"

class MusicFinder : public QObject, public IMusicFinder
{
    Q_OBJECT
public:
    explicit MusicFinder(QObject *parent = nullptr);
    virtual QList<QString>* getMusicFiles();

    void setPath(const QString &value);

signals:

public slots:

private:
    QString path;
    QList<QString> list;

};

#endif // MUSICFINDER_H
