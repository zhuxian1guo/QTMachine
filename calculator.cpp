#include "calculator.h"
#include "qlineedit.h"
#include "ui_calculator.h"
#include <QGridLayout>
#include <QPushButton>

Calculator::Calculator(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Calculator)
{
    ui->setupUi(this);
    // 1. 创建网格布局对象
    QGridLayout *gridLayout = new QGridLayout(this);

    // 2. 设置布局的间距和边距（可选）
    gridLayout->setSpacing(10);
    gridLayout->setContentsMargins(10, 10, 10, 10);

    QLineEdit*LE=new QLineEdit();

    gridLayout->addWidget(LE,0,0,1,4);
    /*
        addWidget 的参数含义：(控件指针, 行索引, 列索引, 行跨度, 列跨度)。
        0, 0：表示控件放置在第 0 行、第 0 列。
        1, 4：表示该控件占据 ‌1 行‌ 和 ‌4 列‌ 的空间。
    */


    // 如果你还没有在 UI 设计器中放置控件，可以动态创建并添加
    QPushButton *btn1 = new QPushButton("1", this);
    QPushButton *btn2 = new QPushButton("2", this);
    QPushButton *btn3 = new QPushButton("3", this);
    QPushButton *btnPlus = new QPushButton("+", this);

    gridLayout->addWidget(btn1, 1, 0);
    gridLayout->addWidget(btn2, 1, 1);
    gridLayout->addWidget(btn3, 2, 0);
    gridLayout->addWidget(btnPlus, 2, 1);

    this->setLayout(gridLayout);

}

Calculator::~Calculator()
{
    delete ui;
}
