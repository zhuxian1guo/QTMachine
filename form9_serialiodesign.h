#ifndef FORM9_SERIALIODESIGN_H
#define FORM9_SERIALIODESIGN_H

#include <QWidget>

namespace Ui {
class Form9_serialIODesign;
}

class Form9_serialIODesign : public QWidget
{
    Q_OBJECT

public:
    explicit Form9_serialIODesign(QWidget *parent = nullptr);
    ~Form9_serialIODesign();

private:
    Ui::Form9_serialIODesign *ui;
};

#endif // FORM9_SERIALIODESIGN_H
