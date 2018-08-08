#include "widget.h"
#include "ui_widget.h"
#include <QUdpSocket>
#include <QHostAddress>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    socket=new QUdpSocket(this);
    //socket->bind(8888);

    //组播 QQ群！！
    socket->bind(QHostAddress::AnyIPv4,8888);
    QHostAddress add("224.0.0.2");
    //加入组播
    socket->joinMulticastGroup(add);
    //离开组播
    //socket->leaveMulticastGroup(add);
    connect(socket,&QUdpSocket::readyRead,this,&Widget::dealMessage);
}

Widget::~Widget()
{
    delete ui;
}

//接收消息
void Widget::dealMessage(){
    char buf[]={0};
    QHostAddress addr;
    quint16 port;
    qint64 len=socket->readDatagram(buf,sizeof(buf),&addr,&port);
    if(len>0){
        QString str=QString("[%1:%2  %3]")
                    .arg(addr.toString())
                    .arg(port)
                    .arg(buf);
        ui->textEditRe->setText(str);
    }
}

//发送消息
void Widget::on_pushButton_clicked()
{
    QString ip=ui->lineEditIP->text();
    int port=ui->lineEditpORT->text().toInt();
    QString data=ui->textEditWr->toPlainText();
    QHostAddress addr(ip);
    socket->writeDatagram(data.toUtf8().data(),addr,(quint16)port);
}
