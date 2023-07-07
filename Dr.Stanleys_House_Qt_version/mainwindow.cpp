#pragma once
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QPainter>
#include<QMouseEvent>
#include<QPalette>
#include<QDockWidget>

Scene s1_1(":/images/1.1.png");
Scene s1_1_1(":/images/1.1a.png");
Scene s1_2(":/images/1.2.png");
Scene s1_4(":/images/1.4.png");
Scene s2_1(":/images/2.1.png");
Scene s2_2(":/images/2.2.png");
Scene s2_3(":/images/2.3.png");
Scene s2_4(":/images/2.4.png");
Scene s3_1(":/images/3.1.png");
Scene s3_2(":/images/3.2.png");
Scene s3_3_1(":/images/3.3.1.png");
Scene s3_3_2(":/images/3.3.2.png");
Scene s3_4_1(":/images/3.4.1.png");
Scene s3_4_2(":/images/3.4.2.png");
Scene s3_5_1(":/images/3.5.1.png");
Scene s3_5_2(":/images/3.5.2.png");
Scene s3_5_3(":/images/3.5.3.png");
Scene s4_1(":/images/4.1.png");
Scene s4_2(":/images/4.2.png");
Scene s4_3(":/images/4.3.png");
Scene s5_1(":/images/5.1.png");

MainWindow::MainWindow(QWidget *parent):QMainWindow(parent),ui(new Ui::MainWindow),scene(&s1_1){
    //1.1
    s1_1.add(862,656,966,716,0,&s1_4);
    s1_1.add(75,443,132,509,0,&s1_2);
    s1_1.add(701,316,770,470,1,&s2_1);
    s1_1.add(770,345,810,375,0,&s1_1_1);//锁
    s1_1.add_tool(530,510,620,570,":/images/1.1.001.png",new Tool(":/images/stick.png","钩子"));//钩子

    //1.1.001
    s1_1_1.add(895,618,968,723,0,&s1_1);
    s1_1_1.add(334,232,693,879,1,&s2_1);
    s1_1_1.has_password = true;

    //1.2
    s1_2.add(853,648,959,704,0,&s1_1);
    s1_2.add(198,167,305,408,1,&s3_5_3);

    //1.4
    s1_4.add(26,559,88,626,0,&s1_1);
    s1_4.add_tool(728,185,758,213,":/images/1.4.001.png",new Tool(":/images/plane.png","纸飞机","钩子"));//plane

    //2.1
    s2_1.add(353,100,514,372,0,&s1_1);
    s2_1.add(208,55,290,450,0,&s3_1);
    s2_1.add(412,654,488,727,0,&s2_2);
    s2_1.add(557,441,615,474,0,&s2_3);

    //2.2
    s2_2.add(821,651,916,711,0,&s2_1);
    s2_2.add(8,252,205,708,1,&s3_2);//2.2-3.2门 初始关闭
    //s2_2.add(8,252,205,708,0,&s3_2);

    //2.3
    s2_3.add(53,200,134,256,0,&s2_1);
    s2_3.add(745,659,824,723,0,&s2_4);
    s2_3.add(458,43,678,291,1,&s3_3_1);//2.3-3.3.1门 初始关闭
    //s2_3.add(458,43,678,291,0,&s3_3_1);

    //2.4
    s2_4.add(505,307,565,351,0,&s2_3);
    s2_4.add(872,122,942,192,0,&s4_1);
    s2_4.add(274,0,502,227,1,&s3_4_1);//2.4-3.4.1门 初始关闭
    //s2_4.add(274,0,502,227,0,&s3_4_1);
    s2_4.add(156,116,271,393,1,&s3_5_1);//2.4-3.5.1门 初始关闭
    //s2_4.add(156,116,271,393,0,&s3_5_1);

    //3.1
    s3_1.add(707,34,830,721,0,&s2_1);
    s3_1.add_tool(227,271,261,306,":/images/3.1.001.png",new Tool(":/images/lighter.png","打火机"));

    //3.2
    s3_2.add(419,128,647,498,0,&s2_2);
    s3_2.add_tool(399,565,421,587,":/images/3.2.001.png",new Tool(":/images/gray_key.png","灰色钥匙"));

    //3.3.1
    s3_3_1.add(649,128,874,550,0,&s2_3);
    s3_3_1.add(0,151,117,642,1,&s3_3_2);//3.3.1-3.3.2门 初始关闭
    //s3_3_1.add(0,151,117,642,0,&s3_3_2);
    s3_3_1.add(522,413,623,456,1,new Scene());
    s3_3_1.add_tool(854,675,885,695,":/images/3.3.1.001.png",new Tool(":/images/silver_key.png","银色钥匙"));

    //3.3.2
    s3_3_2.add(495,5,738,471,0,&s3_3_1);
    s3_3_2.add_tool(321,271,353,290,":/images/3.3.2.001.png",new Tool(":/images/yellow_key.png","黄绿色钥匙"));

    //3.4.1
    s3_4_1.add(349,150,589,479,0,&s2_4);
    s3_4_1.add(149,102,183,515,0,&s3_4_2);

    //3.4.2
    s3_4_2.add(296,48,497,410,0,&s3_4_1);
    s3_4_2.add_tool(151,434,196,459,":/images/3.4.2.001.png",new Tool(":/images/blue_key.png","蓝色钥匙"));

    //3.5.1
    s3_5_1.add(753,39,855,722,0,&s2_4);
    s3_5_1.add(301,254,358,296,0,&s3_5_2);
    s3_5_1.add(903,341,957,410,0,&s3_5_3);

    //3.5.2
    s3_5_2.add(862,481,943,540,0,&s3_5_1);
    s3_5_2.add_tool(95,245,151,372,":/images/3.5.2.001.png",new Tool("","蜡烛","打火机"));
    s3_5_2.add_tool(136,548,418,612,":/images/3.5.2.001.png",new Tool(":/images/meat.png","一块特制的肉","nothing"));

    //3.5.3
    s3_5_3.add(209,366,266,451,0,&s3_5_1);
    s3_5_3.add(817,35,858,470,-1,&s1_2);//-1是做了一个特殊标记，后面要用

    //4.1
    s4_1.add(754,406,790,451,0,&s2_4);
    s4_1.add(30,365,285,707,0,&s5_1);
    s4_1.add(524,633,598,720,0,&s4_2);

    //4.2
    s4_2.add(256,382,331,428,0,&s4_1);
    s4_2.add(501,628,573,715,0,&s4_3);
    s4_2.add(430,2,623,320,-2,new Scene());//-2为特殊标记，表示该版本中无法进入，下面同理
    s4_2.add(730,205,831,561,1,new Scene());

    //4.3
    s4_3.add(499,624,576,717,0,&s4_2);
    s4_3.add(354,1,537,341,-2,new Scene());
    s4_3.add(742,10,879,596,-2,new Scene());

    //5.1
    s5_1.add(825,250,970,728,0,&s4_1);
    s5_1.add_tool(228,408,254,446,":/images/5.1.001.png",new Tool(":/images/green_key.png","青绿色钥匙"));

    scene=&s1_1;
    tool_num = 0;
    tool_list = new Tool[10];

    ui->setupUi(this);
    tool_window=new ToolWindow();

    //音频
    startSound = new QSoundEffect(this);
    startSound->setSource(QUrl::fromLocalFile(":/sound/bgm.wav"));
    startSound->setLoopCount(QSoundEffect::Infinite);
    startSound->play();

    ChangeBackground();
    this->centralWidget()->setMouseTracking(true);
    this->setMouseTracking(true);      //设置为不按下鼠标键触发

    started=0;
}

MainWindow::~MainWindow()
{
    startSound->stop();
    delete startSound;
    delete ui;
    delete tool_window;
}

void MainWindow::paintEvent(QPaintEvent*){
    if(started==0){
        showFirst(this, "   亲爱的程设选手：\n     我是研究中心的Stanley博士，非常希望您能在百忙之中\n   抽出时间来寒舍一聚。\n"
                        "     我有很重要的事情找您！\n     非常感谢！！                进入博士的家",":/images/signal.png",560, 115, 100, 60);
        started++;
    }
    QPainter painter(this);
    painter.drawPixmap(0,0,970,728,scene->path);
    painter.drawPixmap(970,0,73,728,tool_window->s);
    for(int i = 0;i<tool_num;i++)
        tool_list[i].show(this,i);
}

void MainWindow::ChangeBackground(Scene& s){
    scene=&s;
    if(scene == &s1_1_1 && scene->has_password){
        int ans[6] = {1,9,9,0,7,9};
        s1_1_1.set_password(ans,this);
    }
    else
    if(scene == &s1_1_1 && !scene->has_password){
        s1_1_1.cancel_password();
    }
    else{
        s1_1_1.cancel_password();
        s1_1_1.now_num = 0;
    }
    if(!s1_1_1.has_password){
        s1_1.a[2].lock = 0;
        s1_1_1.a[1].lock = 0;
        s1_1.path = ":/images/1.1.002.png";
        for(int i=0;i<s1_1.tool_num;i++){
            s1_1.t[i].used=1;
        }
    }
    QPalette pal=this->palette();
    pal.setBrush(QPalette::Window,QBrush(QPixmap(scene->path)));
    setPalette(pal);
}

void MainWindow::ChangeBackground(){
    QPalette pal=this->palette();
    pal.setBrush(QPalette::Window,QBrush(QPixmap(scene->path)));
    setPalette(pal);
}

void MainWindow::update_lock_status(Scene* scene,Scene* next_scene){
    for(int i=0;i<next_scene->button_num;i++){
        if (next_scene->a[i].next_scene==scene && next_scene->a[i].lock==1){
            next_scene->a[i].lock=0;
            break;
        }
    }
}

void MainWindow::update_lock_status(int i,Scene *scene){
    if ((*scene)==s2_2){
        if (i==1 && chosen_tool=="青绿色钥匙"){
            if(scene->a[i].lock){
                QSoundEffect * Sound = new QSoundEffect(this);
                Sound->setSource(QUrl::fromLocalFile(":/sound/door.wav"));
                Sound->setLoopCount(1);
                Sound->play();
                showHintLabel(this,"你打开了这扇门");
            }
            scene->a[i].lock=0;
        }
    }
    if ((*scene)==s2_3){
        if (i==2 && s3_3_1.first_in==1){
            s3_3_1.first_in=0;
            QSoundEffect * Sound = new QSoundEffect(this);
            Sound->setSource(QUrl::fromLocalFile(":/sound/ring.wav"));
            Sound->setLoopCount(1);
            Sound->play();
            showHintLabel(this,"你打开房门，一阵刺耳铃声…",4000);
            return;
        }
        if (i==2 && chosen_tool=="灰色钥匙"){
            if(scene->a[i].lock){
                QSoundEffect * Sound = new QSoundEffect(this);
                Sound->setSource(QUrl::fromLocalFile(":/sound/door.wav"));
                Sound->setLoopCount(1);
                Sound->play();
                showHintLabel(this,"你打开了这扇门");
            }
            scene->a[i].lock=0;
        }
    }
    if ((*scene)==s2_4){
        if (i==2 && chosen_tool=="粉色钥匙"){
            if(scene->a[i].lock){
                QSoundEffect * Sound = new QSoundEffect(this);
                Sound->setSource(QUrl::fromLocalFile(":/sound/door.wav"));
                Sound->setLoopCount(1);
                Sound->play();
                showHintLabel(this,"你打开了这扇门");
            }
            scene->a[i].lock=0;
        }
        if (i==3 && chosen_tool=="黄绿色钥匙"){
            if(scene->a[i].lock){
                QSoundEffect * Sound = new QSoundEffect(this);
                Sound->setSource(QUrl::fromLocalFile(":/sound/door.wav"));
                Sound->setLoopCount(1);
                Sound->play();
                showHintLabel(this,"你打开了这扇门");
            }
            scene->a[i].lock=0;
        }
    }
    if ((*scene)==s3_3_1){
        if (i==1 && chosen_tool=="银色钥匙"){
            if(scene->a[i].lock){
                QSoundEffect * Sound = new QSoundEffect(this);
                Sound->setSource(QUrl::fromLocalFile(":/sound/door.wav"));
                Sound->setLoopCount(1);
                Sound->play();
                showHintLabel(this,"你打开了这扇门");
            }
            scene->a[i].lock=0;
        }
    }

    //两种支线可能
    if ((*scene)==s3_5_3){
        if (i==1 && scene->a[i].lock==-1){
            if (s1_2.a[0].lock){
                s1_2.a[0].lock=1;
                QSoundEffect * Sound = new QSoundEffect(this);
                Sound->setSource(QUrl::fromLocalFile(":/sound/dog.wav"));
                Sound->setLoopCount(1);
                Sound->play();
                showHintLabel(this,"原来这扇门是通向这儿的…可是这大狗怎么被放出来了！\n看来屋子里一定有第二个人…当务之急是如何从这里过去…",4000);
            }
            else{
                showHintLabel(this,"原来这扇门是通向这儿的…");
            }
            scene->a[i].lock=0;
        }
        if (i==1 && scene->a[i].lock==0){
            if (s1_2.a[0].lock==2){
                s1_2.a[0].lock=1;
                QSoundEffect * Sound = new QSoundEffect(this);
                Sound->setSource(QUrl::fromLocalFile(":/sound/dog.wav"));
                Sound->setLoopCount(1);
                Sound->play();
                showHintLabel(this,"这大狗怎么被放出来了！\n看来屋子里一定有第二个人…当务之急是如何从这里过去…",4000);
            }
        }
    }

    if ((*scene)==s3_4_1 && i==1 && s3_4_2.first_in==1){
        s3_4_2.first_in=0;
        QSoundEffect * Sound = new QSoundEffect(this);
        Sound->setSource(QUrl::fromLocalFile(":/sound/shock.wav"));
        Sound->setLoopCount(1);
        Sound->play();
        showHintLabel(this,"我的天！这是谁坠楼了！！");
    }

    if ((*scene)==s3_5_2 && s3_5_1.first_in==1){
        s3_5_1.first_in=0;
        QSoundEffect * Sound = new QSoundEffect(this);
        Sound->setSource(QUrl::fromLocalFile(":/sound/peng!.wav"));
        Sound->setLoopCount(1);
        Sound->play();
        showHintLabel(this,"你听见了一阵哐当声，发现刚才进厨房的门已经打不开了，奇怪…",4000);
    }
}

void MainWindow::mousePressEvent(QMouseEvent* event){
    QPoint pos=event->pos();
    if(started == 1 && pos.x()>740 && pos.x()<840 && pos.y()>645 && pos.y()<705){
        LpAnimation = new QPropertyAnimation(SwidgetPtr,"pos",this);
        LpAnimation->setDuration(1000);
        LpAnimation->setStartValue(QPoint(180,528));
        LpAnimation->setEndValue(QPoint(180,728));
        LpAnimation->setEasingCurve(QEasingCurve::BezierSpline);
        LpAnimation->start();
        connect(LpAnimation,&QPropertyAnimation::finished,[=]{
            delete SpAnimation;
            delete LpAnimation;
            delete SwidgetPtr;
        });
        started++;
        return;
    }
    if(started == 1)return;
    if(ended == 1 && pos.x()>740 && pos.x()<840 && pos.y()>645 && pos.y()<705){
        startSound->stop();
        close();
        return;
    }
    if(ended == 1)return;
    if (event->button()==Qt::LeftButton){
        //切换场景
        for(int i=0;i<scene->button_num;i++){
            if (pos.x()>scene->a[i].x1 && pos.x()<scene->a[i].x2 && pos.y()>scene->a[i].y1 && pos.y()<scene->a[i].y2){
                //判断手上有没有钥匙可以开锁
                update_lock_status(i,scene);

                //点击电话事件，结局
                if ((*scene)==s3_3_1 && i==2){
                    if (scene->a[i].lock){
                        showHintLabel(this,"你想打电话给谁呢？");
                    }
                    else{
                        ended=1;
                        showFirst(this, "   你接通了电话……\n   在电话中你得知，从天井中摔下的人正是Stanley博士！\n   为何他手中的工具箱和你的工具箱如出一辙？\n"
                                        "   这通电话来自何方？是谁设计的这一场迷局？\n   且听下回分解……                 恭喜通关",":/images/signal.png",560, 115, 100, 60);
                    }
                    break;
                }

                if (scene->a[i].lock==-2){
                    showHintLabel(this,"这扇门似乎坏了…");
                    break;
                }

                //书房被打晕事件
                if ((*scene)==s4_2){
                    if (i==3 && chosen_tool=="蓝色钥匙"){
                        if(scene->a[i].lock){
                            QSoundEffect * Sound = new QSoundEffect(this);
                            Sound->setSource(QUrl::fromLocalFile(":/sound/got_hit.wav"));
                            Sound->setLoopCount(1);
                            Sound->play();

                            showHintLabel(this,"你试图进入书房，但是身后突然出现了一个人把你打晕了！你醒来时，回到了卧室之中…\n你的工具栏也消失了！",4000);
                            ChangeBackground(s3_3_1);
                            s4_2.a[i].lock=-2;
                            s3_4_2.path=":/images/3.4.2.002.png";
                            s3_4_2.first_in=1;
                            s3_4_2.add_tool(489,485,562,540,":/images/3.4.2.003.png",new Tool());
                            //s3_4_2.add(489,485,562,540,0,new Scene());
                            tmp_tool_num=tool_num;
                            tool_num=0;
                            this->repaint();
                            break;
                        }
                    }
                }

                if (scene->a[i].lock){
                    //输出“无法进入”信息
                    if (((*scene)==s3_5_1 || (*scene)==s2_4) && scene->a[i].lock==2){
                        showHintLabel(this,"这扇门已经打不开了…");
                    }
                    else
                    if ((*scene)==s1_2 && i==0){
                        showHintLabel(this,"要从大狗身边直接过去是不可能的…");
                    }
                    else{
                        showHintLabel(this,"这扇门是锁着的");
                    }
                }
                else{
                    update_lock_status(scene, scene->a[i].next_scene);
                    ChangeBackground(*scene->a[i].next_scene);
                }
                break;
            }
        }
        //触发场景内道具
        for(int i=0;i<scene->tool_num;i++){
            if (!scene->t[i].used && pos.x()>scene->t[i].x1 && pos.x()<scene->t[i].x2 && pos.y()>scene->t[i].y1 && pos.y()<scene->t[i].y2){
                //特殊情况，点燃蜡烛
                if (scene->t[i].tool->name=="蜡烛"){
                    if (scene->t[i].tool->pre_tool==chosen_tool){
                        scene->t[i].used=1;
                        scene->path=scene->t[i].s;
                        showHintLabel(this,"你用打火机点亮了蜡烛，现在能看清了");
                        //scene->add_tool(136,548,418,612,":/images/3.5.2.001.png",new Tool(":/images/meat.png","一块特制的肉"));
                        scene->t[1].tool->pre_tool="";
                    }
                    else{
                        showHintLabel(this,"怎么才能点燃蜡烛呢？");
                    }
                    break;
                }

                //捡起工具箱事件
                if ((*scene)==s3_4_2 && i==1){
                    tool_num=tmp_tool_num;
                    this->repaint();
                    showHintLabel(this,"你捡起了地上的工具箱，这时你发现你的工具箱也回来了！\n那地上这个人又是谁？！这时你似乎隐隐约约听见一阵电话铃声…",4000);
                    s3_3_1.a[2].lock=0;
                    s3_3_1.first_in=1;
                    scene->t[i].used=1;
                    scene->path=scene->t[i].s;
                    break;
                }

                //如果有预置道具，则取下，没有则提示不能取。
                if (scene->t[i].tool->pre_tool!="" && scene->t[i].tool->pre_tool!=chosen_tool){
                    if (scene->t[i].tool->name=="纸飞机"){
                        showHintLabel(this,"它太高了，你似乎够不着…");
                    }
                    else
                    if (scene->t[i].tool->name=="大狗"){
                        showHintLabel(this,"这恐怕很难解决这只大狗…");
                    }
                    else
                    if (scene->t[i].tool->name=="一块特制的肉"){
                        showHintLabel(this,"这里似乎有什么东西，但太暗了，看不清…");
                    }
                    else{
                        showHintLabel(this,"你暂时无法拾取它");
                    }
                }
                else{
                    scene->t[i].used=1;
                    scene->path=scene->t[i].s;
                    //ChangeBackground();
                    if (scene->t[i].tool->name=="纸飞机"){
                        showHintLabel(this,"你得到了纸飞机，打开发现上面写着一行数字‘199079’");
                    }
                    else
                    if (scene->t[i].tool->name=="大狗"){
                        showHintLabel(this,"这块肉竟然下药了！大狗晕倒了…");
                        s1_2.a[0].lock=0;
                        s4_1.path=":/images/4.1.001.png";
                        s4_1.add_tool(530,193,551,214,":/images/4.1.png",new Tool(":/images/pink_key.png","粉色钥匙"));
                        break;
                    }
                    else{
                        showHintLabel(this,"你拾取了"+scene->t[i].tool->name);
                    }

                    //特殊情况，取到肉后厨房被锁，狗被放了出来
                    if (scene->t[i].tool->name=="一块特制的肉"){
                        s3_5_1.a[0].lock=2;
                        s3_5_1.first_in=1;
                        s1_2.path=":/images/1.2.001.png";
                        s1_2.a[0].lock=2;
                        s1_2.add_tool(568,404,926,622,":/images/1.2.002.png",new Tool("","大狗","一块特制的肉"));

                        //大门重新上锁，不过密码未变
                        s1_1_1.has_password=1;
                        s1_1.a[2].lock=1;
                        s1_1_1.a[1].lock=1;
                        s1_1.path=":/images/1.1.001.png";
                        s1_1_1.path=":/images/1.1a.png";

                        //更改厨房背景图，锁被拆了
                        s3_5_1.path=":/images/3.5.1.001.png";
                        s2_4.path=":/images/2.4.001.png";
                        s2_4.a[3].lock=2;
                    }

                    //添加道具到工具栏
                    tool_list[tool_num] = *(scene->t[i].tool);
                    tool_num++;
                }
                break;
            }
        }
        //使用道具栏道具
        chosen_tool="";
        for(int i=0;i<tool_num;i++){
            if (pos.x()>970 && pos.x()<1043 && pos.y()>73*i && pos.y()<73*(i+1)){
                if (tool_list[i].name=="纸飞机"){
                    showHintLabel(this,"这是一张纸条，上面写着一行数字‘199079’");
                    break;
                }
                showHintLabel(this,"你选择了"+tool_list[i].name);
                chosen_tool=tool_list[i].name;
                break;
            }
        }
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent* event){
    QPoint pos=event->pos();
    if(started==1 || ended==1){
        if (pos.x()>740 && pos.x()<840 && pos.y()>645 && pos.y()<705)
            SwidgetPtr->setCursor(Qt::PointingHandCursor);
        else
            SwidgetPtr->setCursor(Qt::ArrowCursor);
        return;
    }
    bool flag=0;
    if (pos.x()>970 && pos.x()<1043 && pos.y()>0 && pos.y()<73*tool_num){
        flag=1;
    }
    for(int i=0;i<scene->button_num;i++){
        if (pos.x()>scene->a[i].x1 && pos.x()<scene->a[i].x2 && pos.y()>scene->a[i].y1 && pos.y()<scene->a[i].y2){
            flag=1;
            break;
        }
    }
    for(int i=0;i<scene->tool_num;i++){
        if (!scene->t[i].used && pos.x()>scene->t[i].x1 && pos.x()<scene->t[i].x2 && pos.y()>scene->t[i].y1 && pos.y()<scene->t[i].y2){
            flag=1;
            break;
        }
    }
    if (flag){
        this->setCursor(Qt::PointingHandCursor);
    }
    else{
        this->setCursor(Qt::ArrowCursor);
    }
}

void MainWindow::showHintLabel(QWidget *parentWin, QString strText,  int time, QString strFontSize, QString strColor, QString strBgColor)
{
    QWidget *widgetPtr = new QWidget();
    widgetPtr->setWindowFlags(Qt::FramelessWindowHint);    //去除外框
    widgetPtr->setAttribute(Qt::WA_TranslucentBackground); //设置窗体背景透明

    QLabel *pLabel = new QLabel(widgetPtr);    //创建显示标签
    pLabel->setAlignment(Qt::AlignCenter);  //文字居中显示
    pLabel->setStyleSheet(QString("QLabel{background:%1;color:%2;font:%3 SimHei;border-radius:6px;}")
                              .arg(strBgColor).arg(strColor).arg(strFontSize)); //设置标签风格
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

void MainWindow::showFirst(QWidget *parentWin, QString strText,QString signal_path, int x,int y,int width,int height, int time, QString strFontSize, QString strColor, QString strBgColor)
{
    SwidgetPtr = new QWidget(this);
    SwidgetPtr->setMouseTracking(true);
    SwidgetPtr->setWindowFlags(SwidgetPtr->windowFlags() |Qt::WindowStaysOnTopHint);
    SwidgetPtr->setWindowFlags(Qt::FramelessWindowHint);    //去除外框
    SwidgetPtr->setAttribute(Qt::WA_TranslucentBackground); //设置窗体背景透明

    QLabel *pLabel = new QLabel(SwidgetPtr);    //创建显示标签
    pLabel->setAlignment(Qt::AlignVCenter);  //文字居中显示
    pLabel->setStyleSheet(QString("QLabel{background:%1;color:%2;font:%3 SimHei;border-radius:6px;}")
                              .arg(strBgColor).arg(strColor).arg(strFontSize)); //社长标签风格
    pLabel->setText(strText);                   //设置文字内容
    pLabel->adjustSize();
    pLabel->resize(pLabel->size() + QSize(40,60));
    pLabel->setMouseTracking(false);
    //箭头
    QImage img(signal_path);
    QLabel *qLabel = new QLabel(SwidgetPtr);
    qLabel->setGeometry(x, y, width, height);//560, 115, 100, 60
    QImage scalimg = img.scaled(qLabel->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    qLabel->setPixmap(QPixmap::fromImage(scalimg));
    qLabel->setMouseTracking(true);
    //设置pFrame大小和位置
    SwidgetPtr->resize(pLabel->size());
    SwidgetPtr->move((parentWin->width()-SwidgetPtr->width())/2   + parentWin->pos().x(),
                     (parentWin->height()-SwidgetPtr->height())/11*10 + parentWin->pos().y());
    SwidgetPtr->show();

    SpAnimation = new QPropertyAnimation(SwidgetPtr,"pos",this);
    SpAnimation->setDuration(time);
    SpAnimation->setStartValue(QPoint(180,728));
    SpAnimation->setEndValue(QPoint(180,528));
    SpAnimation->setEasingCurve(QEasingCurve::BezierSpline);
    SpAnimation->start();
}
