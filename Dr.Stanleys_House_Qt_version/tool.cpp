#include "tool.h"

Tool::Tool(QString path_,QString name_,QString pre_tool_,QObject *parent)
    : QObject{parent}
{
    path = path_;
    name = name_;
    pre_tool = pre_tool_;
}

Tool::Tool(Tool& s){
    path = s.path;
    has_hint_word = s.has_hint_word;
    hint_word = s.hint_word;
    name = s.name;
}
void Tool::operator=(Tool& s){
    path = s.path;
    has_hint_word = s.has_hint_word;
    hint_word = s.hint_word;
    name = s.name;
}
void Tool::show(QMainWindow* parent,int num){
    parent->update();
    QPixmap pixmap(path);
    QRect targetRect(970,73*num,73,73);//此处只处理了一列道具栏的情况，后续若要增添道具栏视情况处理。
    QPainter painter(parent);
    painter.drawPixmap(targetRect,pixmap);
}
