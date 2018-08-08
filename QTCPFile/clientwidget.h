#ifndef CLIENTWIDGET_H
#define CLIENTWIDGET_H

#include <QWidget>
#include <QTcpSocket>
#include <QFileInfo>
#include <QFile>

namespace Ui {
class ClientWidget;
}

class ClientWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ClientWidget(QWidget *parent = nullptr);
    ~ClientWidget();

private slots:
    void on_pushButton_clicked();

private:
    Ui::ClientWidget *ui;
    QTcpSocket *socket;
    QFile file;
    QString fileName;
    qint64 fileSize;
    qint16 recevieSize;
    bool isHead;
};

#endif // CLIENTWIDGET_H
