#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "testextern.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// ++
void MainWindow::on_pushButton_clicked()
{
    QMessageBox::warning(this, "tishi", QString::number(LoadConstData()));

    bool ok1, ok2;
    int a = ui->lineEdit->text().toInt(&ok1);
    int b = ui->lineEdit->text().toInt(&ok2); // 实际开发中通常对应不同的
    int c=a+b;
    if (ok1 && ok2) {
        int c = a + b;
        // 可以在这里处理结果，例如显示在label上
        QMessageBox::warning(this, "错误", QString::number(c));
    } else {
        // 处理转换失败的情况，例如输入了非数字字符
        QMessageBox::warning(this, "错误", "请输入有效的整数");
    }
}

//clean
void MainWindow::on_pushButton_2_clicked()
{

}

