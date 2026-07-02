/********************************************************************************
** Form generated from reading UI file 'vip_mgr.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIP_MGR_H
#define UI_VIP_MGR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VIP_Mgr
{
public:
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_4;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QGroupBox *groupBox_2;
    QTextEdit *textEdit;
    QLabel *label_3;

    void setupUi(QWidget *VIP_Mgr)
    {
        if (VIP_Mgr->objectName().isEmpty())
            VIP_Mgr->setObjectName(QString::fromUtf8("VIP_Mgr"));
        VIP_Mgr->resize(900, 502);
        groupBox = new QGroupBox(VIP_Mgr);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(20, 40, 421, 411));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        radioButton = new QRadioButton(groupBox);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));

        horizontalLayout_3->addWidget(radioButton);

        radioButton_2 = new QRadioButton(groupBox);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));

        horizontalLayout_3->addWidget(radioButton_2);

        radioButton_3 = new QRadioButton(groupBox);
        radioButton_3->setObjectName(QString::fromUtf8("radioButton_3"));

        horizontalLayout_3->addWidget(radioButton_3);

        radioButton_4 = new QRadioButton(groupBox);
        radioButton_4->setObjectName(QString::fromUtf8("radioButton_4"));

        horizontalLayout_3->addWidget(radioButton_4);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout->addWidget(lineEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        lineEdit_2 = new QLineEdit(groupBox);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        horizontalLayout_2->addWidget(lineEdit_2);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout_4->addWidget(pushButton_2);

        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_4->addWidget(pushButton);

        pushButton_3 = new QPushButton(groupBox);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        horizontalLayout_4->addWidget(pushButton_3);


        verticalLayout->addLayout(horizontalLayout_4);

        groupBox_2 = new QGroupBox(VIP_Mgr);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(460, 50, 411, 401));
        textEdit = new QTextEdit(groupBox_2);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(30, 100, 361, 281));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(30, 60, 141, 16));

        retranslateUi(VIP_Mgr);

        QMetaObject::connectSlotsByName(VIP_Mgr);
    } // setupUi

    void retranslateUi(QWidget *VIP_Mgr)
    {
        VIP_Mgr->setWindowTitle(QCoreApplication::translate("VIP_Mgr", "Form", nullptr));
        groupBox->setTitle(QCoreApplication::translate("VIP_Mgr", "GroupBox", nullptr));
        radioButton->setText(QCoreApplication::translate("VIP_Mgr", "\345\212\240", nullptr));
        radioButton_2->setText(QCoreApplication::translate("VIP_Mgr", "\345\210\240\351\231\244", nullptr));
        radioButton_3->setText(QCoreApplication::translate("VIP_Mgr", "\346\224\271", nullptr));
        radioButton_4->setText(QCoreApplication::translate("VIP_Mgr", "\346\237\245", nullptr));
        label->setText(QCoreApplication::translate("VIP_Mgr", "ID", nullptr));
        label_2->setText(QCoreApplication::translate("VIP_Mgr", "Name", nullptr));
        pushButton_2->setText(QCoreApplication::translate("VIP_Mgr", "OK", nullptr));
        pushButton->setText(QCoreApplication::translate("VIP_Mgr", "Cancel", nullptr));
        pushButton_3->setText(QCoreApplication::translate("VIP_Mgr", "Save", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("VIP_Mgr", "Verification", nullptr));
        label_3->setText(QCoreApplication::translate("VIP_Mgr", "Member Details", nullptr));
    } // retranslateUi

};

namespace Ui {
    class VIP_Mgr: public Ui_VIP_Mgr {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIP_MGR_H
