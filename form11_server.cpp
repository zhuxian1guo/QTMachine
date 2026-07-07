#include "form11_server.h"
#include "ui_form11_server.h"

Form11_Server::Form11_Server(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form11_Server)
{
    ui->setupUi(this);
}

Form11_Server::~Form11_Server()
{
    delete ui;
}
