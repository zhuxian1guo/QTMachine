#ifndef COUNTDOWN_H
#define COUNTDOWN_H

#include <QWidget>
#include <QButtonGroup>

namespace Ui {
class countdown;
}

class countdown : public QWidget
{
    Q_OBJECT

public:
    explicit countdown(QWidget *parent = nullptr);
    ~countdown();


private slots:
    void on_pushButton_clicked();
    void mtd_cutdown();
      void display_number();
    void display_number2();

private:
    Ui::countdown *ui;
        int a1,a2,a3,a4;
        bool ok1,ok2,ok3,ok4;
        bool isclickbtn=false;
        QTimer *timer;
        int total;
        int type_displaynum=0;
        QButtonGroup* mBtnGroupEdu;
};

#endif // COUNTDOWN_H
