#include "form6_draw.h"
#include "ui_form6_draw.h"
#include  "QMouseEvent"
#include "QPainter"

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


void Form6_Draw::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) // mouse left down
        lastPoint = event->pos();
}

void Form6_Draw::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons()&Qt::LeftButton) // mouse left down and move
    {
        endPoint = event->pos();
        update(); // trigger painter function
    }
}

void Form6_Draw::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) //mouse left release
    {
        endPoint = event->pos();
        update();
    }
}


void Form6_Draw::paintEvent(QPaintEvent *)
{
    QPainter pp(&pix);    // pix is the QPixmap
    pp.setPen(QPen(QBrush(Qt::black), 3, Qt::SolidLine)); // set width
    pp.drawLine(lastPoint, endPoint);    // paint line now

    lastPoint = endPoint;
    QPainter painter(this);
    painter.drawPixmap(0, 0, pix);
}
