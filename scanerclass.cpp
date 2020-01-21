#include "scanerclass.h"
#include <scaner_new_test.h>
ScanerClass::ScanerClass(QObject *parent) : QObject(parent)
{

}

bool ScanerClass::running() const
{
    return m_running;
}

void ScanerClass::run()
{
//    while (m_running)
//    {
//    ScanerInit();
//    ScanerStart();
//    }
    emit finished();
}


void ScanerClass::setRunning(bool running)
{
    if (m_running == running)
        return;

    m_running = running;
    emit runningChanged(m_running);
}


void ScanerClass::ScanerInit()
{
    scaner_init();
}

void ScanerClass::ScanerStart()
{
    read_image_main(); //разрешаем внесение купюр
}

void ScanerClass::ScanerRollback()
{
    command(14);
}
void ScanerClass::ScanerStop()
{
     command(2);
}
