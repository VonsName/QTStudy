#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QPixmap>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //绘图设备
    QPixmap pix(400,300);

    //画图
    QPainter paint(&pix);

    //填充颜色
    paint.fillRect(0,0,400,300,QBrush(Qt::white));

    paint.drawPixmap(0,0,80,80,QPixmap("../image/1.png"));

    pix.save("../pixmap.png");

}

Widget::~Widget()
{
    delete ui;
}
