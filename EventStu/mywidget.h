#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QTimerEvent>
#pragma execution_character_set("utf-8")

namespace Ui {
class MyWidget;
}

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MyWidget(QWidget *parent = nullptr);
    ~MyWidget();
protected:
    //定时器
    void timerEvent(QTimerEvent *qe);
    //事件分发器
    bool event(QEvent *event);
    //事件过滤器
    bool eventFilter(QObject *ob, QEvent *e);
private:
    Ui::MyWidget *ui;
    int timerId;
};

#endif // MYWIDGET_H
