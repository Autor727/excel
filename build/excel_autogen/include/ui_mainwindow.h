/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOPen;
    QAction *actionSave;
    QAction *actionNew;
    QWidget *centralwidget;
    QTableWidget *tableWidget;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menuInsert;
    QMenu *menuDelete;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        actionOPen = new QAction(MainWindow);
        actionOPen->setObjectName("actionOPen");
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName("actionSave");
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName("actionNew");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        tableWidget = new QTableWidget(centralwidget);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(10, 50, 780, 580));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 17));
        menu = new QMenu(menubar);
        menu->setObjectName("menu");
        menuInsert = new QMenu(menubar);
        menuInsert->setObjectName("menuInsert");
        menuDelete = new QMenu(menubar);
        menuDelete->setObjectName("menuDelete");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menuInsert->menuAction());
        menubar->addAction(menuDelete->menuAction());
        menu->addAction(actionOPen);
        menu->addAction(actionSave);
        menu->addAction(actionNew);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionOPen->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200", nullptr));
        actionSave->setText(QCoreApplication::translate("MainWindow", "\344\277\235\345\255\230", nullptr));
        actionNew->setText(QCoreApplication::translate("MainWindow", "\346\226\260\345\273\272", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\346\226\207\344\273\266", nullptr));
        menuInsert->setTitle(QCoreApplication::translate("MainWindow", "\346\217\222\345\205\245", nullptr));
        menuDelete->setTitle(QCoreApplication::translate("MainWindow", "\345\210\240\351\231\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
