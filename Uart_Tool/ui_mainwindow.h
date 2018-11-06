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
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *Sendfile;
    QPushButton *clear;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(400, 530);
        MainWindow->setMinimumSize(QSize(400, 530));
        MainWindow->setMaximumSize(QSize(400, 530));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 341, 31));
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
        textEdit->setGeometry(QRect(20, 50, 331, 361));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(50, 430, 244, 25));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        Sendfile = new QPushButton(widget);
        Sendfile->setObjectName(QStringLiteral("Sendfile"));

        horizontalLayout_2->addWidget(Sendfile);

        clear = new QPushButton(widget);
        clear->setObjectName(QStringLiteral("clear"));

        horizontalLayout_2->addWidget(clear);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_2->addWidget(pushButton);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 23));
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
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "UART_TOOL", Q_NULLPTR));
        refresh_com->setText(QApplication::translate("MainWindow", "\345\210\267\346\226\260\347\253\257\345\217\243", Q_NULLPTR));
        opencom->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200\344\270\262\345\217\243", Q_NULLPTR));
        Sendfile->setText(QApplication::translate("MainWindow", "\345\217\221\351\200\201\345\233\276\347\211\207", Q_NULLPTR));
        clear->setText(QApplication::translate("MainWindow", "\346\270\205\347\251\272", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "\345\217\221\351\200\201\347\256\227\346\263\225\345\217\202\346\225\260", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
