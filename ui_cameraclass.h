/********************************************************************************
** Form generated from reading UI file 'cameraclass.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAMERACLASS_H
#define UI_CAMERACLASS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CameraClass
{
public:
    QVBoxLayout *verticalLayout;
    QPushButton *OptionspushButton;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;

    void setupUi(QWidget *CameraClass)
    {
        if (CameraClass->objectName().isEmpty())
            CameraClass->setObjectName(QString::fromUtf8("CameraClass"));
        CameraClass->resize(424, 358);
        verticalLayout = new QVBoxLayout(CameraClass);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        OptionspushButton = new QPushButton(CameraClass);
        OptionspushButton->setObjectName(QString::fromUtf8("OptionspushButton"));

        verticalLayout->addWidget(OptionspushButton);

        scrollArea = new QScrollArea(CameraClass);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 404, 309));
        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);


        retranslateUi(CameraClass);

        QMetaObject::connectSlotsByName(CameraClass);
    } // setupUi

    void retranslateUi(QWidget *CameraClass)
    {
        CameraClass->setWindowTitle(QApplication::translate("CameraClass", "Form", nullptr));
        OptionspushButton->setText(QApplication::translate("CameraClass", "Options", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CameraClass: public Ui_CameraClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAMERACLASS_H
