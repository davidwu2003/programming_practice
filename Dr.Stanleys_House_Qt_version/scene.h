#ifndef SCENE_H
#define SCENE_H

#include <QObject>
#include "tool.h"
#include <QPushButton>
#include <QMainWindow>
#include <QPalette>
#include <QLabel>
#include <QPropertyAnimation>
#include <QSoundEffect>

class Scene;
class Scene:public QObject{
    Q_OBJECT
public:
    explicit Scene(QString p,QObject *parent = nullptr);
    explicit Scene(Scene& s);
    Scene();
    Scene& operator =(Scene& s);
    void add(int _x1,int _y1,int _x2,int _y2,int _lock,Scene* s);
    void add_tool(int _x1,int _y1,int _x2,int _y2,QString _s,Tool* _tool);
    void set_password(int* password,QMainWindow* parent);
    void cancel_password();
    void set_now(int n,QMainWindow* parent);
    bool judge();
    void showHintLabel(QWidget *parent,
                       QString strText, int time = 2000,
                       QString strFontSize = "25px",
                       QString strColor = "#ffffff",
                       QString strBgColor = "#202020");
    bool operator ==(Scene& s);

    QString path;//图片地址

    int button_num;//当前场景可以触发的场景数
    class button{
    public:
        int x1;
        int y1;
        int x2;
        int y2;
        int lock;//标记该场景能否进入
        Scene* next_scene;
    };
    button a[10]={};

    int tool_num;//当前场景可以触发的道具数
    class tool_button{
    public:
        int x1;
        int y1;
        int x2;
        int y2;
        int used;//是否被捡过
        QString s;//记录捡完之后的图片地址
        Tool* tool;
    };
    tool_button t[10]={};

    bool first_in;//记录是否是第一次进入该场景，某些场合要用
    //密码锁的特殊情况
    bool has_password;
    int* ans;
    int* tem;
    int now_num;
    QPushButton* q;
};

#endif // SCENE_H
//储存场景数据，包括场景的图片地址，当前场景的事件
