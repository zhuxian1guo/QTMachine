/*增删改查 json序列号 反序列化（json-Object）数据库*/
#include "vip_mgr.h"
#include "ui_vip_mgr.h"
#include <QFile>
#include <QCoreApplication>
#include <QDebug>
#include  <QJsonDocument>
#include  <QJsonObject>
#include  <QJsonArray>
#include <algorithm>
#include <QtSql/QtSql>
// #include <QtWidgetsApplication>
// #include <>



VIP_Mgr::VIP_Mgr(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::VIP_Mgr)
{
    ui->setupUi(this);
    ui->radioButton->setChecked(true);
    type_num=0;

    connect(ui->radioButton,&QRadioButton::toggled,this,&VIP_Mgr::onRadioButtonToggled);
    connect(ui->radioButton_2,&QRadioButton::toggled,this,&VIP_Mgr::onRadioButtonToggled);
    connect(ui->radioButton_3,&QRadioButton::toggled,this,&VIP_Mgr::onRadioButtonToggled);
    connect(ui->radioButton_4,&QRadioButton::toggled,this,&VIP_Mgr::onRadioButtonToggled);

    loadFile(); // load data from json file

    updateData();
}


//读取json文件：从 data.json 中加载 VIP 数据，解析后存入 id_array_ 和 name_array_
void VIP_Mgr::loadFile()
{
    // 1. 打开文件（只读 + 文本模式）；打不开则打印日志并直接返回
    QFile file(QCoreApplication::applicationDirPath() + "/data.json");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Failed to open JSON file";
        return;
    }

    // 2. 一次性读出全部内容，读完即关闭文件
    QByteArray jsonData = file.readAll();
    file.close();

    // 3. 把字节流解析成 QJsonDocument；格式非法时 isNull() 为真，直接返回
    QJsonDocument jsonDocument = QJsonDocument::fromJson(jsonData);
    if (jsonDocument.isNull()) {
        qDebug() << "Failed to create JSON document";
        return;
    }

    // 4. 取出根对象，读取记录总数 count
    QJsonObject jsonObject = jsonDocument.object();
    int num = jsonObject["count"].toInt();   // 记录条数（注：下面循环用的是数组长度，num 暂未使用）

    // get items：取出 items 数组
    QJsonArray itemsArray = jsonObject["items"].toArray();

    // read data from items：遍历数组，逐条解析
    for (int i = 0; i < itemsArray.size(); ++i) {
        QJsonValue itemValue = itemsArray.at(i);
        if (itemValue.isObject()) {
            QJsonObject itemObject = itemValue.toObject();

            // read data：取出每条的 ID 和 NAME
            int id = itemObject["ID"].toInt();
            QString name = itemObject["NAME"].toString();

            id_array_.push_back(id);                   // 存入成员容器 id_array_
            name_array_.push_back(name.toStdString()); // QString 转 std::string 后存入 name_array_
        }
    }
}

void  VIP_Mgr::updateData(){
    QString s = "";
    int i;

    for (i = 0; i < (int)id_array_.size(); i++)
    {
        s += QString::number(id_array_[i]);              // int 转 QString
        s += " ";
        s += QString::fromStdString(name_array_[i]);     // std::string 转 QString
        s += "\n";
    }

    ui->textEdit->setPlainText(s);                       // ui 是指针，用 ->；s 已是 QString

};



void  VIP_Mgr::onRadioButtonToggled(bool checked){
      qDebug()<<sender();
      //C++ 规定 switch 的表达式必须是整型或枚举。sender() 返回的是 QObject*（指针），编译器会报： switch quantity not an integer
      if (!checked) return;          // 只处理"被选中"的那次
      QObject *obj = sender();
      if (obj == ui->radioButton)
      { type_num=0;qDebug()<<type_num;}
      else if (obj == ui->radioButton_2)
          { type_num=1; qDebug()<<type_num;}
      else if (obj == ui->radioButton_3)
            { type_num=2;qDebug()<<type_num;}
      else if (obj == ui->radioButton_4)
               {type_num=3;qDebug()<<type_num;}
}


VIP_Mgr::~VIP_Mgr()
{
    delete ui;
}


// OK Btn
void VIP_Mgr::on_pushButton_2_clicked()
{
     qDebug()<<type_num;
    switch (type_num) {
    case 0:
        //add
        qDebug()<<"add";
       id_array_.push_back(lineEdit_id.toInt());   // QString 转 int
       name_array_.push_back(lineEdit_name.toStdString());
       updateData();
        break;
    case 1: {   //del：按 ID 删除一条记录（两个平行数组同下标一起删）
        int targetId = lineEdit_id.toInt();
        auto it = std::find(id_array_.begin(), id_array_.end(), targetId);
        if (it != id_array_.end()) {
            int idx = int(it - id_array_.begin());   // 该记录在数组里的下标
            id_array_.erase(id_array_.begin() + idx);
            name_array_.erase(name_array_.begin() + idx);
            updateData();
        } else {
            qDebug() << "未找到 ID =" << targetId;
        }
        break;
    }
    case 2:
        //update
        qDebug()<<"update";
       // id_array_.push_back(lineEdit_id.toInt());   // QString 转 int
       // name_array_.push_back(lineEdit_name.toStdString());
       updateData();
        break;
    case 3: {   //select：按 ID 查询一条记录
        int targetId = lineEdit_id.toInt();
        auto it = std::find(id_array_.begin(), id_array_.end(), targetId);
        if (it != id_array_.end()) {
            int idx = int(it - id_array_.begin());                  // 该记录的下标
            QString name = QString::fromStdString(name_array_[idx]); // 平行数组取对应 NAME
            ui->textEdit->setPlainText("ID: " + QString::number(targetId)
                                     + "\nNAME: " + name);           // 只显示查到的那一条
        } else {
            ui->textEdit->setPlainText("未找到 ID = " + QString::number(targetId));
        }
        break;
    }
    default:
        break;
    }
}

// 取消
void VIP_Mgr::on_pushButton_clicked()
{

}

//Save Btn：把内存里的 id_array_ / name_array_ 写回 data.json（loadFile 的逆操作）
void VIP_Mgr::on_pushButton_3_clicked()
{
    // 1. 组装 JSON：根对象含 count 和 items 数组
    QJsonObject root;
    root["count"] = (int)id_array_.size();

    QJsonArray itemsArray;
    for (int i = 0; i < (int)id_array_.size(); ++i) {
        QJsonObject item;
        item["ID"]   = id_array_[i];                            // int -> QJsonValue
        item["NAME"] = QString::fromStdString(name_array_[i]);  // std::string -> QString -> QJsonValue
        itemsArray.append(item);
    }
    root["items"] = itemsArray;

    // 2. 打开文件（只写 + 文本模式）；打不开则打印日志并返回
    QFile file(QCoreApplication::applicationDirPath() + "/data.json");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Failed to open file for writing";
        return;
    }

    // 3. 把 JSON 文档转成字节流写入文件
    QJsonDocument doc(root);
    file.write(doc.toJson());   // 默认 Indented 格式，带缩进，方便人读
    file.close();

    // 4. 同步存入数据库 data.db（表 mytable: id, name）
    QSqlDatabase db = QSqlDatabase::contains()
            ? QSqlDatabase::database()
            : QSqlDatabase::addDatabase("QSQLITE");   // 复用默认连接，避免重复 add 的警告
    db.setDatabaseName(QCoreApplication::applicationDirPath() + "/data.db");
    if (!db.open()) {
        qDebug() << "Failed to open database";
        return;
    }

    QSqlQuery query(db);
    query.exec("CREATE TABLE IF NOT EXISTS mytable (id INTEGER PRIMARY KEY, name TEXT)");
    query.exec("DELETE FROM mytable");                 // 先清空，让数据库和内存数组保持一致

    // 预处理：先准备 SQL 模板，? 是占位符，后面用 addBindValue 按顺序填值
    query.prepare("INSERT INTO mytable (id, name) VALUES (?, ?)");
    for (int i = 0; i < (int)id_array_.size(); ++i) {
        query.addBindValue(id_array_[i]);                           // 填第 1 个 ?：id
        query.addBindValue(QString::fromStdString(name_array_[i])); // 填第 2 个 ?：name（std::string 转 QString）
        query.exec();                                               // 执行一次插入；模板复用，不用重新 prepare
    }
    db.close();   // 关闭数据库连接
}


//ID
void VIP_Mgr::on_lineEdit_textChanged(const QString &arg1)
{
    qDebug()<<arg1;
    lineEdit_id=arg1;
}

//Name
void VIP_Mgr::on_lineEdit_2_textChanged(const QString &arg1)
{
      qDebug()<<arg1;
      lineEdit_name=arg1;
}


//数据库
int VIP_Mgr::loadDB()
{
    // create database
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(QCoreApplication::applicationDirPath() + "/data.db");

    // open database
    if (!db.open()) {
        qDebug() << "Error: Unable to open database";
        return 1;
    }

    // execute query
    QSqlQuery query;

    // create a table
    if (!query.exec("CREATE TABLE IF NOT EXISTS mytable (id INTEGER PRIMARY KEY, name TEXT)")) {
        qDebug() << "Error: Unable to create table";
        return 1;
    }

    // insert data
    if (!query.exec("INSERT INTO mytable (name) VALUES ('John Doe')")) {
        qDebug() << "Error: Unable to insert data";
        return 1;
    }

    // query data
    if (query.exec("SELECT * FROM mytable")) {
        qDebug() << "Records in mytable:";
        while (query.next()) {
            int id = query.value(0).toInt();
            QString name = query.value(1).toString();
            qDebug() << "ID:" << id << "Name:" << name;
        }
    }
    else {
        qDebug() << "Error: Unable to fetch data";
        return 1;
    }

    // update data
    if (!query.exec("UPDATE mytable SET name='Jane Doe' WHERE id=1")) {
        qDebug() << "Error: Unable to update data";
        return 1;
    }

    // query data after update
    if (query.exec("SELECT * FROM mytable")) {
        qDebug() << "Records in mytable after update:";
        while (query.next()) {
            int id = query.value(0).toInt();
            QString name = query.value(1).toString();
            qDebug() << "ID:" << id << "Name:" << name;
        }
    }
    else {
        qDebug() << "Error: Unable to fetch data";
        return 1;
    }

    // delete data
    if (!query.exec("DELETE FROM mytable WHERE id=1")) {
        qDebug() << "Error: Unable to delete data";
        return 1;
    }

    // query after delete
    if (query.exec("SELECT * FROM mytable")) {
        qDebug() << "Records in mytable after delete:";
        while (query.next()) {
            int id = query.value(0).toInt();
            QString name = query.value(1).toString();
            qDebug() << "ID:" << id << "Name:" << name;
        }
    }
    else {
        qDebug() << "Error: Unable to fetch data";
        return 1;
    }

    // close connection of database
    db.close();
    return 0;   // 成功返回 0
}
