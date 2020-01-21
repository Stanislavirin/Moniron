#include "adminwindow.h"
#include "ui_adminwindow.h"
#include "authwindow.h"
#include <QDateTime>
#include <QTimer>
#include <QDebug>
#include <QSerialPortInfo>
#include <QCameraInfo>
#include <QMessageBox>
#include <QFile>
#include <QtXml>

#include "windows.h"
#include <stdio.h>
#include <process.h>
//#include "goslotolib.h"

extern QString ComNumber1,Description1,Manufactor1,Serial_number1,System_path1,Vendor_ID1,Manufactor_ID1;
extern QString ComNumber2,Description2,Manufactor2,Serial_number2,System_path2,Vendor_ID2,Manufactor_ID2;
extern QString Cam_type,Device_name;
extern QString BankName, UnitNum;
extern QString ScanerHWVer;
extern QString Machine_serial; // серийный номер машины
extern QString Machine_ID; // идентификатор машины в сети ... возможно... взято из протокола ЦБ


static const char blankString[] = QT_TRANSLATE_NOOP("SettingsDialog", "N/A");

Adminwindow::Adminwindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Adminwindow)
{
    QTimer* timer = new QTimer(this);
    timer->start(1000);
    ui->setupUi(this);

    ui->label_2->setText(tr("Текущая дата и время: %1").arg(QDateTime::currentDateTime().toString("dd.MM.yyyy HH:mm:ss") ));

    ui->label_7->setText(BankName);
    ui->label_8->setText(UnitNum);
    ui->label_19->setText(Machine_serial);
    ui->label_20->setText(Machine_ID);

    connect(timer,SIGNAL(timeout()),this, SLOT(onTimeout()));


    fillPortsInfo();
    fillCamerasInfo();
    fillScanerHWVersion();

    connect(ui->serialPortInfoListBox, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &Adminwindow::showPortInfo1);
    connect(ui->serialPortInfoListBox_3, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &Adminwindow::showPortInfo2);
    connect(ui->comboBoxCam, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &Adminwindow::showCameraInfo);



    //Выводим в интерфейс текущие настройки
    showPortInfo1(0);
    showPortInfo2(0);
    QStringList list1, list2;
    int index1=0,index2=0;
    for (int i=0; i < ui->serialPortInfoListBox->count(); i++)
    {
        list1 = ui->serialPortInfoListBox->itemData(i).toStringList();
        if (list1.first() == ComNumber1) {
            ui->serialPortInfoListBox->setCurrentIndex(i);
            showPortInfo1(i);
        }
        list2 = ui->serialPortInfoListBox_3->itemData(i).toStringList();
        if (list2.first() == ComNumber2) {
            ui->serialPortInfoListBox_3->setCurrentIndex(i);
            showPortInfo2(i);
        }
    }


    QStringList list;
    if (ui->comboBoxCam->count() < 2)
    {
        showCameraInfo(0);
        writeDocument();
    }
    else
    {
        for (int i=0; i < ui->comboBoxCam->count(); i++)
        {
            list = ui->comboBoxCam->itemData(i).toStringList();
            if (list.at(1) == Device_name) {
                ui->comboBoxCam->setCurrentIndex(i);
                fillCamerasInfo();
            }
        }
    }



    ui->BankName->setText(BankName);
    ui->UnitNumber->setText(UnitNum);
    ui->Machine_serial->setText(Machine_serial);
    ui->Machine_ID->setText(Machine_ID);

}

Adminwindow::~Adminwindow()
{
    delete ui;
}

void Adminwindow::on_pushButton_7_clicked()//кнопка назад
{
    writeDocument();
    Authwindow *authwindow2;
    authwindow2 = new Authwindow();
    authwindow2->show();
    this->close();
}

void Adminwindow::onTimeout()
{
    ui->label_2->setText(tr("Текущая дата и время: %1").arg(QDateTime::currentDateTime().toString("dd.MM.yyyy HH:mm:ss") ));
}


void Adminwindow::on_pushButton_3_clicked()
{
    ui->label_2->setText(QDateTime::currentDateTime().toString("dd.MM.yyyy HH:mm:ss"));
}

void Adminwindow::on_pushButton_clicked() // добавить/редактировать пользователя
{
    addnewaccwindow = new addNewAcc();
    addnewaccwindow->setModal(true);
    addnewaccwindow->show();
}



void Adminwindow::fillPortsInfo()
{
    ui->serialPortInfoListBox_3->blockSignals(true);
    ui->serialPortInfoListBox->blockSignals(true);
    ui->serialPortInfoListBox_3->clear();
    ui->serialPortInfoListBox->clear();
    QString Description;
    QString manufacturer;
    QString serialNumber;
    const auto infos = QSerialPortInfo::availablePorts();
    for (const QSerialPortInfo &info : infos) {
        QStringList list;
        Description = info.description();
        manufacturer = info.manufacturer();
        serialNumber = info.serialNumber();
        list << info.portName()
             << (!Description.isEmpty() ? Description : blankString)
             << (!manufacturer.isEmpty() ? manufacturer : blankString)
             << (!serialNumber.isEmpty() ? serialNumber : blankString)
             << info.systemLocation()
             << (info.vendorIdentifier() ? QString::number(info.vendorIdentifier(), 16) : blankString)
             << (info.productIdentifier() ? QString::number(info.productIdentifier(), 16) : blankString);

        ui->serialPortInfoListBox->addItem(list.first(), list);
        ui->serialPortInfoListBox_3->addItem(list.first(), list);
    }
    ui->serialPortInfoListBox->blockSignals(false);
    ui->serialPortInfoListBox_3->blockSignals(false);
}





void Adminwindow::fillCamerasInfo()
{
// Проверка на присутствие камер
//     if (QCameraInfo::availableCameras().count() <= 0)
//     {
//        QMessageBox::warning(this, "", "Не обнаружено подключенных камер!");
//     }
     //Далее ищем в списке нашу камеру и выбираем ее
//     QList<QCameraInfo> cameras = QCameraInfo::availableCameras();
//       foreach (const QCameraInfo &cameraInfo, cameras) {
//           if (cameraInfo.deviceName() == "@device:pnp:\\\\?\\usb#vid_05a3&pid_9230&mi_00#8&3a26dea9&0&0000#{65e8773d-8f56-11d0-a3b9-00a0c9223196}\\global")
//               QCamera *mCamera = new QCamera(cameraInfo,this);
//       }
//     if (mCamera == nullptr)
//         QMessageBox::warning(this, "", "Не обнаружено камеры HD USB Camera!");
    ui->serialPortInfoListBox->blockSignals(true);
    ui->serialPortInfoListBox_3->blockSignals(true);
    ui->comboBoxCam->clear();
    const auto infos = QCameraInfo::availableCameras();
    QString Description;
    for (const QCameraInfo &info : infos) {
        QStringList list;
        Description = info.description();
        list << (!Description.isEmpty() ? Description : blankString)
                << info.deviceName();
        ui->comboBoxCam->addItem(list.first(), list);
    }
    ui->serialPortInfoListBox->blockSignals(false);
    ui->serialPortInfoListBox_3->blockSignals(false);

}

void Adminwindow::showPortInfo1(int idx)
{
    if (idx == -1)
        return;
    ui->serialPortInfoListBox->blockSignals(true);
    ui->serialPortInfoListBox_3->blockSignals(true);
    const QStringList list1 = ui->serialPortInfoListBox->itemData(idx).toStringList();
    ui->label_11->setText(tr("Описание: %1").arg(list1.count() > 1 ? list1.at(1) : tr(blankString)));
    ui->label_12->setText(tr("Производитель: %1").arg(list1.count() > 2 ? list1.at(2) : tr(blankString)));
    ui->label_13->setText(tr("Серийный номер: %1").arg(list1.count() > 3 ? list1.at(3) : tr(blankString)));
    ui->label_14->setText(tr("Расположение в системе: %1").arg(list1.count() > 4 ? list1.at(4) : tr(blankString)));
    ui->label_15->setText(tr("Идентификатор продавца: %1").arg(list1.count() > 5 ? list1.at(5) : tr(blankString)));
    ui->label_16->setText(tr("Идентификатор производителя: %1").arg(list1.count() > 6 ? list1.at(6) : tr(blankString)));
    ui->serialPortInfoListBox_3->blockSignals(false);
    ui->serialPortInfoListBox->blockSignals(false);
}


void Adminwindow::showPortInfo2(int idx)
{
    if (idx == -1)
        return;
    ui->serialPortInfoListBox->blockSignals(true);
    ui->serialPortInfoListBox_3->blockSignals(true);
    const QStringList list2 = ui->serialPortInfoListBox_3->itemData(idx).toStringList();
    ui->label_25->setText(tr("Описание: %1").arg(list2.count() > 1 ? list2.at(1) : tr(blankString)));
    ui->label_26->setText(tr("Производитель: %1").arg(list2.count() > 2 ? list2.at(2) : tr(blankString)));
    ui->label_27->setText(tr("Серийный номер: %1").arg(list2.count() > 3 ? list2.at(3) : tr(blankString)));
    ui->label_28->setText(tr("Расположение в системе: %1").arg(list2.count() > 4 ? list2.at(4) : tr(blankString)));
    ui->label_29->setText(tr("Идентификатор продавца: %1").arg(list2.count() > 5 ? list2.at(5) : tr(blankString)));
    ui->label_30->setText(tr("Идентификатор производителя: %1").arg(list2.count() > 6 ? list2.at(6) : tr(blankString)));

    ui->serialPortInfoListBox_3->blockSignals(false);
    ui->serialPortInfoListBox->blockSignals(false);
}

void Adminwindow::showCameraInfo(int idx)
{
    if (idx == -1)
        return;
    ui->comboBoxCam->blockSignals(true);

    const QStringList list = ui->comboBoxCam->itemData(idx).toStringList();
    //ui->textBrowser->setText(tr("Имя устройства: %1").arg(list.count() > 1 ? list.at(1) : tr(blankString)));
    ui->label->setText(tr("Имя устройства: %1").arg(list.count() > 1 ? list.at(1) : tr(blankString)));
    ui->comboBoxCam->blockSignals(false);
}



void Adminwindow::writeDocument()
{


    QDomDocument document;
    QDomElement root = document.createElement("Program_settings");
    document.appendChild(root);


    //Конвертирование кодировки в UTF-8
    QString str,utf8Str,str2;
    QByteArray ba;
    QTextCodec *codec = QTextCodec::codecForName("Windows-1251");
    ba=str.toUtf8();
    utf8Str = codec->toUnicode(ba);


//    accountWithPass.setAttribute("Password",str);
//    str2 = GetModifiedHash(&str);
//    ba=str2.toUtf8();
//    utf8Str = codec->toUnicode(ba);

    const QStringList list1 = ui->serialPortInfoListBox->itemData(ui->serialPortInfoListBox->currentIndex()).toStringList();
    QDomElement COMportElement1 = document.createElement("COMport1");
    COMportElement1.setAttribute("ComNumber1",codec->toUnicode(list1.at(0).toUtf8()));
    COMportElement1.setAttribute("Description1",codec->toUnicode(list1.at(1).toUtf8()));
    COMportElement1.setAttribute("Manufactor1", codec->toUnicode(list1.at(2).toUtf8()));
    COMportElement1.setAttribute("Serial_number1", codec->toUnicode(list1.at(3).toUtf8()));
    COMportElement1.setAttribute("System_path1", codec->toUnicode(list1.at(4).toUtf8()));
    COMportElement1.setAttribute("Vendor_ID1", codec->toUnicode(list1.at(5).toUtf8()));
    COMportElement1.setAttribute("Manufactor_ID1", codec->toUnicode(list1.at(6).toUtf8()));
    root.appendChild(COMportElement1);


    const QStringList list2 = ui->serialPortInfoListBox_3->itemData(ui->serialPortInfoListBox_3->currentIndex()).toStringList();
    QDomElement COMportElement2 = document.createElement("COMport2");
    COMportElement2.setAttribute("ComNumber2",codec->toUnicode(list2.at(0).toUtf8()));
    COMportElement2.setAttribute("Description2",codec->toUnicode(list2.at(1).toUtf8()));
    COMportElement2.setAttribute("Manufactor2", codec->toUnicode(list2.at(2).toUtf8()));
    COMportElement2.setAttribute("Serial_number2", codec->toUnicode(list2.at(3).toUtf8()));
    COMportElement2.setAttribute("System_path2", codec->toUnicode(list2.at(4).toUtf8()));
    COMportElement2.setAttribute("Vendor_ID2", codec->toUnicode(list2.at(5).toUtf8()));
    COMportElement2.setAttribute("Manufactor_ID2", codec->toUnicode(list2.at(6).toUtf8()));
    root.appendChild(COMportElement2);

    const QStringList list3 = ui->comboBoxCam->itemData(ui->comboBoxCam->currentIndex()).toStringList();
    QDomElement CamElement = document.createElement("Camera");
    if (!list3.empty())
    {
        CamElement.setAttribute("Cam_type",codec->toUnicode(list3.first().toUtf8()));
        CamElement.setAttribute("Device_name",codec->toUnicode(list3.at(1).toUtf8()));
    }
    else
    {
        CamElement.setAttribute("Cam_type",codec->toUnicode("No_camera_detected"));
        CamElement.setAttribute("Device_name",codec->toUnicode("No_camera_detected"));
    }
    root.appendChild(CamElement);

    QDomElement BankNameElement = document.createElement("Bank");
    BankNameElement.setAttribute("BankName",codec->toUnicode(BankName.toUtf8()));
    root.appendChild(BankNameElement);

    QDomElement UnitNumElement = document.createElement("Unit");
    UnitNumElement.setAttribute("UnitNum",codec->toUnicode(UnitNum.toUtf8()));
    root.appendChild(UnitNumElement);

    QDomElement ScanerHWVersionElement = document.createElement("Scaner");
    ScanerHWVersionElement.setAttribute("ScanerHWVer",codec->toUnicode(ScanerHWVer.toUtf8()));
    root.appendChild(ScanerHWVersionElement);

    QDomElement Machine_serialElement = document.createElement("Machine_serial");
    Machine_serialElement.setAttribute("Machine_serial",codec->toUnicode(Machine_serial.toUtf8()));
    root.appendChild(Machine_serialElement);

    QDomElement Machine_IDElement = document.createElement("Machine_ID");
    Machine_IDElement.setAttribute("Machine_ID",codec->toUnicode(Machine_ID.toUtf8()));
    root.appendChild(Machine_IDElement);


    QFile file("C:/ProgramData/PROFINDUSTRY/MonironExpertS/settings.xml");
    if  (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QMessageBox::information(this, "", "Не получается записать данные настроек в файл.");
    }
    QTextStream stream(&file);
    QString sss;
    sss = document.toString();
    stream << sss;
    file.close();

}

void Adminwindow::fillScanerHWVersion()
{
    int state;
    ScanerHWVer="version 1.3"; // что бы не оставлять пустым поле - запихнем туда рандомный номер
//    state = ScannerInit(call_back,-16);
//    if (state == SUCCES_RESULT) qDebug()<<"scaner ready";
//    else if (state == ERROR_DELTA_LEVEL_COUPON) qDebug() << "ScannerInit - ERROR_DELTA_LEVEL_COUPON\n";
//    else {
//        QMessageBox::warning(this, "Ошибка", "Не удалось инициализировать валидатор");
//    }
////    DWORD ver;
////    int i;
////    for (i=0;i<50;i++) {
////        Sleep(100);
////        state = ScannerIsReady();
////        if (state == SUCCES_RESULT) break;
////    }
////    if (state == SUCCES_RESULT);
////    else
////    {
////        QMessageBox::warning(this, "Ошибка", "Сканер не готов");
////    }
//    DWORD ver = ScannerGetHWVersion();
//    ScanerHWVersion.sprintf("%d",ver);
//    qDebug()<< ScanerHWVersion;
//    ui->ScanerHWVersion->setText(tr("Версия прошивки сканера: %1").arg(ScanerHWVersion > 1 ? ScanerHWVersion : tr(blankString)));
}





void Adminwindow::on_pushButton_2_clicked() // Применить
{
    BankName = ui->BankName->text();
    UnitNum = ui->UnitNumber->text();
    Machine_serial=ui->Machine_serial->text();
    Machine_ID=ui->Machine_ID->text();
    ui->Machine_serial->setText(Machine_serial);
    ui->Machine_ID->setText(Machine_ID);
//    Machine_serial = ui->
//    ui->label_8->setText(UnitNum);
    ui->label_7->setText(BankName);
    ui->label_8->setText(UnitNum);
    ui->label_19->setText(Machine_serial);
    ui->label_20->setText(Machine_ID);
    writeDocument();
}
