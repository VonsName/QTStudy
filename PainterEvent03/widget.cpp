#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QPicture>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    QPicture picture;
    QPainter paint;
    paint.begin(&picture);
    paint.drawPixmap(0,0,50,50,QPixmap("../image/1.png"));

    paint.end();
    //保存的是二进制文件
    picture.save("../pic.png");


}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *e)
{
//    QPicture pic;
//    pic.load("../pic.png");
//    QPainter p(this);
//    p.drawPicture(0,0,pic);

    QPixmap pix;
    QPainter p(this);

    pix.load("../image/1.png");

    //QPixmap  -> QImage
    QImage image=pix.toImage();
    //p.drawImage(0,0,image);

    QImage loadImage;
    loadImage.load("../image/1.png");
    //QImage -> QPixmap
    QPixmap pixtmp=QPixmap::fromImage(loadImage);

   p.drawPixmap(30,30,30,30,pixtmp);
}
