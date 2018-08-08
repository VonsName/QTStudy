#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    this->setStyleSheet("QLabel{color:red;background-color:blue;}");
    //设置样式
    ui->label->setStyleSheet("QLabel{color:red;"
                             "background:black;"
                             "image:url(://image/0.jpg)"
                             "}");
    ui->pushButton->setStyleSheet("QPushButton:hover{"
                                        "color:red"
                                  "}");
}

Widget::~Widget()
{
    delete ui;
}
