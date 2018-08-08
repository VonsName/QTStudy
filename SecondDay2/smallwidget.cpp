#include "smallwidget.h"
#include <QSpinBox>
#include <QSlider>
#include <QHBoxLayout>

smallWidget::smallWidget(QWidget *parent) : QWidget(parent)
{

    QSpinBox *spi=new QSpinBox(this);
    QSlider *qsli=new QSlider(Qt::Horizontal,this);
    QHBoxLayout *qhb=new QHBoxLayout();
    qhb->addWidget(spi);
    qhb->addWidget(qsli);
}
