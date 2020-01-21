/********************************************************************************
** Form generated from reading UI file 'operatorwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPERATORWINDOW_H
#define UI_OPERATORWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OperatorWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_18;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_17;
    QFrame *frame_2;
    QGridLayout *gridLayout_11;
    QGridLayout *gridLayout_3;
    QSpacerItem *horizontalSpacer_13;
    QLabel *Curtimelabel;
    QFrame *frame_5;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout_5;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_8;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QSpacerItem *horizontalSpacer_9;
    QLabel *WhiteSpectorPic;
    QSpacerItem *verticalSpacer_3;
    QGridLayout *gridLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_10;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;
    QSpacerItem *horizontalSpacer_11;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_6;
    QLabel *label_19;
    QLabel *label_20;
    QLabel *label_21;
    QLabel *label_22;
    QSpacerItem *horizontalSpacer_7;
    QLabel *label_13;
    QLabel *InfraSpectorPic;
    QSpacerItem *verticalSpacer_5;
    QFrame *frame_4;
    QGridLayout *gridLayout_16;
    QFrame *frame_7;
    QGridLayout *gridLayout_15;
    QGridLayout *gridLayout_7;
    QGridLayout *gridLayout_6;
    QSpacerItem *horizontalSpacer_12;
    QSpacerItem *horizontalSpacer_16;
    QLabel *BankName;
    QLabel *UnitNum;
    QGridLayout *gridLayout_9;
    QLabel *YesConnectionPic;
    QLabel *NoConnectionPic;
    QFrame *frame_8;
    QGridLayout *gridLayout_12;
    QGridLayout *gridLayout_14;
    QSpacerItem *horizontalSpacer_20;
    QFrame *frame_6;
    QGridLayout *gridLayout_13;
    QGridLayout *gridLayout_8;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QSpacerItem *horizontalSpacer_15;
    QSpacerItem *horizontalSpacer_14;
    QGridLayout *gridLayout_10;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_6;
    QPushButton *DestroyButton;
    QPushButton *pushButton_5;
    QPushButton *CashRollBack;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_24;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_18;
    QLabel *label_23;
    QLineEdit *lineEdit_2;
    QSpacerItem *horizontalSpacer_17;
    QPushButton *editButton;
    QPushButton *StartButton;
    QSpacerItem *horizontalSpacer_21;
    QFrame *frame;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *OperatorWindow)
    {
        if (OperatorWindow->objectName().isEmpty())
            OperatorWindow->setObjectName(QString::fromUtf8("OperatorWindow"));
        OperatorWindow->resize(1089, 800);
        OperatorWindow->setStyleSheet(QString::fromUtf8("/*\n"
"Aqua Style Sheet for QT Applications\n"
"Author: Jaime A. Quiroga P.\n"
"Company: GTRONICK\n"
"Last updated: 22/01/2019, 07:55.\n"
"Available at: https://github.com/GTRONICK/QSS/blob/master/Aqua.qss\n"
"*/\n"
"QMainWindow {\n"
"	background-color:rgb(250,250,250);\n"
"}\n"
"QTextEdit {\n"
"	border-width: 1px;\n"
"	border-style: solid;\n"
"	border-color: qlineargradient(spread:pad, x1:0.5, y1:1, x2:0.5, y2:0, stop:0 rgba(0, 113, 255, 255), stop:1 rgba(91, 171, 252, 255));\n"
"}\n"
"QPlainTextEdit {\n"
"	border-width: 1px;\n"
"	border-style: solid;\n"
"	border-color: qlineargradient(spread:pad, x1:0.5, y1:1, x2:0.5, y2:0, stop:0 rgba(0, 113, 255, 255), stop:1 rgba(91, 171, 252, 255));\n"
"}\n"
"QToolButton {\n"
"	border-style: solid;\n"
"	border-top-color: qlineargradient(spread:pad, x1:0.5, y1:1, x2:0.5, y2:0, stop:0 rgb(215, 215, 215), stop:1 rgb(222, 222, 222));\n"
"	border-right-color: qlineargradient(spread:pad, x1:0, y1:0.5, x2:1, y2:0.5, stop:0 rgb(217, 217, 217), stop:1 rgb(227, 227, 227));\n"
"	bo"
                        "rder-left-color: qlineargradient(spread:pad, x1:0, y1:0.5, x2:1, y2:0.5, stop:0 rgb(227, 227, 227), stop:1 rgb(217, 217, 217));\n"
"	border-bottom-color: qlineargradient(spread:pad, x1:0.5, y1:1, x2:0.5, y2:0, stop:0 rgb(215, 215, 215), stop:1 rgb(222, 222, 222));\n"
"	border-width: 1px;\n"
"	border-radius: 5px;\n"
"	color: rgb(0,0,0);\n"
"	padding: 2px;\n"
"	background-color: rgb(255,255,255);\n"
"}\n"
"QToolButton:hover{\n"
"	border-style: solid;\n"
"	border-top-color: qlineargradient(spread:pad, x1:0.5, y1:1, x2:0.5, y2:0, stop:0 rgb(195, 195, 195), stop:1 rgb(222, 222, 222));\n"
"	border-right-color: qlineargradient(spread:pad, x1:0, y1:0.5, x2:1, y2:0.5, stop:0 rgb(197, 197, 197), stop:1 rgb(227, 227, 227));\n"
"	border-left-color: qlineargradient(spread:pad, x1:0, y1:0.5, x2:1, y2:0.5, stop:0 rgb(227, 227, 227), stop:1 rgb(197, 197, 197));\n"
"	border-bottom-color: qlineargradient(spread:pad, x1:0.5, y1:1, x2:0.5, y2:0, stop:0 rgb(195, 195, 195), stop:1 rgb(222, 222, 222));\n"
"	border-width: 1px;\n"
"	b"
                        "order-radius: 5px;\n"
"	color: rgb(0,0,0);\n"
"	padding: 2px;\n"
"	background-color: rgb(255,255,255);\n"
"}\n"
"QToolButton:pressed{\n"
"	border-style: solid;\n"
"	border-top-color: qlineargradient(spread:pad, x1:0.5, y1:1, x2:0.5, y2:0, stop:0 rgb(215, 215, 215), stop:1 rgb(222, 222, 222));\n"
"	border-right-color: qlineargradient(spread:pad, x1:0, y1:0.5, x2:1, y2:0.5, stop:0 rgb(217, 217, 217), stop:1 rgb(227, 227, 227));\n"
"	border-left-color: qlineargradient(spread:pad, x1:0, y1:0.5, x2:1, y2:0.5, stop:0 rgb(227, 227, 227), stop:1 rgb(217, 217, 217));\n"
"	border-bottom-color: qlineargradient(spread:pad, x1:0.5, y1:1, x2:0.5, y2:0, stop:0 rgb(215, 215, 215), stop:1 rgb(222, 222, 222));\n"
"	border-width: 1px;\n"
"	border-radius: 5px;\n"
"	color:rgb(230, 212, 255);\n"
"	padding: 2px;\n"
"	background-color: rgb(142,142,142);\n"
"}\n"
"QPushButton{\n"
"	border-style: solid;\n"
"	border-top-color: qlineargradient(spread:pad, x1:0.5, y1:1, x2:0.5, y2:0, stop:0 rgb(215, 215, 215), stop:1 rgb(222, 222, 222));\n"
""
                        "	border-right-color: qlineargradient(spread:pad, x1:0, y1:0.5, x2:1, y2:0.5, stop:0 rgb(217, 217, 217), stop:1 rgb(227, 227, 227));\n"
"	border-left-color: qlineargradient(spread:pad, x1:0, y1:0.5, x2:1, y2:0.5, stop:0 rgb(227, 227, 227), stop:1 rgb(217, 217, 217));\n"
"	border-bottom-color: qlineargradient(spread:pad, x1:0.5, y1:1, x2:0.5, y2:0, stop:0 rgb(215, 215, 215), stop:1 rgb(222, 222, 222));\n"
"	border-width: 1px;\n"
"	border-radius: 5px;\n"
"	color: rgb(0,0,0);\n"
"	padding: 2px;\n"
"	background-color: rgb(255,255,255);\n"
"}\n"
"QPushButton::default{\n"
"	border-style: solid;\n"
"	border-top-color: qlineargradient(spread:pad, x1:0.5, y1:1, x2:0.5, y2:0, stop:0 rgb(215, 215, 215), stop:1 rgb(222, 222, 222));\n"
"	border-right-color: qlineargradient(spread:pad, x1:0, y1:0.5, x2:1, y2:0.5, stop:0 rgb(217, 217, 217), stop:1 rgb(227, 227, 227));\n"
"	border-left-color: qlineargradient(spread:pad, x1:0, y1:0.5, x2:1, y2:0.5, stop:0 rgb(227, 227, 227), stop:1 rgb(217, 217, 217));\n"
"	border-bottom-color:"
                        " qlineargradient(spread:pad, x1:0.5, y1:1, x2:0.5, y2:0, stop:0 rgb(215, 215, 215), stop:1 rgb(222, 222, 222));\n"
"	border-width: 1px;\n"
"	border-radius: 5px;\n"
"	color: rgb(0,0,0);\n"
"	padding: 2px;\n"
"	background-color: rgb(255,255,255);\n"
"}\n"
"QPushButton:hover{\n"
"	border-style: solid;\n"
"	border-top-color: qlineargradient(spread:pad, x1:0.5, y1:1, x2:0.5, y2:0, stop:0 rgb(195, 195, 195), stop:1 rgb(222, 222, 222));\n"
"	border-right-color: qlineargradient(spread:pad, x1:0, y1:0.5, x2:1, y2:0.5, stop:0 rgb(197, 197, 197), stop:1 rgb(227, 227, 227));\n"
"	border-left-color: qlineargradient(spread:pad, x1:0, y1:0.5, x2:1, y2:0.5, stop:0 rgb(227, 227, 227), stop:1 rgb(197, 197, 197));\n"
"	border-bottom-color: qlineargradient(spread:pad, x1:0.5, y1:1, x2:0.5, y2:0, stop:0 rgb(195, 195, 195), stop:1 rgb(222, 222, 222));\n"
"	border-width: 1px;\n"
"	border-radius: 5px;\n"
"	color: rgb(0,0,0);\n"
"	padding: 2px;\n"
"	background-color: rgb(255,255,255);\n"
"}\n"
"QPushButton:pressed{\n"
"	border-style: "
                        "solid;\n"
"	border-top-color: qlineargradient(spread:pad, x1:0.5, y1:1, x2:0.5, y2:0, stop:0 rgb(215, 215, 215), stop:1 rgb(222, 222, 222));\n"
"	border-right-color: qlineargradient(spread:pad, x1:0, y1:0.5, x2:1, y2:0.5, stop:0 rgb(217, 217, 217), stop:1 rgb(227, 227, 227));\n"
"	border-left-color: qlineargradient(spread:pad, x1:0, y1:0.5, x2:1, y2:0.5, stop:0 rgb(227, 227, 227), stop:1 rgb(217, 217, 217));\n"
"	border-bottom-color: qlineargradient(spread:pad, x1:0.5, y1:1, x2:0.5, y2:0, stop:0 rgb(215, 215, 215), stop:1 rgb(222, 222, 222));\n"
"	border-width: 1px;\n"
"	border-radius: 5px;\n"
"	color: rgb(0,0,0);\n"
"	padding: 2px;\n"
"	background-color: rgb(142,142,142);\n"
"}\n"
"QPushButton:disabled{\n"
"	border-style: solid;\n"
"	border-top-color: qlineargradient(spread:pad, x1:0.5, y1:1, x2:0.5, y2:0, stop:0 rgb(215, 215, 215), stop:1 rgb(222, 222, 222));\n"
"	border-right-color: qlineargradient(spread:pad, x1:0, y1:0.5, x2:1, y2:0.5, stop:0 rgb(217, 217, 217), stop:1 rgb(227, 227, 227));\n"
"	border-lef"
                        "t-color: qlineargradient(spread:pad, x1:0, y1:0.5, x2:1, y2:0.5, stop:0 rgb(227, 227, 227), stop:1 rgb(217, 217, 217));\n"
"	border-bottom-color: qlineargradient(spread:pad, x1:0.5, y1:1, x2:0.5, y2:0, stop:0 rgb(215, 215, 215), stop:1 rgb(222, 222, 222));\n"
"	border-width: 1px;\n"
"	border-radius: 5px;\n"
"	color: #808086;\n"
"	padding: 2px;\n"
"	background-color:rgb(240, 240, 240);\n"
"}\n"
"QLineEdit {\n"
"	border-width: 1px; border-radius: 4px;\n"
"	border-style: solid;\n"
"	border-color: qlineargradient(spread:pad, x1:0.5, y1:1, x2:0.5, y2:0, stop:0 rgba(0, 113, 255, 255), stop:1 rgba(91, 171, 252, 255));\n"
"}\n"
"QLabel {\n"
"	color: #000000;\n"
"}\n"
"QLCDNumber {\n"
"	color: rgb(0, 113, 255, 255);\n"
"}\n"
"QProgressBar {\n"
"	text-align: center;\n"
"	color: rgb(240, 240, 240);\n"
"	border-width: 1px; \n"
"	border-radius: 10px;\n"
"	border-color: rgb(230, 230, 230);\n"
"	border-style: solid;\n"
"	background-color:rgb(207,207,207);\n"
"}\n"
"QProgressBar::chunk {\n"
"	background-color: qlineargradient"
                        "(spread:pad, x1:0.5, y1:1, x2:0.5, y2:0, stop:0 rgba(49, 147, 250, 255), stop:1 rgba(34, 142, 255, 255));\n"
"	border-radius: 10px;\n"
"}\n"
"QMenuBar {\n"
"	background-color: qlineargradient(spread:pad, x1:0.5, y1:1, x2:0.5, y2:0, stop:0 rgba(207, 209, 207, 255), stop:1 rgba(230, 229, 230, 255));\n"
"}\n"
"QMenuBar::item {\n"
"	color: #000000;\n"
"  	spacing: 3px;\n"
"  	padding: 1px 4px;\n"
"	background-color: qlineargradient(spread:pad, x1:0.5, y1:1, x2:0.5, y2:0, stop:0 rgba(207, 209, 207, 255), stop:1 rgba(230, 229, 230, 255));\n"
"}\n"
"\n"
"QMenuBar::item:selected {\n"
"  	background-color: qlineargradient(spread:pad, x1:0.5, y1:1, x2:0.5, y2:0, stop:0 rgba(0, 113, 255, 255), stop:1 rgba(91, 171, 252, 255));\n"
"	color: #FFFFFF;\n"
"}\n"
"QMenu::item:selected {\n"
"	border-style: solid;\n"
"	border-top-color: transparent;\n"
"	border-right-color: transparent;\n"
"	border-left-color: qlineargradient(spread:pad, x1:0.5, y1:1, x2:0.5, y2:0, stop:0 rgba(0, 113, 255, 255), stop:1 rgba(91, 171, 252, 255));\n"
""
                        "	border-bottom-color: transparent;\n"
"	border-left-width: 2px;\n"
"	color: #000000;\n"
"	padding-left:15px;\n"
"	padding-top:4px;\n"
"	padding-bottom:4px;\n"
"	padding-right:7px;\n"
"}\n"
"QMenu::item {\n"
"	border-style: solid;\n"
"	border-top-color: transparent;\n"
"	border-right-color: transparent;\n"
"	border-left-color: transparent;\n"
"	border-bottom-color: transparent;\n"
"	border-bottom-width: 1px;\n"
"	color: #000000;\n"
"	padding-left:17px;\n"
"	padding-top:4px;\n"
"	padding-bottom:4px;\n"
"	padding-right:7px;\n"
"}\n"
"QTabWidget {\n"
"	color:rgb(0,0,0);\n"
"	background-color:#000000;\n"
"}\n"
"QTabWidget::pane {\n"
"		border-color: rgb(223,223,223);\n"
"		background-color:rgb(226,226,226);\n"
"		border-style: solid;\n"
"		border-width: 2px;\n"
"    	border-radius: 6px;\n"
"}\n"
"QTabBar::tab:first {\n"
"	border-style: solid;\n"
"	border-left-width:1px;\n"
"	border-right-width:0px;\n"
"	border-top-width:1px;\n"
"	border-bottom-width:1px;\n"
"	border-top-color: rgb(209,209,209);\n"
"	border-left-col"
                        "or: qlineargradient(spread:pad, x1:0.5, y1:1, x2:0.5, y2:0, stop:0 rgba(209, 209, 209, 209), stop:1 rgba(229, 229, 229, 229));\n"
"	border-bottom-color: rgb(229,229,229);\n"
"	border-top-left-radius: 4px;\n"
"	border-bottom-left-radius: 4px;\n"
"	color: #000000;\n"
"	padding: 3px;\n"
"	margin-left:0px;\n"
"	background-color: qlineargradient(spread:pad, x1:0.5, y1:1, x2:0.5, y2:0, stop:0 rgba(247, 247, 247, 255), stop:1 rgba(255, 255, 255, 255));\n"
"}\n"
"QTabBar::tab:last {\n"
"	border-style: solid;\n"
"	border-width:1px;\n"
"	border-top-color: rgb(209,209,209);\n"
"	border-left-color: qlineargradient(spread:pad, x1:0.5, y1:1, x2:0.5, y2:0, stop:0 rgba(209, 209, 209, 209), stop:1 rgba(229, 229, 229, 229));\n"
"	border-right-color: qlineargradient(spread:pad, x1:0.5, y1:1, x2:0.5, y2:0, stop:0 rgba(209, 209, 209, 209), stop:1 rgba(229, 229, 229, 229));\n"
"	border-bottom-color: rgb(229,229,229);\n"
"	border-top-right-radius: 4px;\n"
"	border-bottom-right-radius: 4px;\n"
"	color: #000000;\n"
"	padding: 3px;\n"
""
                        "	margin-left:0px;\n"
"	background-color: qlineargradient(spread:pad, x1:0.5, y1:1, x2:0.5, y2:0, stop:0 rgba(247, 247, 247, 255), stop:1 rgba(255, 255, 255, 255));\n"
"}\n"
"QTabBar::tab {\n"
"	border-style: solid;\n"
"	border-top-width:1px;\n"
"	border-bottom-width:1px;\n"
"	border-left-width:1px;\n"
"	border-top-color: rgb(209,209,209);\n"
"	border-left-color: qlineargradient(spread:pad, x1:0.5, y1:1, x2:0.5, y2:0, stop:0 rgba(209, 209, 209, 209), stop:1 rgba(229, 229, 229, 229));\n"
"	border-bottom-color: rgb(229,229,229);\n"
"	color: #000000;\n"
"	padding: 3px;\n"
"	margin-left:0px;\n"
"	background-color: qlineargradient(spread:pad, x1:0.5, y1:1, x2:0.5, y2:0, stop:0 rgba(247, 247, 247, 255), stop:1 rgba(255, 255, 255, 255));\n"
"}\n"
"QTabBar::tab:selected, QTabBar::tab:last:selected, QTabBar::tab:hover {\n"
"  	border-style: solid;\n"
"  	border-left-width:1px;\n"
"	border-right-color: transparent;\n"
"	border-top-color: rgb(209,209,209);\n"
"	border-left-color: qlineargradient(spread:pad, x1:0.5, y1:1, "
                        "x2:0.5, y2:0, stop:0 rgba(209, 209, 209, 209), stop:1 rgba(229, 229, 229, 229));\n"
"	border-bottom-color: rgb(229,229,229);\n"
"	color: #FFFFFF;\n"
"	padding: 3px;\n"
"	margin-left:0px;\n"
"	background-color: qlineargradient(spread:pad, x1:0.5, y1:1, x2:0.5, y2:0, stop:0 rgba(0, 113, 255, 255), stop:1 rgba(91, 171, 252, 255));\n"
"}\n"
"\n"
"QTabBar::tab:selected, QTabBar::tab:first:selected, QTabBar::tab:hover {\n"
"  	border-style: solid;\n"
"  	border-left-width:1px;\n"
"  	border-bottom-width:1px;\n"
"  	border-top-width:1px;\n"
"	border-right-color: transparent;\n"
"	border-top-color: rgb(209,209,209);\n"
"	border-left-color: qlineargradient(spread:pad, x1:0.5, y1:1, x2:0.5, y2:0, stop:0 rgba(209, 209, 209, 209), stop:1 rgba(229, 229, 229, 229));\n"
"	border-bottom-color: rgb(229,229,229);\n"
"	color: #FFFFFF;\n"
"	padding: 3px;\n"
"	margin-left:0px;\n"
"	background-color: qlineargradient(spread:pad, x1:0.5, y1:1, x2:0.5, y2:0, stop:0 rgba(0, 113, 255, 255), stop:1 rgba(91, 171, 252, 255));\n"
"}\n"
"\n"
""
                        "QCheckBox {\n"
"	color: #000000;\n"
"	padding: 2px;\n"
"}\n"
"QCheckBox:disabled {\n"
"	color: #808086;\n"
"	padding: 2px;\n"
"}\n"
"\n"
"QCheckBox:hover {\n"
"	border-radius:4px;\n"
"	border-style:solid;\n"
"	padding-left: 1px;\n"
"	padding-right: 1px;\n"
"	padding-bottom: 1px;\n"
"	padding-top: 1px;\n"
"	border-width:1px;\n"
"	border-color: transparent;\n"
"}\n"
"QCheckBox::indicator:checked {\n"
"\n"
"	height: 10px;\n"
"	width: 10px;\n"
"	border-style:solid;\n"
"	border-width: 1px;\n"
"	border-color: qlineargradient(spread:pad, x1:0.5, y1:1, x2:0.5, y2:0, stop:0 rgba(0, 113, 255, 255), stop:1 rgba(91, 171, 252, 255));\n"
"	color: #000000;\n"
"	background-color: qlineargradient(spread:pad, x1:0.5, y1:1, x2:0.5, y2:0, stop:0 rgba(0, 113, 255, 255), stop:1 rgba(91, 171, 252, 255));\n"
"}\n"
"QCheckBox::indicator:unchecked {\n"
"\n"
"	height: 10px;\n"
"	width: 10px;\n"
"	border-style:solid;\n"
"	border-width: 1px;\n"
"	border-color: qlineargradient(spread:pad, x1:0.5, y1:1, x2:0.5, y2:0, stop:0 rgba(0, 113, 255"
                        ", 255), stop:1 rgba(91, 171, 252, 255));\n"
"	color: #000000;\n"
"}\n"
"QRadioButton {\n"
"	color: 000000;\n"
"	padding: 1px;\n"
"}\n"
"QRadioButton::indicator:checked {\n"
"	height: 10px;\n"
"	width: 10px;\n"
"	border-style:solid;\n"
"	border-radius:5px;\n"
"	border-width: 1px;\n"
"	border-color: qlineargradient(spread:pad, x1:0.5, y1:1, x2:0.5, y2:0, stop:0 rgba(0, 113, 255, 255), stop:1 rgba(91, 171, 252, 255));\n"
"	color: #a9b7c6;\n"
"	background-color: qlineargradient(spread:pad, x1:0.5, y1:1, x2:0.5, y2:0, stop:0 rgba(0, 113, 255, 255), stop:1 rgba(91, 171, 252, 255));\n"
"}\n"
"QRadioButton::indicator:!checked {\n"
"	height: 10px;\n"
"	width: 10px;\n"
"	border-style:solid;\n"
"	border-radius:5px;\n"
"	border-width: 1px;\n"
"	border-color: qlineargradient(spread:pad, x1:0.5, y1:1, x2:0.5, y2:0, stop:0 rgba(0, 113, 255, 255), stop:1 rgba(91, 171, 252, 255));\n"
"	color: #a9b7c6;\n"
"	background-color: transparent;\n"
"}\n"
"QStatusBar {\n"
"	color:#027f7f;\n"
"}\n"
"QSpinBox {\n"
"	border-style: solid;\n"
""
                        "	border-width: 1px;\n"
"	border-color: qlineargradient(spread:pad, x1:0.5, y1:1, x2:0.5, y2:0, stop:0 rgba(0, 113, 255, 255), stop:1 rgba(91, 171, 252, 255));\n"
"}\n"
"QDoubleSpinBox {\n"
"	border-style: solid;\n"
"	border-width: 1px;\n"
"	border-color: qlineargradient(spread:pad, x1:0.5, y1:1, x2:0.5, y2:0, stop:0 rgba(0, 113, 255, 255), stop:1 rgba(91, 171, 252, 255));\n"
"}\n"
"QTimeEdit {\n"
"	border-style: solid;\n"
"	border-width: 1px;\n"
"	border-color: qlineargradient(spread:pad, x1:0.5, y1:1, x2:0.5, y2:0, stop:0 rgba(0, 113, 255, 255), stop:1 rgba(91, 171, 252, 255));\n"
"}\n"
"QDateTimeEdit {\n"
"	border-style: solid;\n"
"	border-width: 1px;\n"
"	border-color: qlineargradient(spread:pad, x1:0.5, y1:1, x2:0.5, y2:0, stop:0 rgba(0, 113, 255, 255), stop:1 rgba(91, 171, 252, 255));\n"
"}\n"
"QDateEdit {\n"
"	border-style: solid;\n"
"	border-width: 1px;\n"
"	border-color: qlineargradient(spread:pad, x1:0.5, y1:1, x2:0.5, y2:0, stop:0 rgba(0, 113, 255, 255), stop:1 rgba(91, 171, 252, 255));\n"
"}\n"
"\n"
""
                        "QToolBox {\n"
"	color: #a9b7c6;\n"
"	background-color:#000000;\n"
"}\n"
"QToolBox::tab {\n"
"	color: #a9b7c6;\n"
"	background-color:#000000;\n"
"}\n"
"QToolBox::tab:selected {\n"
"	color: #FFFFFF;\n"
"	background-color:#000000;\n"
"}\n"
"QScrollArea {\n"
"	color: #FFFFFF;\n"
"	background-color:#000000;\n"
"}\n"
"QSlider::groove:horizontal {\n"
"	height: 5px;\n"
"	background-color: qlineargradient(spread:pad, x1:0.5, y1:1, x2:0.5, y2:0, stop:0 rgba(49, 147, 250, 255), stop:1 rgba(34, 142, 255, 255));\n"
"}\n"
"QSlider::groove:vertical {\n"
"	width: 5px;\n"
"	background-color: qlineargradient(spread:pad, x1:0.5, y1:1, x2:0.5, y2:0, stop:0 rgba(49, 147, 250, 255), stop:1 rgba(34, 142, 255, 255));\n"
"}\n"
"QSlider::handle:horizontal {\n"
"	background: rgb(253,253,253);\n"
"	border-style: solid;\n"
"	border-width: 1px;\n"
"	border-color: rgb(207,207,207);\n"
"	width: 12px;\n"
"	margin: -5px 0;\n"
"	border-radius: 7px;\n"
"}\n"
"QSlider::handle:vertical {\n"
"	background: rgb(253,253,253);\n"
"	border-style: solid;"
                        "\n"
"	border-width: 1px;\n"
"	border-color: rgb(207,207,207);\n"
"	height: 12px;\n"
"	margin: 0 -5px;\n"
"	border-radius: 7px;\n"
"}\n"
"QSlider::add-page:horizontal {\n"
"    background: rgb(181,181,181);\n"
"}\n"
"QSlider::add-page:vertical {\n"
"    background: rgb(181,181,181);\n"
"}\n"
"QSlider::sub-page:horizontal {\n"
"    background-color: qlineargradient(spread:pad, x1:0.5, y1:1, x2:0.5, y2:0, stop:0 rgba(49, 147, 250, 255), stop:1 rgba(34, 142, 255, 255));\n"
"}\n"
"QSlider::sub-page:vertical {\n"
"    background-color: qlineargradient(spread:pad, y1:0.5, x1:1, y2:0.5, x2:0, stop:0 rgba(49, 147, 250, 255), stop:1 rgba(34, 142, 255, 255));\n"
"}\n"
"QScrollBar:horizontal {\n"
"	max-height: 20px;\n"
"	border: 1px transparent grey;\n"
"	margin: 0px 20px 0px 20px;\n"
"}\n"
"QScrollBar:vertical {\n"
"	max-width: 20px;\n"
"	border: 1px transparent grey;\n"
"	margin: 20px 0px 20px 0px;\n"
"}\n"
"QScrollBar::handle:horizontal {\n"
"	background: rgb(253,253,253);\n"
"	border-style: solid;\n"
"	border-width: 1"
                        "px;\n"
"	border-color: rgb(207,207,207);\n"
"	border-radius: 7px;\n"
"	min-width: 25px;\n"
"}\n"
"QScrollBar::handle:horizontal:hover {\n"
"	background: rgb(253,253,253);\n"
"	border-style: solid;\n"
"	border-width: 1px;\n"
"	border-color: rgb(147, 200, 200);\n"
"	border-radius: 7px;\n"
"	min-width: 25px;\n"
"}\n"
"QScrollBar::handle:vertical {\n"
"	background: rgb(253,253,253);\n"
"	border-style: solid;\n"
"	border-width: 1px;\n"
"	border-color: rgb(207,207,207);\n"
"	border-radius: 7px;\n"
"	min-height: 25px;\n"
"}\n"
"QScrollBar::handle:vertical:hover {\n"
"	background: rgb(253,253,253);\n"
"	border-style: solid;\n"
"	border-width: 1px;\n"
"	border-color: rgb(147, 200, 200);\n"
"	border-radius: 7px;\n"
"	min-height: 25px;\n"
"}\n"
"QScrollBar::add-line:horizontal {\n"
"   border: 2px transparent grey;\n"
"   border-top-right-radius: 7px;\n"
"   border-bottom-right-radius: 7px;\n"
"   background: rgba(34, 142, 255, 255);\n"
"   width: 20px;\n"
"   subcontrol-position: right;\n"
"   subcontrol-origin: margin;"
                        "\n"
"}\n"
"QScrollBar::add-line:horizontal:pressed {\n"
"   border: 2px transparent grey;\n"
"   border-top-right-radius: 7px;\n"
"   border-bottom-right-radius: 7px;\n"
"   background: rgb(181,181,181);\n"
"   width: 20px;\n"
"   subcontrol-position: right;\n"
"   subcontrol-origin: margin;\n"
"}\n"
"QScrollBar::add-line:vertical {\n"
"   border: 2px transparent grey;\n"
"   border-bottom-left-radius: 7px;\n"
"   border-bottom-right-radius: 7px;\n"
"   background: rgba(34, 142, 255, 255);\n"
"   height: 20px;\n"
"   subcontrol-position: bottom;\n"
"   subcontrol-origin: margin;\n"
"}\n"
"QScrollBar::add-line:vertical:pressed {\n"
"   border: 2px transparent grey;\n"
"   border-bottom-left-radius: 7px;\n"
"   border-bottom-right-radius: 7px;\n"
"   background: rgb(181,181,181);\n"
"   height: 20px;\n"
"   subcontrol-position: bottom;\n"
"   subcontrol-origin: margin;\n"
"}\n"
"QScrollBar::sub-line:horizontal {\n"
"   border: 2px transparent grey;\n"
"   border-top-left-radius: 7px;\n"
"   border-bottom-left-ra"
                        "dius: 7px;\n"
"   background: rgba(34, 142, 255, 255);\n"
"   width: 20px;\n"
"   subcontrol-position: left;\n"
"   subcontrol-origin: margin;\n"
"}\n"
"QScrollBar::sub-line:horizontal:pressed {\n"
"   border: 2px transparent grey;\n"
"   border-top-left-radius: 7px;\n"
"   border-bottom-left-radius: 7px;\n"
"   background: rgb(181,181,181);\n"
"   width: 20px;\n"
"   subcontrol-position: left;\n"
"   subcontrol-origin: margin;\n"
"}\n"
"QScrollBar::sub-line:vertical {\n"
"   border: 2px transparent grey;\n"
"   border-top-left-radius: 7px;\n"
"   border-top-right-radius: 7px;\n"
"   background: rgba(34, 142, 255, 255);\n"
"   height: 20px;\n"
"   subcontrol-position: top;\n"
"   subcontrol-origin: margin;\n"
"}\n"
"QScrollBar::sub-line:vertical:pressed {\n"
"   border: 2px transparent grey;\n"
"   border-top-left-radius: 7px;\n"
"   border-top-right-radius: 7px;\n"
"   background: rgb(181,181,181);\n"
"   height: 20px;\n"
"   subcontrol-position: top;\n"
"   subcontrol-origin: margin;\n"
"}\n"
"QScrollBar::le"
                        "ft-arrow:horizontal {\n"
"   border: 1px transparent grey;\n"
"   border-top-left-radius: 3px;\n"
"   border-bottom-left-radius: 3px;\n"
"   width: 6px;\n"
"   height: 6px;\n"
"   background: white;\n"
"}\n"
"QScrollBar::right-arrow:horizontal {\n"
"   border: 1px transparent grey;\n"
"   border-top-right-radius: 3px;\n"
"   border-bottom-right-radius: 3px;\n"
"   width: 6px;\n"
"   height: 6px;\n"
"   background: white;\n"
"}\n"
"QScrollBar::up-arrow:vertical {\n"
"   border: 1px transparent grey;\n"
"   border-top-left-radius: 3px;\n"
"   border-top-right-radius: 3px;\n"
"   width: 6px;\n"
"   height: 6px;\n"
"   background: white;\n"
"}\n"
"QScrollBar::down-arrow:vertical {\n"
"   border: 1px transparent grey;\n"
"   border-bottom-left-radius: 3px;\n"
"   border-bottom-right-radius: 3px;\n"
"   width: 6px;\n"
"   height: 6px;\n"
"   background: white;\n"
"}\n"
"QScrollBar::add-page:horizontal, QScrollBar::sub-page:horizontal {\n"
"   background: none;\n"
"}\n"
"QScrollBar::add-page:vertical, QScrollBar::sub"
                        "-page:vertical {\n"
"   background: none;\n"
"}\n"
"\n"
"\n"
""));
        centralwidget = new QWidget(OperatorWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_18 = new QGridLayout(centralwidget);
        gridLayout_18->setObjectName(QString::fromUtf8("gridLayout_18"));
        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 1069, 740));
        gridLayout_17 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_17->setObjectName(QString::fromUtf8("gridLayout_17"));
        frame_2 = new QFrame(scrollAreaWidgetContents);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout_11 = new QGridLayout(frame_2);
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_13, 0, 1, 1, 3);

        Curtimelabel = new QLabel(frame_2);
        Curtimelabel->setObjectName(QString::fromUtf8("Curtimelabel"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Curtimelabel->sizePolicy().hasHeightForWidth());
        Curtimelabel->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        Curtimelabel->setFont(font);
        Curtimelabel->setFrameShape(QFrame::Panel);

        gridLayout_3->addWidget(Curtimelabel, 0, 0, 1, 1);


        gridLayout_11->addLayout(gridLayout_3, 0, 0, 1, 1);

        frame_5 = new QFrame(frame_2);
        frame_5->setObjectName(QString::fromUtf8("frame_5"));
        frame_5->setFrameShape(QFrame::Box);
        frame_5->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame_5);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        gridLayout_5 = new QGridLayout();
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        label_9 = new QLabel(frame_5);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        QFont font1;
        font1.setPointSize(10);
        label_9->setFont(font1);

        horizontalLayout_2->addWidget(label_9);

        label_10 = new QLabel(frame_5);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setFont(font);
        label_10->setStyleSheet(QString::fromUtf8("color : rgb(255, 0, 0);"));
        label_10->setFrameShape(QFrame::Panel);
        label_10->setFrameShadow(QFrame::Plain);

        horizontalLayout_2->addWidget(label_10);

        label_11 = new QLabel(frame_5);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setFont(font1);

        horizontalLayout_2->addWidget(label_11);

        label_12 = new QLabel(frame_5);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setFont(font);
        label_12->setStyleSheet(QString::fromUtf8("color : rgb(255, 0, 0);"));
        label_12->setFrameShape(QFrame::Panel);
        label_12->setFrameShadow(QFrame::Plain);

        horizontalLayout_2->addWidget(label_12);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);


        gridLayout_5->addLayout(horizontalLayout_2, 3, 0, 1, 1);

        label_4 = new QLabel(frame_5);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy1);

        gridLayout_5->addWidget(label_4, 0, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_8);

        label_5 = new QLabel(frame_5);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font1);

        horizontalLayout_4->addWidget(label_5);

        label_6 = new QLabel(frame_5);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font);
        label_6->setFrameShape(QFrame::Panel);

        horizontalLayout_4->addWidget(label_6);

        label_7 = new QLabel(frame_5);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font1);

        horizontalLayout_4->addWidget(label_7);

        label_8 = new QLabel(frame_5);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font);
        label_8->setFrameShape(QFrame::Panel);

        horizontalLayout_4->addWidget(label_8);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_9);


        gridLayout_5->addLayout(horizontalLayout_4, 1, 0, 1, 1);

        WhiteSpectorPic = new QLabel(frame_5);
        WhiteSpectorPic->setObjectName(QString::fromUtf8("WhiteSpectorPic"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(WhiteSpectorPic->sizePolicy().hasHeightForWidth());
        WhiteSpectorPic->setSizePolicy(sizePolicy2);
        WhiteSpectorPic->setFrameShape(QFrame::NoFrame);
        WhiteSpectorPic->setPixmap(QPixmap(QString::fromUtf8(":/pictures/img/WhiteSpectorPic.png")));

        gridLayout_5->addWidget(WhiteSpectorPic, 2, 0, 1, 1);


        verticalLayout_2->addLayout(gridLayout_5);

        verticalSpacer_3 = new QSpacerItem(518, 13, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_10);

        label_14 = new QLabel(frame_5);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setFont(font1);

        horizontalLayout_3->addWidget(label_14);

        label_15 = new QLabel(frame_5);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setFont(font);
        label_15->setFrameShape(QFrame::Panel);

        horizontalLayout_3->addWidget(label_15);

        label_16 = new QLabel(frame_5);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setFont(font1);

        horizontalLayout_3->addWidget(label_16);

        label_17 = new QLabel(frame_5);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setFont(font);
        label_17->setFrameShape(QFrame::Panel);

        horizontalLayout_3->addWidget(label_17);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_11);


        gridLayout_4->addLayout(horizontalLayout_3, 1, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer, 4, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_6);

        label_19 = new QLabel(frame_5);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setFont(font1);

        horizontalLayout->addWidget(label_19);

        label_20 = new QLabel(frame_5);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setFont(font);
        label_20->setStyleSheet(QString::fromUtf8("color : rgb(255, 0, 0);"));
        label_20->setFrameShape(QFrame::Panel);

        horizontalLayout->addWidget(label_20);

        label_21 = new QLabel(frame_5);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setFont(font1);

        horizontalLayout->addWidget(label_21);

        label_22 = new QLabel(frame_5);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setFont(font);
        label_22->setStyleSheet(QString::fromUtf8("color : rgb(255, 0, 0);"));
        label_22->setFrameShape(QFrame::Panel);

        horizontalLayout->addWidget(label_22);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_7);


        gridLayout_4->addLayout(horizontalLayout, 3, 0, 1, 1);

        label_13 = new QLabel(frame_5);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout_4->addWidget(label_13, 0, 0, 1, 1);

        InfraSpectorPic = new QLabel(frame_5);
        InfraSpectorPic->setObjectName(QString::fromUtf8("InfraSpectorPic"));
        sizePolicy2.setHeightForWidth(InfraSpectorPic->sizePolicy().hasHeightForWidth());
        InfraSpectorPic->setSizePolicy(sizePolicy2);
        InfraSpectorPic->setFrameShape(QFrame::NoFrame);
        InfraSpectorPic->setPixmap(QPixmap(QString::fromUtf8(":/pictures/img/InfraSpectorPic.png")));

        gridLayout_4->addWidget(InfraSpectorPic, 2, 0, 1, 1);


        verticalLayout_2->addLayout(gridLayout_4);

        verticalSpacer_5 = new QSpacerItem(518, 23, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_5);


        gridLayout->addLayout(verticalLayout_2, 0, 0, 1, 1);


        gridLayout_11->addWidget(frame_5, 1, 0, 1, 1);


        gridLayout_17->addWidget(frame_2, 0, 0, 1, 1);

        frame_4 = new QFrame(scrollAreaWidgetContents);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        gridLayout_16 = new QGridLayout(frame_4);
        gridLayout_16->setObjectName(QString::fromUtf8("gridLayout_16"));
        frame_7 = new QFrame(frame_4);
        frame_7->setObjectName(QString::fromUtf8("frame_7"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(frame_7->sizePolicy().hasHeightForWidth());
        frame_7->setSizePolicy(sizePolicy3);
        frame_7->setFrameShape(QFrame::StyledPanel);
        frame_7->setFrameShadow(QFrame::Raised);
        gridLayout_15 = new QGridLayout(frame_7);
        gridLayout_15->setObjectName(QString::fromUtf8("gridLayout_15"));
        gridLayout_7 = new QGridLayout();
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        gridLayout_7->setSizeConstraint(QLayout::SetFixedSize);
        gridLayout_6 = new QGridLayout();
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        horizontalSpacer_12 = new QSpacerItem(148, 18, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_12, 0, 1, 1, 1);

        horizontalSpacer_16 = new QSpacerItem(118, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_16, 2, 1, 1, 1);

        BankName = new QLabel(frame_7);
        BankName->setObjectName(QString::fromUtf8("BankName"));
        sizePolicy3.setHeightForWidth(BankName->sizePolicy().hasHeightForWidth());
        BankName->setSizePolicy(sizePolicy3);
        QFont font2;
        font2.setPointSize(14);
        BankName->setFont(font2);

        gridLayout_6->addWidget(BankName, 0, 0, 1, 1);

        UnitNum = new QLabel(frame_7);
        UnitNum->setObjectName(QString::fromUtf8("UnitNum"));
        sizePolicy3.setHeightForWidth(UnitNum->sizePolicy().hasHeightForWidth());
        UnitNum->setSizePolicy(sizePolicy3);
        QFont font3;
        font3.setPointSize(14);
        font3.setBold(false);
        font3.setWeight(50);
        UnitNum->setFont(font3);

        gridLayout_6->addWidget(UnitNum, 2, 0, 1, 1);


        gridLayout_7->addLayout(gridLayout_6, 0, 0, 1, 1);

        gridLayout_9 = new QGridLayout();
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        YesConnectionPic = new QLabel(frame_7);
        YesConnectionPic->setObjectName(QString::fromUtf8("YesConnectionPic"));
        YesConnectionPic->setStyleSheet(QString::fromUtf8("Qlabel {\n"
"	border-width: 10px;\n"
"	border-style: solid;\n"
"	border-color: qlineargradient(spread:pad, x1:0.5, y1:1, x2:0.5, y2:0, stop:0 rgba(0, 113, 255, 255), stop:1 rgba(91, 171, 252, 255));\n"
"}"));
        YesConnectionPic->setFrameShape(QFrame::NoFrame);
        YesConnectionPic->setFrameShadow(QFrame::Plain);
        YesConnectionPic->setLineWidth(1);
        YesConnectionPic->setMidLineWidth(0);
        YesConnectionPic->setPixmap(QPixmap(QString::fromUtf8("img/NoConnection.png")));

        gridLayout_9->addWidget(YesConnectionPic, 0, 1, 1, 1);

        NoConnectionPic = new QLabel(frame_7);
        NoConnectionPic->setObjectName(QString::fromUtf8("NoConnectionPic"));
        NoConnectionPic->setStyleSheet(QString::fromUtf8("Qlabel {\n"
"	border-width: 10px;\n"
"	border-style: solid;\n"
"	border-color: qlineargradient(spread:pad, x1:0.5, y1:1, x2:0.5, y2:0, stop:0 rgba(0, 113, 255, 255), stop:1 rgba(91, 171, 252, 255));\n"
"}"));
        NoConnectionPic->setFrameShape(QFrame::NoFrame);
        NoConnectionPic->setPixmap(QPixmap(QString::fromUtf8("img/YesConnection.png")));

        gridLayout_9->addWidget(NoConnectionPic, 0, 0, 1, 1);


        gridLayout_7->addLayout(gridLayout_9, 0, 1, 1, 1);


        gridLayout_15->addLayout(gridLayout_7, 0, 0, 1, 1);


        gridLayout_16->addWidget(frame_7, 0, 0, 1, 1);

        frame_8 = new QFrame(frame_4);
        frame_8->setObjectName(QString::fromUtf8("frame_8"));
        sizePolicy3.setHeightForWidth(frame_8->sizePolicy().hasHeightForWidth());
        frame_8->setSizePolicy(sizePolicy3);
        frame_8->setFrameShape(QFrame::StyledPanel);
        frame_8->setFrameShadow(QFrame::Raised);
        gridLayout_12 = new QGridLayout(frame_8);
        gridLayout_12->setObjectName(QString::fromUtf8("gridLayout_12"));
        gridLayout_14 = new QGridLayout();
        gridLayout_14->setObjectName(QString::fromUtf8("gridLayout_14"));
        horizontalSpacer_20 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_14->addItem(horizontalSpacer_20, 0, 0, 1, 1);

        frame_6 = new QFrame(frame_8);
        frame_6->setObjectName(QString::fromUtf8("frame_6"));
        sizePolicy3.setHeightForWidth(frame_6->sizePolicy().hasHeightForWidth());
        frame_6->setSizePolicy(sizePolicy3);
        frame_6->setFrameShape(QFrame::Panel);
        frame_6->setFrameShadow(QFrame::Raised);
        gridLayout_13 = new QGridLayout(frame_6);
        gridLayout_13->setObjectName(QString::fromUtf8("gridLayout_13"));
        gridLayout_8 = new QGridLayout();
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        groupBox = new QGroupBox(frame_6);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        groupBox->setMinimumSize(QSize(400, 0));
        groupBox->setMaximumSize(QSize(550, 300));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalSpacer_15 = new QSpacerItem(90, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_15, 0, 3, 2, 1);

        horizontalSpacer_14 = new QSpacerItem(90, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_14, 0, 0, 2, 1);

        gridLayout_10 = new QGridLayout();
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        horizontalSpacer_3 = new QSpacerItem(74, 16, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_10->addItem(horizontalSpacer_3, 0, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(74, 16, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_10->addItem(horizontalSpacer_2, 0, 3, 1, 1);

        pushButton_6 = new QPushButton(groupBox);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setEnabled(true);
        sizePolicy.setHeightForWidth(pushButton_6->sizePolicy().hasHeightForWidth());
        pushButton_6->setSizePolicy(sizePolicy);
        pushButton_6->setMinimumSize(QSize(120, 20));
        pushButton_6->setFont(font1);

        gridLayout_10->addWidget(pushButton_6, 2, 2, 1, 1);

        DestroyButton = new QPushButton(groupBox);
        DestroyButton->setObjectName(QString::fromUtf8("DestroyButton"));
        DestroyButton->setEnabled(false);
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(DestroyButton->sizePolicy().hasHeightForWidth());
        DestroyButton->setSizePolicy(sizePolicy4);
        DestroyButton->setMinimumSize(QSize(180, 30));
        QFont font4;
        font4.setPointSize(12);
        DestroyButton->setFont(font4);

        gridLayout_10->addWidget(DestroyButton, 0, 1, 1, 2);

        pushButton_5 = new QPushButton(groupBox);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setEnabled(true);
        sizePolicy.setHeightForWidth(pushButton_5->sizePolicy().hasHeightForWidth());
        pushButton_5->setSizePolicy(sizePolicy);
        pushButton_5->setMinimumSize(QSize(90, 20));
        pushButton_5->setFont(font1);

        gridLayout_10->addWidget(pushButton_5, 2, 1, 1, 1);

        CashRollBack = new QPushButton(groupBox);
        CashRollBack->setObjectName(QString::fromUtf8("CashRollBack"));
        CashRollBack->setEnabled(true);
        sizePolicy4.setHeightForWidth(CashRollBack->sizePolicy().hasHeightForWidth());
        CashRollBack->setSizePolicy(sizePolicy4);
        CashRollBack->setMinimumSize(QSize(120, 20));
        CashRollBack->setFont(font1);

        gridLayout_10->addWidget(CashRollBack, 1, 1, 1, 2);


        gridLayout_2->addLayout(gridLayout_10, 3, 0, 1, 4);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_24 = new QLabel(groupBox);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        sizePolicy4.setHeightForWidth(label_24->sizePolicy().hasHeightForWidth());
        label_24->setSizePolicy(sizePolicy4);
        label_24->setMinimumSize(QSize(0, 20));
        label_24->setFont(font1);

        verticalLayout_3->addWidget(label_24);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalSpacer_18 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_18);

        label_23 = new QLabel(groupBox);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        QSizePolicy sizePolicy5(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(label_23->sizePolicy().hasHeightForWidth());
        label_23->setSizePolicy(sizePolicy5);
        label_23->setMinimumSize(QSize(0, 20));
        label_23->setMaximumSize(QSize(16777215, 20));
        label_23->setFont(font1);
        label_23->setStyleSheet(QString::fromUtf8("color : rgb(255, 0, 0);"));

        horizontalLayout_5->addWidget(label_23);

        lineEdit_2 = new QLineEdit(groupBox);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        QSizePolicy sizePolicy6(QSizePolicy::Expanding, QSizePolicy::Ignored);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(lineEdit_2->sizePolicy().hasHeightForWidth());
        lineEdit_2->setSizePolicy(sizePolicy6);
        lineEdit_2->setMinimumSize(QSize(75, 20));
        lineEdit_2->setMaximumSize(QSize(75, 20));
        lineEdit_2->setFont(font1);
        lineEdit_2->setStyleSheet(QString::fromUtf8("color : rgb(255, 0, 0);"));
        lineEdit_2->setMaxLength(10);
        lineEdit_2->setCursorPosition(10);

        horizontalLayout_5->addWidget(lineEdit_2);

        horizontalSpacer_17 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_17);


        verticalLayout_3->addLayout(horizontalLayout_5);


        gridLayout_2->addLayout(verticalLayout_3, 2, 0, 1, 4);

        editButton = new QPushButton(groupBox);
        editButton->setObjectName(QString::fromUtf8("editButton"));
        editButton->setEnabled(false);
        editButton->setFont(font1);

        gridLayout_2->addWidget(editButton, 1, 1, 1, 2);

        StartButton = new QPushButton(groupBox);
        StartButton->setObjectName(QString::fromUtf8("StartButton"));
        StartButton->setMaximumSize(QSize(19999, 16777215));
        StartButton->setFont(font2);
        StartButton->setAutoDefault(false);
        StartButton->setFlat(false);

        gridLayout_2->addWidget(StartButton, 0, 1, 1, 2);


        gridLayout_8->addWidget(groupBox, 0, 0, 1, 1);


        gridLayout_13->addLayout(gridLayout_8, 0, 0, 1, 1);


        gridLayout_14->addWidget(frame_6, 0, 1, 1, 1);

        horizontalSpacer_21 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_14->addItem(horizontalSpacer_21, 0, 2, 1, 1);


        gridLayout_12->addLayout(gridLayout_14, 0, 0, 1, 1);


        gridLayout_16->addWidget(frame_8, 1, 0, 1, 1);

        frame = new QFrame(frame_4);
        frame->setObjectName(QString::fromUtf8("frame"));
        sizePolicy1.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy1);
        frame->setMinimumSize(QSize(0, 0));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Raised);

        gridLayout_16->addWidget(frame, 2, 0, 1, 1);


        gridLayout_17->addWidget(frame_4, 0, 1, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout_18->addWidget(scrollArea, 0, 0, 1, 1);

        OperatorWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(OperatorWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1089, 19));
        OperatorWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(OperatorWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        OperatorWindow->setStatusBar(statusbar);

        retranslateUi(OperatorWindow);

        DestroyButton->setDefault(false);
        StartButton->setDefault(true);


        QMetaObject::connectSlotsByName(OperatorWindow);
    } // setupUi

    void retranslateUi(QMainWindow *OperatorWindow)
    {
        OperatorWindow->setWindowTitle(QApplication::translate("OperatorWindow", "MainWindow", nullptr));
        Curtimelabel->setText(QApplication::translate("OperatorWindow", "<html><head/><body><p>09.05.2019 12:47:15</p></body></html>", nullptr));
        label_9->setText(QApplication::translate("OperatorWindow", "<html><head/><body><p><span style=\" color:#ff0000;\">\320\241\320\265\321\200\320\270\320\271\320\275\321\213\320\271 \320\275\320\276\320\274\320\265\321\200:</span></p></body></html>", nullptr));
        label_10->setText(QApplication::translate("OperatorWindow", "<html><head/><body><p><span style=\" font-weight:400; color:#ff0000;\">\320\240\320\240 0000000</span></p></body></html>", nullptr));
        label_11->setText(QApplication::translate("OperatorWindow", "<html><head/><body><p><span style=\" color:#ff0000;\">\320\235\320\276\320\274\320\270\320\275\320\260\320\273:</span></p></body></html>", nullptr));
        label_12->setText(QApplication::translate("OperatorWindow", "<html><head/><body><p><span style=\" color:#ff0000;\">5000</span></p></body></html>", nullptr));
        label_4->setText(QApplication::translate("OperatorWindow", "<html><head/><body><p align=\"center\">\320\221\320\260\320\275\320\272\320\275\320\276\321\202\320\260 \320\262 \320\261\320\265\320\273\320\276\320\274 \321\201\320\277\320\265\320\272\321\202\321\200\320\265</p></body></html>", nullptr));
        label_5->setText(QApplication::translate("OperatorWindow", "\320\241\320\265\321\200\320\270\320\271\320\275\321\213\320\271 \320\275\320\276\320\274\320\265\321\200:", nullptr));
        label_6->setText(QApplication::translate("OperatorWindow", "\320\240\320\240 0000000", nullptr));
        label_7->setText(QApplication::translate("OperatorWindow", "\320\235\320\276\320\274\320\270\320\275\320\260\320\273:", nullptr));
        label_8->setText(QApplication::translate("OperatorWindow", "5000", nullptr));
        WhiteSpectorPic->setText(QString());
        label_14->setText(QApplication::translate("OperatorWindow", "\320\241\320\265\321\200\320\270\320\271\320\275\321\213\320\271 \320\275\320\276\320\274\320\265\321\200:", nullptr));
        label_15->setText(QApplication::translate("OperatorWindow", "\320\240\320\240 0000000", nullptr));
        label_16->setText(QApplication::translate("OperatorWindow", "\320\235\320\276\320\274\320\270\320\275\320\260\320\273:", nullptr));
        label_17->setText(QApplication::translate("OperatorWindow", "5000", nullptr));
        label_19->setText(QApplication::translate("OperatorWindow", "<html><head/><body><p><span style=\" color:#ff0000;\">\320\241\320\265\321\200\320\270\320\271\320\275\321\213\320\271 \320\275\320\276\320\274\320\265\321\200:</span></p></body></html>", nullptr));
        label_20->setText(QApplication::translate("OperatorWindow", "<html><head/><body><p><span style=\" font-weight:400; color:#ff0000;\">\320\240\320\240 0000000</span></p></body></html>", nullptr));
        label_21->setText(QApplication::translate("OperatorWindow", "<html><head/><body><p><span style=\" color:#ff0000;\">\320\235\320\276\320\274\320\270\320\275\320\260\320\273:</span></p></body></html>", nullptr));
        label_22->setText(QApplication::translate("OperatorWindow", "<html><head/><body><p><span style=\" color:#ff0000;\">5000</span></p></body></html>", nullptr));
        label_13->setText(QApplication::translate("OperatorWindow", "<html><head/><body><p align=\"center\">\320\221\320\260\320\275\320\272\320\275\320\276\321\202\320\260 \320\262 \320\270\320\275\321\204\321\200\320\260\320\272\321\200\320\260\321\201\320\275\320\276\320\274 \321\201\320\277\320\265\320\272\321\202\321\200\320\265</p></body></html>", nullptr));
        InfraSpectorPic->setText(QString());
        BankName->setText(QApplication::translate("OperatorWindow", "TextLabel", nullptr));
        UnitNum->setText(QApplication::translate("OperatorWindow", "TextLabel", nullptr));
        YesConnectionPic->setText(QString());
        NoConnectionPic->setText(QString());
        groupBox->setTitle(QApplication::translate("OperatorWindow", "\320\237\320\260\320\275\320\265\320\273\321\214 \320\276\320\277\320\265\321\200\320\260\321\202\320\276\321\200\320\260", nullptr));
        pushButton_6->setText(QApplication::translate("OperatorWindow", "\320\222\321\213\321\205\320\276\320\264", nullptr));
        DestroyButton->setText(QApplication::translate("OperatorWindow", " \320\243\320\275\320\270\321\207\321\202\320\276\320\266\320\270\321\202\321\214 ", nullptr));
        pushButton_5->setText(QApplication::translate("OperatorWindow", "\320\236\321\202\321\207\320\265\321\202", nullptr));
        CashRollBack->setText(QApplication::translate("OperatorWindow", " \320\222\320\276\320\267\320\262\321\200\320\260\321\202 \320\261\320\260\320\275\320\272\320\275\320\276\321\202\321\213 ", nullptr));
        label_24->setText(QApplication::translate("OperatorWindow", "<html><head/><body><p align=\"center\">\320\240\320\260\321\201\320\277\320\276\320\267\320\275\320\260\320\275\320\275\321\213\320\271 \321\201\320\265\321\200\320\270\320\271\320\275\321\213\320\271 \320\275\320\276\320\274\320\265\321\200: \320\240\320\240 0000000</p></body></html>", nullptr));
        label_23->setText(QApplication::translate("OperatorWindow", "\320\241\320\265\321\200\320\270\320\271\320\275\321\213\320\271 \320\275\320\276\320\274\320\265\321\200:", nullptr));
        lineEdit_2->setText(QApplication::translate("OperatorWindow", "\320\240\320\240 0000000", nullptr));
        editButton->setText(QApplication::translate("OperatorWindow", "  \320\240\320\265\320\264\320\260\320\272\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214  ", nullptr));
        StartButton->setText(QApplication::translate("OperatorWindow", "\320\241\321\202\320\260\321\200\321\202", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OperatorWindow: public Ui_OperatorWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPERATORWINDOW_H
