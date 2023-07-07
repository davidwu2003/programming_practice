#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.resize(970,728);
    w.setWindowFlags(Qt::Dialog);
    w.setFixedSize(w.width(), w.height());
    w.show();
    return a.exec();
}
