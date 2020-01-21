#include "cameratry.h"
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

cameratry::cameratry()
{
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



}
