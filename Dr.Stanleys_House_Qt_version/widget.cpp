#pragma once
#include "widget.h"
#include "ui_widget.h"
#include "mainwindow.h"
#include "toolwindow.h"
#include<QPainter>
#include<QPoint>
#include<QString>
#include<QMouseEvent>

Widget::Widget(QWidget *parent):QWidget(parent),ui(new Ui::Widget){
    ui->setupUi(this);
    this->setMouseTracking(true);
    //tool_window=new ToolWindow();
}

Widget::~Widget(){
    delete ui;
}

void Widget::paintEvent(QPaintEvent*){
    QPainter painter(this);
    QString path(":/images/menu.png");
    painter.drawPixmap(0,0,970,728,path);
}

void Widget::mousePressEvent(QMouseEvent* event){
    QPoint pos=event->pos();
    if (event->button()==Qt::LeftButton){
        if (pos.x()>190 && pos.x()<440 && pos.y()>360 && pos.y()<430){
            MainWindow* start_window=new MainWindow();
            //start_window->resize(970,728);
            start_window->resize(1070,728);
            start_window->setWindowFlags(Qt::Dialog);
            start_window->setFixedSize(this->width()+73, this->height());
            start_window->show();
        }
        if (pos.x()>190 && pos.x()<440 && pos.y()>440 && pos.y()<510){
            exit(0);
        }
    }
}

void Widget::mouseMoveEvent(QMouseEvent* event){
    QPoint pos=event->pos();
    bool flag=0;
    if (pos.x()>190 && pos.x()<440 && pos.y()>360 && pos.y()<430) flag=1;
    if (pos.x()>190 && pos.x()<440 && pos.y()>440 && pos.y()<510) flag=1;
    if (flag){
        this->setCursor(Qt::PointingHandCursor);
    }
    else{
        this->setCursor(Qt::ArrowCursor);
    }
}
