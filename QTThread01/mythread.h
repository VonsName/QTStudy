#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QObject>

class MyThread : public QObject
{
    Q_OBJECT
public:
    explicit MyThread(QObject *parent = nullptr);
    //线程处理函数
    void myTimeout();
    void setStop(bool flag=true);
signals:
     void mysignal();
public slots:
private:
     bool isStop;

};

#endif // MYTHREAD_H
