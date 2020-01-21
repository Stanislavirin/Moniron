#ifndef PRINTFORM_H
#define PRINTFORM_H

#include <QWidget>

#include <QPrintDialog>
#include <QPrinter>

namespace Ui {
class PrintForm;
}

class PrintForm : public QWidget
{
    Q_OBJECT

public:
    explicit PrintForm(QWidget *parent = nullptr);
    ~PrintForm();

private slots:
    void on_pushButton_clicked();

private:
    Ui::PrintForm *ui;
};

#endif // PRINTFORM_H
