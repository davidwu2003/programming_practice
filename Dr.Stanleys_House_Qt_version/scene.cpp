#include "scene.h"
Scene::Scene(){}

Scene::Scene(QString p,QObject *parent):QObject{parent}{
    path=p;
    button_num=0;
    tool_num=0;
    first_in=0;
    has_password = false;now_num = 0;q = NULL;ans = NULL;tem = NULL;
}

Scene::Scene(Scene& s){
    path=s.path;
    button_num=s.button_num;
    tool_num=s.tool_num;
    first_in=s.first_in;
    for(int i=0;i<button_num;i++){
        a[i]=s.a[i];
    }
    for(int i=0;i<tool_num;i++){
        t[i]=s.t[i];
    }
}

Scene& Scene::operator =(Scene& s){
    path=s.path;
    button_num=s.button_num;
    tool_num=s.tool_num;
    first_in=s.first_in;
    for(int i=0;i<button_num;i++){
        a[i]=s.a[i];
    }
    for(int i=0;i<tool_num;i++){
        t[i]=s.t[i];
    }
    return *this;
}

void Scene::add(int _x1,int _y1,int _x2,int _y2,int _lock,Scene* s){
    a[button_num].x1=_x1;
    a[button_num].y1=_y1;
    a[button_num].x2=_x2;
    a[button_num].y2=_y2;
    a[button_num].lock=_lock;
    a[button_num].next_scene=s;
    button_num++;
}

void Scene::add_tool(int _x1,int _y1,int _x2,int _y2,QString _s,Tool* _tool){
    //printf("Done\n");
    t[tool_num].x1=_x1;
    t[tool_num].y1=_y1;
    t[tool_num].x2=_x2;
    t[tool_num].y2=_y2;
    t[tool_num].tool=_tool;
    t[tool_num].used=0;
    t[tool_num].s=_s;
    tool_num++;
}

void Scene::set_password(int* password,QMainWindow* parent){
    has_password = true;
    q = new QPushButton[10];
    ans = new int[6];
    tem = new int[6];
    for(int i = 0;i<6;i++)ans[i] = password[i];
    q[0].move(631,430);q[1].move(608,410);q[2].move(634,410);q[3].move(661,411);
    q[4].move(611,390);q[5].move(637,391);q[6].move(664,391);
    q[7].move(613,370);q[8].move(640,370);q[9].move(667,371);
    for(int i = 0;i<10;i++){
        q[i].setParent(parent);
        q[i].resize(23,21);
        q[i].setFlat(true);
        q[i].setCursor(Qt::PointingHandCursor);
        q[i].setStyleSheet("QPushButton:hover {background-color: rgb(100, 100, 100);}");
        connect(&q[i],&QPushButton::clicked,this,std::bind(&Scene::set_now,this,i,parent));//注意有错可能
        q[i].show();
    }
}

void Scene::cancel_password(){
    if(q != NULL){
        for(int i = 0;i<10;i++)
            q[i].hide();
    }
}

void Scene::set_now(int n,QMainWindow* parent){
    if(now_num == 6)now_num = 0;
    tem[now_num] = n;
    now_num++;
    if(judge()){
        showHintLabel(parent,"你打开了这扇门");
        a[1].lock=0;//因为只有这个场景用了密码锁，所以可以直接这么写，如果要拓展请注意

        QSoundEffect * Sound = new QSoundEffect(parent);
        Sound->setSource(QUrl::fromLocalFile(":/sound/gate_ac.wav"));
        Sound->setLoopCount(1);
        Sound->play();

        QPalette pal=parent->palette();
        pal.setBrush(QPalette::Window,QBrush(QPixmap(path)));
        parent->setPalette(pal);
    }
    else if(now_num == 6){
        QSoundEffect * Sound = new QSoundEffect(parent);
        Sound->setSource(QUrl::fromLocalFile(":/sound/gate_wa.wav"));
        Sound->setLoopCount(1);
        Sound->play();

        showHintLabel(parent,"密码错误，请重新输入！");
    }
}
//判断是否输入正确密码
bool Scene::judge(){
    if(now_num == 6){
        for(int i = 0;i<6;i++)
            if(ans[i] != tem[i])return false;
        has_password = false;
        cancel_password();
        path = ":/images/1.1b.png";
        q = NULL;
        return true;
    }
    return false;
}

void Scene::showHintLabel(QWidget *parentWin, QString strText,  int time, QString strFontSize, QString strColor, QString strBgColor)
{
    QWidget *widgetPtr = new QWidget();
    widgetPtr->setWindowFlags(Qt::FramelessWindowHint);    //去除外框
    widgetPtr->setAttribute(Qt::WA_TranslucentBackground); //设置窗体背景透明

    QLabel *pLabel = new QLabel(widgetPtr);    //创建显示标签
    pLabel->setAlignment(Qt::AlignCenter);  //文字居中显示
    pLabel->setStyleSheet(QString("QLabel{background:%1;color:%2;font:%3 SimHei;border-radius:6px;}")
                              .arg(strBgColor).arg(strColor).arg(strFontSize)); //社长标签风格
    pLabel->setText(strText);                   //设置文字内容
    pLabel->adjustSize();
    pLabel->resize(pLabel->size() + QSize(80,60));
    //设置pFrame大小和位置
    widgetPtr->resize(pLabel->size());
    widgetPtr->move((parentWin->width()-widgetPtr->width())/2   + parentWin->pos().x(),
                    (parentWin->height()-widgetPtr->height())/11*10 + parentWin->pos().y());
    widgetPtr->show();

    //创建动画，使窗口淡化消失
    QPropertyAnimation *pAnimation = new QPropertyAnimation(widgetPtr,"windowOpacity",this);
    pAnimation->setDuration(time);
    pAnimation->setEasingCurve(QEasingCurve::InCirc);
    pAnimation->setStartValue(1.0);
    pAnimation->setEndValue(0.0);
    pAnimation->start();
    //动画结束后删除创建的资源
    connect(pAnimation,&QPropertyAnimation::finished,[=]{
        delete pAnimation;
        delete widgetPtr;
    });
}

bool Scene::operator==(Scene& s){
    return s.path==path;
}
