#ifndef FORM15_ANIMATION_H
#define FORM15_ANIMATION_H

#include <QWidget>
#include "common.h"

namespace Ui {
class Form15_Animation;
}

class Form15_Animation : public QWidget
{
    Q_OBJECT

public:
    explicit Form15_Animation(QWidget *parent = nullptr);
    ~Form15_Animation();

private:
    Ui::Form15_Animation *ui;

private slots:
    void startAnimation();

private:
    QPushButton *p_button;
    QPropertyAnimation *p_animation;
};

#endif // FORM15_ANIMATION_H
