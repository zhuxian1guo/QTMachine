#include "calculator.h"
#include "lottery.h"
#include "mainwindow.h"
#include "countdown.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    // countdown s;
    // s.show();

    // Lottery s1;
    // s1.show();

    // Calculator s2;
    // s2.show();

    return a.exec();
}
