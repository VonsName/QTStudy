#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtDebug>
#include <QCompleter>
#include <QStringList>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->btn->setText("ui");

    connect(ui->btn,&QPushButton::clicked,this,&MainWindow::close);

    QString str= ui->lineEdit->text();
    qDebug()<<str;

    //设置内容间隙
    ui->lineEdit->setTextMargins(20,0,0,0);
    //设置内容显示方式
    //ui->lineEdit->setEchoMode(QLineEdit::Password);
    //
    QStringList list;
    list<<"hello"<<"hi";

    //模型  用来设置词语联想功能
    QCompleter *qc=new QCompleter(list,this);
    qc->setCaseSensitivity(Qt::CaseInsensitive);

    ui->lineEdit->setCompleter(qc);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_change_clicked()
{
    static int i=0;
    ui->stackedWidget->setCurrentIndex(++i%4);
}
