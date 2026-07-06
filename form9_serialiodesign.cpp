#include "form9_serialiodesign.h"
#include "ui_form9_serialiodesign.h"

Form9_serialIODesign::Form9_serialIODesign(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form9_serialIODesign)
{
    ui->setupUi(this);
}

Form9_serialIODesign::~Form9_serialIODesign()
{
    delete ui;
}
