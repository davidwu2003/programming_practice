#ifndef TOOLWINDOW_H
#define TOOLWINDOW_H

#include <QMainWindow>

namespace Ui {class ToolWindow;}

class ToolWindow:public QMainWindow
{
    Q_OBJECT
public:
    explicit ToolWindow(QWidget *parent = nullptr);
    ~ToolWindow();
    QString s;
    void paintEvent(QPaintEvent*);

private:
    Ui::ToolWindow *ui;
};

#endif // TOOLWINDOW_H
