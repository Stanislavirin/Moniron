#include <QDebug>
#include <videostreamobject.h>


VideoStreamObject::VideoStreamObject(QString threadName) :
    name(threadName)
{

}

bool VideoStreamObject::running() const
{
    return m_running;
}

WId VideoStreamObject::message() const
{
    return m_widgetID;
}

void VideoStreamObject::run()
{
    if (m_running)
    {
        qDebug()<<"ok ok ok";
        rtsp_server_start(m_widgetID);
    }
    emit finished();

}

void VideoStreamObject::setRunning(bool running)
{
    if (m_running == running)
        return;
    m_running = running;
    emit runningChanged(m_running);
}

void VideoStreamObject::setMessage(WId widgetID)
{
    if (m_widgetID == widgetID)
        return;
    m_widgetID = widgetID;
    emit messageChanged(m_widgetID);
}

