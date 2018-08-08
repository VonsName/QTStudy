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
    int x;
protected:
    //重写绘图事件
    void paintEvent(QPaintEvent *qe);
private slots:
    void on_pushButton_clicked();

};

#endif // PAINTEVENT01_H
