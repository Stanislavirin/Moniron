#include "cameraclass.h"
#include "ui_cameraclass.h"
#include <QCamera>
#include <QCameraViewfinder>
#include <QCameraImageCapture>
#include <QVBoxLayout>
#include <QMenu>
#include <QAction>
#include <QFileDialog>
#include <QCameraInfo>
#include <QMessageBox>
#include <QMediaRecorder>

CameraClass::CameraClass(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CameraClass)
{

    ui->setupUi(this);

    // Проверка на присутствие камер
    if (QCameraInfo::availableCameras().count() <= 0)
    {
       QMessageBox::warning(this, "", "Не обнаружено подключенных камер!");
    }
    //Далее ищем в списке нашу камеру и выбираем ее
    QList<QCameraInfo> cameras = QCameraInfo::availableCameras();
      foreach (const QCameraInfo &cameraInfo, cameras) {
          if (cameraInfo.deviceName() == "@device:pnp:\\\\?\\usb#vid_05a3&pid_9230&mi_00#8&3a26dea9&0&0000#{65e8773d-8f56-11d0-a3b9-00a0c9223196}\\global")
              mCamera = new QCamera(cameraInfo,this);
      }
    if (mCamera == nullptr)
        QMessageBox::warning(this, "", "Не обнаружено камеры HD USB Camera!");
    //mCamera = new QCamera(this);






    mCameraViewfinder = new QCameraViewfinder(this);
    mCameraImageCapture = new QCameraImageCapture(mCamera, this);
    mLayout = new QVBoxLayout;
    mOptionsMenu = new QMenu("Options", this);
    mApagarAction = new QAction("Apagar включить камеру",this);
    mCapturarAction = new QAction("Capturar сделать снимок",this);
    mEncenderAction = new QAction("Encender остановить камеру",this);
    mOptionsMenu->addActions({mEncenderAction, mApagarAction,
                              mCapturarAction});

    ui->OptionspushButton->setMenu(mOptionsMenu);
    mCamera->setViewfinder(mCameraViewfinder);
    mLayout->addWidget(mCameraViewfinder);
    mLayout->setMargin(0);
    ui->scrollArea->setLayout(mLayout);

    connect(mEncenderAction, &QAction::triggered, [&]() {
        mCamera->start();
    });
    connect(mApagarAction, &QAction::triggered, [&]() {
        mCamera->stop();
    });
    connect(mCapturarAction, &QAction::triggered, [&]() {
        auto filename = QFileDialog::getSaveFileName(this, "Capturar", "/",
                                     "Imagen{*.jpg; *.jpeg}");
        if (filename.isEmpty()){
            return;
        }
        mCameraImageCapture->setCaptureDestination(
                    QCameraImageCapture::CaptureToFile);
        QImageEncoderSettings ImageEncoderSettings;
        ImageEncoderSettings.setCodec("image/jpeg");
        ImageEncoderSettings.setResolution(1600,1200);
        mCameraImageCapture->setEncodingSettings(ImageEncoderSettings);
        mCamera->setCaptureMode(QCamera::CaptureStillImage);
        mCamera->start();
        mCamera->searchAndLock();
        mCameraImageCapture->capture(filename);
        mCamera->unlock();
    });



}

CameraClass::~CameraClass()
{
    delete ui;
}
