#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "authwindow.h"

#include <QtSerialPort/QtSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QMessageBox>
#include <QDebug>
#include <QtCore>

//#include "cameraclass.h"
#include "videostreamobject.h"
#include "gstreamer_example.h"
#include <emitterclass.h>

//#include <cv.h>
//#include <highgui.h>

//EmitterClass b;
//extern VideoStreamObject videostreamobject1;

//#include "opencv.hpp"

//#include "videostreamobject.h"






//! [0]
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{


//! [0]
    ui->setupUi(this);
//    connect(&b, &EmitterClass::WidSignal, &videostreamobject1, &VideoStreamObject::run);
    //setMessage(b.widgetID);
    //widjet=ui->frame;
    //example();
//    b.widgetID=ui->frame->winId();
//    videostreamobject1.setMessage(b.widgetID);
//    videostreamobject1.setRunning(true);
//    b.WidSend();


//    example_run(ui->frame);



//    VideoStreamObject videostreamobject1("videostream");
//    videostreamobject1.start();


    //! [1]
//    serial = new QSerialPort(this);


//    if(! image.data )
//           {
//                  qDebug() <<  "Could not open or find the image" ;
//           }


//! [1]

}

MainWindow::~MainWindow()
{
    //videostreamobject1.setRunning(false);
    delete ui;
}

//! [4]
void MainWindow::openSerialPort()
{
    serial->setPortName("COM13");
    serial->setBaudRate(QSerialPort::Baud9600);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);
    if (serial->open(QIODevice::ReadWrite)) {
       ;
    } else {
       ;
    }
}
//! [4]


void MainWindow::on_pushButton_clicked() // успешное самотестирование
{

//    authwindow1 = new Authwindow();
//    connect(authwindow1, &Authwindow::firstWindow, this, &MainWindow::show);

//    authwindow1->show();
//    this->close();
}

void MainWindow::on_pushButton_4_clicked() // openserial
{
    MainWindow::openSerialPort();

}

void MainWindow::on_pushButton_5_clicked() // DTR
{
    if (serial->isDataTerminalReady()){
        serial->setDataTerminalReady(false);
    }
    else {
        serial->setDataTerminalReady(true);
    }
}


void MainWindow::on_pushButton_6_clicked() // RTS
{
    if (serial->isRequestToSend()){
        serial->setRequestToSend(false);
    }
    else {
        serial->setRequestToSend(true);
    }

}




void MainWindow::on_pushButton_2_clicked() // неуспешное самотестирование
{
    QMessageBox::warning(this, "", "Самотестирование не пройдено!");
}
