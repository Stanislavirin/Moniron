#ifndef ADDNEWACC_H
#define ADDNEWACC_H

#include <QDialog>
#include <qabstractbutton.h>
#include <QDomDocument>
#include <QCryptographicHash>


namespace Ui {
class addNewAcc;
}

class addNewAcc : public QDialog
{
    Q_OBJECT

public:
    explicit addNewAcc(QWidget *parent = nullptr);
    ~addNewAcc();

private slots:


    void on_btnAddNewUser_clicked();

    void createFileAndRegisterfromDOM();

    QDomDocument *getDocFromTestFileAndSaveInRegister(); //For test only

    QDomDocument *showAccoutsTable(QDomDocument* InputDocument);

    int chekTableForPassAndLoginLength(); // возвращает код ошибки : 0 - ok, 1 - ErrorS

    void on_btnOk_clicked();
    void on_btnCancel_clicked();
    void on_btnApply_clicked();

    void on_tableWidget_cellChanged(int row, int column);
    int checkForEmptyRowsAndAdminExistence();

    void writeAdminOrOperatorToTable(QString text);

    void on_pushButton_clicked();


private:
    Ui::addNewAcc *ui;
    QDomDocument *document;
};

#endif // ADDNEWACC_H
