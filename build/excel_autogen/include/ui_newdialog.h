/********************************************************************************
** Form generated from reading UI file 'newdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWDIALOG_H
#define UI_NEWDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_newDialog
{
public:
    QLabel *label;
    QPushButton *buttonClear;
    QLabel *label_4;
    QPushButton *buttonSure;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer;
    QSpinBox *spinBoxRow;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_2;
    QSpinBox *spinBoxCol;

    void setupUi(QWidget *newDialog)
    {
        if (newDialog->objectName().isEmpty())
            newDialog->setObjectName("newDialog");
        newDialog->resize(400, 253);
        newDialog->setMinimumSize(QSize(400, 253));
        newDialog->setMaximumSize(QSize(400, 253));
        label = new QLabel(newDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(170, 50, 40, 12));
        buttonClear = new QPushButton(newDialog);
        buttonClear->setObjectName("buttonClear");
        buttonClear->setGeometry(QRect(300, 190, 80, 18));
        label_4 = new QLabel(newDialog);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(40, 20, 321, 41));
        buttonSure = new QPushButton(newDialog);
        buttonSure->setObjectName("buttonSure");
        buttonSure->setGeometry(QRect(190, 190, 80, 18));
        widget = new QWidget(newDialog);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(100, 80, 211, 31));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");

        horizontalLayout->addWidget(label_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        spinBoxRow = new QSpinBox(widget);
        spinBoxRow->setObjectName("spinBoxRow");

        horizontalLayout->addWidget(spinBoxRow);

        widget1 = new QWidget(newDialog);
        widget1->setObjectName("widget1");
        widget1->setGeometry(QRect(100, 120, 211, 31));
        horizontalLayout_2 = new QHBoxLayout(widget1);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(widget1);
        label_3->setObjectName("label_3");

        horizontalLayout_2->addWidget(label_3);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        spinBoxCol = new QSpinBox(widget1);
        spinBoxCol->setObjectName("spinBoxCol");

        horizontalLayout_2->addWidget(spinBoxCol);


        retranslateUi(newDialog);

        QMetaObject::connectSlotsByName(newDialog);
    } // setupUi

    void retranslateUi(QWidget *newDialog)
    {
        newDialog->setWindowTitle(QCoreApplication::translate("newDialog", "Form", nullptr));
        label->setText(QString());
        buttonClear->setText(QCoreApplication::translate("newDialog", "\346\270\205\351\231\244", nullptr));
        label_4->setText(QCoreApplication::translate("newDialog", "<html><head/><body><p><span style=\" font-size:16pt; font-weight:700;\">\350\257\267\350\276\223\345\205\245\344\275\240\346\203\263\350\246\201\345\210\233\345\273\272\347\232\204\347\251\272\347\231\275\350\241\250\346\240\274\347\232\204\350\241\214\346\225\260\345\222\214\345\210\227\346\225\260</span></p></body></html>", nullptr));
        buttonSure->setText(QCoreApplication::translate("newDialog", "\347\241\256\350\256\244", nullptr));
        label_2->setText(QCoreApplication::translate("newDialog", "<html><head/><body><p><span style=\" font-size:14pt;\">\350\241\214\346\225\260</span></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("newDialog", "<html><head/><body><p><span style=\" font-size:14pt;\">\345\210\227\346\225\260</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class newDialog: public Ui_newDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWDIALOG_H
