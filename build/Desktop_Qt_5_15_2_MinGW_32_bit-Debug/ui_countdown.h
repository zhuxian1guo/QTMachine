/********************************************************************************
** Form generated from reading UI file 'countdown.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COUNTDOWN_H
#define UI_COUNTDOWN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_countdown
{
public:
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;

    void setupUi(QWidget *countdown)
    {
        if (countdown->objectName().isEmpty())
            countdown->setObjectName(QString::fromUtf8("countdown"));
        countdown->resize(944, 601);
        lineEdit = new QLineEdit(countdown);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(330, 310, 113, 23));
        pushButton = new QPushButton(countdown);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(480, 310, 81, 24));
        layoutWidget = new QWidget(countdown);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(300, 240, 271, 51));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout->addWidget(label_4);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout->addWidget(label_5);

        widget = new QWidget(countdown);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(300, 360, 281, 23));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        radioButton = new QRadioButton(widget);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setChecked(false);

        horizontalLayout_2->addWidget(radioButton);

        radioButton_2 = new QRadioButton(widget);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
        radioButton_2->setChecked(false);
        radioButton_2->setAutoExclusive(false);

        horizontalLayout_2->addWidget(radioButton_2);


        retranslateUi(countdown);

        QMetaObject::connectSlotsByName(countdown);
    } // setupUi

    void retranslateUi(QWidget *countdown)
    {
        countdown->setWindowTitle(QCoreApplication::translate("countdown", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("countdown", "CutDown", nullptr));
        label->setText(QCoreApplication::translate("countdown", "0", nullptr));
        label_2->setText(QCoreApplication::translate("countdown", "0", nullptr));
        label_3->setText(QCoreApplication::translate("countdown", ":", nullptr));
        label_4->setText(QCoreApplication::translate("countdown", "0", nullptr));
        label_5->setText(QCoreApplication::translate("countdown", "6", nullptr));
        radioButton->setText(QCoreApplication::translate("countdown", "\350\256\241\346\227\266\346\226\271\345\274\2171", nullptr));
        radioButton_2->setText(QCoreApplication::translate("countdown", "\350\256\241\346\227\266\346\226\271\345\274\2172", nullptr));
    } // retranslateUi

};

namespace Ui {
    class countdown: public Ui_countdown {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COUNTDOWN_H
