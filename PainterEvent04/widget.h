#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMoveEvent>
#include <QPoint>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
protected:
    void paintEvent(QPaintEvent *e);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);

private:
    Ui::Widget *ui;
    QPoint p;
};

#endif // WIDGET_H
