#include "paintevent01.h"
#include "ui_paintevent01.h"
#include <QPaintEvent>
#include <QPainter>
#include <QPen>
#include <QBrush>
#include <QBitmap>

PaintEvent01::PaintEvent01(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PaintEvent01)
{
    ui->setupUi(this);
    x=0;
}

PaintEvent01::~PaintEvent01()
{
    delete ui;
}
void PaintEvent01::paintEvent(QPaintEvent *qe){
    QPainter p;
    p.begin(this);
    //p.drawPixmap(0,0,width(),height(),QPixmap("../image/1.png"));
    //p.drawPixmap(rect(),QPixmap("../image/1.png"));

    //画笔
    QPen pen;
    pen.setWidth(5);
    pen.setStyle(Qt::DashLine);
    pen.setColor(Qt::red);
    p.setPen(pen);
    p.drawLine(50,50,150,50);
    p.drawLine(50,50,50,150);


    //画刷
    QBrush brush;
    brush.setColor(Qt::blue);
    brush.setStyle(Qt::Dense1Pattern);
    p.setBrush(brush);

    //画矩形
   // p.drawRect(100,100,150,100);

    //画圆形
   // p.drawEllipse(QPoint(200,200),100,100);

    //QPixmap:针对屏幕进行优化，和平台有关,不能对图片进行修改
    //QImage:和平台无关，可以对图片进行修改
    //QPicture:保存绘图状态 二进制文件
    p.drawPixmap(x,0,50,50,QPixmap("../image/1.png"));

    //QBitmap
    p.drawPixmap(50,50,50,50,QBitmap("../image/1.png"));
    p.end();
}

void PaintEvent01::on_pushButton_clicked()
{
    x+=20;
    if(x>=width()-50/2){
        x=0;
    }
    update();
}
