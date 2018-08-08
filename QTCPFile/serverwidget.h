#ifndef SERVERWIDGET_H
#define SERVERWIDGET_H

#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>
#include <QFile>
#include <QFileInfo>
#include <QTimer>

namespace Ui {
class ServerWidget;
}

class ServerWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ServerWidget(QWidget *parent = nullptr);
    ~ServerWidget();
    void sendData();

private slots:
    void on_choiceFile_clicked();

    void on_sendFile_clicked();

private:
    Ui::ServerWidget *ui;
    QTcpServer *server;
    QTcpSocket *socket;
    QFile file;
    QFileInfo fileInfo;
    QString fileName;
    qint64 fileSize;
    qint16 sendSize;
    QTimer timer;
};

#endif // SERVERWIDGET_H
