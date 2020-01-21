/********************************************************************************
** Form generated from reading UI file 'printform.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRINTFORM_H
#define UI_PRINTFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PrintForm
{
public:
    QTableWidget *tableWidget_2;
    QTableWidget *tableWidget_3;
    QTextEdit *textEdit;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QPushButton *pushButton;
    QTableWidget *tableWidget;

    void setupUi(QWidget *PrintForm)
    {
        if (PrintForm->objectName().isEmpty())
            PrintForm->setObjectName(QString::fromUtf8("PrintForm"));
        PrintForm->resize(430, 522);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(PrintForm->sizePolicy().hasHeightForWidth());
        PrintForm->setSizePolicy(sizePolicy);
        PrintForm->setMinimumSize(QSize(430, 0));
        PrintForm->setMaximumSize(QSize(430, 16777215));
        tableWidget_2 = new QTableWidget(PrintForm);
        if (tableWidget_2->columnCount() < 4)
            tableWidget_2->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        if (tableWidget_2->rowCount() < 3)
            tableWidget_2->setRowCount(3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget_2->setVerticalHeaderItem(0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget_2->setVerticalHeaderItem(1, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget_2->setVerticalHeaderItem(2, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget_2->setItem(0, 0, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget_2->setItem(0, 1, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget_2->setItem(0, 2, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget_2->setItem(0, 3, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget_2->setItem(1, 0, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget_2->setItem(1, 1, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget_2->setItem(1, 2, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget_2->setItem(1, 3, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidget_2->setItem(2, 0, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableWidget_2->setItem(2, 1, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tableWidget_2->setItem(2, 2, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tableWidget_2->setItem(2, 3, __qtablewidgetitem18);
        tableWidget_2->setObjectName(QString::fromUtf8("tableWidget_2"));
        tableWidget_2->setGeometry(QRect(9, 246, 256, 192));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tableWidget_2->sizePolicy().hasHeightForWidth());
        tableWidget_2->setSizePolicy(sizePolicy1);
        tableWidget_2->setAutoScroll(false);
        tableWidget_2->setShowGrid(false);
        tableWidget_2->verticalHeader()->setVisible(false);
        tableWidget_3 = new QTableWidget(PrintForm);
        if (tableWidget_3->columnCount() < 4)
            tableWidget_3->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tableWidget_3->setHorizontalHeaderItem(0, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        tableWidget_3->setHorizontalHeaderItem(1, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        tableWidget_3->setHorizontalHeaderItem(2, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        tableWidget_3->setHorizontalHeaderItem(3, __qtablewidgetitem22);
        if (tableWidget_3->rowCount() < 1)
            tableWidget_3->setRowCount(1);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        tableWidget_3->setVerticalHeaderItem(0, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        tableWidget_3->setItem(0, 0, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        tableWidget_3->setItem(0, 1, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        tableWidget_3->setItem(0, 2, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        tableWidget_3->setItem(0, 3, __qtablewidgetitem27);
        tableWidget_3->setObjectName(QString::fromUtf8("tableWidget_3"));
        tableWidget_3->setGeometry(QRect(9, 483, 412, 30));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(tableWidget_3->sizePolicy().hasHeightForWidth());
        tableWidget_3->setSizePolicy(sizePolicy2);
        tableWidget_3->setMaximumSize(QSize(16777215, 30));
        tableWidget_3->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget_3->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget_3->horizontalHeader()->setVisible(false);
        tableWidget_3->horizontalHeader()->setDefaultSectionSize(100);
        tableWidget_3->verticalHeader()->setVisible(false);
        textEdit = new QTextEdit(PrintForm);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(300, 140, 104, 71));
        widget = new QWidget(PrintForm);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(9, 9, 258, 225));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        sizePolicy2.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy2);
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(12);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMaximumSize(QSize(60, 16777215));

        horizontalLayout->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout);

        tableWidget = new QTableWidget(widget);
        if (tableWidget->columnCount() < 2)
            tableWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem29);
        if (tableWidget->rowCount() < 6)
            tableWidget->setRowCount(6);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem30);
        QTableWidgetItem *__qtablewidgetitem31 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem31);
        QTableWidgetItem *__qtablewidgetitem32 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(2, __qtablewidgetitem32);
        QTableWidgetItem *__qtablewidgetitem33 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(3, __qtablewidgetitem33);
        QTableWidgetItem *__qtablewidgetitem34 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(4, __qtablewidgetitem34);
        QTableWidgetItem *__qtablewidgetitem35 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(5, __qtablewidgetitem35);
        QTableWidgetItem *__qtablewidgetitem36 = new QTableWidgetItem();
        tableWidget->setItem(0, 0, __qtablewidgetitem36);
        QTableWidgetItem *__qtablewidgetitem37 = new QTableWidgetItem();
        tableWidget->setItem(0, 1, __qtablewidgetitem37);
        QTableWidgetItem *__qtablewidgetitem38 = new QTableWidgetItem();
        tableWidget->setItem(1, 0, __qtablewidgetitem38);
        QTableWidgetItem *__qtablewidgetitem39 = new QTableWidgetItem();
        tableWidget->setItem(1, 1, __qtablewidgetitem39);
        QTableWidgetItem *__qtablewidgetitem40 = new QTableWidgetItem();
        tableWidget->setItem(2, 0, __qtablewidgetitem40);
        QTableWidgetItem *__qtablewidgetitem41 = new QTableWidgetItem();
        tableWidget->setItem(2, 1, __qtablewidgetitem41);
        QTableWidgetItem *__qtablewidgetitem42 = new QTableWidgetItem();
        tableWidget->setItem(3, 0, __qtablewidgetitem42);
        QTableWidgetItem *__qtablewidgetitem43 = new QTableWidgetItem();
        tableWidget->setItem(3, 1, __qtablewidgetitem43);
        QTableWidgetItem *__qtablewidgetitem44 = new QTableWidgetItem();
        tableWidget->setItem(4, 0, __qtablewidgetitem44);
        QTableWidgetItem *__qtablewidgetitem45 = new QTableWidgetItem();
        tableWidget->setItem(4, 1, __qtablewidgetitem45);
        QTableWidgetItem *__qtablewidgetitem46 = new QTableWidgetItem();
        tableWidget->setItem(5, 0, __qtablewidgetitem46);
        QTableWidgetItem *__qtablewidgetitem47 = new QTableWidgetItem();
        tableWidget->setItem(5, 1, __qtablewidgetitem47);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        sizePolicy2.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
        tableWidget->setSizePolicy(sizePolicy2);
        tableWidget->setAutoScroll(false);
        tableWidget->setShowGrid(false);
        tableWidget->setGridStyle(Qt::NoPen);
        tableWidget->setCornerButtonEnabled(true);
        tableWidget->horizontalHeader()->setVisible(false);
        tableWidget->horizontalHeader()->setDefaultSectionSize(200);
        tableWidget->horizontalHeader()->setStretchLastSection(false);
        tableWidget->verticalHeader()->setVisible(false);

        verticalLayout->addWidget(tableWidget);


        retranslateUi(PrintForm);

        QMetaObject::connectSlotsByName(PrintForm);
    } // setupUi

    void retranslateUi(QWidget *PrintForm)
    {
        PrintForm->setWindowTitle(QApplication::translate("PrintForm", "Form", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_2->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("PrintForm", "\320\232\320\260\321\202\320\265\320\263\320\276\321\200\320\270\321\217", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_2->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("PrintForm", "\320\235\320\276\320\274\320\270\320\275\320\260\320\273", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_2->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("PrintForm", "\320\232\320\276\320\273-\320\262\320\276", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_2->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("PrintForm", "\320\241\321\203\320\274\320\274\320\260", nullptr));

        const bool __sortingEnabled = tableWidget_2->isSortingEnabled();
        tableWidget_2->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget_2->item(0, 0);
        ___qtablewidgetitem4->setText(QApplication::translate("PrintForm", "\320\250\321\200\320\265\320\264\320\265\321\200", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget_2->item(0, 1);
        ___qtablewidgetitem5->setText(QApplication::translate("PrintForm", "RUB 500", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget_2->item(0, 2);
        ___qtablewidgetitem6->setText(QApplication::translate("PrintForm", "57", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget_2->item(0, 3);
        ___qtablewidgetitem7->setText(QApplication::translate("PrintForm", "43500.00", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget_2->item(1, 0);
        ___qtablewidgetitem8->setText(QApplication::translate("PrintForm", "\320\250\321\200\320\265\320\264\320\265\321\200", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget_2->item(1, 1);
        ___qtablewidgetitem9->setText(QApplication::translate("PrintForm", "RUB 500-04", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget_2->item(1, 2);
        ___qtablewidgetitem10->setText(QApplication::translate("PrintForm", "96", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget_2->item(1, 3);
        ___qtablewidgetitem11->setText(QApplication::translate("PrintForm", "48000.00", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget_2->item(2, 0);
        ___qtablewidgetitem12->setText(QApplication::translate("PrintForm", "\320\250\321\200\320\265\320\264\320\265\321\200", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget_2->item(2, 1);
        ___qtablewidgetitem13->setText(QApplication::translate("PrintForm", "RUB 500-10", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget_2->item(2, 2);
        ___qtablewidgetitem14->setText(QApplication::translate("PrintForm", "2975", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget_2->item(2, 3);
        ___qtablewidgetitem15->setText(QApplication::translate("PrintForm", "1487500.00", nullptr));
        tableWidget_2->setSortingEnabled(__sortingEnabled);

        QTableWidgetItem *___qtablewidgetitem16 = tableWidget_3->verticalHeaderItem(0);
        ___qtablewidgetitem16->setText(QApplication::translate("PrintForm", "\320\230\321\202\320\276\320\263", nullptr));

        const bool __sortingEnabled1 = tableWidget_3->isSortingEnabled();
        tableWidget_3->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem17 = tableWidget_3->item(0, 0);
        ___qtablewidgetitem17->setText(QApplication::translate("PrintForm", "\320\230\321\202\320\276\320\263", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = tableWidget_3->item(0, 2);
        ___qtablewidgetitem18->setText(QApplication::translate("PrintForm", "3158", nullptr));
        QTableWidgetItem *___qtablewidgetitem19 = tableWidget_3->item(0, 3);
        ___qtablewidgetitem19->setText(QApplication::translate("PrintForm", "1579000.00", nullptr));
        tableWidget_3->setSortingEnabled(__sortingEnabled1);

        label->setText(QApplication::translate("PrintForm", "\320\234\320\260\321\210\320\270\320\275\320\275\321\213\320\271 \320\277\321\200\320\276\321\202\320\276\320\272\320\276\320\273", nullptr));
        pushButton->setText(QApplication::translate("PrintForm", "print", nullptr));

        const bool __sortingEnabled2 = tableWidget->isSortingEnabled();
        tableWidget->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem20 = tableWidget->item(0, 0);
        ___qtablewidgetitem20->setText(QApplication::translate("PrintForm", "\320\234\320\260\321\210\320\270\320\275\320\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem21 = tableWidget->item(0, 1);
        ___qtablewidgetitem21->setText(QApplication::translate("PrintForm", "163503257", nullptr));
        QTableWidgetItem *___qtablewidgetitem22 = tableWidget->item(1, 0);
        ___qtablewidgetitem22->setText(QApplication::translate("PrintForm", "ID \320\274\320\260\321\210\320\270\320\275\321\213", nullptr));
        QTableWidgetItem *___qtablewidgetitem23 = tableWidget->item(1, 1);
        ___qtablewidgetitem23->setText(QApplication::translate("PrintForm", "3257", nullptr));
        QTableWidgetItem *___qtablewidgetitem24 = tableWidget->item(2, 0);
        ___qtablewidgetitem24->setText(QApplication::translate("PrintForm", "\320\235\320\276\320\274\320\265\321\200 \320\277\321\200\320\276\321\202\320\276\320\272\320\276\320\273\320\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem25 = tableWidget->item(2, 1);
        ___qtablewidgetitem25->setText(QApplication::translate("PrintForm", "2019081944", nullptr));
        QTableWidgetItem *___qtablewidgetitem26 = tableWidget->item(3, 0);
        ___qtablewidgetitem26->setText(QApplication::translate("PrintForm", "\320\235\320\260\321\207\320\260\320\273\320\276", nullptr));
        QTableWidgetItem *___qtablewidgetitem27 = tableWidget->item(3, 1);
        ___qtablewidgetitem27->setText(QApplication::translate("PrintForm", "19.08.2019 08.43.26", nullptr));
        QTableWidgetItem *___qtablewidgetitem28 = tableWidget->item(4, 0);
        ___qtablewidgetitem28->setText(QApplication::translate("PrintForm", "\320\230\320\275\320\264\320\265\320\272\321\201", nullptr));
        QTableWidgetItem *___qtablewidgetitem29 = tableWidget->item(4, 1);
        ___qtablewidgetitem29->setText(QApplication::translate("PrintForm", "4", nullptr));
        QTableWidgetItem *___qtablewidgetitem30 = tableWidget->item(5, 0);
        ___qtablewidgetitem30->setText(QApplication::translate("PrintForm", "\320\222\321\200\320\265\320\274\321\217 \321\204\320\276\321\200\320\274\320\270\321\200\320\276\320\262\320\260\320\275\320\270\321\217", nullptr));
        QTableWidgetItem *___qtablewidgetitem31 = tableWidget->item(5, 1);
        ___qtablewidgetitem31->setText(QApplication::translate("PrintForm", "19.08.2019 14.54.06", nullptr));
        tableWidget->setSortingEnabled(__sortingEnabled2);

    } // retranslateUi

};

namespace Ui {
    class PrintForm: public Ui_PrintForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRINTFORM_H
