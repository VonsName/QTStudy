#include "paintevent01.h"
#include "ui_paintevent01.h"

PaintEvent01::PaintEvent01(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PaintEvent01)
{
    ui->setupUi(this);
}

PaintEvent01::~PaintEvent01()
{
    delete ui;
}
