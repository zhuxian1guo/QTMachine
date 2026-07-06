#ifndef VIP_MGR_H
#define VIP_MGR_H

#include <QWidget>
#include <vector>
#include <string>

namespace Ui {
class VIP_Mgr;
}

class VIP_Mgr : public QWidget
{
    Q_OBJECT

public:
    explicit VIP_Mgr(QWidget *parent = nullptr);
    void loadFile();
    void  updateData();
    void  onRadioButtonToggled(bool checked);
    int type_num;
    QString lineEdit_id;
    QString lineEdit_name;
    int loadDB();
    ~VIP_Mgr();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

    void on_lineEdit_2_textChanged(const QString &arg1);

private:
    Ui::VIP_Mgr *ui;
    std::vector<int> id_array_;            // 存放每条记录的 ID
    std::vector<std::string> name_array_;  // 存放每条记录的 NAME
};

#endif // VIP_MGR_H
