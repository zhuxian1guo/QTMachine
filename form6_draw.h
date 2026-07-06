#ifndef FORM6_DRAW_H
#define FORM6_DRAW_H

#include <QWidget>
#include <QMouseEvent>
#include <QPixmap>
#include <QPoint>


namespace Ui {
class Form6_Draw;
}

// 简易画板控件：按住鼠标左键拖动即可在画布上绘制黑色线条。
// 采用“后台 QPixmap 缓存 + paintEvent 贴图”的方式：
//   - 真正的画线在鼠标事件中完成，并写入后台画布 pix；
//   - paintEvent 只负责把 pix 显示到屏幕上，不画线、不改状态。
class Form6_Draw : public QWidget
{
    Q_OBJECT

public:
    explicit Form6_Draw(QWidget *parent = nullptr);
    ~Form6_Draw();

    QPixmap pix;        // 后台画布，所有线条都画在这里，窗口重绘时内容不会丢失
    QPoint lastPoint;   // 上一次落笔的位置（下一段线段的起点）

private:
    void drawLineTo(const QPoint &endPoint);   // 从 lastPoint 画线到 endPoint，并刷新对应区域、更新 lastPoint
    Ui::Form6_Draw *ui;

protected:
    void paintEvent(QPaintEvent *) override;          // 只把 pix 贴到控件上，不在此处画线
    void mousePressEvent(QMouseEvent *) override;     // 左键按下：记录落笔起点
    void mouseMoveEvent(QMouseEvent *) override;      // 左键按住移动：连续画线
    void mouseReleaseEvent(QMouseEvent *) override;   // 左键松开：补齐最后一段（单击则画一个点）
};

#endif // FORM6_DRAW_H
