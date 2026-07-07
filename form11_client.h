#ifndef FORM11_CLIENT_H
#define FORM11_CLIENT_H

#include <QWidget>

namespace Ui {
class Form11_Client;
}

class Form11_Client : public QWidget
{
    Q_OBJECT

public:
    explicit Form11_Client(QWidget *parent = nullptr);
    ~Form11_Client();

private:
    Ui::Form11_Client *ui;
};

#endif // FORM11_CLIENT_H
