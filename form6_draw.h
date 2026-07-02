#ifndef FORM6_DRAW_H
#define FORM6_DRAW_H

#include <QWidget>

namespace Ui {
class Form6_Draw;
}

class Form6_Draw : public QWidget
{
    Q_OBJECT

public:
    explicit Form6_Draw(QWidget *parent = nullptr);
    ~Form6_Draw();

    QPixmap pix;
    QPoint lastPoint;
    QPoint endPoint;

private:
    Ui::Form6_Draw *ui;

protected:
    void paintEvent(QPaintEvent *) override;
    void mousePressEvent(QMouseEvent *) override;
    void mouseMoveEvent(QMouseEvent *) override;
    void mouseReleaseEvent(QMouseEvent *) override;
};

#endif // FORM6_DRAW_H
