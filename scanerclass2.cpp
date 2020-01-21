#include "scanerclass2.h"

#include "scaner_new_test.h"

ScanerClass2::ScanerClass2(QObject *parent) :
    QObject(parent)
{

}


bool ScanerClass2::running() const
{
    return m_running;
}

void ScanerClass2::run()
{

    while(m_running)
    {
//          ScanerInit();
//          ScanerStart();
    }
//    emit finished();
}

void ScanerClass2::setrunning(bool running)
{
    if (m_running == running)
        return;

    m_running = running;
    emit runningChanged(m_running);
}





//void ScanerClass2::ScanerStart()
//{
//    read_image_main(); //разрешаем внесение купюр
//}
//void ScanerClass2::ScanerInit()
//{
//    scaner_init();
//}
//void ScanerClass2::ScanerRollback()
//{
//    command(14);
//}
//void ScanerClass2::ScanerStop()
//{
//     command(2);
//}
