#include "ui_authwindow.h"
#include "mainwindow.h"
#include <QMessageBox>
#include "adminwindow.h"

#include <QtDebug>
#include <QtXml>
#include <QtCore>
#include "Windows.h"
#include "functions.h"
#include <tchar.h>
#include "videostreamobject.h"
#include <QTextCodec>

QString ComNumber1,Description1,Manufactor1,Serial_number1,System_path1,Vendor_ID1,Manufactor_ID1;
QString ComNumber2,Description2,Manufactor2,Serial_number2,System_path2,Vendor_ID2,Manufactor_ID2;
QString Cam_type,Device_name;
QString BankName, UnitNum;
QString SystemType;
QString ScanerHWVer;
QString User_ID;  //Идентификатор оператора
QString Machine_serial = "№1234567";; // серийный номер машины
QString Machine_ID = "99999"; // идентификатор машины в сети ... возможно... взято из протокола ЦБ
QString Machine_nominal; //Номинал купюр, принимаемый машиной

VideoStreamObject videostreamobject1("videostream");


bool IsUserAdmin(){
    SystemType = QSysInfo::kernelType();
    //Если винда
    if (SystemType == "winnt")
    {
        //TCHAR way[]= "Software\\Microsoft\\Windows\\CurrentVersion\\Run\\";
        HKEY CH;

//        WCHAR buffer[MAX_PATH];
//         LPCWSTR lpSubKey = _T("Software\\PROFINDUSTRY");
//         HKEY hKey;
//         LSTATUS status;
//         if (!GetModuleFileNameW(NULL, buffer, sizeof(buffer))) qDebug() << GetLastError();
//         if ((status = RegCreateKeyExW(HKEY_LOCAL_MACHINE, lpSubKey, 0, NULL, REG_OPTION_VOLATILE, KEY_WRITE, NULL, &hKey, NULL)) != ERROR_SUCCESS) qDebug() << status;
//         if ((status = RegSetValueExW(hKey, _T("SampleEntry"), 0, REG_SZ, (BYTE*)&buffer, sizeof(buffer))) != ERROR_SUCCESS) qDebug() << status;
//         if ((status = RegCloseKey(hKey)) != ERROR_SUCCESS) qDebug() << status;

        if (RegCreateKey(HKEY_LOCAL_MACHINE, L"Software\\Microsoft\\Windows\\CurrentVersion\\Run",&CH) != 0){  //Microsoft\\Windows\\CurrentVersion\\Run
            //qDebug() << "Not Admin";
            //RegDeleteKey(HKEY_LOCAL_MACHINE, L"Software\\Microsoft\\Windows\\CurrentVersion\\Run");
            return false;
        }
        else {
            //qDebug() << "Admin";
            return true;
        }
    }
    // Что то другое
    // ...
    return false;
}



Authwindow::Authwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Authwindow)
{
    ui->setupUi(this);
//    this->close();
    readSettingsData();

    //scaner_init(this);


//    //===============================
//    operatorwindow1 = new OperatorWindow();
//    operatorwindow1->show();
//    //==============================

}

Authwindow::~Authwindow()
{
    delete ui;
}

void Authwindow::on_pushButton_clicked()
{
    this->close();
    emit firstWindow();
}

void Authwindow::on_pushButton_2_clicked() // Войти
{
    bool EnterDone=false; //флаг успешной авторизации
    QString login = ui->lineEdit->text();
    QString pass = ui->lineEdit_2->text();
    //------------------------------------------------------------------------------
    // получаем хеш пароля
    QString passHash = GetModifiedHash(&pass);
    //------------------------------------------------------------------------------

    QDomDocument document;
    QFile file("C:/ProgramData/PROFINDUSTRY/MonironExpertS/accounts.xml");

    // Если файл существует, то пытаемся его открыть
    if (file.exists())
    {
        if  (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
                QMessageBox::information(this, "","Невозможно открыть файл с паролями или его нет");
        }
        else {
            if (!document.setContent(&file)){
                QMessageBox::information(this, "","Ошибка загрузки документа");
                delete ui;
            }
            file.close();
        }
    }
    else
    {
        QMessageBox::information(this, "Первый вход","Добро пожаловать! Установите логины пароли!");
        addnewaccwindow = new addNewAcc();
        addnewaccwindow->setModal(true);
        addnewaccwindow->show();
        this->close();
        EnterDone=true;
        return;
    }

    QDomAttr attr;
    QString LogXML,PassHashXML,RightXML;
    QDomElement root = document.documentElement();
    QDomNode node = root.firstChild();
    QDomNodeList items = root.elementsByTagName("Account"); // кол-во Логинов
    //qDebug()<< "total items =" << items.count();

    while(!node.isNull())
    {
        QDomElement element = node.toElement(); // try to convert the node to an element.
        if(!element.isNull())
        {
            attr = element.attributeNode("Login");
            LogXML = attr.value();

            attr = element.attributeNode("Password_Hash");
            PassHashXML = attr.value();

            attr = element.attributeNode("Rights");
            RightXML = attr.value();

            //qDebug() << "LogXML " << LogXML;
            //qDebug() << "PassHashXML from file = " << PassHashXML;
            //qDebug() << "PassHash = " << passHash;

            if (login == LogXML && passHash == PassHashXML)
            {
                if (RightXML == "Админ")
                {
                    if (IsUserAdmin() == 1 )
                    {
//                        QMessageBox::information(this, "", "Добро пожаловать!");
//                        adminwindow1 = new Adminwindow();
//                        adminwindow1->show();


                        addnewaccwindow = new addNewAcc();
                        addnewaccwindow->setModal(true);
                        addnewaccwindow->show();


                        this->close();
                        EnterDone=true;
                    }
                    else
                    {
                        QMessageBox::information(this, "", "Зайдите под учетной записью администратора!");
                    }
                }
                else if (RightXML == "Оператор")
                {
                    videostreamobject1.setRunning(false);
                    QMessageBox::information(this, "", "Добро пожаловать!");
                    User_ID=login;
                    operatorwindow1 = new OperatorWindow();
                    operatorwindow1->setWindowTitle("Окно оператора");
                    operatorwindow1->show();

                    videostreamobject1.setRunning(true);
                    videostreamobject1.start();

                    this->close();
                    EnterDone=true;
                }
                else
                {
                    QMessageBox::warning(this, "", "У пользователя не назначены права! Обратитесь к администратору!");
                    EnterDone=true;
                }
            }

        }
        node = node.nextSibling();
    }
    file.close();
    if (EnterDone==false){
        QMessageBox::warning(this, "", "Неверный логин или пароль!");
    }

}

void Authwindow::readSettingsData()
{
    // Читаем файл настроек
    {
        // Установка сохраненных ранее настроек
        QDomDocument *document= new QDomDocument();
        QFile file("C:/ProgramData/PROFINDUSTRY/MonironExpertS/settings.xml"); //"
        QTextStream stream(&file);
        if  (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QMessageBox::information(this, "","Невозможно открыть файл с настройками или он отстутствует");
        }
        else {
            if (!document->setContent(&file)){
                QMessageBox::information(this, "","Ошибка загрузки документа настроек");
                delete ui;
            }
            file.close();
        }

        QDomElement root = document->documentElement();
        QDomNode node = root.firstChild();
        QDomElement element0 = node.toElement(); // try to convert the node to an element.
        if(!element0.isNull()) {
            QDomAttr attr = element0.attributeNode("ComNumber1");
            ComNumber1=attr.value();
            attr = element0.attributeNode("Description1");
            Description1=attr.value();
            attr = element0.attributeNode("Manufactor1");
            Manufactor1=attr.value();
            attr = element0.attributeNode("Serial_number1");
            Serial_number1=attr.value();
            attr = element0.attributeNode("System_path1");
            System_path1=attr.value();
            attr = element0.attributeNode("Vendor_ID1");
            Vendor_ID1=attr.value();
            attr = element0.attributeNode("Manufactor_ID1");
            Manufactor_ID1=attr.value();
        }
        node = node.nextSibling();
        QDomElement element1 = node.toElement(); // try to convert the node to an element.
        if(!element1.isNull()) {
            QDomAttr attr = element1.attributeNode("ComNumber2");
            ComNumber2=attr.value();
            attr = element1.attributeNode("Description2");
            Description2=attr.value();
            attr = element1.attributeNode("Manufactor2");
            Manufactor2=attr.value();
            attr = element1.attributeNode("Serial_number2");
            Serial_number2=attr.value();
            attr = element1.attributeNode("System_path2");
            System_path2=attr.value();
            attr = element1.attributeNode("Vendor_ID2");
            Vendor_ID2=attr.value();
            attr = element1.attributeNode("Manufactor_ID2");
            Manufactor_ID2=attr.value();
        }



        node = node.nextSibling();
        QDomElement element2 = node.toElement(); // try to convert the node to an element.
        if(!element2.isNull()) {
            QDomAttr attr = element2.attributeNode("Cam_type");
            Cam_type=attr.value();
            attr = element2.attributeNode("Device_name");
            Device_name=attr.value();
        }
        node = node.nextSibling();
        QDomElement element3 = node.toElement(); // try to convert the node to an element.
        if(!element3.isNull()) {
            QDomAttr attr = element3.attributeNode("BankName");
            BankName=attr.value();
        }
        node = node.nextSibling();
        QDomElement element4 = node.toElement(); // try to convert the node to an element.
        if(!element4.isNull()) {
            QDomAttr attr = element4.attributeNode("UnitNum");
            UnitNum=attr.value();
        }
        node = node.nextSibling();
        QDomElement element5 = node.toElement(); // try to convert the node to an element.
        if(!element5.isNull()) {
            QDomAttr attr = element5.attributeNode("ScanerHWVer");
            ScanerHWVer=attr.value();
        }
        node = node.nextSibling();
        QDomElement element6 = node.toElement(); // try to convert the node to an element.
        if(!element6.isNull()) {
            QDomAttr attr = element6.attributeNode("Machine_serial");
            Machine_serial=attr.value();
        }
        node = node.nextSibling();
        QDomElement element7 = node.toElement(); // try to convert the node to an element.
        if(!element7.isNull()) {
            QDomAttr attr = element7.attributeNode("Machine_ID");
            Machine_ID=attr.value();
        }
        node = node.nextSibling();
        QDomElement element8 = node.toElement(); // try to convert the node to an element.
        if(!element8.isNull()) {
            QDomAttr attr = element8.attributeNode("Machine_nominal");
            Machine_nominal=attr.value();
        }
        node = node.nextSibling();
    }
}

