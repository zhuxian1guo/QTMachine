#ifndef FORM8_OPENCV_H
#define FORM8_OPENCV_H

#include <QWidget>

namespace Ui {
class Form8_Opencv;
}

class Form8_Opencv : public QWidget
{
    Q_OBJECT

public:
    explicit Form8_Opencv(QWidget *parent = nullptr);
    ~Form8_Opencv();

private:
    Ui::Form8_Opencv *ui;
};

#endif // FORM8_OPENCV_H
