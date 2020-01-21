#ifndef CAMERATRY_H
#define CAMERATRY_H

class QCamera;
class QCameraViewfinder;
class QCameraImageCapture;
class QVBoxLayout;
class QMenu;
class QAction;


class cameratry
{
public:
    cameratry();      
private:
    QCamera *mCamera;
    QCameraViewfinder *mCameraViewfinder;
    QCameraImageCapture *mCameraImageCapture;
    QVBoxLayout *mLayout;
    QMenu *mOptionsMenu;
    QAction *mEncenderAction;
    QAction *mApagarAction;
    QAction *mCapturarAction;
};

#endif // CAMERATRY_H
