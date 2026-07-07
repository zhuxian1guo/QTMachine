#include "form11_client.h"
#include "ui_form11_client.h"

Form11_Client::Form11_Client(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form11_Client)
{
    ui->setupUi(this);
}

Form11_Client::~Form11_Client()
{
    delete ui;
}
