#ifndef TOOL_H
#define TOOL_H

#include <QObject>
#include <QString>
#include <QMainWindow>
#include <QPainter>
class Tool : public QObject{
    Q_OBJECT
public:
    explicit Tool(QString path_ = "",QString name_ = "",QString pre_tool_ = "",QObject *parent = nullptr);
    explicit Tool(Tool& s);
    void operator=(Tool& s);
    void show(QMainWindow* parent,int num);


    bool has_hint_word;
    QString hint_word;
    QString path;
    QString name;
    QString pre_tool;//拾取该道具需要的前置道具
};

#endif // TOOL_H
