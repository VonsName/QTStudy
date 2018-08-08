#include "serverwidget.h"
#include "ui_serverwidget.h"
#include <QHostAddress>
#include <QFileDialog>
#include <QDebug>
ServerWidget::ServerWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ServerWidget)
{
    ui->setupUi(this);
    ui->choiceFile->setEnabled(false);
    ui->sendFile->setEnabled(false);

    server=new QTcpServer(this);
    server->listen(QHostAddress::Any,8888);
    connect(server,&QTcpServer::newConnection,
            [=](){
        socket=server->nextPendingConnection();
        QHostAddress addr;
        int port;
        addr=socket->peerAddress();
        port=socket->peerPort();
        QString str=QString("[%1:%2]connect success").arg(addr.toString()).arg(port);
        ui->textEdit->setText(str);
        ui->choiceFile->setEnabled(true);
    });

    connect(&timer,&QTimer::timeout,
            [=](){
        timer.stop();
        sendData();
    });
}

ServerWidget::~ServerWidget()
{
    delete ui;
}

//发送数据
void ServerWidget::sendData()
{
    qint64 len=0;
    do{
        char buf[4*1024]={0};
        len=file.read(buf,sizeof(buf));
        len=socket->write(buf,len);
        sendSize+=len;
    }while(len>0);

    //文件关闭
    if(sendSize==fileSize){
        ui->textEdit->setText("file send finsh");
        socket->disconnectFromHost();
        socket->close();
    }
}

//选择文件
void ServerWidget::on_choiceFile_clicked()
{
    QString path=QFileDialog::getOpenFileName(this,"open","../");
    if(!path.isEmpty()){
        fileName.clear();
        fileSize=0;
        QFileInfo info(path);
        fileName=info.fileName();
        fileSize=info.size();

        file.setFileName(path);
        if(file.open(QIODevice::ReadOnly)){
             ui->choiceFile->setEnabled(false);
             ui->sendFile->setEnabled(true);
             ui->textEdit->append("file path:"+path);
             ui->textEdit->append("file name:"+fileName);
        }else{
            qDebug()<<"open filee error";
            file.close();

        }
    }

}

//发送文件;
void ServerWidget::on_sendFile_clicked()
{
    //先发送头信息
    QString head=QString("%1##%2").arg(fileName).arg(fileSize);
    qint64 len= socket->write(head.toUtf8().data());
    //头信息发送成功再利用定时器发送主体 防止tcp黏包
    if(len>0){
        timer.start(10);
    }else{
        file.close();
        ui->choiceFile->setEnabled(false);
        ui->sendFile->setEnabled(false);
    }
}
