/********************************************************************************
** Form generated from reading UI file 'searchdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHDIALOG_H
#define UI_SEARCHDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_searchDialog
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *searchDialog)
    {
        if (searchDialog->objectName().isEmpty())
            searchDialog->setObjectName("searchDialog");
        searchDialog->resize(300, 200);
        centralwidget = new QWidget(searchDialog);
        centralwidget->setObjectName("centralwidget");
        searchDialog->setCentralWidget(centralwidget);
        menubar = new QMenuBar(searchDialog);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 300, 17));
        searchDialog->setMenuBar(menubar);
        statusbar = new QStatusBar(searchDialog);
        statusbar->setObjectName("statusbar");
        searchDialog->setStatusBar(statusbar);

        retranslateUi(searchDialog);

        QMetaObject::connectSlotsByName(searchDialog);
    } // setupUi

    void retranslateUi(QMainWindow *searchDialog)
    {
        searchDialog->setWindowTitle(QCoreApplication::translate("searchDialog", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class searchDialog: public Ui_searchDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHDIALOG_H
