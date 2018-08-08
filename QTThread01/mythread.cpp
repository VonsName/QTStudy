#include "mythread.h"
#include <QThread>
#include <QDebug>
#include <QMessageBox>



MyThread::MyThread(QObject *parent) : QObject(parent)
{
    isStop=false;
}
void MyThread::myTimeout()
{
    while(isStop==false){
        //线程函数内部不能操作图形界面
        //QMessageBox::aboutQt(nullptr);
        thread()->sleep(1);
        emit mysignal();
         qDebug()<<"zi线程"<<QThread::currentThread();
         if(isStop){
             break;
         }
    }
}


void MyThread::setStop(bool flag){
    isStop=flag;
}
