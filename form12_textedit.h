#ifndef FORM12_TEXTEDIT_H
#define FORM12_TEXTEDIT_H

#include <QWidget>

namespace Ui {
class Form12_TextEdit;
}

class Form12_TextEdit : public QWidget
{
    Q_OBJECT

public:
    explicit Form12_TextEdit(QWidget *parent = nullptr);
    ~Form12_TextEdit();
    void  tips();

private:
    Ui::Form12_TextEdit *ui;
};

#endif // FORM12_TEXTEDIT_H
