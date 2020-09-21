#include "mylabel.h"
#include<QMouseEvent>
#include<QDebug>
MyLabel::MyLabel(QWidget *parent) : QLabel(parent)
{
    //设置跟踪鼠标
   this->setMouseTracking(true);
}


//鼠标点击事件
void MyLabel::mousePressEvent(QMouseEvent *ev)
{
    int i=ev->x();
    int j=ev->y();
    //sprinf
    /*
     * QString str= Qstring("abc %1 ^_^ %2").arg(123).arg("Mike");
     * str = abc 123 ^_^ mike
    */


    /**/
    if(ev->button()==Qt::LeftButton)
    {
       qDebug()<<"left";
    }else if(ev->button()==Qt::RightButton)
    {
        qDebug()<<"right";

    }else if(ev->button()==Qt::MidButton)
    {
      qDebug()<<"mid";
    }

    QString text = QString("<center><h1>Mouse Press:(%1,%2)</center>")
            .arg(i).arg(j);
    this->setText(text);

}
//鼠标释放事件
void MyLabel::mouseReleaseEvent(QMouseEvent *ev)
{

    QString text = QString("<center><h1>Mouse Release:(%1,%2)</center>")
            .arg(ev->x()).arg(ev->y());
    this->setText(text);

}
//鼠标移动事件
void MyLabel::mouseMoveEvent(QMouseEvent *ev)
{

    QString text = QString("<center><h1>Mouse Move:(%1,%2)</center>")
            .arg(ev->x()).arg(ev->y());
    //this->setText(text);

}
//进入窗口
void MyLabel::enterEvent(QEvent *event)
{
    QString text = QString("<center><h1>Mouse Enter</h1>");
    this->setText(text);

}
//离开窗口
void MyLabel::leaveEvent(QEvent *event)
{
    QString text = QString("<center><h1>Mouse Leave</h1>");
    this->setText(text);

}



















