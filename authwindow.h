#ifndef AUTHWINDOW_H
#define AUTHWINDOW_H

#include <QDialog>
#include "adminwindow.h"
#include "operatorwindow.h"
#include "addnewacc.h"

namespace Ui {
class Authwindow;
}

class Authwindow : public QDialog
{
    Q_OBJECT

public:
    explicit Authwindow(QWidget *parent = 0);
    ~Authwindow();


signals:
    void firstWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();
    void readSettingsData();

private:
    Ui::Authwindow *ui;
    Adminwindow *adminwindow1;
    OperatorWindow *operatorwindow1;

    addNewAcc *addnewaccwindow;

};

#endif // AUTHWINDOW_H
