#include "widget.h"
#include "ui_widget.h"
#include <QFile>
#include <QFileDialog>
#include <QtDebug>
#include <QFileInfo>
#include <QDateTime>
#include <QDataStream>
#include <QTextStream>
#include <QBuffer>
#define cout qDebug() <<"[" <<__FILE__<<":"<<__LINE__<<"]"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //writeData();
    //readData();
    writeDataByTextStream();
    readDataByTextStream();
}

Widget::~Widget()
{
    delete ui;
}

//通过流写数据
void Widget::writeData()
{
    QFile file("../test.txt");
    if(file.open(QIODevice::WriteOnly)){
        QDataStream stream(&file);
        stream<<"测试机是"<<100;
    }
    file.close();
}

//通过流读取数据
void Widget::readData()
{

    QFile file("../test.txt");
    if(file.open(QIODevice::ReadOnly)){
        QDataStream stream(&file);
        QString str;
        int a;
        stream >>str>>a;
        cout<<str.toUtf8().data()<<"--"<<a;
    }
    file.close();
}

//以文本流的方式写数据
void Widget::writeDataByTextStream()
{
    QFile file("../tstm.txt");
    if(file.open(QIODevice::WriteOnly)){
        QTextStream stream(&file);
        stream.setCodec("UTF-8");
        stream<<"测试";
    }
    file.close();
}

//以文本流的方式读数据
void Widget::readDataByTextStream()
{
    QFile file("../tstm.txt");
    if(file.open(QIODevice::ReadOnly)){
         QTextStream stream(&file);
         QString str;
         stream>>str;
         cout <<str;
    }
    file.close();
}

void Widget::buffWrite()
{

}

//读文件槽函数
void Widget::on_btRe_clicked()
{
    QString path=QFileDialog::getOpenFileName(this,"open","../");
    if(!path.isEmpty()){
        //创建文件对象
        QFile file(path);
        //打开文件
//        if(file.open(QIODevice::ReadOnly)){
//            //默认只识别utf-8编码
//            QByteArray arr=file.readAll();
//            ui->textEdit->setText(arr);
//        }else{
//            ui->textEdit->setText("读取错误");
//        }
        if(file.open(QIODevice::ReadOnly)){
            QByteArray arr;
            while (!file.atEnd()) {
                arr+=file.readLine();
            }
            ui->textEdit->setText(arr);
        }

        QFileInfo info(path);
        qDebug()<<"文件大小:" <<info.size();
        qDebug()<<"文件后缀:"<<info.suffix();
        qDebug()<<"文件名称:"<<info.fileName();
        qDebug()<<"文件创建时间:"<<info.birthTime().toString("yyyy-MM-dd HH:mm:ss");
        file.close();
    }

}

//写文件槽函数
void Widget::on_btWr_clicked()
{
    QString path=QFileDialog::getSaveFileName(this,"save","../","TXT(*.txt)");
    if(!path.isEmpty()){
        //创建文件对象
        QFile file;
        file.setFileName(path);
        if(file.open(QIODevice::WriteOnly)){
            QString str=ui->textEdit->toPlainText();
            //file.write(str.toUtf8());
            file.write(str.toStdString().data());
        }else {
            qDebug()<<"err  when write";
        }
        file.close();
    }
}
