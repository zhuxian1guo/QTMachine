#include "vip_mgr.h"
#include "ui_vip_mgr.h"

VIP_Mgr::VIP_Mgr(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::VIP_Mgr)
{
    ui->setupUi(this);
}

VIP_Mgr::~VIP_Mgr()
{
    delete ui;
}
