#include "widget.h"
#include "ui_widget.h"
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlError>
#include <QMessageBox>
#include <QSqlQuery>
#include <QVariantList>
#include <QSqlTableModel>
#include <QSqlRecord>
#define cout qDebug()

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    QSqlDatabase db= QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setUserName("root");
    db.setPassword("root");
    db.setDatabaseName("user");
    if(!db.open()){
        QMessageBox::warning(this,"error",db.lastError().text());
        return;
    }

    //设置模型
    model=new QSqlTableModel(this);
    model->setTable("user");
    //view设置model
    ui->tableView->setModel(model);
    //显示数据
    model->select();
    //改变列的显示名称
    model->setHeaderData(0,Qt::Horizontal,"nO");
    model->setHeaderData(1,Qt::Horizontal,"your name");
    model->setHeaderData(2,Qt::Horizontal,"your pwd");
    //设置修改策略 手动提交
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    //设置是否能够修改  QAbstractItemView::NoEditTriggers 禁止修改
    //ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

Widget::~Widget()
{
    delete ui;
}

//添加
void Widget::on_pushButton_clicked()
{
    //添加空记录
    QSqlRecord record= model->record();

    int row=model->rowCount();

    model->insertRecord(row,record);
}

//确定
void Widget::on_pushButton_4_clicked()
{
    model->submitAll();
}

//取消
void Widget::on_pushButton_5_clicked()
{
    model->revertAll();
    model->submitAll();
}

//删除
void Widget::on_pushButton_2_clicked()
{
    //获取选中的模型
    QItemSelectionModel * smodel=ui->tableView->selectionModel();

    //取出模型中的索引
    QModelIndexList list=smodel->selectedRows();



    //删除选中的行
    for(int i=0;i<list.size();i++){
        model->removeRow(list.at(i).row());
    }
}

void Widget::on_pushButton_3_clicked()
{
    QString str=ui->lineEdit->text();
    QString filter=QString("username='%1'").arg(str);
    model->setFilter(filter);
}
