#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtDebug>
#include <QCompleter>
#include <QStringList>
#include <QMovie>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //ui->btn->setText("ui");

   // connect(ui->btn,&QPushButton::clicked,this,&MainWindow::close);

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

    //设置文本内容
    ui->labelText->setText("^^^");

    //设置图片
    ui->labelImg->setPixmap(QPixmap("://image/0.jpg"));
    //设置适应lable大小
    ui->labelImg->setScaledContents(true);

    //设置动画 构造函数参数是一张gif动图
    QMovie *qom=new QMovie("");
    ui->label_4->setMovie(qom);
    qom->start();
    ui->label_4->setScaledContents(true);

    ui->labelUrl->setText("<h1><a hrfe=\"http://www.baidu.com\"></a></h1>");
    ui->labelUrl->setOpenExternalLinks(true);

    ui->lcdNumber->display(123);

    ui->progressBar->setMinimum(0);
    ui->progressBar->setMaximum(100);
    ui->progressBar->setValue(90);
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
