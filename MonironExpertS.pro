#-------------------------------------------------
#
# Project created by QtCreator 2019-04-25T19:16:55
#
#-------------------------------------------------



greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


QT += network
QT += xml
QT += serialport
QT += multimedia multimediawidgets
QT += printsupport

TARGET = MonironExpertS
TEMPLATE = app




SOURCES += main.cpp\
    addnewacc.cpp \
    cameraclass.cpp \
    connectionobject.cpp \
    emitterclass.cpp \
    functions.cpp \
    goslotolib.cpp \
    gstreamer_example.cpp \
        mainwindow.cpp \
    authwindow.cpp \
    adminwindow.cpp \
    operatorwindow.cpp \
    printform.cpp \
    programmdatawrite.cpp \
    rotate_help.cpp \
    rtsp_server.cpp \
    scaner_new_test.cpp \
    scanerclass.cpp \
    tesseract_class.cpp \
    text_detection.cpp \
    videostreamobject.cpp

HEADERS  += mainwindow.h \
    addnewacc.h \
    authwindow.h \
    adminwindow.h \
    cameraclass.h \
    connectionobject.h \
    emitterclass.h \
    functions.h \
    goslotolib.h \
    gstreamer_example.h \
    operatorwindow.h \
    printform.h \
    programmdatawrite.h \
    rotate_help.h \
    rtsp_server.h \
    scaner_new_test.h \
    scanerclass.h \
    tesseract_class.h \
    text_detection.h \
    videostreamobject.h

FORMS    += mainwindow.ui \
    addnewacc.ui \
    authwindow.ui \
    adminwindow.ui \
    cameraclass.ui \
    operatorwindow.ui \
    printform.ui

RESOURCES += \
    pictures.qrc

#QMAKE_CXXFLAGS += -std=gnu++14


INCLUDEPATH+=C:\Stas\opencv\build\include
#INCLUDEPATH+=D:\OpenCv\opencv\sources\include\opencv2
#D:\OpenCv\opencv\release\install\x86\vc15\lib

#LIBS+= D:\OpenCv\opencv\release\install\x86\vc15\lib\ade.lib

LIBS+= C:\Stas\opencv\release\lib\Debug\opencv_calib3d410d.lib
LIBS+= C:\Stas\opencv\release\lib\Debug\opencv_core410d.lib
LIBS+= C:\Stas\opencv\release\lib\Debug\opencv_dnn410d.lib
LIBS+= C:\Stas\opencv\release\lib\Debug\opencv_features2d410d.lib
LIBS+= C:\Stas\opencv\release\lib\Debug\opencv_flann410d.lib
LIBS+= C:\Stas\opencv\release\lib\Debug\opencv_gapi410d.lib
LIBS+= C:\Stas\opencv\release\lib\Debug\opencv_highgui410d.lib
LIBS+= C:\Stas\opencv\release\lib\Debug\opencv_imgcodecs410d.lib
LIBS+= C:\Stas\opencv\release\lib\Debug\opencv_imgproc410d.lib
LIBS+= C:\Stas\opencv\release\lib\Debug\opencv_ml410d.lib
LIBS+= C:\Stas\opencv\release\lib\Debug\opencv_objdetect410d.lib
LIBS+= C:\Stas\opencv\release\lib\Debug\opencv_photo410d.lib
LIBS+= C:\Stas\opencv\release\lib\Debug\opencv_stitching410d.lib
LIBS+= C:\Stas\opencv\release\lib\Debug\opencv_video410d.lib
LIBS+= C:\Stas\opencv\release\lib\Debug\opencv_videoio410d.lib

#LIBS+= D:\OpenCv\opencv\release\install\x86\vc15\lib\opencv_ts410d.lib


LIBS += -L'C:/Program Files (x86)/Windows Kits/10/Lib/10.0.16299.0/um/x86/' -lAdvAPI32
LIBS += -L'C:/Program Files (x86)/Windows Kits/10/Lib/10.0.16299.0/um/x86/' -lUser32


win32: LIBS += -L'C:/Program Files (x86)/Windows Kits/10/Lib/10.0.16299.0/um/x86/' -lAdvAPI32

INCLUDEPATH += 'C:/Program Files (x86)/Windows Kits/10/Lib/10.0.16299.0/um/x86'
DEPENDPATH += 'C:/Program Files (x86)/Windows Kits/10/Lib/10.0.16299.0/um/x86'

win32:!win32-g++: PRE_TARGETDEPS += 'C:/Program Files (x86)/Windows Kits/10/Lib/10.0.16299.0/um/x86/AdvAPI32.lib'
else:win32-g++: PRE_TARGETDEPS += 'C:/Program Files (x86)/Windows Kits/10/Lib/10.0.16299.0/um/x86/libAdvAPI32.a'

win32: LIBS += -L'C:/Program Files (x86)/Windows Kits/10/Lib/10.0.16299.0/um/x86/' -lUser32

INCLUDEPATH += 'C:/Program Files (x86)/Windows Kits/10/Lib/10.0.16299.0/um/x86'

DEPENDPATH += 'C:/Program Files (x86)/Windows Kits/10/Lib/10.0.16299.0/um/x86'
#########################################################################


LIBS += -L'C:\Stas\1\MonironExpertS' -llibgosloto_new

INCLUDEPATH += 'C:\Stas\1\MonironExpertS'




INCLUDEPATH+=C:\Stas\gstreamer\1.0\x86\include
INCLUDEPATH+=C:\Stas\gstreamer\1.0\x86\lib\glib-2.0\include
INCLUDEPATH+=C:\Stas\gstreamer\1.0\x86\include\glib-2.0
INCLUDEPATH+=C:\Stas\gstreamer\1.0\x86\include\gstreamer-1.0

INCLUDEPATH+=C:\Stas\gstreamer\1.0\x86\lib

LIBS+=C:\Stas\gstreamer\1.0\x86\lib\gstreamer-1.0.lib
LIBS+=C:\Stas\gstreamer\1.0\x86\lib\gstrtspserver-1.0.lib
LIBS+=C:\Stas\gstreamer\1.0\x86\lib\glib-2.0.lib
LIBS+=C:\Stas\gstreamer\1.0\x86\lib\gobject-2.0.lib
LIBS+=C:\Stas\gstreamer\1.0\x86\lib\gstapp-1.0.lib
LIBS+=C:\Stas\gstreamer\1.0\x86\lib\gstvideo-1.0.lib



#INCLUDEPATH+=C:\GstreamerOld\gstreamer\1.0\x86\include
#INCLUDEPATH+=C:\GstreamerOld\gstreamer\1.0\x86\lib\glib-2.0\include
#INCLUDEPATH+=C:\GstreamerOld\gstreamer\1.0\x86\include\glib-2.0
#INCLUDEPATH+=C:\GstreamerOld\gstreamer\1.0\x86\include\gstreamer-1.0

#INCLUDEPATH+=C:\GstreamerOld\gstreamer\1.0\x86\lib

#LIBS+=C:\GstreamerOld\gstreamer\1.0\x86\lib\gstreamer-1.0.lib
#LIBS+=C:\GstreamerOld\gstreamer\1.0\x86\lib\gstrtspserver-1.0.lib
#LIBS+=C:\GstreamerOld\gstreamer\1.0\x86\lib\glib-2.0.lib
#LIBS+=C:\GstreamerOld\gstreamer\1.0\x86\lib\gobject-2.0.lib

#LIBS+=C:\GstreamerOld\gstreamer\1.0\x86\lib\gstvideo-1.0.lib

#tesseract win64
#INCLUDEPATH+=C:\Users\stani\vcpkg\installed\x64-windows\include

#INCLUDEPATH+=C:\Users\stani\vcpkg\installed\x64-windows\lib

#LIBS+=C:\Users\stani\vcpkg\installed\x64-windows\lib\tesseract41.lib


#tesseract win32
#INCLUDEPATH+=C:\libraries\tesseract\include
#INCLUDEPATH+=C:\libraries\tesseract\lib
#LIBS+=C:\libraries\tesseract\lib\libtesseract302.lib

#leptonica win32
#INCLUDEPATH+=C:\libraries\leptonica\include
#INCLUDEPATH+=C:\libraries\leptonica\lib
#LIBS+=C:\libraries\leptonica\lib\liblept168.lib

