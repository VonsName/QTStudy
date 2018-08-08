#include "mylabel.h"
#include <QMouseEvent>
#include <QDebug>
#pragma execution_character_set("utf-8")

//第十一课
MyLabel::MyLabel(QWidget *parent) : QLabel(parent)
{
    //设置鼠标追踪
    this->setMouseTracking(true);
}

//鼠标移动
void MyLabel::mouseMoveEvent(QMouseEvent *ev){

    Qt::MouseButton bt=ev->button();
    if(bt==Qt::LeftButton){
        //事件被接收后，就不会向下继续传递
        qDebug()<<"zuo键"<<endl;
        ev->ignore();//表示事件会继续向下传递，事件传递给了父组件
    }else if(bt==Qt::RightButton){
        qDebug()<<"右键"<<endl;
    }

    int x=ev->x();
    int t=ev->y();
    QString str=QString("%1 %2").arg(x).arg(t);
    this->setText(str);
    qDebug()<<str;
}

void MyLabel::mousePressEvent(QMouseEvent *ev){

    Qt::MouseButton bt=ev->button();
    if(bt==Qt::LeftButton){
        qDebug()<<"zuo键"<<endl;
    }else if(bt==Qt::RightButton){
        qDebug()<<"右键"<<endl;
    }
    int x=ev->x();
    int t=ev->y();
    QString str=QString("%1 %2").arg(x).arg(t);
    this->setText(str);
    qDebug()<<str;
}

void MyLabel::mouseReleaseEvent(QMouseEvent *ev){
    int x=ev->x();
    int t=ev->y();
    QString str=QString("%1 %2").arg(x).arg(t);
    this->setText(str);
    qDebug()<<str;
}
