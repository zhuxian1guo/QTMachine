/*//add Btn
    //添加到Table tableWidget
*/
#include "form14_vipconsum.h"
#include "ui_form14_vipconsum.h"

Form14_VIPConsum::Form14_VIPConsum(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form14_VIPConsum)
{
    ui->setupUi(this);

    // 初始化表格:4 列 + 表头
    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->setHorizontalHeaderLabels(
        QStringList() << "First Name" << "Last Name" << "Age" << "Sum");
    // 整行选中、不可编辑、列宽自适应
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

Form14_VIPConsum::~Form14_VIPConsum()
{
    delete ui;
}



//FIRST NAME
void Form14_VIPConsum::on_lineEdit_textChanged(const QString &arg1)
{
    m_firstName = arg1;
}

//LAST NAME
void Form14_VIPConsum::on_lineEdit_2_textChanged(const QString &arg1)
{
    m_lastName = arg1;
}

//AGE
void Form14_VIPConsum::on_lineEdit_3_textChanged(const QString &arg1)
{
    m_age = arg1;
}

//SUM
void Form14_VIPConsum::on_lineEdit_4_textChanged(const QString &arg1)
{
    m_sum = arg1;
}


//add Btn
void Form14_VIPConsum::on_pushButton_clicked()
{
    //添加到Table
    const int row = ui->tableWidget->rowCount();   // 新行号
    ui->tableWidget->insertRow(row);

    // 把 4 个字段写入该行的 4 列
    ui->tableWidget->setItem(row, 0, new QTableWidgetItem(m_firstName));
    ui->tableWidget->setItem(row, 1, new QTableWidgetItem(m_lastName));
    ui->tableWidget->setItem(row, 2, new QTableWidgetItem(m_age));
    ui->tableWidget->setItem(row, 3, new QTableWidgetItem(m_sum));

    // 滚到最底,让新行可见
    ui->tableWidget->scrollToBottom();
}

