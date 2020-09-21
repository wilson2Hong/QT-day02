#include "mybutton.h"
#include<QMouseEvent>
#include<QDebug>
MyButton::MyButton(QWidget *parent) : QPushButton(parent)
{
}


 void MyButton::mousePressEvent(QMouseEvent *e)
 {
     if(e->button()==Qt::LeftButton)
     {
         //如果左键被按下
      qDebug()<<"左键被按下";
      //事件接收后，就不会往下传递
      e->ignore();//忽略，事件继续往下传递，给谁传递？
                  //事件传递给了父组件，不是给父类（基类）
     }
     else
     {
         //不做处理
         QPushButton::mousePressEvent(e);
         //事件的忽略，事件继续往下传递
     }
 }
