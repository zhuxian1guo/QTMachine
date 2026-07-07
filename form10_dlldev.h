/* DLL 引用*/
#ifndef FORM1__DLLDEV_H
#define FORM1__DLLDEV_H

#include <QWidget>

namespace Ui {
class form10_dllDev;
}

class form10_dllDev : public QWidget
{
    Q_OBJECT

public:
    explicit form10_dllDev(QWidget *parent = nullptr);
    ~form10_dllDev();

private:
    Ui::form10_dllDev *ui;
};

#endif // FORM1__DLLDEV_H
