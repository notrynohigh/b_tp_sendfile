/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTextEdit *textEdit;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton;
    QPushButton *clear;
    QPushButton *readtime;
    QPushButton *settime;
    QLabel *label_img;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *label_path;
    QPushButton *c_path;
    QHBoxLayout *horizontalLayout;
    QPushButton *refresh_com;
    QComboBox *COMx;
    QPushButton *opencom;
    QWidget *widget1;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QLabel *record;
    QLabel *battery;
    QLabel *label;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(950, 600);
        MainWindow->setMinimumSize(QSize(950, 600));
        MainWindow->setMaximumSize(QSize(950, 600));
        MainWindow->setStyleSheet(QString::fromUtf8("QMainWindow\n"
"{\n"
"	background-color: rgb(156, 156, 156);\n"
"}\n"
"\n"
"QTextEdit\n"
"{\n"
"	background-color: rgb(156, 156, 156);\n"
"}\n"
"\n"
"QLabel\n"
"{\n"
"	background-color: rgb(156, 156, 156);\n"
"}\n"
"\n"
"QPushButton{\n"
"     background-color: rgb(156, 156, 156);/*\350\203\214\346\231\257\350\211\262*/\n"
"     color: rgb(0, 0, 0);\n"
"}\n"
"\n"
"\n"
"QPushButton:pressed { /*\346\214\211\351\222\256\350\242\253\346\214\211\344\270\213\346\227\266*/\n"
"     background-color: rgb(106, 106, 106);\n"
"}\n"
"\n"
"QComboBox\n"
"{\n"
"	background-color: rgb(156, 156, 156);\n"
"}"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(20, 100, 331, 391));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 500, 320, 36));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_2->addWidget(pushButton);

        clear = new QPushButton(layoutWidget);
        clear->setObjectName(QStringLiteral("clear"));

        horizontalLayout_2->addWidget(clear);

        readtime = new QPushButton(layoutWidget);
        readtime->setObjectName(QStringLiteral("readtime"));

        horizontalLayout_2->addWidget(readtime);

        settime = new QPushButton(layoutWidget);
        settime->setObjectName(QStringLiteral("settime"));

        horizontalLayout_2->addWidget(settime);

        label_img = new QLabel(centralWidget);
        label_img->setObjectName(QStringLiteral("label_img"));
        label_img->setGeometry(QRect(400, 50, 480, 360));
        label_img->setAlignment(Qt::AlignCenter);
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(20, 10, 331, 81));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_path = new QLabel(widget);
        label_path->setObjectName(QStringLiteral("label_path"));

        verticalLayout->addWidget(label_path);

        c_path = new QPushButton(widget);
        c_path->setObjectName(QStringLiteral("c_path"));

        verticalLayout->addWidget(c_path);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        refresh_com = new QPushButton(widget);
        refresh_com->setObjectName(QStringLiteral("refresh_com"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(refresh_com->sizePolicy().hasHeightForWidth());
        refresh_com->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(refresh_com);

        COMx = new QComboBox(widget);
        COMx->setObjectName(QStringLiteral("COMx"));
        COMx->setEnabled(true);

        horizontalLayout->addWidget(COMx);

        opencom = new QPushButton(widget);
        opencom->setObjectName(QStringLiteral("opencom"));

        horizontalLayout->addWidget(opencom);


        verticalLayout->addLayout(horizontalLayout);

        widget1 = new QWidget(centralWidget);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(400, 430, 481, 106));
        verticalLayout_3 = new QVBoxLayout(widget1);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        record = new QLabel(widget1);
        record->setObjectName(QStringLiteral("record"));

        verticalLayout_2->addWidget(record);

        battery = new QLabel(widget1);
        battery->setObjectName(QStringLiteral("battery"));

        verticalLayout_2->addWidget(battery);

        label = new QLabel(widget1);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_2->addWidget(label);


        verticalLayout_3->addLayout(verticalLayout_2);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 950, 23));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        mainToolBar->setEnabled(false);
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "JPEG", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "\347\273\223\346\235\237\346\216\245\346\224\266", Q_NULLPTR));
        clear->setText(QApplication::translate("MainWindow", "\346\270\205\347\251\272", Q_NULLPTR));
        readtime->setText(QApplication::translate("MainWindow", "\350\257\273\345\217\226\346\227\266\351\227\264", Q_NULLPTR));
        settime->setText(QApplication::translate("MainWindow", "\350\256\276\347\275\256\346\227\266\351\227\264", Q_NULLPTR));
        label_img->setText(QString());
        label_path->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        c_path->setText(QApplication::translate("MainWindow", "\344\277\256\346\224\271\350\267\257\345\276\204", Q_NULLPTR));
        refresh_com->setText(QApplication::translate("MainWindow", "\345\210\267\346\226\260\347\253\257\345\217\243", Q_NULLPTR));
        opencom->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200\344\270\262\345\217\243", Q_NULLPTR));
        record->setText(QApplication::translate("MainWindow", "\346\227\240\346\213\206\346\234\272\350\256\260\345\275\225", Q_NULLPTR));
        battery->setText(QApplication::translate("MainWindow", "\347\224\265\351\207\217\357\274\232", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "<html><head/><body><p>\346\231\272\350\203\275\350\275\246\350\275\275\347\273\210\347\253\257\345\267\245\345\205\267V0.1.3 [\346\263\242\347\211\271\347\216\207230400bps]</p></body></html>", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
