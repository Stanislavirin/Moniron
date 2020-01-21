#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include <QMainWindow>
#include "addnewacc.h"


namespace Ui {
class Adminwindow;
}
class Adminwindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit Adminwindow(QWidget *parent = 0);
    ~Adminwindow();

signals:
    void authwindowshow();
    void SendName(QString str);
    void SendUnitNum(QString str);

private slots:
    void on_pushButton_7_clicked();
    void onTimeout();


    void on_pushButton_3_clicked();

    void on_pushButton_clicked();


    void on_pushButton_2_clicked();

private:
    void fillPortsInfo();
    void fillCamerasInfo();
    void showPortInfo1(int idx);
    void showPortInfo2(int idx);
    void showCameraInfo(int idx);
    void writeDocument();
    void fillScanerHWVersion();


private:
    Ui::Adminwindow *ui;
    addNewAcc *addnewaccwindow;

};

#endif // ADMINWINDOW_H
