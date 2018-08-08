#include "widget.h"
#include "ui_widget.h"
#include <QPaintEvent>
#include <QMouseEvent>
#include <QPainter>
#include <QBrush>
#include <QPen>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    chessX=-1;
    chessY=-1;
    ui->setupUi(this);
//    gridW=10;
//    gridH=10;
//    startX=10;
//    startY=10;
//    chessX=10;
//    chessY=10;
}

Widget::~Widget()
{
    delete ui;
}

//绘图
void Widget::paintEvent(QPaintEvent *e){
    gridW=width()/10;
    gridH=this->height()/10;
    startX=gridW;
    startY=gridH;
    QPainter paint(this);

    //paint.drawPixmap(rect(),QPixmap("../image/1.png"));
    QPen pen;
    pen.setWidth(4);
    paint.setPen(pen);
    //QBrush brush;
    //brush.setColor(Qt::lightGray);
    //paint.setBrush(brush);

    //画棋盘
    for (int i=0;i<=8;i++){
        paint.drawLine(startX,startY+i*gridH,startX+8*gridW,startY+i*gridH);
        paint.drawLine(startX+i*gridW,startY,startX+i*gridW,startY+8*gridH);
    }
//    paint.drawLine(10,10,50,10);
//    paint.drawLine(10,10+10,50,10+10);
//    paint.drawLine(10,10+20,50,10+20);

    if(chessX!=-1&&chessY!=-1){
        paint.drawPixmap(startX+chessX*gridW,startY+chessY*gridH,gridW,gridH,QPixmap("../image/1.png"));
    }
}

void Widget::mousePressEvent(QMouseEvent *e){
    int x=e->x();
    int y=e->y();
    if(x>=startX&&x<startX*80&&y>=startY&&y<startY*80){
        chessX=(x-startX)/gridW;
        chessY=(y-startY)/gridH;
        //重绘
        update();
    }
}
