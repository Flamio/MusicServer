QT -= gui
QT += network

CONFIG += c++11 console
CONFIG -= app_bundle

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH+=/usr/include/gstreamer-1.0 /usr/include/glib-2.0 /usr/lib/x86_64-linux-gnu/glib-2.0/include

CONFIG += link_pkgconfig
PKGCONFIG += gstreamer-1.0 glib-2.0 gobject-2.0


SOURCES += main.cpp \
    server.cpp \
    settings.cpp \
    musicfinder.cpp \
    player.cpp \
    abstractReceiver.cpp

DISTFILES += \
    settings.json

HEADERS += \
    server.h \
    isettings.h \
    settings.h \
    imusicfinder.h \
    musicfinder.h \
    iplayer.h \
    player.h \
    abstractReceiver.h
