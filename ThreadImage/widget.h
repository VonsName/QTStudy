#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QThread>
#include "mythread.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
    QThread *thread;

    void paintEvent(QPaintEvent *e);
    void getImage(QImage);
signals:
    void paintGui();

private slots:
    void on_pushButton_clicked();
    void winDestory();

private:
    Ui::Widget *ui;
    QImage image;
    MyThread *mt;
};

#endif // WIDGET_H
