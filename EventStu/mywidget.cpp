#include "mywidget.h"
#include "ui_mywidget.h"
#include <QDebug>

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);
    timerId=this->startTimer(100);

    connect(ui->pushButton,&MyButton::clicked,
            [=](){
        qDebug()<<"按钮被按下";
    });
    //安装过滤器
    ui->label->installEventFilter(this);
}

MyWidget::~MyWidget()
{
    delete ui;
}

void MyWidget::timerEvent(QTimerEvent *qe)
{
    static int a=0;
    int timeId=qe->timerId();
    ui->time->setText(QString("%1").arg(a++));
    if(a==10){
        this->killTimer(timeId);
    }
}

//使用Event()函数分发事件
bool MyWidget::event(QEvent *event)
{
    if(event->type()==QEvent::Timer){
        //QTimerEvent *qev=static_cast<QTimerEvent *>(event);
       //timerEvent(qev);
        return  true;//return  true 表示阻止事件继续向下传递
    }else{
        return QWidget::event(event);
    }
}

//事件过滤器
bool MyWidget::eventFilter(QObject *ob,QEvent *e)
{
    if(ob==ui->label){
        qDebug()<<"事件过滤器";
        return true;
    }else{
        return  QWidget::eventFilter(ob,e);
    }
}
