#include "connectionobject.h"
#include "operatorwindow.h"
#include "authwindow.h"
#include <QDebug>

ConnectionObject::ConnectionObject(QObject *parent) :
    QObject(parent),
    m_message("")
{

}

bool ConnectionObject::running() const
{
    return m_running;
}

QString ConnectionObject::message() const
{
    return m_message;
}

void ConnectionObject::run()
{
    count = 0;
    while(m_running)
    {
//        count++;
//        qDebug() << m_message << " " << count;
          Connect();       
    }
    emit finished();
}

void ConnectionObject::setRunning(bool running)
{
    if (m_running == running)
        return;

    m_running = running;
    emit runningChanged(m_running);
}

void ConnectionObject::setMessage(QString message)
{
    if (m_message == message)
        return;

    m_message = message;
    emit messageChanged(m_message);
}


void ConnectionObject::Connect()
{
    socket = new QTcpSocket(this);
    socket->connectToHost("voidrealms.com",80);
    if (socket->waitForConnected(10000)){
        //qDebug() << "Connected!";
        emit ShowYesConnection();
        socket -> close();
    }
    else {
        emit ShowNoConnection();
        //qDebug()<< "Not Connected!";
    }
}
