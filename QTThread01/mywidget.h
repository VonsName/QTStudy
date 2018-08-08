#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include "mythread.h"
#include <QThread>

namespace Ui {
class MyWidget;
}

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MyWidget(QWidget *parent = nullptr);
    ~MyWidget();
    void dealSignal();
signals:
    void timeSignal();//启动子线程的信号

private slots:
    void on_start_clicked();

    void on_stop_clicked();

    void dealDestory();

private:
    Ui::MyWidget *ui;
    MyThread *mt;
    QThread *th;
};

#endif // MYWIDGET_H
