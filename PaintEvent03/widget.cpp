#include "widget.h"
#include "ui_widget.h"
#include <QPainter>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    QImage image(400,300,QImage::Format_ARGB32);

    QPainter painter;
    painter.begin(&image);

    painter.drawImage(0,0,QImage("../image/1.png"));
    painter.end();

    image.save("../image.png");
}

Widget::~Widget()
{
    delete ui;
}
