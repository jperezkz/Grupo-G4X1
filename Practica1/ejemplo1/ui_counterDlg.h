/********************************************************************************
** Form generated from reading UI file 'counterDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COUNTERDLG_H
#define UI_COUNTERDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Counter
{
public:
    QPushButton *button;
    QLCDNumber *lcdNumber;
    QPushButton *faster_button;
    QPushButton *slower_button;

    void setupUi(QWidget *Counter)
    {
        if (Counter->objectName().isEmpty())
            Counter->setObjectName(QString::fromUtf8("Counter"));
        Counter->resize(400, 300);
        button = new QPushButton(Counter);
        button->setObjectName(QString::fromUtf8("button"));
        button->setGeometry(QRect(130, 190, 251, 71));
        lcdNumber = new QLCDNumber(Counter);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        lcdNumber->setGeometry(QRect(50, 40, 301, 91));
        faster_button = new QPushButton(Counter);
        faster_button->setObjectName(QString::fromUtf8("faster_button"));
        faster_button->setGeometry(QRect(20, 150, 89, 25));
        slower_button = new QPushButton(Counter);
        slower_button->setObjectName(QString::fromUtf8("slower_button"));
        slower_button->setGeometry(QRect(20, 200, 89, 25));

        retranslateUi(Counter);

        QMetaObject::connectSlotsByName(Counter);
    } // setupUi

    void retranslateUi(QWidget *Counter)
    {
        Counter->setWindowTitle(QApplication::translate("Counter", "Counter", nullptr));
        button->setText(QApplication::translate("Counter", "STOP", nullptr));
        faster_button->setText(QApplication::translate("Counter", "Faster", nullptr));
        slower_button->setText(QApplication::translate("Counter", "Slower", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Counter: public Ui_Counter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COUNTERDLG_H
