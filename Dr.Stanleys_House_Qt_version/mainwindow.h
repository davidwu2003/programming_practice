#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "scene.h"
#include "toolwindow.h"
#include <QPropertyAnimation>
#include <QMediaPlayer>
#include <QSoundEffect>

namespace Ui {class MainWindow;}

class MainWindow:public QMainWindow{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void paintEvent(QPaintEvent*);
    void mousePressEvent(QMouseEvent*);
    void ChangeBackground(Scene& s);
    void ChangeBackground();
    void mouseMoveEvent(QMouseEvent*);
    void showHintLabel(QWidget *parent,
                       QString strText, int time = 2000,
                       QString strFontSize = "25px",
                       QString strColor = "#ffffff",
                       QString strBgColor = "#202020");
    void showChoiceLabel(QWidget *parent,
                         QString strText,
                         QString strFontSize = "25px",
                         QString strColor = "#ffffff",
                         QString strBgColor = "#202020");
    void showFirst(QWidget *parent,
                   QString strText,//文字，后面依次是按钮图片地址，位置和高宽
                   QString signal_path, int x,int y,int width,int height,
                   int time = 1000,
                   QString strFontSize = "25px",
                   QString strColor = "#000000",
                   QString strBgColor = "#8B4513");
    void showEnd(QWidget *parent,
                   QString strText,//文字，后面依次是按钮图片地址，位置和高宽
                   QString signal_path, int x,int y,int width,int height,
                   int time = 1000,
                   QString strFontSize = "25px",
                   QString strColor = "#000000",
                   QString strBgColor = "#8B4513");
    void update_lock_status(int i,Scene* scene);//判断是否有钥匙打开这道门，更新开关锁状态
    void update_lock_status(Scene* scene,Scene* next_scene);//更新开关锁状态，有些门本来从外面进不去，但是一旦从里面能出去了，就能从外面回到里面

private:
    Ui::MainWindow *ui;
    ToolWindow* tool_window;
    Tool* tool_list;
    int started;//记录开头，初始为0，开始游戏后++
    int ended;//记录结尾
    int tool_num;//工具栏目前工具数量
    int tmp_tool_num;//记录清空工具栏时的工具数量
    QString chosen_tool;//目前选中的道具
    Scene* scene;
    //文字开始窗口
    QWidget *SwidgetPtr;
    //上升动画指针
    QPropertyAnimation *SpAnimation;
    //下降动画指针
    QPropertyAnimation *LpAnimation;
    //背景音效
    QSoundEffect * startSound;
};

#endif // MAINWINDOW_H
