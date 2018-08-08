#include "serverwidget.h"
#include "ui_serverwidget.h"
#include <QTcpServer>
#include <QTcpSocket>

ServerWidget::ServerWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ServerWidget)
{
    ui->setupUi(this);

    this->setWindowTitle("服务器8888");

    server=new QTcpServer(this);
    server->listen(QHostAddress::Any,8888);
    //获取连接
    connect(server,&QTcpServer::newConnection,
            [=](){
        socket=server->nextPendingConnection();
        QString ip=socket->peerAddress().toString();
        quint16 port=socket->peerPort();
        QString str=QString("[%1:%2]连接").arg(ip).arg(port);
        ui->textRead->setText(str);
        //接收数据
        connect(socket,&QTcpSocket::readyRead,
                [=](){
            QByteArray arr=socket->readAll();
            ui->textRead->append(arr);
        });
    });
}

ServerWidget::~ServerWidget()
{
    delete ui;
}

//发送数据
void ServerWidget::on_pushButton_clicked()
{
    QString str=ui->textWrite->toPlainText();
    socket->write(str.toUtf8().data());
}

//服务器主动和客服端断开连接
void ServerWidget::on_pushButton_2_clicked()
{
    socket->disconnectFromHost();
    socket->close();
}
