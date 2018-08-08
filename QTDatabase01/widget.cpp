#include "widget.h"
#include "ui_widget.h"
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlError>
#include <QMessageBox>
#include <QSqlQuery>
#include <QVariantList>
#define cout qDebug()

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    qDebug()<< QSqlDatabase::drivers();
    QSqlDatabase db= QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("../info.db");
    QSqlQuery query;
    if(!db.open()){
        QMessageBox::warning(this,"error",db.lastError().text());
        return;
    }
//    bool isok=query.exec("create table stu(id int(11) not null,username varchar(45),password varchar(45));");
//    query.prepare("insert into stu (id,username,password) values(?,?,?)");
//    QVariantList namelist;
//    namelist<<"张三"<<"赵六";
//    QVariantList plist;
//    plist<<"qwert"<<"12345";
//    query.addBindValue(namelist);
//    query.addBindValue(plist);
//    //批量插入
//    query.execBatch();

    //查询
    query.exec("select * from stu");
    while ( query.next()) {
        cout << query.value(0).toInt();
        cout << query.value(1).toString();
        cout << query.value("password").toString();
    }
}

Widget::~Widget()
{
    delete ui;
}
