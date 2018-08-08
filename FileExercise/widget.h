#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
    void writeData();
    void readData();
private:
    void writeDataByTextStream();

    void readDataByTextStream();

    void buffWrite();
private slots:
    void on_btRe_clicked();

    void on_btWr_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
