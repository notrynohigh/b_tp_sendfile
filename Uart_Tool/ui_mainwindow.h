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
#include <QtWidgets/QDial>
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
    QLabel *label_img;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_path;
    QPushButton *c_path;
    QHBoxLayout *horizontalLayout;
    QPushButton *refresh_com;
    QComboBox *COMx;
    QPushButton *opencom;
    QLabel *label_img_2;
    QLabel *label;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QPushButton *clear;
    QPushButton *pushButton;
    QPushButton *readtime;
    QPushButton *settime;
    QPushButton *color_sel;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_3;
    QLabel *search_result;
    QLabel *record;
    QLabel *battery;
    QDial *dial;
    QLabel *label_2;
    QLabel *label_3;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1040, 750);
        MainWindow->setMinimumSize(QSize(1040, 750));
        MainWindow->setMaximumSize(QSize(1040, 750));
        MainWindow->setStyleSheet(QString::fromUtf8("QMainWindow\n"
"{\n"
"	background-color: rgb(158, 158, 78);\n"
"}\n"
"\n"
"QTextEdit\n"
"{\n"
"	background-color: rgb(158, 158, 78);\n"
"}\n"
"\n"
"QLabel\n"
"{\n"
"	background-color: rgb(158, 158, 78);\n"
"}\n"
"\n"
"QPushButton{\n"
"     background-color: rgb(158, 158, 78);/*\350\203\214\346\231\257\350\211\262*/\n"
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
"	background-color: rgb(158, 158, 78);\n"
"}"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(20, 100, 481, 181));
        label_img = new QLabel(centralWidget);
        label_img->setObjectName(QStringLiteral("label_img"));
        label_img->setGeometry(QRect(20, 300, 480, 360));
        label_img->setAlignment(Qt::AlignCenter);
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 10, 471, 74));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_path = new QLabel(layoutWidget);
        label_path->setObjectName(QStringLiteral("label_path"));

        verticalLayout->addWidget(label_path);

        c_path = new QPushButton(layoutWidget);
        c_path->setObjectName(QStringLiteral("c_path"));

        verticalLayout->addWidget(c_path);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        refresh_com = new QPushButton(layoutWidget);
        refresh_com->setObjectName(QStringLiteral("refresh_com"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(refresh_com->sizePolicy().hasHeightForWidth());
        refresh_com->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(refresh_com);

        COMx = new QComboBox(layoutWidget);
        COMx->setObjectName(QStringLiteral("COMx"));
        COMx->setEnabled(true);

        horizontalLayout->addWidget(COMx);

        opencom = new QPushButton(layoutWidget);
        opencom->setObjectName(QStringLiteral("opencom"));

        horizontalLayout->addWidget(opencom);


        verticalLayout->addLayout(horizontalLayout);

        label_img_2 = new QLabel(centralWidget);
        label_img_2->setObjectName(QStringLiteral("label_img_2"));
        label_img_2->setGeometry(QRect(540, 300, 480, 360));
        label_img_2->setAlignment(Qt::AlignCenter);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(800, 0, 240, 16));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(520, 100, 82, 181));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        clear = new QPushButton(layoutWidget1);
        clear->setObjectName(QStringLiteral("clear"));

        verticalLayout_2->addWidget(clear);

        pushButton = new QPushButton(layoutWidget1);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout_2->addWidget(pushButton);

        readtime = new QPushButton(layoutWidget1);
        readtime->setObjectName(QStringLiteral("readtime"));

        verticalLayout_2->addWidget(readtime);

        settime = new QPushButton(layoutWidget1);
        settime->setObjectName(QStringLiteral("settime"));

        verticalLayout_2->addWidget(settime);

        color_sel = new QPushButton(layoutWidget1);
        color_sel->setObjectName(QStringLiteral("color_sel"));

        verticalLayout_2->addWidget(color_sel);

        layoutWidget2 = new QWidget(centralWidget);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(780, 230, 231, 52));
        verticalLayout_3 = new QVBoxLayout(layoutWidget2);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        search_result = new QLabel(layoutWidget2);
        search_result->setObjectName(QStringLiteral("search_result"));

        verticalLayout_3->addWidget(search_result);

        record = new QLabel(layoutWidget2);
        record->setObjectName(QStringLiteral("record"));

        verticalLayout_3->addWidget(record);

        battery = new QLabel(layoutWidget2);
        battery->setObjectName(QStringLiteral("battery"));

        verticalLayout_3->addWidget(battery);

        dial = new QDial(centralWidget);
        dial->setObjectName(QStringLiteral("dial"));
        dial->setGeometry(QRect(690, 50, 171, 131));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(200, 670, 54, 12));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(770, 670, 54, 12));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1040, 23));
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
        label_img->setText(QString());
        label_path->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        c_path->setText(QApplication::translate("MainWindow", "\344\277\256\346\224\271\350\267\257\345\276\204", Q_NULLPTR));
        refresh_com->setText(QApplication::translate("MainWindow", "\345\210\267\346\226\260\347\253\257\345\217\243", Q_NULLPTR));
        opencom->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200\344\270\262\345\217\243", Q_NULLPTR));
        label_img_2->setText(QString());
        label->setText(QApplication::translate("MainWindow", "<html><head/><body><p>\346\231\272\350\203\275\350\275\246\350\275\275\347\273\210\347\253\257\345\267\245\345\205\267V0.2.1 [\346\263\242\347\211\271\347\216\207230400bps]</p></body></html>", Q_NULLPTR));
        clear->setText(QApplication::translate("MainWindow", "\346\270\205\347\251\272", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "\347\273\223\346\235\237\346\216\245\346\224\266", Q_NULLPTR));
        readtime->setText(QApplication::translate("MainWindow", "\350\257\273\345\217\226\346\227\266\351\227\264", Q_NULLPTR));
        settime->setText(QApplication::translate("MainWindow", "\350\256\276\347\275\256\346\227\266\351\227\264", Q_NULLPTR));
        color_sel->setText(QApplication::translate("MainWindow", "\350\203\214\346\231\257\351\242\234\350\211\262\351\200\211\346\213\251", Q_NULLPTR));
        search_result->setText(QString());
        record->setText(QApplication::translate("MainWindow", "\346\227\240\346\213\206\346\234\272\350\256\260\345\275\225", Q_NULLPTR));
        battery->setText(QApplication::translate("MainWindow", "\347\224\265\351\207\217\357\274\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "\346\213\215\346\221\204\345\233\276\347\211\207", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "\345\214\271\351\205\215\345\233\276\347\211\207", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
