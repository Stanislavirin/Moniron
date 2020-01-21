#include "comsignalsobject.h"

ComSignalsObject::ComSignalsObject(QObject *parent) :
    QObject(parent),
    m_message("")
{

}


bool ComSignalsObject::running() const
{
    return m_running;
}

QString ComSignalsObject::message() const
{
    return m_message;
}

void ComSignalsObject::run()
{
    count = 0;
    while(m_running)
    {



    }
    emit finished();
}

void ComSignalsObject::setRunning(bool running)
{
    if (m_running == running)
        return;

    m_running = running;
    emit runningChanged(m_running);
}

void ComSignalsObject::setMessage(QString message)
{
    if (m_message == message)
        return;

    m_message = message;
    emit messageChanged(m_message);
}


void ComSignalsObject::Connect()
{


}
