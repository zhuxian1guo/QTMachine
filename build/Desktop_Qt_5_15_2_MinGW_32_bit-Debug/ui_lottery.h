/********************************************************************************
** Form generated from reading UI file 'lottery.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOTTERY_H
#define UI_LOTTERY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Lottery
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *Lottery)
    {
        if (Lottery->objectName().isEmpty())
            Lottery->setObjectName(QString::fromUtf8("Lottery"));
        Lottery->resize(706, 533);
        verticalLayout = new QVBoxLayout(Lottery);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(80, -1, -1, -1);
        label_4 = new QLabel(Lottery);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        QFont font;
        font.setPointSize(29);
        label_4->setFont(font);

        horizontalLayout_4->addWidget(label_4);

        label_5 = new QLabel(Lottery);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font);

        horizontalLayout_4->addWidget(label_5);

        label_6 = new QLabel(Lottery);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font);

        horizontalLayout_4->addWidget(label_6);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(80, -1, -1, -1);
        label = new QLabel(Lottery);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);

        horizontalLayout->addWidget(label);

        label_2 = new QLabel(Lottery);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        horizontalLayout->addWidget(label_2);

        label_3 = new QLabel(Lottery);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);

        horizontalLayout->addWidget(label_3);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(50);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(20, -1, 20, -1);
        pushButton = new QPushButton(Lottery);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_2->addWidget(pushButton);

        pushButton_2 = new QPushButton(Lottery);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout_2->addWidget(pushButton_2);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(Lottery);

        QMetaObject::connectSlotsByName(Lottery);
    } // setupUi

    void retranslateUi(QWidget *Lottery)
    {
        Lottery->setWindowTitle(QCoreApplication::translate("Lottery", "Form", nullptr));
        label_4->setText(QCoreApplication::translate("Lottery", "1", nullptr));
        label_5->setText(QCoreApplication::translate("Lottery", "1", nullptr));
        label_6->setText(QCoreApplication::translate("Lottery", "1", nullptr));
        label->setText(QCoreApplication::translate("Lottery", "1", nullptr));
        label_2->setText(QCoreApplication::translate("Lottery", "1", nullptr));
        label_3->setText(QCoreApplication::translate("Lottery", "1", nullptr));
        pushButton->setText(QCoreApplication::translate("Lottery", "\345\274\200\345\247\213", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Lottery", "\345\201\234\346\255\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Lottery: public Ui_Lottery {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOTTERY_H
