#ifndef FORM6_DRAW_H
#define FORM6_DRAW_H

#include <QWidget>

namespace Ui {
class Form6_Draw;
}

// 画板主窗口：顶部菜单栏 + 工具栏，下方是 CanvasWidget 画布。
// 绘画逻辑全部在 CanvasWidget 里，本类只负责 UI 和菜单动作转发。
class Form6_Draw : public QWidget
{
    Q_OBJECT

public:
    explicit Form6_Draw(QWidget *parent = nullptr);
    ~Form6_Draw();

private slots:
    void on_actionClear_triggered();    // 清空画布
    void on_actionExit_triggered();    // 退出
    void on_actionSave_triggered();    // 保存图片
    void on_actionPenColor_triggered(); // 画笔颜色
    void on_actionPenWidth_triggered(); // 画笔粗细
    void on_actionLine_triggered();     // 直线工具
    void on_actionRec_triggered();     // 矩形工具
    void on_actionCircle_triggered();  // 圆形工具

private:
    Ui::Form6_Draw *ui;
};

#endif // FORM6_DRAW_H
