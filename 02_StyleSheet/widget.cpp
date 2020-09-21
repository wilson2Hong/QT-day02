#include "widget.h"
#include "ui_widget.h"
#include<QPushButton>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

//    ui->label->setStyleSheet("QLabel{color:rgb(0,255,255);"
//                             "background-color:red"
//                             "}");

    this->setStyleSheet("QLabel{color:rgb(0,255,255);"
                             "background-color:red"
                             "}");

    ui->label->setStyleSheet("QLabel{color:rgb(0,255,255);"
                             "background-color:red;"
                             "border-image:url(:/new/prefix1/2.png)"
                             "}");

    ui->QPushButton->setStyleSheet("Q"
                                  );
}

Widget::~Widget()
{
    delete ui;
}
