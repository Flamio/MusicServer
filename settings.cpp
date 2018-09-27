#include "settings.h"
#include <QFile>
#include <QJsonDocument>


Settings::Settings(QObject *parent) : QObject(parent)
{
    QFile file("/etc/MusicServer/settings.json");
    file.open(QIODevice::ReadOnly);
    auto data = file.readAll();
    settings = QJsonDocument::fromJson(data).object();
}

QJsonObject *Settings::getSettings()
{
    return &settings;
}
