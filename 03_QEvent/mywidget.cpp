#include "mywidget.h"
#include "ui_mywidget.h"
#include<QDebug>
#include<QKeyEvent>
#include<QCloseEvent>
#include<QMessageBox>
#include<QEvent>
MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);
    timerId=this->startTimer(1000);//以毫秒为单位，每隔一秒触发一次定时器
    this->timerId2=this->startTimer(500);


    connect(ui->pushButton,&MyButton::clicked,
            [=]()
            {
                qDebug()<<"按钮被按下";
            }
            );

    //安装过滤器
    ui->label_2->installEventFilter(this);
    ui->label_2->setMouseTracking(tr);
}

MyWidget::~MyWidget()
{
    delete ui;
}

void MyWidget::keyPressEvent(QKeyEvent *event)
{
     qDebug()<<(char)event->key();
     if(event->key()==Qt::Key_A)
     {
         qDebug()<<"Qt::Key_A";
     }
}


void MyWidget::timerEvent(QTimerEvent *event)
{
    if(event->timerId()==this->timerId)
    {
        static int sec=0;
       //sec++;
        ui->label->setText(QString("<center><h1>Time Out:%1</h1></center>").arg(sec++));

      if(5==sec)
       {
        this->killTimer(this->timerId);
       }
    }
    else if(event->timerId()==this->timerId2)
    {
        if(event->timerId()==this->timerId2)
        {
        static int sec=0;
        //sec++;
        ui->label_2->setText(QString("<center><h1>Time Out:%1</h1></center>").arg(sec++));
        }
    }
}

void MyWidget::mousePressEvent(QMouseEvent *event)
{
    qDebug()<<"+++++++++++";
}


void MyWidget::closeEvent(QCloseEvent *event)
{
    int  ret=QMessageBox::question(this,"question","是否需要关闭窗口");
         if(ret==QMessageBox::Yes)
         {
             //关闭窗口
             //节处理关闭窗口的事件，接收事件事件就不会往下传递
             event->accept();
         }
         else
         {
             //不关闭窗口
             //忽略事件，事件继续传递给父组件
             event->ignore();
         }
}

bool MyWidget::event(QEvent *event)
{
//    //事件分发
//    switch(event->type())
//    {
//    case QEvent::Close:
//        closeEvent(event);
//        break;
//    case QEvent::MouseMove:
//        mouseMoveEvent(event);
//        break;
//        /*
//         * .....
//        */
//    }
    if(event->type()==QEvent::Timer)
    {
        //干掉定时器
        //如果返回true，事件停止传播
        QTimerEvent *env = static_cast<QTimerEvent *>(event);
        timerEvent(env);
        return true;
    }
    else if(event->type()==QEvent::KeyPress)
    {
        //类型转换
        QKeyEvent *env = static_cast<QKeyEvent *>(event);
        if(env->key()==Qt::Key_B)
        {
            return QWidget::event(event);
        }
        return true;
    }
    else
    {
        return QWidget::event(event);
        //return false;
    }
}

 bool MyWidget::eventFilter(QObject *watched, QEvent *event)
 {
     if(watched == ui->label_2)
     {
         QMouseEvent *env = static_cast<QMouseEvent *>(event);
         //判断事件
         if(event->type()==QEvent::MouseMove)
         {
             ui->label_2->setText(QString("Mouse Move:(%1,%2)").arg(env->x()).arg(env->y()));
             return true;
         }
         if(event->type()==QEvent::MouseButtonPress)
         {
             ui->label_2->setText(QString("Mouse Press:(%1,%2)").arg(env->x()).arg(env->y()));
             return true;
         }
         if(event->type()==QEvent::MouseButtonRelease)
         {
             ui->label_2->setText(QString("Mouse Release:(%1,%2)").arg(env->x()).arg(env->y()));
             return true;
         }
         else
         {
             return QWidget::eventFilter(watched,event);
         }
     }
     else
     {
         return QWidget::eventFilter(watched,event);
     }
    if(watched==ui->pushButton)
    {

         //判断事件
        if(event->type()==QEvent::MouseButtonDblClick)
        {
            qDebug()<<"click";
            return true;
        }
        if(event->type()==QEvent::MouseButtonPress)
        {
            qDebug()<<"press";
            return true;
        }
        if(event->type()==QEvent::MouseButtonRelease)
        {
            qDebug()<<"release";
            return true;
        }
        else
        {
            return QWidget::eventFilter(watched,event);
        }
    }
    else
    {
        return QWidget::eventFilter(watched,event);
    }
 }





