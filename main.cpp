#include "calculator.h"
#include "lottery.h"
#include "mainwindow.h"
#include "countdown.h"
#include "Form6_Draw.h"
#include "vip_mgr.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // MainWindow w;
    // w.show();

    // countdown s;  //计时器 config
    // s.show();

    // Lottery s1; //彩票抽奖
    // s1.show();

    // Calculator s2;  //计算器
    // s2.show();

    // Form6_Draw f6; //绘图软件 eventDraw
    // f6.show();

    VIP_Mgr f7;  // vip 管理软件  增删改查
     f7.show();

    return a.exec();
}
