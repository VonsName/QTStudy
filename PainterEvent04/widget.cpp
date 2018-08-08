#include "widget.h"
#include "ui_widget.h"
#include <QPainter>

//13
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //去窗口边框
    this->setWindowFlags(Qt::FramelessWindowHint|windowFlags());

    //设置窗口背景为透明
    this->setAttribute(Qt::WA_TintedBackground);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *e){
    QPixmap pixmap;
    pixmap.load("../image/1.png");
    QPainter p(this);
    p.drawPixmap(0,0,pixmap);
}

void Widget::mouseMoveEvent(QMouseEvent *e)
{

    if(e->button() & Qt::LeftButton){
        move(e->globalPos()-p);
    }
}

void Widget::mousePressEvent(QMouseEvent *e)
{
    if(e->button()==Qt::RightButton){
        close();
    }
    //获取点击的坐标
    else if(e->buttons()==Qt::LeftButton)
    {
        p=e->globalPos()-this->frameGeometry().topLeft();
    }
}
