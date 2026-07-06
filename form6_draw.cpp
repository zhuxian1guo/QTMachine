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
    resize(600, 500);    // windows size is 600 by 500
    pix = QPixmap(600, 500);
    pix.fill(Qt::white);
}

Form6_Draw::~Form6_Draw()
{
    delete ui;
}


void Form6_Draw::drawLineTo(const QPoint &endPoint)
{
    QPainter pp(&pix);    // draw the new segment straight onto the backing pixmap
    pp.setRenderHint(QPainter::Antialiasing);
    pp.setPen(QPen(Qt::black, 3, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    pp.drawLine(lastPoint, endPoint);

    // repaint only the region that actually changed
    const int rad = pp.pen().width() / 2 + 2;
    update(QRect(lastPoint, endPoint).normalized().adjusted(-rad, -rad, +rad, +rad));

    lastPoint = endPoint;
}

void Form6_Draw::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)   // mouse left down
        lastPoint = event->pos();
}

void Form6_Draw::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton)   // mouse left down and move
        drawLineTo(event->pos());
}

void Form6_Draw::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)   // mouse left release: close the stroke (or a dot on a click)
        drawLineTo(event->pos());
}


void Form6_Draw::paintEvent(QPaintEvent *event)
{
    // paintEvent must only display the backing pixmap — never draw into it.
    QPainter painter(this);
    painter.drawPixmap(event->rect(), pix, event->rect());
}
