#include "countdown.h"
#include "ui_countdown.h"
#include <qDebug>
#include <QMessageBox>
#include <QTimer>
#include <QButtonGroup>




countdown::countdown(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::countdown)
{
    ui->setupUi(this);

    total=1800;

    // 1. 创建 QTimer 对象
    timer = new QTimer(this); // this 为父对象，确保内存自动管理

    // 2. 连接 timeout() 信号到槽函数
    // connect(timer,&QTimer::timeout,this,&countdown::mtd_cutdown);
    connect(timer,&QTimer::timeout,this,&countdown::mtd_cutdown);
    display_number2();


    // 4. 读取初始值
    // toInt 会自动处理转换失败，返回 0，并将 ok 设为 false
    a1 = ui->label->text().toInt(&ok1);
    a2 = ui->label_2->text().toInt(&ok2);
    a3 = ui->label_4->text().toInt(&ok3);
    a4 = ui->label_5->text().toInt(&ok4);

    qDebug() << "Initial values:" << a1 << a2 << a3 << a4;

    //radiobtn
     mBtnGroupEdu = new QButtonGroup(this);
    mBtnGroupEdu->addButton(  ui->radioButton,0);
    mBtnGroupEdu->addButton(  ui->radioButton_2,1);
    ui->radioButton->setChecked(true);
    if(  ui->radioButton->isChecked()){
        type_displaynum=0;
    }else{
        type_displaynum=1;
    }
}

countdown::~countdown()
{
    delete ui;
}


//mtd_cutdown

void countdown::mtd_cutdown(){
    if(type_displaynum==0){
        display_number();
    }else{
        total--;
        display_number2();
    }
}


//倒计时方式1
void countdown::display_number(){
    // 假设进制：a4(10进制, 0-9), a3(6进制, 0-5), a2(10进制, 0-9), a1(10进制, 0-9)
    // 请根据实际业务需求调整 MAX_A3 等常量

    const int MAX_A4 = 9;
    const int MAX_A3 = 5; // a3 最大值为 5 (即 0-5 共6个数，若需0-6则设为6)
    const int MAX_A2 = 9;
    const int MAX_A1 = 9;

    if (a4 > 0) {
        a4--;
    } else {
        a4 = MAX_A4; // a4 归零，重置为最大值
        if (a3 > 0) {
            a3--;
        } else {
            a3 = MAX_A3; // a3 归零，重置为最大值
            if (a2 > 0) {
                a2--;
            } else {
                a2 = MAX_A2; // a2 归零，重置为最大值
                if (a1 > 0) {
                    a1--;
                } else {
                    // 全部归零
                    qDebug() << "Countdown Finished";
                    QMessageBox::information(this, "tips", "timeout!");
                    if(timer) timer->stop();
                    return;
                }
            }
        }
    }

    // 更新 UI
    ui->label_5->setText(QString::number(a4));
    ui->label_4->setText(QString::number(a3));
    ui->label_2->setText(QString::number(a2));
    ui->label->setText(QString::number(a1));
}


// 第二种方式
void countdown::display_number2()
{
    ui->label->setText(QString::number((total / 60) / 10));
    ui->label_2->setText(QString::number((total / 60) % 10));
    ui->label_4->setText(QString::number((total % 60) / 10));
    ui->label_5->setText(QString::number((total % 60) % 10));
}



void countdown::on_pushButton_clicked()
{
    if(isclickbtn==false){
        isclickbtn=true;
        // 3. 启动定时器，参数为毫秒
        timer->start(1000); // 每 1000 毫秒（1秒）触发一次
         QMessageBox::information(this, "tips", "开始倒计时!");
    }else{
        isclickbtn=false;
        timer->stop();
        QMessageBox::information(this, "tips", "暂停倒计时!");
    }

      // 首先判断所有转换是否都成功
      if (!ok1 || !ok2 || !ok3 || !ok4) {
          // 如果有任何一个标签的内容不是有效整数，则提示错误或返回
          QMessageBox::information(this, "错误", "标签内容包含非数字字符");
          return;
      }

          //判断是否归零  cutdown
           if (a1 == 0 && a2 == 0 && a3 == 0 && a4 == 0) {
                 //   归零处理逻辑
                 //   qDebug() << "倒计时已归零";
                 QMessageBox::information(this,"warning","倒计时已归零");
          }
}

