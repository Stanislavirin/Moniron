#include "addnewacc.h"
#include "ui_addnewacc.h"
#include "authwindow.h"


#include <QtDebug>
#include <QtXml>
#include <QtCore>

#include <QMessageBox>
#include <QCryptographicHash>
#include <QHash>
#include "functions.h"
//#include <wincrypt.h>
#include <adminwindow.h>
#include <QComboBox>

#define ORGANIZATION_NAME "PROFINDUSTRY"
#define ORGANIZATION_DOMAIN "www.profindustry.com/"
#define APPLICATION_NAME "MonironExpertS"//

//extern Q_CORE_EXPORT int qt_ntfs_permission_lookup;

addNewAcc::addNewAcc(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addNewAcc)
{

    ui->setupUi(this);
    QDomDocument docx;
    document = new QDomDocument();

    QCoreApplication::setOrganizationName("PROFINDUSTRY");
    QCoreApplication::setOrganizationDomain("www.profindustry.com/");
    QCoreApplication::setApplicationName("MonironExpertS");

    //for (int i=0; i<row; i++) {
    //connect(ui->tableWidget, SIGNAL(cellChanged), this, SLOT(chekTableForPathAndLoginLength));
        //connect(ui->tableWidget, SIGNAL(cellChanged(row,1)), this, SLOT(&addNewAcc::chekTableForPathAndLoginLength));
    //}

    //connect(ui->tableWidget, &QTableWidget::cellClicked, this, &addNewAcc::showComboBoxInTable);
    //document = getDocFromTestFileAndSaveInRegister();
    document = showAccoutsTable(&docx);
    createFileAndRegisterfromDOM();
    //ui->tableWidget->sortItems(0,Qt::AscendingOrder);


}


addNewAcc::~addNewAcc()
{
    delete ui;
}

void addNewAcc::on_btnAddNewUser_clicked()
{
    int rows;

    ui->tableWidget->blockSignals(true);
    //ui->tableWidget->sortItems(0,Qt::DescendingOrder);
    rows = ui->tableWidget->rowCount();
    ui->tableWidget->setRowCount(rows+1);
    int currentrow = ui->tableWidget->currentRow();
    //ui->tableWidget->sortItems(0,Qt::DescendingOrder);
    ui->tableWidget->setSortingEnabled(false);
    QTableWidgetItem *item0 = new QTableWidgetItem("");
    QTableWidgetItem *item1 = new QTableWidgetItem("");
    QTableWidgetItem *item2 = new QTableWidgetItem("");
    ui->tableWidget->setItem(rows,0,item0);
    ui->tableWidget->setItem(rows,1,item1);
    ui->tableWidget->setItem(rows,2,item2);

    QComboBox *comboBox = new QComboBox;
    comboBox->blockSignals(true);

    ui->tableWidget->setCellWidget(rows,2,comboBox);
    comboBox->addItem("Оператор");
    comboBox->addItem("Админ");

    //ui->tableWidget->item(rows,1)->setBackgroundColor("#ff0000");
    //ui->tableWidget->item(rows,2)->setData(Qt::DisplayRole,QString("Оператор"));
    ui->tableWidget->item(rows,2)->setText("Оператор");
    connect(comboBox,SIGNAL(currentIndexChanged(QString)),this,SLOT(writeAdminOrOperatorToTable(QString)) );

    ui->tableWidget->setCurrentCell(rows,0); //setCurrentCell(int row, int column, QItemSelectionModel::SelectionFlags command)
    ui->tableWidget->editItem(ui->tableWidget->item(rows,0));

    //Сортируем порядковые номера
//    int rowsInTable=ui->tableWidget->rowCount();
//    QStringList indexes;
//    for (int i=0; i<rowsInTable; i++)
//    {
//         indexes << QString::number(i+1);
//    }
//    ui->tableWidget->setVerticalHeaderLabels(indexes);
    ui->tableWidget->setSortingEnabled(true);
    comboBox->blockSignals(false);
    ui->tableWidget->blockSignals(false);
    // добавляем в таблицу пустые элементы
}

void addNewAcc::createFileAndRegisterfromDOM()
{

    //------------------------------------------------------------------------------------------
    //------------------------- Создание файла с ID, логинами, Хеш-паролями и правами ----------
    //------------------------------------------------------------------------------------------
    //создаю корневой элемент
    //QDomDocument document=documentWithHash;
    //Write XML

    QDomDocument documentWithHash;
    QDomDocument documentWithPass;
    //Make the root element
    QDomElement rootWithHash = documentWithHash.createElement("Accounts");
    QDomElement rootWithPass = documentWithPass.createElement("Accounts");
    //Add it to the document
    documentWithHash.appendChild(rootWithHash);
    documentWithPass.appendChild(rootWithPass);

    //Конвертирование кодировки в UTF-8
    QString str,utf8Str,str2;
    QByteArray ba;
    QTextCodec *codec = QTextCodec::codecForName("Windows-1251");
    ba=str.toUtf8();
    utf8Str = codec->toUnicode(ba);

    //Add some elements
    for (int i = 0; i < ui->tableWidget->rowCount(); i++)
    {
         QDomElement accountWithHash = documentWithHash.createElement("Account");
         QDomElement accountWithPass = documentWithPass.createElement("Account");

         accountWithHash.setAttribute("ID", QString::number(i));
         accountWithPass.setAttribute("ID", QString::number(i));

         str = ui->tableWidget->item(i,0)->text();
         accountWithPass.setAttribute("Login",str);
         ba=str.toUtf8();
         utf8Str = codec->toUnicode(ba);
         accountWithHash.setAttribute("Login",utf8Str);


         str = ui->tableWidget->item(i,1)->text();
         accountWithPass.setAttribute("Password",str);
         str2 = GetModifiedHash(&str);
         ba=str2.toUtf8();
         utf8Str = codec->toUnicode(ba);
         accountWithHash.setAttribute("Password_Hash", utf8Str);


         str = ui->tableWidget->item(i,2)->text();
         accountWithPass.setAttribute("Rights", str);
         ba=str.toUtf8();
         utf8Str = codec->toUnicode(ba);
         accountWithHash.setAttribute("Rights", utf8Str);


         rootWithHash.appendChild(accountWithHash);
         rootWithPass.appendChild(accountWithPass);
    }


    // Пишем логины и хэш-пароли в файл (изменять этот файл сможет только админ)
    //QFile file("D:/Stas/desintagrator_pro/1/MonironExpertS/myXML/accounts.xml");
    //QFile file("C:/ProgramData/PROFINDUSTRY/MonironExpertS/accounts.xml");
//    QString appdatadir = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
//    qDebug() << appdatadir;
//    QDir dir(appdatadir);
//    if (!dir.exists())
//        dir.mkpath(appdatadir);

//    appdatadir = dir.absoluteFilePath("PROFINDUSTRY/MonironExpertS/accounts.xml");


//    qDebug() << appdatadir;

    QFile file("C:/ProgramData/PROFINDUSTRY/MonironExpertS/accounts.xml");
    //QFile file(appdatadir);
    //qDebug() << QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    if  (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QMessageBox::information(this, "", "Не получается записать данные в файл.");
    }
    QTextStream stream(&file);
    QString sss;
    sss = documentWithHash.toString();
    stream << sss;
    file.close();


    //------------------------------------------------------------------------------------------
    //------------------------- Создание файла с чистыми паролями ------------------------------
    //---------------------------------в реестре админа ----------------------------------------
    //------------------------------------------------------------------------------------------
    QSettings settings(QSettings::UserScope, ORGANIZATION_NAME,APPLICATION_NAME );
    QString ss = documentWithPass.toString();
    settings.setValue("AccountInfo", ss);

    //sss = document->toString();
}

QDomDocument* addNewAcc::showAccoutsTable(QDomDocument* InputDocument)
{

//--------------------------------------------------------------------------------------------------------
    // достаем пароли из реестра, доступного только админу, в чистом виде
    //QDomDocument document;
    QSettings accountsWithPasswords(QSettings::UserScope, ORGANIZATION_NAME,APPLICATION_NAME );
    QString sss;
    ui->tableWidget->blockSignals(true);
    sss = accountsWithPasswords.value("AccountInfo").toString();
    if (!InputDocument->setContent(sss)){
        QMessageBox::information(this, "","Первый вход");

        sss="<Accounts>\n"
                    " <Account Login=\"Админ\" ID=\"1\" Password=\"123\" Rights=\"Админ\"/>\n"
                    " <Account Login=\"Оператор\" ID=\"2\" Password=\"321\" Rights=\"Оператор\"/>\n"
                    "</Accounts>\n";
//        sss="<Accounts>"
//            "<Account Login=\"Админ\" ID=\"1\" Password=\"123\" Rights=\"Админ\"/>"
//            "<Account Login=\"Оператор\" ID=\"2\" Password=\"321\" Rights=\"Оператор\"/>"
//            "</Accounts>";

        accountsWithPasswords.setValue("AccountInfo", sss);

        if (!InputDocument->setContent(sss)){
            QMessageBox::information(this, "","Ошибка создания первых аккаунтов");
            delete ui;
        }
    }
    //qDebug() << "Register /n" << sss;

    QComboBox* comboBox = new QComboBox();
    comboBox->addItem("Админ");
    comboBox->addItem("Опепратор");

    QDomElement root = InputDocument->documentElement();
    QDomNode node = root.firstChild();
    QDomNodeList items = root.elementsByTagName("Account"); // кол-во Логинов
    //qDebug()<< "total items =" << items.count();
    //ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setRowCount(items.count());
    ui->tableWidget->setColumnWidth(1,150);
    int row=0, col=0;
    while(!node.isNull()) {
        QDomElement element = node.toElement(); // try to convert the node to an element.
        if(!element.isNull()) {
            QDomAttr attr = element.attributeNode("Login");
            QString s = attr.value();
            //qDebug() << s ;
            QTableWidgetItem *newItem = new QTableWidgetItem(s);
            ui->tableWidget->setItem(row,0,newItem);

            attr = element.attributeNode("Password");
            s = attr.value();
            newItem = new QTableWidgetItem(s);
            ui->tableWidget->setItem(row,1,newItem);

            attr = element.attributeNode("Rights");
            s = attr.value();
            newItem = new QTableWidgetItem(s);
            ui->tableWidget->setItem(row,2,newItem);

            QComboBox *comboBox = new QComboBox;
            ui->tableWidget->setCellWidget(row,2,comboBox);
            if (ui->tableWidget->item(row,2)->text() == "Админ")
            {
                comboBox->setStyleSheet("background-color: rgb(252, 255, 188) ; color: rgb(0, 0, 0);");
                comboBox->addItem("Админ");
                comboBox->addItem("Оператор");
            }
            else if (ui->tableWidget->item(row,2)->text() == "Оператор")
            {
                comboBox->addItem("Оператор");
                comboBox->addItem("Админ");
            }

            connect(comboBox,SIGNAL(currentIndexChanged(QString)),this,SLOT(writeAdminOrOperatorToTable(QString)) );
            row++;
            //col++;
            //qDebug() << qPrintable(element.tagName()); // the node really is an element.
        }
        node = node.nextSibling();
    }


    ui->tableWidget->blockSignals(false);
    return InputDocument;
}

int addNewAcc::chekTableForPassAndLoginLength() // возвращает код ошибки : 0 - ok, 1 - ErrorS
{
    int res=0;
    int rowcount = ui->tableWidget->rowCount(); // кол-во рядов в таблице
    qDebug() << "rowcount=" << rowcount;
    int loginLen, passwordLen; // логин, пароль
    QString Login, Password, CurrentLogin;
    QColor backgroundColor;
    QTableWidgetItem *item;

    ui->tableWidget->blockSignals(true);

    ////////////////////////////////////////////////////////////////////////////////////////////////
    //Забеляем всю таблицу
    for (int i=0; i<rowcount; i++)
    {
        for (int j=0; j<3; j++)
        {
            ui->tableWidget->item(i,j)->setBackgroundColor("#ffffff");
        }
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////


    ////////////////////////////////////////////////////////////////////////////////////////////////
    // Проверка на повторяющиеся логины
    int i=0,j=0;
    for (i; i<rowcount-1 ; i++)
    {
        j=i+1;
        CurrentLogin = ui->tableWidget->item(i,0)->text();
        for (j; j<=rowcount-1; j++)
        {
            if ( CurrentLogin == ui->tableWidget->item(j,0)->text())
            {
                ui->tableWidget->item(j,0)->setBackgroundColor("#00ff00");
                ui->tableWidget->item(i,0)->setBackgroundColor("#00ff00");
                res=2;
            }
        }
    }

    if (res == 2)
    {
        QMessageBox::information(this, "", "Повторяющиеся логины недопустимы!");
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////


    //Проверка паролей и логинов, что б были длиннее 3 символов
    for (int i=0; i < rowcount; i++)
    {
        if ((ui->tableWidget->item(i,0) != NULL) && (!ui->tableWidget->item(i,0)->text().isEmpty()) )  //
        {
            Login = ui->tableWidget->item(i,0)->text();
            if ( Login.length() < 3 )
            {
                ui->tableWidget->item(i,0)->setBackgroundColor("#ff0000");
                res = 1;
            }
        }
        else
        {
            QTableWidgetItem *item0 = new QTableWidgetItem();
            ui->tableWidget->setItem(i,0,item0);
            ui->tableWidget->item(i,0)->setBackgroundColor("#ff0000");
            res = 1;
        }


        if ((ui->tableWidget->item(i,1) != NULL) && (!ui->tableWidget->item(i,1)->text().isEmpty()))
        {
            Password = ui->tableWidget->item(i,1)->text();
            if ( Password.length() < 3 )
            {

                ui->tableWidget->item(i,1)->setBackgroundColor("#ff0000");
                res = 1;
            }
        }
        else
        {
            QTableWidgetItem *item1 = new QTableWidgetItem();
            ui->tableWidget->setItem(i,1,item1);
            ui->tableWidget->item(i,1)->setBackgroundColor("#ff0000");
            res = 1;
        }
    }
    if (res == 1)
    {
        QMessageBox::information(this, "", "Слишком короткий логин или пароль!");
    }
    ui->tableWidget->blockSignals(false);
    return res;
}

QDomDocument *addNewAcc::getDocFromTestFileAndSaveInRegister() //For test only
{
    document= new QDomDocument();
    QFile file("D:/Stas/desintagrator_pro/1/MonironExpertS/myXML/myXML.xml"); //"
    QTextStream stream(&file);
    if  (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
            QMessageBox::information(this, "","Невозможно открыть файл с паролями или его нет");
    }
    else {
        if (!document->setContent(&file)){
            QMessageBox::information(this, "","Ошибка загрузки документа");
            delete ui;
        }
        file.close();
    }

    qDebug() << "Register /n" << &file;

    QDomElement root = document->documentElement();
    QDomNode node = root.firstChild();
    QDomNodeList items = root.elementsByTagName("Account"); // кол-во Логинов
    qDebug()<< "total items =" << items.count();
    //ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setRowCount(items.count());

    QTableWidgetItem *newItem2;
    int row=0;

    while(!node.isNull()) {
        QDomElement element = node.toElement(); // try to convert the node to an element.
        if(!element.isNull()) {
            QDomAttr attr = element.attributeNode("Login");
            QString s = attr.value();
            qDebug() << s;
            newItem2 = new QTableWidgetItem(s);
            ui->tableWidget->setItem(row,0,newItem2);

            attr = element.attributeNode("Password");
            s = attr.value();
            newItem2 = new QTableWidgetItem(s);
            ui->tableWidget->setItem(row,1,newItem2);

            attr = element.attributeNode("Rights");
            s = attr.value();
            newItem2 = new QTableWidgetItem(s);
            ui->tableWidget->setItem(row,2,newItem2);

            row++;
            //col++;
            qDebug() << qPrintable(element.tagName()); // the node really is an element.
        }
        node = node.nextSibling();
    }

    QSettings settings(QSettings::UserScope, ORGANIZATION_NAME,APPLICATION_NAME );
    QString sss;
    sss = document->toString();
    settings.setValue("AccountInfo", sss);

    return document;  
}




void addNewAcc::on_btnOk_clicked()
{
    if (checkForEmptyRowsAndAdminExistence() == 0)
    {
        if (chekTableForPassAndLoginLength() == 0)
        {
            createFileAndRegisterfromDOM();
            this->close();

            Authwindow *authwindow2;
            authwindow2 = new Authwindow();
            authwindow2->show();
        }
    }
}

void addNewAcc::on_btnCancel_clicked()
{
    this->close();

    Authwindow *authwindow2;
    authwindow2 = new Authwindow();
    authwindow2->show();

//    Authwindow w;
//    w.show();
//    w.setFixedSize(w.sizeHint());

}

void addNewAcc::on_btnApply_clicked()
{
    if (checkForEmptyRowsAndAdminExistence() == 0)
    {
        if (chekTableForPassAndLoginLength() == 0)
        {
            createFileAndRegisterfromDOM();
//            QDomDocument docx;
//            document = new QDomDocument();
            //document = showAccoutsTable(&docx);
        }
    }
}

void addNewAcc::on_tableWidget_cellChanged(int row, int column)
{
    QString Login, Password, CurrentLogin;
    QColor backgroundColor;
    int rowcount = ui->tableWidget->rowCount();
    ui->tableWidget->setSortingEnabled(false);
    ui->tableWidget->blockSignals(true);

    if ( (ui->tableWidget->item(row,0) != 0) &
         (ui->tableWidget->item(row,1) != 0) &
         (ui->tableWidget->item(row,2) != 0) )
    {
        Login = ui->tableWidget->item(row,0)->text();
        Password = ui->tableWidget->item(row,1)->text();
//        for (int i=0; i<rowcount; i++)
//        {
//            for (int j=0; j<3; j++)
//            {
//                ui->tableWidget->item(i,j)->setBackgroundColor("#ffffff");
//            }
//        }
        ui->tableWidget->item(row,column)->setBackgroundColor("#ffffff");
        //Проверка, чтобы логин и пароль были длиннее 3 символов
        if (column == 0)
        {
            ///////////////////////////////////////////////////////////////////////////////////////////
            // Проверка наличия повторного логина

            CurrentLogin = ui->tableWidget->item(row,0)->text();
            int i=0;

            for (i; i<rowcount-1 ; i++)
            {
                if ( (CurrentLogin == ui->tableWidget->item(i,0)->text()) & (row != i) )
                {
                    ui->tableWidget->item(i,0)->setBackgroundColor("#00ff00");
                    ui->tableWidget->item(row,0)->setBackgroundColor("#00ff00");
                }
            }

            ///////////////////////////////////////////////////////////////////////////////////////////

            if ( Login.size() < 3 )
            {
                ui->tableWidget->item(row,0)->setBackgroundColor("#ff0000");
            }
        }
        else if (column == 1)
        {
            if ( Password.size() < 3 )
            {
                ui->tableWidget->item(row,1)->setBackgroundColor("#ff0000");
            }
        }
        else if (column == 2)
        {
            QComboBox *comboBox = new QComboBox;
            ui->tableWidget->blockSignals(false);
            comboBox->blockSignals(true);
            if (ui->tableWidget->item(row,2)->text() == "Админ" )
            {
                ui->tableWidget->setCellWidget(row,2,comboBox);
                comboBox->addItem("Админ");
                comboBox->addItem("Оператор");
                comboBox->setStyleSheet("background-color: rgb(252, 255, 188) ; color: rgb(0, 0, 0);");

            }
            else if (ui->tableWidget->item(row,2)->text() == "Оператор" )
            {
                ui->tableWidget->setCellWidget(row,2,comboBox);
                comboBox->addItem("Оператор");
                comboBox->addItem("Админ");
                comboBox->setStyleSheet("background-color: rgb(255, 255, 255) ; color: rgb(0, 0, 0);");
            }
            connect(comboBox,SIGNAL(currentIndexChanged(QString)),this,SLOT(writeAdminOrOperatorToTable(QString)),Qt::DirectConnection);
            comboBox->blockSignals(false);
        }

    }
    ui->tableWidget->setSortingEnabled(true);
    ui->tableWidget->blockSignals(false);
}

int addNewAcc::checkForEmptyRowsAndAdminExistence() // если возвращает 0 - все ок, если 1 - нет аккаунта админа
{
    int res=1;
    int rowcount = ui->tableWidget->rowCount();
    ui->tableWidget->blockSignals(true);
    //ui->tableWidget->sortItems(0,Qt::AscendingOrder);
    for (int i=0; i<rowcount; i++)
    {
        //Проверяем наличие админа
        if ( ui->tableWidget->item(i,2)->text() == "Админ" )
        {
             res=0;
        }
    }

    //удаляем пустые строки
    for (int i=0; i<rowcount; i++)
    {
        if (   ( ui->tableWidget->item(i,0)->text().isEmpty() )  &&
               ( ui->tableWidget->item(i,1)->text().isEmpty() )
               )
        {
            ui->tableWidget->removeRow(i);
            rowcount--;
            i--;
            res=2;
        }
    }

    if (res == 1)
    {
        QMessageBox::information(this, "","Не назначено ни 1 пользователя с правами администратора");
    }
    if (res == 2)
    {
//        int rowsInTable=ui->tableWidget->rowCount();
//        QStringList indexes;
//        for (int i=0; i<rowsInTable; i++)
//        {
//             indexes << QString::number(i+1);
//        }
//        ui->tableWidget->setVerticalHeaderLabels(indexes);
        QMessageBox::information(this, "","Незаполненые поля удалены!");
    }
    ui->tableWidget->blockSignals(false);
    return res;
}

void addNewAcc::writeAdminOrOperatorToTable(QString text)
{
    ui->tableWidget->blockSignals(false);

    qDebug() << text;

    if (text == "Оператор")
    {
        ui->tableWidget->currentItem()->setText("Оператор");
    }
    else if (text == "Админ") {
        ui->tableWidget->currentItem()->setText("Админ");
    }
    ui->tableWidget->blockSignals(false);
}

void addNewAcc::on_pushButton_clicked() // Удалить пользователя
{
    QString bufstr;
    ui->tableWidget->blockSignals(true);
    int currentRow=ui->tableWidget->currentRow();
    int rowsInTable=ui->tableWidget->rowCount();
    ui->tableWidget->removeRow(currentRow);

//    QStringList indexes;
//    for (int i=0; i<rowsInTable; i++)
//    {
//         indexes << QString::number(i+1);
//    }
//    ui->tableWidget->setVerticalHeaderLabels(indexes);
    ui->tableWidget->blockSignals(false);
}
