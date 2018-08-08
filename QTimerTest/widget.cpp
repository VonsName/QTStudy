#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    timer=new QTimer(this);
    connect(timer,&QTimer::timeout,
            [=](){
        static int i;
        i++;
        ui->lcdNumber->display(i);
    });
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    if(!timer->isActive()){
        timer->start(100);
    }
}

void Widget::on_pushButton_2_clicked()
{
    if(timer->isActive()){
        timer->stop();
    }
}
