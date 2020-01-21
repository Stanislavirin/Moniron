#include "operatorwindow.h"
#include "ui_operatorwindow.h"
#include <QDateTime>
#include <QPixmap>
#include <QTimer>
#include <QtDebug>

#include <QtCore>
#include <QtXml>



#include <QCamera>
#include <QCameraViewfinder>
#include <QCameraImageCapture>
#include <QVBoxLayout>
#include <QMenu>
#include <QAction>
#include <QFileDialog>
#include <QCameraInfo>
#include <QSerialPortInfo>
#include <QCameraInfo>
#include <QMessageBox>
#include <QFile>
#include <QtXml>
#include <QSerialPort>
#include <QMediaRecorder>

#include "opencv2/opencv.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include "rotate_help.h"
#include "text_detection.h"

#include "windows.h"
#include <stdio.h>
#include <process.h>
#include "goslotolib.h"
#include "scaner_new_test.h"
#include <QPixmap>
#include <QPainter>
#include "videostreamobject.h"


#include <QXmlStreamWriter>
#include <QXmlStreamReader>


#include <QPrintDialog>
#include <QPrinter>

#include <scanerclass.h>


extern QString ComNumber1,Description1,Manufactor1,Serial_number1,System_path1,Vendor_ID1,Manufactor_ID1;
extern QString ComNumber2,Description2,Manufactor2,Serial_number2,System_path2,Vendor_ID2,Manufactor_ID2;
extern QString Cam_type,Device_name;
extern QString BankName, UnitNum;
extern QString ScanerHWVer;
extern QByteArray image_buffer; // буфер со сканом купюры
extern QByteArray image_buffer_simple; //буфер со сканом купюры
extern QByteArray image_buffer_sensors; //буфер со сканом купюры sensors
extern QString Machine_serial; // серийный номер машины
extern QString Machine_ID; // идентификатор машины в сети ... возможно... взято из протокола ЦБ
extern QString Machine_nominal; //Номинал купюр, принимаемый машиной

cv::dnn::Net net;



int TotalFit_int, TotalUnfit_int, TotalShred_int, TotalReject_int;

QDomDocument Result_doc;
QDomElement root;
QDomElement SSMS,SSM,USER,NOMINAL,Quality,Outpck, AU, B;
QDomElement Totals, TotalFit, TotalUnfit, TotalShred, TotalReject;
QDomText TotalFitText, TotalUnfitText, TotalShredText, TotalRejectText;

extern QString User_ID;  //Идентификатор оператора
static int Banknote_Id=0; // Id отсканированной купюры

int did_array[255]; // массив кол-ва купюр с определнным did
int machine_num=163503257; // Номер машины
int machine_ID=3257; // ID машины
static int Protocol_Num=0;
QString Start_Time="00.00.0000 00:00:00";
static int Index=4;
QString Form_Time="12.12.1212 12:12:12";
int nominal; // номинал купюр
int denomid=3; // ID номинала

static int banknote_count; //всего банкнот
QString qualityName_value="normal";
QString Outpck_value="1";

#include "emitterclass.h"
extern EmitterClass a;
extern EmitterClass image_simple;
extern EmitterClass image_sensors;

extern VideoStreamObject videostreamobject1;
EmitterClass b;



OperatorWindow::OperatorWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::OperatorWindow)
{
    nominal=Machine_nominal.toInt();
    ui->setupUi(this);
    ui->CashRollBack->setEnabled(true);

    //заполняем поля с номиналом
    ui->label_8->setText(Machine_nominal);//(QString::number(nominal));
    ui->label_12->setText(Machine_nominal);//(QString::number(nominal));
    ui->label_17->setText(Machine_nominal);//(QString::number(nominal));
    ui->label_22->setText(Machine_nominal);//(QString::number(nominal));



    //включаем таймер прокрутки
//    QTimer* timer_shreder_off = new QTimer(this); // таймер, для отложенного выключения двигателя шредера
//    connect(timer_shreder_off, SIGNAL(timeout()),this,SLOT(onTimeout_shreder_off()));
//    timer_shreder_off->setInterval(5000);


//подключаем и проверяем наличие требуемого COM порта
    //com_open(this);
//подключаем и проверяем наличие требуемой камеры
    int camid=-1;
    int position=-1;
    const auto infos = QCameraInfo::availableCameras();
    QString Description;
    for (const QCameraInfo &info : infos) {
        QStringList list;
        position++;
        Description = info.description();
        list << info.deviceName();
        if (Device_name==info.deviceName())
        {
            //наша камера подключена
            camid=position;
            //qDebug()<<camid;
        }  
    }



    if (camid==-1)
    {
        QMessageBox::warning(this, "Ошибка", "Не удалось обнаружить установленную администратором камеру");
//        this->close();
    }
    else
    {
        //----------------------------------------------------------------
        //Подключаем камеру через gstreamer
        //----------------------------------------------------------------

        connect(&b, &EmitterClass::WidSignal, &videostreamobject1, &VideoStreamObject::run);
        b.widgetID=ui->frame->winId();
        videostreamobject1.setMessage(b.widgetID);
        videostreamobject1.setRunning(true);
        b.WidSend();



//        //подключаем камеру в OpenCV
//        capWebcam.open(camid);
//        capWebcam.set(3,1920); //1920
//        capWebcam.set(4,1080); //1080
//        //qDebug() << capWebcam.get(3) << capWebcam.get(4);

//        if (capWebcam.isOpened()== false){
//            qDebug() << "error: capWebcam not accessed successfully";
//            //          this->close();
//        }

//        VideoRecordTimer = new QTimer(this);
//        VideoShowTimer = new QTimer(this);
//        connect(VideoShowTimer, SIGNAL(timeout()), this, SLOT(processCameraShow()));
//        connect(VideoRecordTimer, SIGNAL(timeout()),this, SLOT(processCameraRecord()));
//        VideoShowTimer->start(10);
//        const char *filename = "Video.avi";
//        double fps = 15; // частота кадров
//        //writeWebcam.fourcc('M','J','P','G');
//        writeWebcam.open(filename, writeWebcam.fourcc('M','J','P','G'), fps, cv::Size(800, 600), true);

    }
    //Подргужаем нейросеть для детектирования текста
    cv::String model = "C:\\Stas\\1\\MonironExpertS\\frozen_east_text_detection.pb";
    CV_Assert(!model.empty());
    // Load network.
    net = cv::dnn::readNet(model);


    //Проверяем сканер
    validator_open(this);
    //Создаем поток для управления сканером



    //thread_for_scaner = new QThread(this);
//    scaner1 = new ScanerClass(this);
//    connect(&thread_for_scaner, &QThread::started, &scaner1, &ScanerClass::run);
////    connect(&thread_for_scaner, &QThread::started, &scaner1, &ScanerClass::ScanerInit);
//    connect(&scaner1,SIGNAL(finished),&thread_for_scaner,SLOT(terminate));
//    scaner1.moveToThread(&thread_for_scaner);
//    //scaner1.setRunning(true);
//    thread_for_scaner.start();
//    connect(this, &OperatorWindow::start_button_signal, &scaner1, &ScanerClass::ScanerStart);





//    connect(ui->serialPortInfoListBox, QOverload<int>::of(&QComboBox::currentIndexChanged),
//            this, &Adminwindow::showPortInfo);


     connect(&image_simple,SIGNAL(ImageChangeSignal()),this, SLOT(changeImage()));
     //connect(&image_sensors,SIGNAL(ImageChangeSignal()),this, SLOT(changeImage()));

//    connect(&a,SIGNAL(ImageChangeSignal()),
//            this, SLOT(changeImage()));
//    connect(&a,SIGNAL(MechanicsErrorSignal()),
//            this, SLOT(MechanicsError()));
    //ui->textEdit->hide();
    ui->label_23->hide();
    ui->lineEdit_2->hide();

//    a.ImageChangeFunction();
//    a.MechanicsErrorFunction();



    ui->YesConnectionPic->close();
    ui->NoConnectionPic->close();

    //Таймер даты, запускаем часы
    QTimer* timer = new QTimer(this);
    timer->start(1000);
    connect(timer, SIGNAL(timeout()),this,SLOT(onTimeout()));

    //Таймер опроса COMport-ов, запускаем проверку концевиков
//    QTimer* timer2 = new QTimer(this);
//    timer2->start(500);
//    QTimer::singleShot(2000, this, SLOT(onTimeout_Comport_start()));
//    connect(timer2, SIGNAL(timeout()),this,SLOT(onTimeout2()));
//    TXset1();

    //запускаем проверку наличия соединения с сервером в отдельном потоке
    connect(&thread_1, &QThread::started, &connectionobject1, &ConnectionObject::run);
    connect(&connectionobject1, &ConnectionObject::finished, &thread_1, &QThread::terminate);
    connectionobject1.moveToThread(&thread_1);
    connectionobject1.setRunning(true);
    thread_1.start();





//    connect(&thread_2, &QThread::started, &videostreamobject1, &VideoStreamObject::init);
//    videostreamobject1.moveToThread(&thread_2);
//    thread_2.start();


    QPixmap pixNoCon(":/pictures/img/NoConnection.png");
    QPixmap pixYesCon(":/pictures/img/YesConnection.png");

    ui->NoConnectionPic->setPixmap(pixNoCon.scaled(64,64, Qt::KeepAspectRatio));
    ui->YesConnectionPic->setPixmap(pixYesCon.scaled(64,64, Qt::KeepAspectRatio));
    connect(&connectionobject1, &ConnectionObject::ShowYesConnection, this, &OperatorWindow::ShowIconYesConnection);
    connect(&connectionobject1, &ConnectionObject::ShowNoConnection, this, &OperatorWindow::ShowIconNoConnection);
    //tr("Текущая дата и время: %1").arg(QDateTime::currentDateTime().toString("dd.MM.yyyy HH:mm:ss") )
    ui->BankName->setText(tr("Наименование Банка:%1").arg(BankName));
    ui->UnitNum->setText(tr("Подразделение Банка:%1").arg(UnitNum));



    // Создаем буферный документ, в который вначале записываем данные из XML файла текущего дня
    // А в конце работы в него сохраняем обновленный результат
    // считываем XML сегодняшнего дня
    // заполняем DOM
    Result_doc = *GetDataFromXML();

//    //содаем новую ССМ - открывается новая сессия по имени человека вошедшего в окно оператора
//    SSM = Result_doc.createElement("SSM");
//    SSM.setAttribute("ssmName", User_ID);
//    SSMS.appendChild(SSM);

//    USER = Result_doc.createElement("USER");
//    SSM.appendChild(USER);

}

OperatorWindow::~OperatorWindow()
{
    connectionobject1.setRunning(false);
    mCamera->stop();
    recorder->stop();
    videostreamobject1.setRunning(false);
    writeWebcam.release();
    writeWebcam.~VideoWriter();        
    delete ui;
}

void OperatorWindow::ShowIconYesConnection()
{
    ui->YesConnectionPic->show();
    ui->NoConnectionPic->close();
}

void OperatorWindow::ShowIconNoConnection()
{
    ui->NoConnectionPic->show();
    ui->YesConnectionPic->close();
}



void OperatorWindow::onTimeout() //часы тикают
{
    ui->Curtimelabel->setText(QDateTime::currentDateTime().toString("dd.MM.yyyy HH:mm:ss"));
}

void OperatorWindow::onTimeout2() // проверяем состояние компортов
{
    int ser1, ser2;
    ser1=serial1->pinoutSignals();
    ser2=serial2->pinoutSignals();
//    qDebug() << "serial1 =" << serial1->pinoutSignals() ;
//    qDebug() << "serial2 =" << serial2->pinoutSignals() ;
//    if ((ser1&QSerialPort::DataSetReadySignal)) QMessageBox::critical(this, "Ошибка DSR", "Сигнал оптического датчика наличия купюры в тракте между валидатором и шредером");
//    if ((ser1&QSerialPort::DataCarrierDetectSignal)) QMessageBox::critical(this, "Ошибка DCD", "Датчик переполнения приемной корзины");
//    if (!(ser2&QSerialPort::DataSetReadySignal)) QMessageBox::critical(this, "Ошибка DSR", "Сигнал концевого датчика валидатора");
//    if (!(ser2&QSerialPort::DataCarrierDetectSignal)) QMessageBox::critical(this, "Ошибка DCD", "Сигнал концевого датчика верхней крышки");
//    if (!(ser2&QSerialPort::ClearToSendSignal)) QMessageBox::critical(this, "Ошибка CTS", "Сигнал концевого датчика двери сейфа");


    //if (!(ser2&QSerialPort::RingIndicatorSignal)) QMessageBox::critical(this, "Ошибка RI", "Сигнал концевого датчика крышки зоны шредера");

}


void OperatorWindow::recieveBankName(QString str)
{
    ui->BankName->setText(str);
}

void OperatorWindow::recieveUnitNumb(QString str)
{
    ui->UnitNum->setText(str);
}


void OperatorWindow::on_pushButton_6_clicked() //Стоп
{
    recorder->stop();
    writeWebcam.release();
    writeWebcam.~VideoWriter();
//    command(2);
    this->close();
}

void OperatorWindow::on_StartButton_clicked() //Старт
{
    //QMessageBox::information(this,"Старт","Поднесите купюру к купюроприемнику");

    //Запуск самотестирования;
    selftest(serial1,serial2);
    //Проверяем состояние сканера

    //команда включить сканер
    //scaner1.ScanerStart();
    //emit start_button_signal();
    read_image_main(); //разрешаем внесение купюр


    //changeImage();
    ui->DestroyButton->setEnabled(true);

//    int state;
//    state = ScannerInit(call_back,-16);
//    qDebug() << state;
//    if (state == SUCCES_RESULT) qDebug()<<"scaner ready";
//    else if (state == ERROR_DELTA_LEVEL_COUPON) qDebug() << "ScannerInit - ERROR_DELTA_LEVEL_COUPON\n";
//    else if (state == SCANNING_ALREADY_GOES ) qDebug() << "SCANNING_ALREADY_GOES";
//    else {
//        QMessageBox::warning(this, "Ошибка", "Не удалось инициализировать сканер");
//        this->close();
//    }
//    DWORD ver;
//    int i;
//    for (i=0;i<50;i++) {
//        Sleep(100);
//        state = ScannerIsReady();
//        if (state == SUCCES_RESULT) break;
//    }
//    if (state == SUCCES_RESULT);
//    else
//    {
//        QMessageBox::warning(this, "Ошибка", "Сканер не готов");
//        this->close();
//    }
//    ver = ScannerGetHWVersion();
//    QString ScanerReadVerision;
//    ScanerReadVerision.sprintf("%d",ver);
//    if (ScanerReadVerision != ScanerHWVer)
//    {
//        qDebug() << ScanerReadVerision << "вместо" << ScanerHWVer;
//        QMessageBox::warning(this, "Ошибка", "Версия прошивки сканера не соответствует установленной администратором");
//        this->close();
//    }




    //Перевод валидатора в режим приёма банкнот;

        //Оператор изделия вносит банкноту в тракт валидатора
        //Банкнота проходит по тракту. Сканируется в белом и инфракрасном спектрах
        //Банкнота должна остановиться как только пересечёт датчик END расположенный на платформе валидатора







}



void OperatorWindow::processCameraRecord(){
    capWebcam.read(matOriginal);
    // размер картинки
    cv::Size(matOriginal.cols, matOriginal.rows);
    if(matOriginal.empty() == true) return;
    writeWebcam.write(matOriginal);


    //cv::cvtColor(matOriginal, matOriginal, 4); //CV_BGR2RGB
    //QImage qimgOriginal((uchar*)matOriginal.data, matOriginal.cols, matOriginal.rows, matOriginal.step, QImage::Format_RGB888);
    //ui->lblOriginal->setPixmap(QPixmap::fromImage(qimgOriginal.scaled(640,480,Qt::KeepAspectRatio)));
}


void OperatorWindow::processCameraShow()
{
    capWebcam.read(matOriginal);

    cv::cvtColor(matOriginal, matOriginal, 4 ); //CV_BGR2RGB

    QImage qimgOriginal((uchar*)matOriginal.data, matOriginal.cols, matOriginal.rows, matOriginal.step, QImage::Format_RGB888);
    //ui->lblCam->setPixmap(QPixmap::fromImage(qimgOriginal.scaled(640,480,Qt::KeepAspectRatio)));
}

static const char blankString[] = QT_TRANSLATE_NOOP("SettingsDialog", "N/A");
int OperatorWindow::selftest(QSerialPort *serial1,QSerialPort *serial2)
{
    int Comres=2;
    int Camres=1;
    const auto infos = QSerialPortInfo::availablePorts();
    for (const QSerialPortInfo &info : infos)
    {
        QStringList list;
        QString descriptionCom = info.description();
        QString manufacturerCom = info.manufacturer();
        QString serialNumberCom = info.serialNumber();
        list << info.portName()
             << (!descriptionCom.isEmpty() ? descriptionCom : blankString)
             << (!manufacturerCom.isEmpty() ? manufacturerCom : blankString)
             << (!serialNumberCom.isEmpty() ? serialNumberCom : blankString)
             << info.systemLocation()
             << (info.vendorIdentifier() ? QString::number(info.vendorIdentifier(), 16) : blankString)
             << (info.productIdentifier() ? QString::number(info.productIdentifier(), 16) : blankString);
        //qDebug() << ComNumber1<<Description1<<Manufactor1<<Serial_number1<<System_path1<<Vendor_ID1<<Manufactor_ID1;
        //qDebug() << list.at(0)<<list.at(1)<<list.at(2)<<list.at(3)<<list.at(4)<<list.at(5)<<list.at(6);
        if ( ((ComNumber1==list.at(0)) & (Description1==list.at(1)) & (Manufactor1==list.at(2)) & (Serial_number1==list.at(3)) & (System_path1==list.at(4)) & (Vendor_ID1==list.at(5)) & (Manufactor_ID1==list.at(6))) |
             ((ComNumber2==list.at(0)) & (Description2==list.at(1)) & (Manufactor2==list.at(2)) & (Serial_number2==list.at(3)) & (System_path2==list.at(4)) & (Vendor_ID2==list.at(5)) & (Manufactor_ID2==list.at(6))) )
        {
            Comres--; //Установленный компорт админом найден
        }
    }
    if (Comres>0)
    {
        QMessageBox::warning(this, "Ошибка", "Не удалось найти установленный администратором последовательный порт");
    }


    const auto infoscam = QCameraInfo::availableCameras();
    QString descriptionCam;
    for (const QCameraInfo &info : infoscam)
    {
        QStringList list;
        descriptionCam = info.description();
        list << (!descriptionCam.isEmpty() ? descriptionCam : "")
             << info.deviceName();
        //qDebug()<<list.at(0)<<list.at(1);
        if ( (Cam_type==list.at(0)) & (Device_name==list.at(1)) )
        {
            Camres=0;
        }
    }
    if (Camres==1)
    {
        QMessageBox::warning(this, "Ошибка", "Не удалось найти установленную администратором камеру");
//        this->close();
    }

    //qDebug();
    if ( (Camres==0) & (Comres==0) ) return 0; else return 1;
}


void OperatorWindow::onTimeoutComTimer() // пишем в TX 1, что бы от него сделать подтяжку на плате
{
    serial1->write(TxData);
    serial2->write(TxData);
}

void OperatorWindow::TXset1() //TX=1
{
    comTimer->start(10);
    for (int i=0; i<112; i++) {
        TxData[i]=0x00;
    }
}

void OperatorWindow::TXset0() //TX=0
{
    comTimer->stop();
    //    for (int i=0; i<112; i++) {
    //        TxData[i]=0x255;
        //    }
}


void OperatorWindow::changeImage() //  Функция обработки сигнала о завершении сканирования
{

    int w=508 , h=508;
    QPixmap pix,pix2,pix3, pixrotated;
    QImage image;
    QTransform transform;
    //-----------------------------------------------------------------------------
    //получаем скан изображения из буфера
    pix.loadFromData(image_buffer_simple);




    //-----------------------------------------------------------------------------
    //-----------------------------------------------------------------------------
    //сохраняем изображение в строку в кодировке Base64;
    QString str;
    QByteArray bytes;
    QBuffer buffer(&bytes);
    buffer.open(QIODevice::WriteOnly);
    pix.save(&buffer, "bmp"); // writes pixmap into bytes in bmp format
    str=bytes.toBase64();
    //-----------------------------------------------------------------------------

    //-----------------------------------------------------------------------------------------------------------
    //конвертирование Qpixmap->Qimage->cv::mat
    image=pix.toImage();
    cv::Mat tmp(image.height(),image.width(),CV_8UC4,(uchar*)image.bits(),image.bytesPerLine());
//    char k[] = "Canny_window1";
//    char* Canny_window = k;
//    namedWindow( Canny_window, cv::BORDER_DEFAULT );
//    imshow(Canny_window, tmp);
    //cv::Mat result; // deep copy just in case (my lack of knowledge with open cv)
    //cvtColor(tmp, result,cv::COLOR_RGB2BGR);
    //-----------------------------------------------------------------------------------------------------------
    //разбиваем скан на 2 картинки: в белом спектре и в ифнракрасном
    cv::Mat white_spect_image, infrared_spect_image;
    if (!divide_images(tmp, infrared_spect_image, white_spect_image) )
    {
        QMessageBox::critical(this, "Не найдена середина", "Проверьте картинку со сканера");
        return;
    }

    //----------------------------------------------------------------------------------------------------------

    //Обрезаем и поворачиваем скан, удаляем все черные края, выравниваем
    cv::Mat turnedAndCroppedMatWhite = turnTheMatAndCashCrop(white_spect_image);
    cv::Mat turnedAndCroppedMatInfra = turnTheMatAndCashCrop(infrared_spect_image);







    //Определяю наличие текста в правой области скана купюры и копирую в входную матрицу область с текстом
    cv::Mat mat_for_detection;
    cv::Mat right_serial, left_serial;
    int result[4];
    memset(result,0,4);
    //cvtColor(turnedAndCroppedMatInfra, mat_for_detection,cv::COLOR_RGB2BGR);
    cvtColor(turnedAndCroppedMatWhite, mat_for_detection,cv::COLOR_RGBA2BGR); //cv::COLOR_RGB2BGR


//    // Поворачиваем изображение на найденный угол (выравниваем по горизонту)
//    cv::Mat rot1 = cv::getRotationMatrix2D(cv::Point2f(turnedAndCroppedMatWhite.cols/2,turnedAndCroppedMatWhite.rows/2),(180),1);
//    cv::Rect2f bbox1 = cv::RotatedRect(cv::Point2f(), turnedAndCroppedMatWhite.size(),180).boundingRect2f();
//    rot1.at<double>(0,2) += bbox1.width/2.0 - turnedAndCroppedMatWhite.cols/2.0;
//    rot1.at<double>(1,2) += bbox1.height/2.0 - turnedAndCroppedMatWhite.rows/2.0;
//    cv::warpAffine(turnedAndCroppedMatWhite, turnedAndCroppedMatWhite, rot1, bbox1.size()); //bbox.size()

//    // Поворачиваем изображение на найденный угол (выравниваем по горизонту)
//    cv::Mat rot2 = cv::getRotationMatrix2D(cv::Point2f(turnedAndCroppedMatInfra.cols/2,turnedAndCroppedMatInfra.rows/2),(180),1);
//    cv::Rect2f bbox2 = cv::RotatedRect(cv::Point2f(), turnedAndCroppedMatInfra.size(),180).boundingRect2f();
//    rot2.at<double>(0,2) += bbox2.width/2.0 - turnedAndCroppedMatInfra.cols/2.0;
//    rot2.at<double>(1,2) += bbox2.height/2.0 - turnedAndCroppedMatInfra.rows/2.0;
//    cv::warpAffine(turnedAndCroppedMatInfra, turnedAndCroppedMatInfra, rot2, bbox2.size()); //bbox.size()

    if ( getAllRegionsWithText(net, mat_for_detection, right_serial, left_serial, result) )    //1021,96,1587,192     1024, 96, 1536, 192
    {
        qDebug() << "серийник нашелся";
//                static const std::string kWinName0 = "right region";
//                namedWindow(kWinName0, cv::WINDOW_NORMAL);
//                imshow(kWinName0, right_serial);

//                static const std::string kWinName1 = "left region";
//                namedWindow(kWinName1, cv::WINDOW_NORMAL);
//                imshow(kWinName1, left_serial);
    }
    else
    {
        // Поворачиваем изображение на найденный угол (выравниваем по горизонту)
        cv::Mat rot = cv::getRotationMatrix2D(cv::Point2f(mat_for_detection.cols/2,mat_for_detection.rows/2),(180),1);
        cv::Rect2f bbox = cv::RotatedRect(cv::Point2f(), mat_for_detection.size(),180).boundingRect2f();
        rot.at<double>(0,2) += bbox.width/2.0 - mat_for_detection.cols/2.0;
        rot.at<double>(1,2) += bbox.height/2.0 - mat_for_detection.rows/2.0;
        cv::warpAffine(mat_for_detection, mat_for_detection, rot, bbox.size()); //bbox.size()
        if ( getAllRegionsWithText(net, mat_for_detection, right_serial, left_serial, result) )    //1021,96,1587,192     1024, 96, 1536, 192
        {
            qDebug() << "серийник нашелся";
        }
        else {
            qDebug() << "серийник не нашелся";
        }

        rotate180(turnedAndCroppedMatWhite, turnedAndCroppedMatWhite,180);
        rotate180(turnedAndCroppedMatInfra, turnedAndCroppedMatInfra,180);

    }

    //Определяю наличие текста в левой области скана купюры и копирую в входную матрицу область с текстом
    cv::Mat left_ROI;

    //получение pixmap:     cv::mat->QImage->QPixmap
    pix2 = QPixmap::fromImage(QImage((unsigned char*) turnedAndCroppedMatWhite.data,turnedAndCroppedMatWhite.cols,turnedAndCroppedMatWhite.rows,QImage::Format_ARGB32));  //Format_ARGB32
    pix3 = QPixmap::fromImage(QImage((unsigned char*) turnedAndCroppedMatInfra.data,turnedAndCroppedMatInfra.cols,turnedAndCroppedMatInfra.rows,QImage::Format_ARGB32));

    //Вывод в панель оператора скана
    //ui->label_18->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio,Qt::FastTransformation));
    pix2 = pix2.scaled(w,h,Qt::KeepAspectRatio,Qt::FastTransformation);
    pix3 = pix3.scaled(w,h,Qt::KeepAspectRatio,Qt::FastTransformation);
    //ui->label_18->setPixmap(pix);
    //pix2=rotateImage(pix2);
    //pix=pix.scaled(h,w,Qt::KeepAspectRatio,Qt::FastTransformation);
    ui->WhiteSpectorPic->setPixmap(pix2);
    ui->InfraSpectorPic->setPixmap(pix3);
    //ui->label_18->setPixmap(rotateImage(pix));

    //Обработка информация о отсканированной банкноты (распознавание серийного номера и номинала)
    //Вывод на экран, информации о банкноте (Информация обработанная автоматически чёрного цвета)
     //QMessageBox::warning(this, "Проверка данных", "Проверте распознанные данные: Серия, номер");

    //Если банкнота некорректно отсканирована 1. Оператор должен нажать кнопку ВОЗВРАТ БАНКНОТЫ. После чего, повторно её внести в валидатор для распознавания

//     После нажатия оператором кнопки РЕДАКТИРОВАТЬ (Информация вводимая оператором красного цвета)
//     Должно активизироваться меню в котором оператор может выбрать причину редактирования.
//     СЕРИЙНЫЙ НОМЕР НЕ РАСПОЗНАН НОМИНАЛ НЕ РАСПОЗНАН ОТСУТСТВУЕТ ЧАСТЬ СЕРИЙНОГО НОМЕРА ОТСУТСТВУЕТ ЧАСТЬ БАНКНОТЫ БАНКНОТА СКЛЕЕНА (ОДИН СН) БАНКНОТА СКЛЕЕНА (РАЗНЫЕ СН)
//     Так же должна быть строка в которой оператор может ввести дополнительную информацию о состоянии банкноты, её ветхости и т.д.
//     Данные

//     Оператор вводит недостающую информацию, после чего нажимает кнопку ПОДТВЕРДИТЬ
//      Введённая оператором информация отображается на экране для проверки Оператор должен проверить корректность информации.


    ui->DestroyButton->setEnabled(true);
    ui->editButton->setEnabled(true);
}

QPixmap OperatorWindow::rotateImage(QPixmap pix)
{
//    int couner=90;
//    QPixmap buf;
//    QPixmap rotate(pix.size());
//    QPainter p(&rotate);
//    p.setRenderHint(QPainter::Antialiasing);
//    p.setRenderHint(QPainter::SmoothPixmapTransform);
//    p.setRenderHint(QPainter::HighQualityAntialiasing);
//    p.translate(rotate.size().width() / 2, rotate.size().height() / 2);
//    p.rotate(couner);
//    p.translate(-rotate.size().width() / 2, -rotate.size().height() / 2);
//    p.drawPixmap(0,0,pix);
//    p.end();
//    return rotate;

    cv::Mat image;

//    angel = get_angel_for_rotating();
    QPixmap* pixmap = &pix;
    QTransform transform;
    QTransform trans = transform.rotate(90);
    //pixmap = new QPixmap(pixmap->scaled(sqrt(pixmap->size().width()), sqrt(pixmap->size().height())));
    QPixmap transPixmap =  QPixmap(pixmap->transformed(trans));
    return transPixmap;
}

void OperatorWindow::MechanicsError()
{
    QMessageBox::warning(this, "Замятие", "Замятие. \n 1. Нажмите кнопку ВОЗВРАТ БАНКНОТЫ, банкнота должна возвратиться по тракту.\n 2. Если это не помогло, то потяните зону валидатора (банкнотоприёмника) на себя. Поднимите крышку валидатора и извлеките банкноту.\n 3. Внесите банкноту заново.\n 4. Нажмите ОК для продолжения.");
}



void OperatorWindow::on_CashRollBack_clicked() // Возврат
{
//    ScannerRollBack();
    ui->DestroyButton->setEnabled(false);
    ui->lineEdit_2->hide();
    ui->label_6->setText("РР 0000000");
    ui->label_10->setText("РР 0000000");
    ui->label_15->setText("РР 0000000");
    ui->label_20->setText("РР 0000000");
    ui->editButton->setEnabled(false);
    command(14);
    //scaner1->ScanerRollback();
}

void OperatorWindow::on_editButton_clicked() //Редактировать
{


    ui->label_23->show();
    ui->lineEdit_2->show();

}

void OperatorWindow::enableLineEdit(QString text)
{
    //if (text == "Другое")
    {
        //ui->textEdit->selectAll();

    }
//    else
//    {
//        ui->lineEdit->setEnabled(false);
//        ui->lineEdit->hide();
//    }
}

void OperatorWindow::on_acceptButton_clicked() //Подтвердить
{


}





void OperatorWindow::updateXMLresult()
{

    // записываем DOM в XML файл
    QString filename = QString("%1%2").arg("C:/ProgramData/PROFINDUSTRY/MonironExpertS/reports/").arg(QDate::currentDate().toString("'data_'yyyy_MM_dd'.xml'"));
    QFile file(filename);
    if  (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QMessageBox::information(this, "", "Не получается записать данные в файл.");
    }
    else
    {

        QTextStream stream(&file);
        QString sss;
        sss = Result_doc.toString();
        stream << sss;
    }
    file.close();

}


QDomDocument *OperatorWindow::GetDataFromXML()
{
    //заполняем Domdocument
    document= new QDomDocument();
    int SSMS_exists=0; // флаг существования тега SSMS в XML файле
    int SSM_exists=0; // флаг существования тега SSMS в XML файле
    //QDomNode xmlNode = document->createProcessingInstruction("xml","version=\"1.0\" encoding=\"ISO-8859-1\"");

    root = document->createElement("BNList");
    document->appendChild(root);
    root.setAttribute("xmlns:xsi","http://www.w3.org/2001/XMLSchema");
    QDomElement TransMode = document->createElement("TransMode");

    //Конвертирование кодировки в UTF-8
    QString str="только номера",utf8Str,str2; //только номера
    QByteArray ba;
    QTextCodec *codec = QTextCodec::codecForName("Windows-1251");
    ba=str.toUtf8();
    utf8Str = codec->toUnicode(ba);

    QDomText TransModeText = document->createTextNode(utf8Str);
    root.appendChild(TransMode);
    TransMode.appendChild(TransModeText);


    //Добавляем SprDenoms
    QDomElement SprDenoms = document->createElement("SprDenoms");
    root.appendChild(SprDenoms);
    QDomElement SprDenom1 = document->createElement("SprDenom"); //"2010" year="1997" value="500" denomid="1353"/>
    SprDenom1.setAttribute("denomid","1353");
    SprDenom1.setAttribute("value","500");
    SprDenom1.setAttribute("year","1997");
    SprDenom1.setAttribute("modify","2010");
    SprDenoms.appendChild(SprDenom1);
    QDomElement SprDenom2 = document->createElement("SprDenom"); //"1997" year="1997" value="5000" denomid="1339"/>
    SprDenom2.setAttribute("denomid","1339");
    SprDenom2.setAttribute("value","5000");
    SprDenom2.setAttribute("year","1997");
    SprDenom2.setAttribute("modify","1997");
    SprDenoms.appendChild(SprDenom2);
    QDomElement SprDenom3 = document->createElement("SprDenom");//"2001" year="1997" value="100" denomid="1320"/>
    SprDenom3.setAttribute("denomid","1320");
    SprDenom3.setAttribute("value","100");
    SprDenom3.setAttribute("year","1997");
    SprDenom3.setAttribute("modify","2001");
    SprDenoms.appendChild(SprDenom3);
    QDomElement SprDenom4 = document->createElement("SprDenom");//"2004" year="1997" value="500" denomid="1337"/>
    SprDenom4.setAttribute("denomid","1337");
    SprDenom4.setAttribute("value","500");
    SprDenom4.setAttribute("year","1997");
    SprDenom4.setAttribute("modify","2004");
    SprDenoms.appendChild(SprDenom1);
    QDomElement SprDenom5 = document->createElement("SprDenom");//"2010" year="1997" value="1000" denomid="1354"/>
    SprDenom5.setAttribute("denomid","1354");
    SprDenom5.setAttribute("value","1000");
    SprDenom5.setAttribute("year","1997");
    SprDenom5.setAttribute("modify","2010");
    SprDenoms.appendChild(SprDenom2);
    QDomElement SprDenom6 = document->createElement("SprDenom");//"1997" year="1997" value="5" denomid="1317"/>
    SprDenom6.setAttribute("denomid","1317");
    SprDenom6.setAttribute("value","5");
    SprDenom6.setAttribute("year","1997");
    SprDenom6.setAttribute("modify","1997");
    SprDenoms.appendChild(SprDenom3);
    QDomElement SprDenom7 = document->createElement("SprDenom");//"2004" year="1997" value="10" denomid="1334"/>
    SprDenom7.setAttribute("denomid","1334");
    SprDenom7.setAttribute("value","10");
    SprDenom7.setAttribute("year","1997");
    SprDenom7.setAttribute("modify","2004");
    SprDenoms.appendChild(SprDenom1);
    QDomElement SprDenom8 = document->createElement("SprDenom");//"2001" year="1997" value="50" denomid="1319"/>
    SprDenom8.setAttribute("denomid","1319");
    SprDenom8.setAttribute("value","50");
    SprDenom8.setAttribute("year","1997");
    SprDenom8.setAttribute("modify","2001");
    SprDenoms.appendChild(SprDenom2);
    QDomElement SprDenom9 = document->createElement("SprDenom");//"2004" year="1997" value="50" denomid="1335"/>
    SprDenom9.setAttribute("denomid","1335");
    SprDenom9.setAttribute("value","50");
    SprDenom9.setAttribute("year","1997");
    SprDenom9.setAttribute("modify","2004");
    SprDenoms.appendChild(SprDenom3);
    QDomElement SprDenom10 = document->createElement("SprDenom");//"2001" year="1997" value="500" denomid="1321"/>
    SprDenom10.setAttribute("denomid","1321");
    SprDenom10.setAttribute("value","500");
    SprDenom10.setAttribute("year","1997");
    SprDenom10.setAttribute("modify","2001");
    SprDenoms.appendChild(SprDenom1);
    QDomElement SprDenom11 = document->createElement("SprDenom");//"2017" year="2017" value="2000" denomid="1293"/>
    SprDenom11.setAttribute("denomid","1293");
    SprDenom11.setAttribute("value","2000");
    SprDenom11.setAttribute("year","2017");
    SprDenom11.setAttribute("modify","2017");
    SprDenoms.appendChild(SprDenom2);
    QDomElement SprDenom12 = document->createElement("SprDenom");//"2017" year="2017" value="200" denomid="1292"/>
    SprDenom12.setAttribute("denomid","1292");
    SprDenom12.setAttribute("value","200");
    SprDenom12.setAttribute("year","2017");
    SprDenom12.setAttribute("modify","2017");
    SprDenoms.appendChild(SprDenom3);
    QDomElement SprDenom13 = document->createElement("SprDenom");//"2010" year="1997" value="5000" denomid="1355"/>
    SprDenom13.setAttribute("denomid","1355");
    SprDenom13.setAttribute("value","5000");
    SprDenom13.setAttribute("year","1997");
    SprDenom13.setAttribute("modify","2010");
    SprDenoms.appendChild(SprDenom1);
    QDomElement SprDenom14 = document->createElement("SprDenom");//"2004" year="1997" value="1000" denomid="1338"/>
    SprDenom14.setAttribute("denomid","1338");
    SprDenom14.setAttribute("value","1000");
    SprDenom14.setAttribute("year","1997");
    SprDenom14.setAttribute("modify","2004");
    SprDenoms.appendChild(SprDenom2);
    QDomElement SprDenom15 = document->createElement("SprDenom");//"2001" year="1997" value="10" denomid="1318"/>
    SprDenom15.setAttribute("denomid","1318");
    SprDenom15.setAttribute("value","10");
    SprDenom15.setAttribute("year","1997");
    SprDenom15.setAttribute("modify","2001");
    SprDenoms.appendChild(SprDenom3);
    QDomElement SprDenom16 = document->createElement("SprDenom");//"2001" year="1997" value="1000" denomid="1322"/>
    SprDenom16.setAttribute("denomid","1322");
    SprDenom16.setAttribute("value","1000");
    SprDenom16.setAttribute("year","1997");
    SprDenom16.setAttribute("modify","2001");
    SprDenoms.appendChild(SprDenom1);
    QDomElement SprDenom17 = document->createElement("SprDenom");//"2004" year="1997" value="100" denomid="1336"/>
    SprDenom17.setAttribute("denomid","1336");
    SprDenom17.setAttribute("value","100");
    SprDenom17.setAttribute("year","1997");
    SprDenom17.setAttribute("modify","2004");
    SprDenoms.appendChild(SprDenom2);







    //Добавляем SprQualities
    QDomElement SprQualities = document->createElement("SprQualities");
    root.appendChild(SprQualities);
    QDomElement SprQuality1 = document->createElement("SprQuality");
    SprQuality1.setAttribute("qualityId","1");
    SprQuality1.setAttribute("qualityName","bad");
    SprQualities.appendChild(SprQuality1);
    QDomElement SprQuality2 = document->createElement("SprQuality");
    SprQuality2.setAttribute("qualityId","2");
    SprQuality2.setAttribute("qualityName","normal");
    SprQualities.appendChild(SprQuality2);
    QDomElement SprQuality3 = document->createElement("SprQuality");
    SprQuality3.setAttribute("qualityId","3");
    SprQuality3.setAttribute("qualityName","good");
    SprQualities.appendChild(SprQuality3);


    //Добавляем Totals
    Totals = document->createElement("Totals");
    root.appendChild(Totals);
    TotalFit = document->createElement("TotalFit");
    TotalFitText = document->createTextNode("0");
    TotalFit.appendChild(TotalFitText);
    Totals.appendChild(TotalFit);

    TotalUnfit = document->createElement("TotalUnfit");
    TotalUnfitText = document->createTextNode("0");
    TotalUnfit.appendChild(TotalUnfitText);
    Totals.appendChild(TotalUnfit);

    TotalShred = document->createElement("TotalShred");
    TotalShredText = document->createTextNode("0");
    TotalShred.appendChild(TotalShredText);
    Totals.appendChild(TotalShred);

    TotalReject = document->createElement("TotalReject");
    TotalRejectText = document->createTextNode("0");
    TotalReject.appendChild(TotalRejectText);
    Totals.appendChild(TotalReject);




    //QDomElement SSMS,SSM,USER,NOMINAL,Quality,Outpck, AU, B;


    /* Открываем файл для Чтения с помощью пути */
    QString filename = QString("%1%2").arg("C:/ProgramData/PROFINDUSTRY/MonironExpertS/reports/").arg(QDate::currentDate().toString("'data_'yyyy_MM_dd'.xml'"));
    //QString filename = "C:/Stas/1/MonironExpertS/myXML/Day_result_test.xml";
    QFile file(filename);
    if (!file.open(QFile::ReadOnly | QFile::Text))
    {
        //Если файл существует, но не открылся - то выдаем ошибку
        if (file.exists())
        {
            QMessageBox::warning(this,
                                 "Ошибка файла",
                                 "Не удалось открыть файл",
                                 QMessageBox::Ok);
        }
        //Если файла не существует, то создаем новый
        else
        {
            TotalFit_int=0;
            TotalUnfit_int=0;
            TotalShred_int=0;
            TotalReject_int=0;


            SSMS = document->createElement("SSMS");
            root.appendChild(SSMS);

            SSM = document->createElement("SSM");
            ba=User_ID.toUtf8();
            utf8Str = codec->toUnicode(ba);
            SSM.setAttribute("ssmName", utf8Str);
            SSMS.appendChild(SSM);

            //создаем теги, при открытии окна оператора
            //тег USER говорит о начатии новой сессии
            USER = document->createElement("USER");
            SSM.appendChild(USER);
            //тег NOMINAL описывает номинал, который будет испольованн в течении сесиии
            NOMINAL = document->createElement("NOMINAL");
            NOMINAL.setAttribute("did", nominal);
            USER.appendChild(NOMINAL);
            //Конвертирование кодировки в UTF-8
            QTextCodec *codec = QTextCodec::codecForName("Windows-1251");
            //тег Quality описывает состояние купюры, мы с ним не работаем, заполняем его везде атрибутом normal
            Quality = document->createElement("Quality");
            Quality.setAttribute("qualityName",codec->toUnicode(qualityName_value.toUtf8()));
            NOMINAL.appendChild(Quality);
            //тег Outpack описывает выходную пачку - у нас всегда одна выходная пачка - та, что идет на шредор
            Outpck = document->createElement("Outpck");
            Outpck.setAttribute("oid",codec->toUnicode(Outpck_value.toUtf8()));
            Quality.appendChild(Outpck);


        }

    } else {
        /* Создаем объект, с помощью которого осуществляется чтение из файла */
        QXmlStreamReader xmlReader;
        xmlReader.setDevice(&file);
        xmlReader.readNext();   // Переходит к первому элементу в файле

        /* Крутимся в цикле до тех пор, пока не достигнем конца документа
             * */
        while(!xmlReader.atEnd())
        {
            /* Проверяем, является ли элемент началом тега
                 * */
            if(xmlReader.isStartElement())
            {

                //qDebug() << xmlReader.name();

                //qDebug() << attributes.value("modify").toString();
                QXmlStreamAttributes attributes = xmlReader.attributes();
                if(xmlReader.name() == "TotalFit")
                {
                    TotalFit_int=xmlReader.readElementText().toInt();
                    //qDebug() << TotalFit_int;
//                    /* Проверяем атрибут TotalFit */
//                    QXmlStreamAttributes attributes = xmlReader.attributes();
//                    if (attributes.hasAttribute("xmlns:xsi") & (attributes.value("xmlns:xsi") == "http://www.w3.org/2001/XMLSchema") )
//                        qDebug() << xmlReader.readElementText();

                } else if(xmlReader.name() == "TotalUnfit"){
                    TotalUnfit_int=xmlReader.readElementText().toInt();
                    //qDebug() << TotalUnfit_int;

                } else if(xmlReader.name() == "TotalShred"){
                    TotalShred_int=xmlReader.readElementText().toInt();
                    //qDebug() << TotalShred_int;

                } else if(xmlReader.name() == "TotalReject"){
                    TotalReject_int=xmlReader.readElementText().toInt();
                    //qDebug() << TotalReject_int;
                } else if(xmlReader.name() == "SSMS"){
                    SSMS = document->createElement("SSMS");
                    root.appendChild(SSMS);
                    SSMS_exists=1; //если за проход по XML документу обнаружился тег SSMS - поднимаем флаг
                } else if((xmlReader.name() == "SSM") & (attributes.hasAttribute("ssmName"))){
                    SSM = document->createElement("SSM");
                    ba=attributes.value("ssmName").toString().toUtf8();
                    utf8Str = codec->toUnicode(ba);
                    SSM.setAttribute("ssmName", utf8Str);
                    SSMS.appendChild(SSM);
                    qDebug()<<attributes.value("ssmName").toString().toUtf8()<< "User_ID \ "<<User_ID;
                    if (User_ID==attributes.value("ssmName").toString().toUtf8())
                    {
                        SSM_exists=1; //если в XML файле встритился тег SSM с нашим именем - то поднимаем флаг
                    }
                } else if(xmlReader.name() == "USER"){
                    USER = document->createElement("USER");
                    SSM.appendChild(USER);
                } else if((xmlReader.name() == "NOMINAL") & (attributes.hasAttribute("did"))){
                    NOMINAL = document->createElement("NOMINAL");
                    NOMINAL.setAttribute("did", attributes.value("did").toString() );
                    USER.appendChild(NOMINAL);
                } else if((xmlReader.name() == "Quality") & (attributes.hasAttribute("qualityName"))){
                    Quality = document->createElement("Quality");
                    Quality.setAttribute("qualityName", attributes.value("qualityName").toString());
                    NOMINAL.appendChild(Quality);
                } else if((xmlReader.name() == "Outpck") & (attributes.hasAttribute("oid"))){
                    Outpck = document->createElement("Outpck");
                    Outpck.setAttribute("oid", attributes.value("oid").toString());
                    Quality.appendChild(Outpck);
                } else if( (xmlReader.name() == "AU") & (attributes.hasAttribute("st")) & (attributes.hasAttribute("id")) & (attributes.hasAttribute("et")) ){
                    AU = document->createElement("AU");
                    AU.setAttribute("st", attributes.value("st").toString());
                    AU.setAttribute("id", attributes.value("id").toString());
                    AU.setAttribute("et", attributes.value("et").toString());
                    Outpck.appendChild(AU);
                } else if( (xmlReader.name() == "B") & (attributes.hasAttribute("s")) & (attributes.hasAttribute("u")) & (attributes.hasAttribute("r")) ){
                    B = document->createElement("B");
                    B.setAttribute("s", attributes.value("s").toString());
                    B.setAttribute("u", attributes.value("u").toString());
                    B.setAttribute("r", attributes.value("r").toString());
                    AU.appendChild(B);
                }








            }
            xmlReader.readNext(); // Переходим к следующему элементу файла
        }


        if (!SSMS_exists) //если в XML файле не нашлось тега SSMS, создаем(проверка на всякий случай)
        {
            SSMS = document->createElement("SSMS");
            root.appendChild(SSMS);
        }
        if (!SSM_exists) // Если в XML файле (за текущий день) не нашлось тега SMM, создаем его с нашим User_ID
        {
            SSM = document->createElement("SSM");
            ba=User_ID.toUtf8();
            utf8Str = codec->toUnicode(ba);
            SSM.setAttribute("ssmName", utf8Str);
            SSMS.appendChild(SSM);
        }
        //создаем теги, при открытии окна оператора
        //тег USER говорит о начатии новой сессии
        USER = document->createElement("USER");
        SSM.appendChild(USER);
        //тег NOMINAL описывает номинал, который будет испольованн в течении сесиии
        NOMINAL = document->createElement("NOMINAL");
        NOMINAL.setAttribute("did", denomid);
        USER.appendChild(NOMINAL);
        //Конвертирование кодировки в UTF-8
        QTextCodec *codec = QTextCodec::codecForName("Windows-1251");
        //тег Quality описывает состояние купюры, мы с ним не работаем, заполняем его везде атрибутом normal
        Quality = document->createElement("Quality");
        Quality.setAttribute("qualityName",codec->toUnicode(qualityName_value.toUtf8()));
        NOMINAL.appendChild(Quality);
        //тег Outpack описывает выходную пачку - у нас всегда одна выходная пачка - та, что идет на шредор
        Outpck = document->createElement("Outpck");
        Outpck.setAttribute("oid",codec->toUnicode(Outpck_value.toUtf8()));
        Quality.appendChild(Outpck);


        file.close(); // Закрываем файл


    }
    return document;
}


void OperatorWindow::on_pushButton_5_clicked() // Отчет
{
    // Создаем таблицу в HTML из данных QDomDocument *document;
    // заносим ее в текстовый документ в виде строкового потока
    // и распечатываем этот документ

    QString strStream;
    QTextStream out(&strStream);

    QDomNodeList NOMINAL_list,AU_list;

    NOMINAL_list=document->elementsByTagName("NOMINAL");

    QDomNodeList SprDenom_List;
    SprDenom_List=document->elementsByTagName("SprDenom");
    AU_list=document->elementsByTagName("AU");
    int SprDenom_count=SprDenom_List.count(); // узнаем кол-во did
    //qDebug() << SprDenom_count << "кол-во did";



    //Подсчитываем кол-во купюр по did
    //------------------------------------------------------------------------------------------------------------




    int did_count=document->elementsByTagName("AU").count();

//    }


    //------------------------------------------------------------------------------------------------


//    int AU_count=AU_list.count(); //кол-во купюр в XML документе(всего купюр за текущий день)
//    int SprDenom_id;
//    for (int i=0; i<SprDenom_List.count(); i++){
//         SprDenom_id=NOMINAL_list.item(i).toElement().attribute("did").toInt();
//         did_array[i]++;
//    }
    //в массиве did_array[] хранятся кол-во купюр с did


    out<<"<div style=\"height:20px\"></div>";
    out << "<meta charset=\"Windows-1251\">\n"<<
           QString("<title>%1</title>\n").arg("Машинный протокол")<<
           "</head>\n"<<
           "<body bgcolor =#ffffff link=#5000A0>\n"<<
           QString("<p align=\"center\"><font size=\"6\" face=\"Times New Roman\">%1</font></p>\n").arg("Машинный протокол")<<

         "<table border = 0 width=100% cellpadding=1>\n";

    // первая строчка таблицы
    out<<"<thread><tr bgcolor=#ffffff>\n";
    out<<QString("<th align=\"left\"><font size=\"5\" face=\"Times New Roman\">%1</font></th>\n").arg("Машина:");
    out<<QString("<th align=\"right\"><font size=\"5\" face=\"Times New Roman\">%1</font></th>\n").arg(Machine_serial);
    out<<"</tr></thread>\n";

    // вторая строчка таблицы
    out<<"<thread><tr bgcolor=#ffffff>";
    out<<QString("<th align=\"left\"><font size=\"5\" face=\"Times New Roman\">%1</font></th>\n").arg("ID машины");
    out<<QString("<th align=\"right\"><font size=\"5\" face=\"Times New Roman\">%1</font></th>\n").arg(Machine_ID);
    out<<"</tr></thread>\n";

    // 3 строчка таблицы
    QTextCodec *codec = QTextCodec::codecForName("Windows-1251");
    out<<"<thread><tr bgcolor=#ffffff>";
    out<<QString("<th align=\"left\"><font size=\"5\" face=\"Times New Roman\">%1</font></th>\n").arg("Номер протокола");
    out<<QString("<th align=\"right\"><font size=\"5\" face=\"Times New Roman\">%1</font></th>\n")
         .arg(codec->toUnicode((QDateTime::currentDateTime().toString("ddMMyyhms")+QString::number(Protocol_Num)).toUtf8()));
    out<<"</tr></thread>\n";
    Protocol_Num++;
    // 4 строчка таблицы
    out<<"<thread><tr bgcolor=#ffffff>";
    out<<QString("<th align=\"left\"><font size=\"5\" face=\"Times New Roman\">%1</font></th>\n").arg("Начало");
    out<<QString("<th align=\"right\"><font size=\"5\" face=\"Times New Roman\">%1</font></th>\n").arg(Start_Time);
    out<<"</tr></thread>\n";

    // 5 строчка таблицы
    out<<"<thread><tr bgcolor=#ffffff>";
    out<<QString("<th align=\"left\"><font size=\"5\" face=\"Times New Roman\">%1</font></th>\n").arg("Индекс");
    out<<QString("<th align=\"right\"><font size=\"5\" face=\"Times New Roman\">%1</font></th>\n").arg(Index);
    out<<"</tr></thread>\n";

    // 6 строчка таблицы (пустая)
    out<<"<thread><tr bgcolor=#ffffff>";
    out<<QString("<th align=\"left\"><font size=\"5\" face=\"Times New Roman\">%1</font></th>\n").arg("");
    out<<QString("<th align=\"right\"><font size=\"5\" face=\"Times New Roman\">%1</font></th>\n").arg("");
    out<<"</tr></thread>\n";

    // 7 строчка таблицы
    out<<"<thread><tr bgcolor=#ffffff>";
    out<<QString("<th align=\"left\"><font size=\"5\" face=\"Times New Roman\">%1</font></th>\n").arg("Время формирования");
    out<<QString("<th align=\"right\"><font size=\"5\" face=\"Times New Roman\">%1</font></th>\n").arg(QDateTime::currentDateTime().toString("dd.MM.yyyy HH:mm:ss"));
    out<<"</tr></thread>\n";


    out<<"</table>\n";
    out<<"<div style=\"height:20px\"></div>";
    out<<"<hr>";



    //вторая таблица с 4 столбцами
    out<<"<table border = 0 width=100% cellpadding=1>\n";

    // 1 строчка таблицы
    out<<"<thread><tr bgcolor=#ffffff>\n";
    out<<QString("<th align=\"left\"><font size=\"5\" face=\"Times New Roman\">%1</font></th>\n").arg("Категория");
    out<<QString("<th align=\"left\"><font size=\"5\" face=\"Times New Roman\">%1</font></th>\n").arg("Номинал");
    out<<QString("<th align=\"right\"><font size=\"5\" face=\"Times New Roman\">%1</font></th>\n").arg("Кол-во");
    out<<QString("<th align=\"right\"><font size=\"5\" face=\"Times New Roman\">%1</font></th>\n").arg("Сумма");
    out<<"</tr></thread>\n";

    //banknote_count=0;
    out<<"<thread><tr bgcolor=#ffffff>\n";
    out<<QString("<th align=\"left\"><font size=\"5\" face=\"Times New Roman\">%1</font></th>\n").arg("Шредер");
    out<<QString("<th align=\"left\"><font size=\"5\" face=\"Times New Roman\">%1</font></th>\n").arg(nominal);//.arg("did_year");
    out<<QString("<th align=\"right\"><font size=\"5\" face=\"Times New Roman\">%1</font></th>\n").arg(did_count);
    out<<QString("<th align=\"right\"><font size=\"5\" face=\"Times New Roman\">%1</font></th>\n").arg(did_count*nominal);

//    for (int g=0;g<50;g++){
//        if (did_array[g]>0)
//        {
//            // Если была отсканирована купюра с did = g, то добавляем в документ строчку
//            out<<"<thread><tr bgcolor=#ffffff>\n";
//            out<<QString("<th align=\"left\"><font size=\"5\" face=\"Times New Roman\">%1</font></th>\n").arg("Шредер");
//            out<<QString("<th align=\"left\"><font size=\"5\" face=\"Times New Roman\">%1-%2</font></th>\n").arg(nominal).arg("did_year");
//            out<<QString("<th align=\"right\"><font size=\"5\" face=\"Times New Roman\">%1</font></th>\n").arg(did_array[g]);
//            out<<QString("<th align=\"right\"><font size=\"5\" face=\"Times New Roman\">%1</font></th>\n").arg(did_array[g]*nominal);
//            out<<"</tr></thread>\n";
//            banknote_count+=did_array[g];
//        }
//    }

    // строчка таблицы пустая
    out<<"<thread><tr bgcolor=#ffffff>\n";
    out<<QString("<th align=\"left\"><font size=\"5\" face=\"Times New Roman\">%1</font></th>\n").arg("");
    out<<QString("<th align=\"left\"><font size=\"5\" face=\"Times New Roman\">%1</font></th>\n").arg("");
    out<<QString("<th align=\"right\"><font size=\"5\" face=\"Times New Roman\">%1</font></th>\n<hr>\n").arg("");
    out<<QString("<th align=\"right\"><font size=\"5\" face=\"Times New Roman\">%1</font></th>\n<hr>\n").arg("");
    out<<"</tr></thread>\n";

    // строчка таблицы
    out<<"<thread><tr bgcolor=#ffffff>\n";
    out<<QString("<th align=\"left\"><font size=\"5\" face=\"Times New Roman\">%1</font></th>\n").arg("Итог");
    out<<QString("<th align=\"left\"><font size=\"5\" face=\"Times New Roman\">%1</font></th>\n").arg("");
    out<<QString("<th align=\"right\"><font size=\"5\" face=\"Times New Roman\">%1</font></th>\n").arg(did_count); //banknote_count
    out<<QString("<th align=\"right\"><font size=\"5\" face=\"Times New Roman\">%1</font></th>\n").arg(did_count*nominal);  //banknote_count*nominal
    out<<"</tr></thread>\n";




    out<<"</table>\n";





    out<<"</body>\n";
    out<<"</html>";


    textdocument = new QTextDocument;
    textdocument->setHtml(strStream);
    QPrinter printer;
    QPrintDialog *dialog = new QPrintDialog(&printer,0);
    if (dialog->exec() == QDialog::Accepted){
        textdocument->print(&printer);
    }

    // пишем данные отчета в файл
    updateXMLresult();



}



void OperatorWindow::validator_open(QWidget *parent)
{

    int res;
    res=scaner_init();
    if (res) QMessageBox::warning(parent, "Ошибка валидатора", QString("%1%2").arg("ERROR open device res =").arg(res));
    else qDebug()<<"Open USB device - O'k";




//версию сканера не проверяем, тк нету функции пока


//-------------------------------------------------------------------------------------------------------------------
//-------------------------------------------- Старый сканер --------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------

//    int state;
//    state = ScannerInit(call_back,-16);
//    qDebug() << state;
//    if (state == SUCCES_RESULT) qDebug()<<"scaner ready";
//    else if (state == ERROR_DELTA_LEVEL_COUPON) qDebug() << "ScannerInit - ERROR_DELTA_LEVEL_COUPON\n";
//    else if (state == SCANNING_ALREADY_GOES ) qDebug() << "SCANNING_ALREADY_GOES";
//    else {
//        QMessageBox::warning(parent, "Ошибка", "Не удалось инициализировать сканер");
//    }
//    DWORD ver;
//    int i;
//    for (i=0;i<50;i++) {
//        Sleep(100);
//        state = ScannerIsReady();
//        if (state == SUCCES_RESULT) break;
//    }
//    if (state == SUCCES_RESULT);
//    else
//    {
//        QMessageBox::warning(parent, "Ошибка", "Сканер не готов");
//    }
//    ver = ScannerGetHWVersion();
//    QString ScanerReadVerision;
//    ScanerReadVerision.sprintf("%d",ver);
//    if (ScanerReadVerision != ScanerHWVer)
//    {
//        qDebug() << ScanerReadVerision << "вместо" << ScanerHWVer;
//        QMessageBox::warning(parent, "Ошибка", "Версия прошивки сканера не соответствует установленной администратором");
//    }

   //Отключаем прием купюр
   //ScannerDisable();

//-------------------------------------------------------------------------------------------------------------------

}


void OperatorWindow::com_open(QWidget *parent) //открываем компорты
{
    //создаем таймеры для компортов, что б повесить на их TX 1
    comTimer = new QTimer(this);
    connect(comTimer, &QTimer::timeout,this, &OperatorWindow::onTimeoutComTimer);


    serial1 = new QSerialPort;
    serial2 = new QSerialPort;
    if ( selftest(serial1,serial2) == 0)
    {
        serial1->setPortName(ComNumber1);
        serial1->setBaudRate(QSerialPort::Baud9600);
        serial1->setDataBits(QSerialPort::Data8);
        serial1->setParity(QSerialPort::NoParity);
        serial1->setStopBits(QSerialPort::OneStop);
        serial1->setFlowControl(QSerialPort::NoFlowControl);
        if (serial1->open(QIODevice::ReadWrite)) {
            ;
        } else {
            QMessageBox::warning(parent, "Ошибка serial1", "Не удалось открыть установленный администратором последовательный порт");
        }
        serial2->setPortName(ComNumber2);
        serial2->setBaudRate(QSerialPort::Baud9600);
        serial2->setDataBits(QSerialPort::Data8);
        serial2->setParity(QSerialPort::NoParity);
        serial2->setStopBits(QSerialPort::OneStop);
        serial2->setFlowControl(QSerialPort::NoFlowControl);
        if (serial2->open(QIODevice::ReadWrite)) {
            ;
        } else {
            QMessageBox::warning(parent, "Ошибка serial2", "Не удалось открыть установленный администратором последовательный порт");
        }
    }
    serial1->setDataTerminalReady(false);//отключаем, тк DTR инициализируется в 1
    serial2->setDataTerminalReady(false);//отключаем, тк DTR инициализируется в 1
    //второй компорт



}




void OperatorWindow::on_DestroyButton_clicked() //уничтожить
{

    //Оператор должен будет подтвердить в всплывающем диалоговом окне начало операции уничтожения банкноты
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, QString::fromUtf8("Подтверждение уничтожения"),
                          QString::fromUtf8("Уничтожить купюру?"),
                          QMessageBox::Yes | QMessageBox::No );
    if (reply == QMessageBox::Yes){
        ui->DestroyButton->setEnabled(false);
        ui->StartButton->setEnabled(false);
        ui->editButton->setEnabled(false);

        Start_Time=QDateTime::currentDateTime().toString("dd.MM.yyyy HH:mm:ss");
//        timer_shreder_off->start();
        //serial1->setDataTerminalReady(true); // запускаем шредер
        serial1->setRequestToSend(true);

        qDebug()<<serial1->pinoutSignals();
        qDebug()<<serial2->pinoutSignals();
        QTimer::singleShot(2000, this, SLOT(onTimeout_validator_roll_forward()));//запускаем прокрутку валидатор через 2 сек
        QTimer::singleShot(7000, this, SLOT(onTimeout_shreder_off())); //шредор выключится через 7 секунд


        //Конвертирование кодировки в UTF-8
        QString str,utf8Str,str2;
        QByteArray ba;
        QTextCodec *codec = QTextCodec::codecForName("Windows-1251");
        AU = document->createElement("AU");
        AU.setAttribute("st", codec->toUnicode(QDateTime::currentDateTime().toString("ddMMyyhms").toUtf8()));
        AU.setAttribute("id",codec->toUnicode((QDateTime::currentDateTime().toString("ddMMyyhms")+QString::number(Banknote_Id)).toUtf8()));
        Outpck.appendChild(AU);
        Banknote_Id++;
        B = document->createElement("B");
        B.setAttribute("u",codec->toUnicode("-"));
        B.setAttribute("r",codec->toUnicode("-"));
        B.setAttribute("s",codec->toUnicode("-"));
        AU.appendChild(B);
        TotalShred_int++;
//        document->elementsByTagName("TotalShred").
        TotalShredText.setData(QString::number(TotalShred_int));
        // пишем данные отчета в файл
        updateXMLresult();

        //запускаем видеострим


//        recorder=new QMediaRecorder(mCamera,this);
//            QVideoEncoderSettings settings = recorder->videoSettings();
//            settings.setResolution(640,480);
//            settings.setQuality(QMultimedia::VeryHighQuality);
//            settings.setFrameRate(30.0);
//            settings.setCodec("video/mp4");
//            recorder->setVideoSettings(settings);
//            recorder->setContainerFormat("mp4");

//            mCamera->setCaptureMode(QCamera::CaptureVideo);
//            mCamera->focus();

//            auto fileName = QFileDialog::getSaveFileName(this,"Capture","/","Video(*.mp4)");
//            recorder->setOutputLocation(QUrl::fromLocalFile(fileName));

//        if (fileName.isEmpty()){
//            return;
//        }


//        recorder->record();
//    }
//    else {
//        ;
//    }




    //camera = new QCamera(this);
    //viewFinder = new QCameraViewfinder(this);
    //camera->setViewfinder(viewFinder);
//    recorder = new QMediaRecorder(mCamera,this);
//    QVideoEncoderSettings settings = recorder->videoSettings();
//    settings.setResolution(640,480);
//    settings.setQuality(QMultimedia::VeryHighQuality);
//    settings.setFrameRate(30.0);
//    recorder->setVideoSettings(settings);
    //mCamera->setCaptureMode(QCamera::CaptureStillImage)
//    mCamera->setCaptureMode(QCamera::CaptureVideo);
//    QString name = "filname" + QDateTime::currentDateTime().toString("dd.MM.yy-h-m-s");
//    recorder->setOutputLocation(QUrl::fromLocalFile("C:/Stas/video"));
//    recorder->record();

//    qDebug()<<recorder->state();
//    qDebug()<<recorder->status();
//    qDebug()<<recorder->error();

//        VideoRecordTimer->start(10);
//        ui->pushButton_6->setEnabled(true);
    }
    else {
        ;
    }


}

void OperatorWindow::onTimeout_shreder_off()
{
     //timer_shreder_off->stop();
     QTextCodec *codec = QTextCodec::codecForName("Windows-1251");
     // serial1->setDataTerminalReady(false); // отключаем двиган шредера
     serial1->setRequestToSend(false);
     AU.setAttribute("et",codec->toUnicode(QDateTime::currentDateTime().toString("ddMMyyhms").toUtf8()));
     updateXMLresult();
     ui->lineEdit_2->hide();
     ui->label_6->setText("РР 0000000");
     ui->label_10->setText("РР 0000000");
     ui->label_15->setText("РР 0000000");
     ui->label_20->setText("РР 0000000");
     ui->StartButton->setEnabled(true);
     //ui->editButton->setEnabled(false);
}

void OperatorWindow::onTimeout_Comport_start()
{

}

void OperatorWindow::onTimeout_validator_roll_forward()
{
    command(13); //прокрутка вперед
}

//При редактировании серийного номера в поле для его редактирования - текст меняется везде.
void OperatorWindow::on_lineEdit_2_textEdited(const QString &arg1)
{
    ui->label_20->setText(ui->lineEdit_2->text());
    ui->label_10->setText(ui->lineEdit_2->text());
    ui->label_15->setText(ui->lineEdit_2->text());
    ui->label_6->setText(ui->lineEdit_2->text());
}
