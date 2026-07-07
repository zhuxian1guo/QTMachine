/* DLL 引用     DLLDev D;    qDebug()<< D.add(66,66); */
#include "form10_dlldev.h"
#include "ui_form10_dlldev.h"
#include "dlldev.h"
#include <QDebug>

form10_dllDev::form10_dllDev(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::form10_dllDev)
{
    ui->setupUi(this);
    DLLDev D;
    qDebug()<< D.add(66,66);

}

form10_dllDev::~form10_dllDev()
{
    delete ui;
}
