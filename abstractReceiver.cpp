#include "abstractReceiver.h"
#include <QDebug>

GstreamerPlayer::GstreamerPlayer(QString filename, QObject *parent) : QObject(parent)
{
    this->fileName = filename;
    connect(this, &GstreamerPlayer::startSignal, this, &GstreamerPlayer::startInThread);
    moveToThread(&thread);
    thread.start();    
}

GstreamerPlayer::~GstreamerPlayer()
{
    thread.quit();
    thread.wait();
}

void GstreamerPlayer::startInThread()
{
    auto pipeline = QString("filesrc location=\"%1\" ! decodebin ! audioconvert ! audioresample ! alsasink device=hw:2").arg(fileName);
    app.pipeline = gst_parse_launch(pipeline.toStdString().c_str(), NULL);
    app.loop = g_main_loop_new (NULL, TRUE);

    auto bus = gst_pipeline_get_bus (GST_PIPELINE (app.pipeline));
    gst_bus_add_signal_watch (bus);
    g_signal_connect (G_OBJECT (bus), "message", G_CALLBACK(&GstreamerPlayer::on_message), NULL);
    gst_object_unref (GST_OBJECT (bus));

    gst_element_set_state (app.pipeline, GST_STATE_PLAYING);
    g_main_loop_run (app.loop);
}

gboolean GstreamerPlayer::on_message_callback(GstBus *, GstMessage *message, gpointer user_data)
{
    auto* app = reinterpret_cast<GstreamerPlayer*>(user_data);
    return app->on_message(message);
}

gboolean GstreamerPlayer::on_message(GstMessage *message)
{
    switch (GST_MESSAGE_TYPE (message)) {
    case GST_MESSAGE_ERROR:{
        GError *err = NULL;
        gchar *debug;

        gst_message_parse_error (message, &err, &debug);
        g_critical ("Got ERROR: %s (%s)", err->message, GST_STR_NULL (debug));
        g_main_loop_quit (app.loop);
        break;
    }
    case GST_MESSAGE_WARNING:{
        GError *err = NULL;
        gchar *debug;

        gst_message_parse_warning (message, &err, &debug);
        g_warning ("Got WARNING: %s (%s)", err->message, GST_STR_NULL (debug));
        g_main_loop_quit (app.loop);
        break;
    }
    case GST_MESSAGE_EOS:
        g_main_loop_quit (app.loop);
        break;
    default:
        break;
    }

    return TRUE;
}

void GstreamerPlayer::start()
{
    emit startSignal();
}
