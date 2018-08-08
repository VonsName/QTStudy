#include "clientwidget.h"
#include "ui_clientwidget.h"
#include <QTcpSocket>
#include <QHostAddress>

ClientWidget::ClientWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ClientWidget)
{
    ui->setupUi(this);
    QString title="客户端";
    this->setWindowTitle(title.toUtf8().data());
    socket=new QTcpSocket(this);
    connect(socket,&QTcpSocket::connected,
            [=](){
        QString str="连接成功";
        ui->textEditRead->append(str.toUtf8().data());
    });

    connect(socket,&QTcpSocket::readyRead,
            [=](){
        QString str=socket->readAll();
        ui->textEditRead->append(str);
    });
}

ClientWidget::~ClientWidget()
{
    delete ui;
}

//发送消息
void ClientWidget::on_buttonSend_clicked()
{
    QString str=ui->textEditWrite->toPlainText();
    socket->write(str.toUtf8().data());
}

//断开连接
void ClientWidget::on_buttonClose_clicked()
{
    socket->disconnect();
    socket->close();
}

//连接服务器
void ClientWidget::on_buttonConnect_clicked()
{
    QString ip=ui->lineEditIP->text();
    int port=ui->lineEditPort->text().toInt();
    socket->connectToHost(QHostAddress(ip),port);
}
