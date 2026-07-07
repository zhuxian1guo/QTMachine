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
#include "form12_textedit.h"
#include "form13_logtype.h"
#include "common.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // 初始化全局日志(之后任何地方可调 customLog)
    customLogInit();
    QObject::connect(&a, &QApplication::aboutToQuit, [](){ customLogClose(); });
    customLog("Application started");

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

    // Form9_serialIODesign f9;  //串口调试界面
    // f9.show();

    // form10_dllDev f10;  //DLL 引用与打包
    // f10.show();

    // Form11_Server f11_0;  //服务端
    // f11_0.show();

    // Form11_Client f11_1; // 客户端
    // f11_1.show();

    // Form12_TextEdit f12;
    // f12 .show();

    Form13_LogType f13;
    f13.show();

    return a.exec();
}
