#include "widget.h"
#include "ui_widget.h"
#include <QThread>
#include <QPushButton>
#include "mythread.h"
#include <QPaintEvent>
#include <QPainter>
#include <QImage>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    mt=new MyThread;
    //子线程对象
    thread=new QThread(this);
    mt->moveToThread(thread);
    //利用信号 和槽函数发送信号到子线程画图 调用子线程处理函数
    connect(this,&Widget::paintGui,mt,&MyThread::drawImage);

    //接收子线程发出的信号
    connect(mt,&MyThread::updateImage,this,&Widget::getImage);

    //关闭窗口 关闭窗口要处理线程关闭的问题
    connect(this,&Widget::destroyed,this,&Widget::winDestory);
}

Widget::~Widget()
{
    delete ui;
}

//退出线程
void Widget::winDestory(){
    thread->quit();
    thread->wait();
}

//通过信号获取子线程传递过来的QImage并重绘
void Widget::getImage(QImage img){
        image=img;
        //间接调用paintEvent();
        update();
}

//重写绘图
void Widget::paintEvent(QPaintEvent *e){
    QPainter paint(this);
    paint.drawImage(50,50,image);
}

//启动线程
void Widget::on_pushButton_clicked()
{
    thread->start();
    //发送信号到子线程绘图
    emit paintGui();
}
