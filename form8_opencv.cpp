#include "form8_opencv.h"
#include "ui_form8_opencv.h"
#include <opencv2/opencv.hpp>
#include <QImage>
#include <QPixmap>
#include <QLabel>
#include <QVBoxLayout>

Form8_Opencv::Form8_Opencv(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form8_Opencv)
{
    ui->setupUi(this);

    // 读取图像
    cv::Mat originalImage = cv::imread("lena.png");

    // 将图像灰度化
    cv::Mat grayImage;
    cv::cvtColor(originalImage, grayImage, cv::COLOR_BGR2GRAY);

    // 将灰度图像进行二值化处理
    cv::Mat binaryImage;
    cv::threshold(grayImage, binaryImage, 128, 255, cv::THRESH_BINARY);

    // 将OpenCV二值化图像转换为Qt图像
    QImage qImage(binaryImage.data, binaryImage.cols, binaryImage.rows, binaryImage.step, QImage::Format_Grayscale8);
    QPixmap pixmap = QPixmap::fromImage(qImage);

    // 在Qt界面中显示二值化图像
    // 用 new 在堆上创建并 parent=this，对象归窗口管理，随窗口显示/销毁；
    // 放进布局才会自动排列。不能用局部变量 QLabel label;（构造函数结束就被销毁）。
    QLabel *label = new QLabel(this);
    label->setPixmap(pixmap);
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(label);

}

Form8_Opencv::~Form8_Opencv()
{
    delete ui;
}
