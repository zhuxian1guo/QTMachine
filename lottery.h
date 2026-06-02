#ifndef LOTTERY_H
#define LOTTERY_H

#include <QWidget>

namespace Ui {
class Lottery;
}

class Lottery : public QWidget
{
    Q_OBJECT

public:
    explicit Lottery(QWidget *parent = nullptr);
    ~Lottery();

private slots:
    void  displaynum();
    void  displaynum2();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    int generateRandomWithQRandomGenerator();

private:
    Ui::Lottery *ui;
    QTimer* timer;
    int totalValue;

};

#endif // LOTTERY_H
