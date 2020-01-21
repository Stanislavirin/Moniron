#ifndef VIDEOSTREAMOBJECT_H
#define VIDEOSTREAMOBJECT_H

#include <rtsp_server.h>
#include <QThread>
#include <QFrame>

class VideoStreamObject : public QThread
{
    Q_OBJECT
    Q_PROPERTY(bool running READ running WRITE setRunning NOTIFY runningChanged)
    Q_PROPERTY(WId widgetID READ message WRITE setMessage NOTIFY messageChanged)

public:
    explicit VideoStreamObject(QString threadName);
    bool running() const;
    WId message() const;

public slots:
    void run();
    void setRunning(bool running);
    void setMessage(WId widgetID);

private:
    QString name;
    bool m_running;
    WId m_widgetID;

signals:
    void finished();
    void runningChanged(bool running);
    void messageChanged(WId widgetID);
};

#endif // VIDEOSTREAMOBJECT_H
