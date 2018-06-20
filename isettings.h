#ifndef ISETTINGS_H
#define ISETTINGS_H

#include <QJsonObject>

class ISettings
{
public:
    virtual QJsonObject* getSettings() = 0;
};

#endif // ISETTINGS_H
