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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *refresh_com;
    QComboBox *COMx;
    QPushButton *opencom;
    QTextEdit *textEdit;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton;
    QPushButton *clear;
    QPushButton *readtime;
    QPushButton *settime;
    QLabel *label_img;
    QLabel *label_path;
    QPushButton *c_path;
    QLabel *label;
    QLabel *battery;
    QLabel *record;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(950, 575);
        MainWindow->setMinimumSize(QSize(400, 530));
        MainWindow->setMaximumSize(QSize(950, 600));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 50, 341, 31));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
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

        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(20, 90, 331, 361));
        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(20, 470, 320, 25));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(layoutWidget1);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_2->addWidget(pushButton);

        clear = new QPushButton(layoutWidget1);
        clear->setObjectName(QStringLiteral("clear"));

        horizontalLayout_2->addWidget(clear);

        readtime = new QPushButton(layoutWidget1);
        readtime->setObjectName(QStringLiteral("readtime"));

        horizontalLayout_2->addWidget(readtime);

        settime = new QPushButton(layoutWidget1);
        settime->setObjectName(QStringLiteral("settime"));

        horizontalLayout_2->addWidget(settime);

        label_img = new QLabel(centralWidget);
        label_img->setObjectName(QStringLiteral("label_img"));
        label_img->setGeometry(QRect(400, 50, 480, 360));
        label_img->setAlignment(Qt::AlignCenter);
        label_path = new QLabel(centralWidget);
        label_path->setObjectName(QStringLiteral("label_path"));
        label_path->setGeometry(QRect(10, 10, 231, 21));
        c_path = new QPushButton(centralWidget);
        c_path->setObjectName(QStringLiteral("c_path"));
        c_path->setGeometry(QRect(260, 10, 91, 31));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(820, 440, 121, 91));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        battery = new QLabel(centralWidget);
        battery->setObjectName(QStringLiteral("battery"));
        battery->setGeometry(QRect(410, 460, 81, 41));
        record = new QLabel(centralWidget);
        record->setObjectName(QStringLiteral("record"));
        record->setGeometry(QRect(580, 460, 171, 41));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 950, 23));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
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
        refresh_com->setText(QApplication::translate("MainWindow", "\345\210\267\346\226\260\347\253\257\345\217\243", Q_NULLPTR));
        opencom->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200\344\270\262\345\217\243", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "\347\273\223\346\235\237\346\216\245\346\224\266", Q_NULLPTR));
        clear->setText(QApplication::translate("MainWindow", "\346\270\205\347\251\272", Q_NULLPTR));
        readtime->setText(QApplication::translate("MainWindow", "\350\257\273\345\217\226\346\227\266\351\227\264", Q_NULLPTR));
        settime->setText(QApplication::translate("MainWindow", "\350\256\276\347\275\256\346\227\266\351\227\264", Q_NULLPTR));
        label_img->setText(QString());
        label_path->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        c_path->setText(QApplication::translate("MainWindow", "\344\277\256\346\224\271\350\267\257\345\276\204", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "<html><head/><body><p>\346\231\272\350\203\275\350\275\246\350\275\275\347\273\210\347\253\257\345\267\245\345\205\267</p><p>V0.1.3</p><p>[\346\263\242\347\211\271\347\216\207230400bps]</p></body></html>", Q_NULLPTR));
        battery->setText(QApplication::translate("MainWindow", "\347\224\265\351\207\217\357\274\232", Q_NULLPTR));
        record->setText(QApplication::translate("MainWindow", "\346\227\240\346\213\206\346\234\272\350\256\260\345\275\225", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
