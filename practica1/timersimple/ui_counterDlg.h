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
    QPushButton *get_period;
    QLCDNumber *lcdPeriod;

    void setupUi(QWidget *Counter)
    {
        if (Counter->objectName().isEmpty())
            Counter->setObjectName(QString::fromUtf8("Counter"));
        Counter->resize(422, 307);
        button = new QPushButton(Counter);
        button->setObjectName(QString::fromUtf8("button"));
        button->setGeometry(QRect(150, 200, 251, 71));
        lcdNumber = new QLCDNumber(Counter);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        lcdNumber->setGeometry(QRect(190, 10, 181, 161));
        faster_button = new QPushButton(Counter);
        faster_button->setObjectName(QString::fromUtf8("faster_button"));
        faster_button->setGeometry(QRect(30, 190, 89, 25));
        slower_button = new QPushButton(Counter);
        slower_button->setObjectName(QString::fromUtf8("slower_button"));
        slower_button->setGeometry(QRect(30, 240, 89, 25));
        get_period = new QPushButton(Counter);
        get_period->setObjectName(QString::fromUtf8("get_period"));
        get_period->setGeometry(QRect(20, 20, 89, 25));
        lcdPeriod = new QLCDNumber(Counter);
        lcdPeriod->setObjectName(QString::fromUtf8("lcdPeriod"));
        lcdPeriod->setGeometry(QRect(20, 50, 131, 111));

        retranslateUi(Counter);

        QMetaObject::connectSlotsByName(Counter);
    } // setupUi

    void retranslateUi(QWidget *Counter)
    {
        Counter->setWindowTitle(QApplication::translate("Counter", "Counter", nullptr));
        button->setText(QApplication::translate("Counter", "STOP", nullptr));
        faster_button->setText(QApplication::translate("Counter", "Faster", nullptr));
        slower_button->setText(QApplication::translate("Counter", "Slower", nullptr));
        get_period->setText(QApplication::translate("Counter", "Get Period", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Counter: public Ui_Counter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COUNTERDLG_H
