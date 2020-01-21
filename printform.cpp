#include "printform.h"
#include "ui_printform.h"

PrintForm::PrintForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PrintForm)
{
    ui->setupUi(this);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
    ui->tableWidget_3->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);


}

PrintForm::~PrintForm()
{
    delete ui;
}

void PrintForm::on_pushButton_clicked()
{
    QPrinter printer;
    printer.setPrinterName("desired printer name");
    QPrintDialog dialog(&printer,this);
    if (dialog.exec() == QDialog::Rejected) return;
    ui->textEdit->print(&printer);

}
