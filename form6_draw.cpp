#include "form6_draw.h"
#include "ui_form6_draw.h"
#include <QPainter>
#include <QPen>
#include <QRect>

Form6_Draw::Form6_Draw(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Form6_Draw)
{
    ui->setupUi(this);
    resize(600, 500);            // 窗口大小 600x500
    pix = QPixmap(600, 500);     // 创建与窗口同大小的后台画布
    pix.fill(Qt::white);         // 用白色填充背景
}

Form6_Draw::~Form6_Draw()
{
    delete ui;
}

// 从 lastPoint 画一条线段到 endPoint：
//   1) 直接画到后台画布 pix 上（窗口重绘时内容不会丢失）；
//   2) 只刷新被线段覆盖的那一小块矩形，而不是整个窗口；
//   3) 更新 lastPoint，作为下一段线的起点。
void Form6_Draw::drawLineTo(const QPoint &endPoint)
{
    QPainter pp(&pix);    // 在后台画布上作画
    pp.setRenderHint(QPainter::Antialiasing);                                    // 抗锯齿，线条更平滑
    pp.setPen(QPen(Qt::black, 3, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));   // 黑色、宽 3、圆头圆角
    pp.drawLine(lastPoint, endPoint);

    // 取线段的外接矩形，向外扩一点（笔宽的一半 + 余量），保证圆头边缘也被重绘
    const int rad = pp.pen().width() / 2 + 2;
    update(QRect(lastPoint, endPoint).normalized().adjusted(-rad, -rad, +rad, +rad));

    lastPoint = endPoint;   // 起点前移，下一段线从这里开始
}

void Form6_Draw::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)   // 按下左键：记录落笔起点
        lastPoint = event->pos();
}

void Form6_Draw::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton)   // 左键按住并移动：连续画线
        drawLineTo(event->pos());
}

void Form6_Draw::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)   // 松开左键：补齐到最后位置；单击（未移动）则画一个点
        drawLineTo(event->pos());
}

// 重绘事件：只负责把后台画布 pix 显示到控件上，绝不在里面画线或修改状态。
// event->rect() 是需要重绘的脏区域，只贴这部分即可，效率更高。
void Form6_Draw::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(event->rect(), pix, event->rect());
}
