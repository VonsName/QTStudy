#include "mythread.h"
#include <QImage>
#include <QPainter>
#include <QPen>
#include <QBrush>
#include <QPoint>

MyThread::MyThread(QObject *parent) : QObject(parent)
{
}

void MyThread::drawImage()
{
    QImage image(500,500,QImage::Format_ARGB32);
    QPainter painer(&image);
    QPen pen;
    pen.setWidth(5);
    painer.setPen(pen);
    QBrush brush;
    brush.setColor(Qt::red);
    brush.setStyle(Qt::SolidPattern);
    painer.setBrush(brush);
    QPoint a[]={
        QPoint(qrand()%500,qrand()%500),
        QPoint(qrand()%500,qrand()%500),
        QPoint(qrand()%500,qrand()%500),
        QPoint(qrand()%500,qrand()%500),
        QPoint(qrand()%500,qrand()%500)
    };

    painer.drawPolygon(a,5);

    emit updateImage(image);
}
