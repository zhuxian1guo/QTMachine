#include "form15_animation.h"
#include "ui_form15_animation.h"

Form15_Animation::Form15_Animation(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form15_Animation)
{
    ui->setupUi(this);

    // 创建按钮
    p_button = new QPushButton("Click Me", this);
    p_button->setGeometry(100, 100, 100, 30);

    // 创建动画对象
    p_animation = new QPropertyAnimation(p_button, "pos");

    // 设置动画的起始和结束值
    p_animation->setStartValue(QPoint(100, 100));
    p_animation->setEndValue(QPoint(300, 300));

    // 设置动画的持续时间 1s
    p_animation->setDuration(1000);

    // 连接按钮的点击信号到槽函数
    connect(p_button, &QPushButton::clicked, this, &Form15_Animation::startAnimation);
}

Form15_Animation::~Form15_Animation()
{
    delete ui;
    delete p_button;
    delete p_animation;
}


void Form15_Animation::startAnimation() {

    // 开始动画
    p_animation->start();
}
