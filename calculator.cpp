#include "calculator.h"
#include "qlineedit.h"
#include "ui_calculator.h"
#include <QGridLayout>
#include <QPushButton>

// function declaration
// 声明
static double calculate(QString str);

// 定义（在文件底部或任何位置）
// static double calculate(QString str) {
//     // 解析字符串并计算
//     return 0.0;
// }

// transfer the string to the calculated result
//https://blog.csdn.net/be_quiet_endeavor/article/details/78847565
//
static double calculate(QString str)
{
    if (str.indexOf("+") != -1)
    {
        int i = str.indexOf("+");
        return calculate(str.left(i)) + calculate(str.right(str.length() - 1 - i));
    }

    if (str.indexOf("-") != -1)
    {
        QStringList list = str.split('-');
        double value = calculate(list[0]);
        if (str.at(0) == "-")
            value = -value;
        for (int i = 1; i < list.count(); ++i)
        {
            value -= calculate(list[i]);
        }
        return value;
    }

    if (str.indexOf("*") != -1)
    {
        int i = str.indexOf("*");
        return calculate(str.left(i))*calculate(str.right(str.length() - 1 - i));
    }

    if (str.indexOf("/") != -1)
    {
        QStringList list = str.split('/');
        double value = calculate(list[0]);
        for (int i = 1; i < list.count(); ++i)
        {
            value /= calculate(list[i]);
        }
        return value;
    }

    return str.toDouble();
}



Calculator::Calculator(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Calculator)
{
    ui->setupUi(this);

    this->setWindowTitle("Calculator");
    this->setFixedWidth(600);
    this->setFixedHeight(400);

    // 1. 创建网格布局对象
    QGridLayout *gridLayout = new QGridLayout(this);

    // 2. 设置布局的间距和边距（可选）
    gridLayout->setSpacing(10);
    gridLayout->setContentsMargins(10, 10, 10, 10);

    //添加LineEdit
    QLineEdit*LE=new QLineEdit();
    gridLayout->addWidget(LE,0,0,1,4);

    // create the buttons
    const QStringList buttonsText = {
        "7", "8", "9", "-",
        "4", "5", "6", "*",
        "1", "2", "3", "/",
        "0", ".", "+", "="
    };

    // add the buttons to the layout
    for (int i = 0; i < 16; ++i) {
        QPushButton *button = new QPushButton(buttonsText[i]);
        button->setFixedHeight(40);
       //  gridLayout->addWidget(button);
        //‌1 + i / 4 (行索引 row)‌:   i % 4 (列索引 column)‌:   4列网格‌
        gridLayout->addWidget(button, 1 + i / 4, i % 4);

        #pragma region 按键赋值 {
            if (buttonsText[i] == "=") {  //  =
                QObject::connect(button, &QPushButton::clicked, [&] {
                    QString expression = LE->text();
                    LE->setText(QString::number(calculate(expression)));
                });
            }
            else if(buttonsText[i] == "+"){  //+
                QObject::connect(button, &QPushButton::clicked, [&] {
                   // 记录参数1
                    bool ok = false;
                    Du1=LE->text().toDouble(&ok);
                    // LE->setText(""); //清空
                    isadd=true;

                });
            }
            else if(buttonsText[i] == "-"){
            }
            else if(buttonsText[i] == "*"){
            }
            else if(buttonsText[i] == "/"){
            }
            else {  //  单个按钮
                QObject::connect(button, &QPushButton::clicked, [=] {
                    // append the clicked button's text to the display
                    LE->setText(LE->text() + button->text());
                });
            }
        #pragma endregion Region_1}

    }


    /*
        addWidget 的参数含义：(控件指针, 行索引, 列索引, 行跨度, 列跨度)。
        0, 0：表示控件放置在第 0 行、第 0 列。
        1, 4：表示该控件占据 ‌1 行‌ 和 ‌4 列‌ 的空间。
    */


    // 如果你还没有在 UI 设计器中放置控件，可以动态创建并添加
    // QPushButton *btn1 = new QPushButton("1", this);
    // QPushButton *btn2 = new QPushButton("2", this);
    // QPushButton *btn3 = new QPushButton("3", this);
    // QPushButton *btnPlus = new QPushButton("+", this);

    // gridLayout->addWidget(btn1, 1, 0);
    // gridLayout->addWidget(btn2, 1, 1);
    // gridLayout->addWidget(btn3, 2, 0);
    // gridLayout->addWidget(btnPlus, 2, 1);

    this->setLayout(gridLayout);

}


//  QString Calculator::calculate(QString str){
//      return str;
// }


Calculator::~Calculator()
{
    delete ui;
}
