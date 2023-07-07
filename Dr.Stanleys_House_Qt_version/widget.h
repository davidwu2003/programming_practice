#ifndef WIDGET_H
#define WIDGET_H

#include<QWidget>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void paintEvent(QPaintEvent*);
    void mousePressEvent(QMouseEvent*);
    void mouseMoveEvent(QMouseEvent*);

    //ToolWindow* tool_window;

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
