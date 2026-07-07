#include "form6_draw.h"
#include "ui_form6_draw.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QColorDialog>
#include <QInputDialog>
#include <QMenuBar>
#include <QToolBar>
#include <QSizePolicy>
#include <QActionGroup>

Form6_Draw::Form6_Draw(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Form6_Draw)
{
    ui->setupUi(this);
    resize(800, 600);

    // 去掉菜单栏与工具栏之间的空白:
    ui->menuBar->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    ui->menuBar->setContentsMargins(0, 0, 0, 0);
    ui->mainToolBar->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    ui->mainToolBar->layout()->setContentsMargins(0, 0, 0, 0);

    // 把"线/矩形/圆形"设为可选中的互斥工具(默认选中自由画线之外的语义:
    // 这里默认不选任何形状 = 自由画线,选中其一则进入该形状模式)
    QActionGroup *shapeGroup = new QActionGroup(this);
    shapeGroup->setExclusive(true);
    ui->actionLine->setCheckable(true);
    ui->actionRec->setCheckable(true);
    ui->actionCircle->setCheckable(true);
    shapeGroup->addAction(ui->actionLine);
    shapeGroup->addAction(ui->actionRec);
    shapeGroup->addAction(ui->actionCircle);
    // 默认自由画线:三个都不选
}

Form6_Draw::~Form6_Draw()
{
    delete ui;
}

// 清空画布
void Form6_Draw::on_actionClear_triggered()
{
    ui->canvasWidget->clearCanvas();
}

// 退出
void Form6_Draw::on_actionExit_triggered()
{
    close();
}

// 保存为图片文件
void Form6_Draw::on_actionSave_triggered()
{
    const QString path = QFileDialog::getSaveFileName(
        this, tr("保存图片"), "drawing.png",
        tr("PNG 图片 (*.png);;JPEG 图片 (*.jpg)"));
    if (path.isEmpty())
        return;
    if (!ui->canvasWidget->saveImage(path))
        QMessageBox::warning(this, tr("保存失败"), tr("无法写入文件：\n") + path);
}

// 画笔颜色
void Form6_Draw::on_actionPenColor_triggered()
{
    const QColor c = QColorDialog::getColor(Qt::black, this, tr("画笔颜色"));
    ui->canvasWidget->setPenColor(c);
}

// 画笔粗细
void Form6_Draw::on_actionPenWidth_triggered()
{
    bool ok = false;
    const int w = QInputDialog::getInt(
        this, tr("画笔粗细"), tr("像素 (1-50):"), 3, 1, 50, 1, &ok);
    if (ok)
        ui->canvasWidget->setPenWidth(w);
}

// 直线工具:选中=直线,取消选中=自由画线
void Form6_Draw::on_actionLine_triggered()
{
    if (ui->actionLine->isChecked())
        ui->canvasWidget->setShape(CanvasWidget::Line);
    else
        ui->canvasWidget->setShape(CanvasWidget::FreeDraw);
}

// 矩形工具
void Form6_Draw::on_actionRec_triggered()
{
    if (ui->actionRec->isChecked())
        ui->canvasWidget->setShape(CanvasWidget::Rect);
    else
        ui->canvasWidget->setShape(CanvasWidget::FreeDraw);
}

// 圆形工具
void Form6_Draw::on_actionCircle_triggered()
{
    if (ui->actionCircle->isChecked())
        ui->canvasWidget->setShape(CanvasWidget::Circle);
    else
        ui->canvasWidget->setShape(CanvasWidget::FreeDraw);
}
