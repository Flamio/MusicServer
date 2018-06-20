#ifndef SETTINGS_H
#define SETTINGS_H

#include <QObject>
#include "isettings.h"

class Settings : public QObject, public ISettings
{
    Q_OBJECT
public:
    explicit Settings(QObject *parent = nullptr);
    virtual QJsonObject* getSettings();

signals:

public slots:
private:
    QJsonObject settings;
};

#endif // SETTINGS_H
