#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QWidget>

namespace Ui {
class Calculator;
}

class Calculator : public QWidget
{
    Q_OBJECT

public:
    explicit Calculator(QWidget *parent = nullptr);
    ~Calculator();
    //QString  calculate();

public:
    double Du1;
    bool isDivid;
    bool isadd;
    bool ismuti;
    bool issubs;

private:
    Ui::Calculator *ui;
};

#endif // CALCULATOR_H
