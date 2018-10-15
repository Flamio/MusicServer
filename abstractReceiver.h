#ifndef ABSTRACTRECEIVER_H
#define ABSTRACTRECEIVER_H

#include <QObject>
#include <QThread>
#include <QTimer>
#include <gst/gst.h>

typedef struct _App App;

struct _App
{
    GstElement *pipeline = nullptr;
    GMainLoop *loop;
    guint sourceid = 0;
};

class GstreamerPlayer : public QObject
{
    Q_OBJECT
public:
    explicit GstreamerPlayer(QString filename, QObject *parent = nullptr);
    virtual ~GstreamerPlayer();

    gboolean on_message(GstMessage * message);


    void start();

signals:
    void startSignal();

public slots:

private:
    QThread thread;
    App app;

    int timestamp = 0;
    QString fileName;

    QByteArray dataBuffer;

    void startInThread();

    static gboolean on_message_callback(GstBus * bus, GstMessage * message, gpointer user_data);
};

#endif // ABSTRACTRECEIVER_H
