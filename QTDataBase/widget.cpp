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
    QSqlDatabase db= QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setUserName("root");
    db.setPassword("root");
    db.setDatabaseName("user");
    if(!db.open()){
        QMessageBox::warning(this,"error",db.lastError().text());
        return;
    }
    QSqlQuery query;
    //bool isok=query.exec("create table stu(id int(11) not null,username varchar(45));");

    //qDebug()<<isok;;
    //query.exec("insert into stu(username) values('lisi')");
//    query.prepare("insert into user (username,password) values(?,?)");
//    QVariantList namelist;
//    namelist<<"张三"<<"赵六";
//    QVariantList plist;
//    plist<<"qwert"<<"12345";
//    query.addBindValue(namelist);
//    query.addBindValue(plist);
//    //批量插入
//    query.execBatch();

    //oracle 风格
//    query.prepare("insert into user (username,password) values(:name,:pwd)");
//    QVariantList namelist;
//    namelist<<"zhangsan"<<"zhaoliu";
//    QVariantList plist;
//    plist<<"qwert"<<"12345";
//    query.bindValue(":name",namelist);
//    query.bindValue(":pwd",plist);
//    query.execBatch();

    //查询
    query.exec("select * from user");
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

void Widget::on_pushButton_clicked()
{
    QString name=ui->lineEdit->text();
    QString del=QString("delete from user where username ='%1'").arg(name);
    //开启事务
    QSqlDatabase::database().transaction();
    QSqlQuery query;
    bool isok=query.exec(del);
    if(isok){
        cout <<"删除成功";
    }else{
        cout <<"删除失败";
    }
    //提交事务
    QSqlDatabase::database().commit();
}
