#ifndef VIP_MGR_H
#define VIP_MGR_H

#include <QWidget>

namespace Ui {
class VIP_Mgr;
}

class VIP_Mgr : public QWidget
{
    Q_OBJECT

public:
    explicit VIP_Mgr(QWidget *parent = nullptr);
    ~VIP_Mgr();

private:
    Ui::VIP_Mgr *ui;
};

#endif // VIP_MGR_H
