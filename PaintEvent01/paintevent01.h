#ifndef PAINTEVENT01_H
#define PAINTEVENT01_H

#include <QWidget>

namespace Ui {
class PaintEvent01;
}

class PaintEvent01 : public QWidget
{
    Q_OBJECT

public:
    explicit PaintEvent01(QWidget *parent = nullptr);
    ~PaintEvent01();

private:
    Ui::PaintEvent01 *ui;
};

#endif // PAINTEVENT01_H
