#include "mywidget.h"
#include "ui_mywidget.h"
#include <QThread>
#include <QtDebug>
#include "mythread.h"

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);
    //这里不能指定父对象  Cannot move objects with a parent
    mt=new MyThread;
    //创建子线程
    th=new QThread(this);
    //把自定义的线程加入到子线程中
    mt->moveToThread(th);

    //处理信号
    connect(mt,&MyThread::mysignal,this,&MyWidget::dealSignal);

    qDebug()<<"father--thread"<<QThread::currentThread();

    //处理信号
    connect(this,&MyWidget::timeSignal,mt,&MyThread::myTimeout,Qt::QueuedConnection);
    //窗口关闭
    connect(this,&MyWidget::destroyed,this,&MyWidget::dealDestory);
    //connect有第五个参数,作用:连接方式 只有在多线程的时候才作用  多线程的时候默认是队列方式
    //Qt::QueuedConnection的时候,槽函数和信号接受者是在同一线程,否则槽函数所在线程和信号发送者在同一线程

}

MyWidget::~MyWidget()
{
    delete ui;
}

void MyWidget::dealDestory()
{
    //槽函数也可以直接调用
    on_stop_clicked();

    delete mt;
}
void MyWidget::dealSignal(){
    static int i=0;
    i++;
    ui->lcdNumber->display(i);
}
//启动线程
void MyWidget::on_start_clicked()
{

    if(th->isRunning()){
        return;
    }

    mt->setStop(false);
    //这里不会启动子线程的处理函数
    th->start();

    //利用信号启动子线程
    emit timeSignal();
}

//停止线程
void MyWidget::on_stop_clicked()
{

    if(!th->isRunning()){
        return;
    }
    mt->setStop();
    th->quit();
    th->wait();
}
