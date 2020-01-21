#ifndef OPERATORWINDOW_H
#define OPERATORWINDOW_H

#include <QMainWindow>

#include <QTcpSocket>
#include <QDebug>
#include <QThread>
#include "connectionobject.h"
#include <QSerialPort>
#include <QDomDocument>

#include <QTimer>

#include "opencv2/opencv.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include "printform.h"
#include <QTextDocument>
//#include <videostreamobject.h>
#include "scanerclass.h"

namespace Ui {
class OperatorWindow;
}


class QCamera;
class QCameraViewfinder;
class QCameraImageCapture;
class QVBoxLayout;
class QMenu;
class QAction;
class QMediaRecorder;

class OperatorWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit OperatorWindow(QWidget *parent = nullptr);
    ~OperatorWindow();

signals:
    void start_button_signal();

private:
    Ui::OperatorWindow *ui;
    QThread thread_1; // поток для проверки наличия соединения
    QThread thread_2; // поток для проверки состояния концевиков
    QThread thread_3; // поток для сервера rtsp
    QThread thread_for_scaner; // поток для сканера
    ConnectionObject connectionobject1;
    ScanerClass scaner1;
    //VideoStreamObject videostreamobject1;
    //CameraClass *cameraclass1;

    QCamera *camera;
    QCameraViewfinder *viewFinder;

    QCamera *mCamera;
    QCameraViewfinder *mCameraViewfinder;
    QCameraImageCapture *mCameraImageCapture;
    QVBoxLayout *mLayout;
    QMenu *mOptionsMenu;
    QAction *mEncenderAction;
    QAction *mApagarAction;
    QAction *mCapturarAction;
    QMediaRecorder *recorder;



    cv::VideoCapture capWebcam;
    cv::VideoWriter writeWebcam;
    cv::Mat matOriginal;
    cv::Mat matProcessed;
    cv::Mat matBuffer1,matBuffer2;
    QImage qimgOriginal;
    QImage qimgProcessed;
    std::vector<cv::Vec3f> vecCircles;
    std::vector<cv::Vec3f>::iterator itrCircles;
    QTimer* VideoRecordTimer;
    QTimer* VideoShowTimer;

    QSerialPort* serial1;
    QSerialPort* serial2;
    QByteArray TxData;
    QTimer *comTimer;
    QTimer *timer2;
    QTimer *timer_shreder_off; //таймер отключения шредера

    QDomDocument *document;
    QTextDocument *textdocument;

    PrintForm *Printform1;




private slots:
    void ShowIconYesConnection();
    void ShowIconNoConnection();
    void onTimeout();
    void onTimeout2();
    void recieveBankName(QString str);
    void recieveUnitNumb(QString str);
    void on_pushButton_6_clicked();
    void on_StartButton_clicked();

    void processCameraRecord();
    void processCameraShow();

    int selftest(QSerialPort *serial1,QSerialPort *serial2);
    void onTimeoutComTimer();
    void TXset1();
    void TXset0();
    void changeImage();
    QPixmap rotateImage(QPixmap pix);
    void MechanicsError(); //вызываем окно с подсказкой что делать, при застрявании купюры

    void on_CashRollBack_clicked();
    void on_editButton_clicked();
    void enableLineEdit(QString text);
    void on_acceptButton_clicked();
    void updateXMLresult();
    QDomDocument *GetDataFromXML();
    void on_pushButton_5_clicked();


    void validator_open(QWidget *parent); //инициализация и проверка сканера
    void com_open(QWidget *parent); //открываем компорты
    void on_DestroyButton_clicked();
    void onTimeout_shreder_off(); // функция, выключаеющая двигатель шредера и отключающая его таймер
    void onTimeout_Comport_start();// запуск проверки состояния концевиков
    void onTimeout_validator_roll_forward();
    void on_lineEdit_2_textEdited(const QString &arg1);
};


#endif // OPERATORWINDOW_H
