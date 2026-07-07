#include "calculator.h"
#include "lottery.h"
#include "mainwindow.h"
#include "countdown.h"
#include "Form6_Draw.h"
#include "vip_mgr.h"
#include "form8_opencv.h"
#include  "form9_serialiodesign.h"
#include "form10_dlldev.h"
#include <QApplication>
#include "form11_client.h"
#include    "form11_server.h"

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

    // VIP_Mgr f7;  // vip 管理软件  增删改查
    //  f7.show();

    // Form8_Opencv f8;  //opencv
    // f8.show();

    // Form9_serialIODesign f9;
    // f9.show();

    // form10_dllDev f10;
    // f10.show();

    Form11_Server f11_0;
    f11_0.show();

    Form11_Client f11_1;
    f11_1.show();

    return a.exec();
}
