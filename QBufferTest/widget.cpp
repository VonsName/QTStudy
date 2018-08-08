#include "widget.h"
#include "ui_widget.h"
#include <QBuffer>
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    buffWrite();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::buffWrite(){
    QBuffer memFile;
    if(memFile.open(QIODevice::WriteOnly)){
        memFile.write("11111");
    }
    memFile.close();
    qDebug()<<memFile.buffer();

}
