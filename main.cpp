#include <QCoreApplication>
#include "server.h"
#include "settings.h"
#include "musicfinder.h"
#include "player.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    gst_init(&argc, &argv);

   Server server(&a);

    Player player(&a);

    server.setPlayer(&player);
    server.run();
    return a.exec();
}
