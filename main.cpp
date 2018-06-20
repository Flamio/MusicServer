#include <QCoreApplication>
#include "server.h"
#include "settings.h"
#include "musicfinder.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Server server(&a);

    Settings settings(&a);

    MusicFinder musicFinder(&a);

    server.setSettings(&settings);
    server.setMusicFinder(&musicFinder);
    server.run();

    return a.exec();
}
