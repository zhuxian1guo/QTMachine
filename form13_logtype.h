#ifndef FORM13_LOGTYPE_H
#define FORM13_LOGTYPE_H

#include <QWidget>

namespace Ui {
class Form13_LogType;
}

class Form13_LogType : public QWidget
{
    Q_OBJECT

public:
    explicit Form13_LogType(QWidget *parent = nullptr);
    ~Form13_LogType();

private:
    Ui::Form13_LogType *ui;
};

#endif // FORM13_LOGTYPE_H
