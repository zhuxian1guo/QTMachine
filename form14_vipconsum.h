#ifndef FORM14_VIPCONSUM_H
#define FORM14_VIPCONSUM_H

#include <QWidget>
#include <QString>

namespace Ui {
class Form14_VIPConsum;
}

class Form14_VIPConsum : public QWidget
{
    Q_OBJECT

public:
    explicit Form14_VIPConsum(QWidget *parent = nullptr);
    ~Form14_VIPConsum();

private slots:
    void on_lineEdit_textChanged(const QString &arg1);

    void on_lineEdit_2_textChanged(const QString &arg1);

    void on_lineEdit_3_textChanged(const QString &arg1);

    void on_lineEdit_4_textChanged(const QString &arg1);

    void on_pushButton_clicked();

private:
    Ui::Form14_VIPConsum *ui;

    // 表单字段缓存(在对应 textChanged 槽里赋值)
    QString m_firstName;   // FIRST NAME
    QString m_lastName;    // LAST NAME
    QString m_age;         // AGE
    QString m_sum;         // SUM
};

#endif // FORM14_VIPCONSUM_H
