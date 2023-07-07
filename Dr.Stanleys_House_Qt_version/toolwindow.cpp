#include "toolwindow.h"
#include "ui_toolwindow.h"
#include<QPainter>

ToolWindow::ToolWindow(QWidget *parent):QMainWindow(parent),ui(new Ui::ToolWindow)
{
    s=":/images/tools_10.png";
    ui->setupUi(this);
}

ToolWindow::~ToolWindow()
{
    delete ui;
}

void ToolWindow::paintEvent(QPaintEvent*){
    QPainter painter(this);
    painter.drawPixmap(0,0,73,728,s);
}
