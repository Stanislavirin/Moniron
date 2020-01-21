#include "authwindow.h"
#include <QApplication>
#include <QtCore>

#include "mainwindow.h"
#include "authwindow.h"

#include <QtSerialPort/QtSerialPort>
#include <QtSerialPort/QSerialPortInfo>

#include <QDebug>
#include <QMessageBox>
#include "videostreamobject.h"
//QString SystemType;

#include <QMediaPlayer>
#include <QVideoWidget>


#include "authwindow.h"
#include "rotate_help.h"

//VideoStreamObject videostreamobject1("videostream");

//#include "scaner_new_test.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //VideoStreamObject videostreamobject1("videostream");



//    QThread thread_1;
//    QThread thread_2;

//    MainWindow testwindow;
//    testwindow.show();

    //videostreamobject1.setRunning(true);
    //videostreamobject1.start();


//    QMediaPlayer* player = new QMediaPlayer;
//    QVideoWidget* vw = new QVideoWidget;

//    player->setVideoOutput(vw);
//    player->setMedia(QUrl::fromLocalFile(""));  //"https://www.freedesktop.org/software/gstreamer-sdk/data/media/sintel_trailer-480p.webm"

//    vw->setGeometry(100,100,300,400);
//    vw->show();
//    player->play();

//    qDebug() << player->state();

//    a.setStyle("fusion");

//    QCoreApplication::setOrganizationName("PROFINDUSTRY");
//    QCoreApplication::setOrganizationDomain("www.profindustry.com/");
//    QCoreApplication::setApplicationName("MonironExpertS");


    Authwindow w;
    w.setWindowTitle("Авторизация");
    w.show();
    w.setFixedSize(w.sizeHint());

    //w.moveToThread(&thread_1);
    //ideostreamobject1.moveToThread(&thread_2);


    return a.exec();
}



