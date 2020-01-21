#ifndef CAMERACLASS_H
#define CAMERACLASS_H

#include <QWidget>

namespace Ui {
class CameraClass;
}

class QCamera;
class QCameraViewfinder;
class QCameraImageCapture;
class QVBoxLayout;
class QMenu;
class QAction;


class CameraClass : public QWidget
{
    Q_OBJECT

public:
    explicit CameraClass(QWidget *parent = nullptr);
    ~CameraClass();

private:
    Ui::CameraClass *ui;
    QCamera *mCamera;
    QCameraViewfinder *mCameraViewfinder;
    QCameraImageCapture *mCameraImageCapture;
    QVBoxLayout *mLayout;
    QMenu *mOptionsMenu;
    QAction *mEncenderAction;
    QAction *mApagarAction;
    QAction *mCapturarAction;
};

#endif // CAMERACLASS_H
