#include "lottery.h"
#include "ui_lottery.h"
#include <qDebug>
#include <QRandomGenerator>
#include <QTimer>
#include <Qstring>

Lottery::Lottery(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Lottery)
{
    ui->setupUi(this);
    generateRandomWithQRandomGenerator();

    // 1. 创建 QTimer 对象
    timer = new QTimer(this); // this 为父对象，确保内存自动管理

    // 2. 连接 timeout() 信号到槽函数
    // connect(timer,&QTimer::timeout,this,&countdown::mtd_cutdown);
    connect(timer,&QTimer::timeout,this,&Lottery::displaynum);
    connect(timer,&QTimer::timeout,this,&Lottery::displaynum2);



}

Lottery::~Lottery()
{
    delete ui;
}

//Btn1开始按钮
void Lottery::on_pushButton_clicked()
{
    qDebug()<<"开始按钮";
    timer->start(100);
}


//Btn2 停止按钮
void Lottery::on_pushButton_2_clicked()
{
    qDebug()<<"停止按钮";
    timer->stop();
}



// 方法一：使用 QRandomGenerator (Qt 5.10 及以上推荐)
 int Lottery::generateRandomWithQRandomGenerator() {
    // globallySeeded() 返回全局共享的生成器，自动处理种子
    // bounded(10) 生成 [0, 10) 之间的整数，即 0-9
    int randomNum = QRandomGenerator::global()->bounded(10);
    qDebug() << "QRandomGenerator generated:" << randomNum;
    return randomNum;
}

//disnum1
void Lottery::displaynum()
{
    qDebug()<<"displaynum";
    ui->label->setText(QString::number(generateRandomWithQRandomGenerator()));
    ui->label_2->setText(QString::number(generateRandomWithQRandomGenerator()));
    ui->label_3->setText(QString::number(generateRandomWithQRandomGenerator()));
}

   // 总计数方式显示
void Lottery::displaynum2()
{

    totalValue=QRandomGenerator::global()->bounded(1000);
    qDebug()<<"displaynum";
    ui->label_4->setText( QString::number(totalValue/100));
    ui->label_5->setText(QString::number((totalValue%100) /10));
    ui->label_6->setText(QString::number( totalValue%10 ));
}
