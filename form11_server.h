#ifndef FORM11_SERVER_H
#define FORM11_SERVER_H

#include <QWidget>

namespace Ui {
class Form11_Server;
}

class Form11_Server : public QWidget
{
    Q_OBJECT

public:
    explicit Form11_Server(QWidget *parent = nullptr);
    ~Form11_Server();

private:
    Ui::Form11_Server *ui;
};

#endif // FORM11_SERVER_H
