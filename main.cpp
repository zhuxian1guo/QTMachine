#include "calculator.h"
#include "lottery.h"
#include "mainwindow.h"
#include "countdown.h"
#include "Form6_Draw.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    // countdown s;  //计时器
    // s.show();

    // Lottery s1; //彩票抽奖
    // s1.show();

    Calculator s2;  //计算器
    s2.show();

    Form6_Draw f6;
    f6.show();

    return a.exec();
}
