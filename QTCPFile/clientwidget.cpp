#include "clientwidget.h"
#include "ui_clientwidget.h"
#include <QHostAddress>
#include <QTcpSocket>
#include <QtDebug>
#include <QMessageBox>

ClientWidget::ClientWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ClientWidget)
{
    ui->setupUi(this);
    socket=new QTcpSocket(this);

    ui->progressBar->setValue(0);

    connect(socket,&QTcpSocket::connected,
            [=](){
        QString str="connct success";
        ui->textEdit->append(str.toUtf8().data());
    });
    isHead=true;
    recevieSize=0;
    connect(socket,&QTcpSocket::readyRead,
            [=](){
        QByteArray arr= socket->readAll();
        if(isHead){
            isHead=false;

            fileName=QString(arr).section("##",0,0);
            fileSize=QString(arr).section("##",1,1).toInt();
            file.setFileName(fileName);
            bool isok=file.open(QIODevice::WriteOnly);
            if(!isok){
                qDebug()<<"read error";
                socket->close();
                return ;
            }
            //QString str=QString("接收的文件是:%1-%2kb").arg(fileName,fileSize/1024);
            //QMessageBox::information(this,"文件信息",str);
            //进度条
            ui->progressBar->setMinimum(0);
            ui->progressBar->setMaximum(fileSize/1014);
            //ui->progressBar->setValue(0);
        }else{
            qint64 len=file.write(arr);
            //qDebug()<<len;
            recevieSize+=len;
            //更新进度条
            //qDebug()<<recevieSize;
            //qDebug()<<fileSize;
            ui->progressBar->setValue(recevieSize/1024);
            if(recevieSize==fileSize){
                qDebug()<<"fiel  receive finsh";
                QMessageBox::information(this,"finsh","finsh");
                socket->disconnectFromHost();
                socket->close();
            }
        }
    });
}

ClientWidget::~ClientWidget()
{
    delete ui;
}

//连接服务器
void ClientWidget::on_pushButton_clicked()
{
    QString ip=ui->lineEdit->text();
    quint16 port=ui->lineEdit_2->text().toInt();
    socket->connectToHost(QHostAddress(ip),port);
}
