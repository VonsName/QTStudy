﻿#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QUdpSocket>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
    void dealMessage();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Widget *ui;
    QUdpSocket *socket;
};

#endif // WIDGET_H
