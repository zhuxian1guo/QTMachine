/*菜单栏 工具栏 状态栏*/
#include "form12_textedit.h"
#include "ui_form12_textedit.h"
#include <QLabel>
#include    <QMessageBox>

Form12_TextEdit::Form12_TextEdit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form12_TextEdit)
{
    ui->setupUi(this);
    // add label for status bar
    QLabel *label = new QLabel("@V1.0", this);
    ui->statusBar->addWidget(label);

   // connect(ui->actionNew,SIGNAL(triggered()),this,SLOT(tips()));
    connect(ui->actionNew, &QAction::triggered, this, &Form12_TextEdit::tips);
}

void Form12_TextEdit::tips()
{
  QMessageBox::information(nullptr,"new","是是是");
}


Form12_TextEdit::~Form12_TextEdit()
{
    delete ui;
}
