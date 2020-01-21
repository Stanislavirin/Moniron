#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtCore/QtGlobal>
#include <QMainWindow>
#include "authwindow.h"
#include <QtSerialPort/QSerialPort>

#include "cameraclass.h"





namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void openSerialPort();

    void on_pushButton_4_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    Authwindow *authwindow1;
    QSerialPort *serial;
    CameraClass *cameraclass1;


};

#endif // MAINWINDOW_H
