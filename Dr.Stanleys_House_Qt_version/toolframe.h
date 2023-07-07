/*
#ifndef TOOLFRAME_H
#define TOOLFRAME_H

#include <QFrame>

namespace Ui {
class ToolFrame;
}

class ToolFrame : public QFrame
{
    Q_OBJECT

public:
    explicit ToolFrame(QWidget *parent = nullptr);
    ~ToolFrame();

private:
    Ui::ToolFrame *ui;
};

#endif // TOOLFRAME_H
*/


#ifndef TOOLFRAME_H
#define TOOLFRAME_H
#pragma once
#include <QFrame>
#include <QLabel>
#include <QListWidget>
#include <QVBoxLayout>
namespace Ui {
class ToolFrame;
}
class ToolFrame : public QFrame
{
    Q_OBJECT
public:
    explicit ToolFrame(QWidget *parent = nullptr);
    ~ToolFrame();
    void addItem(const QString &itemName, const QPixmap &itemIcon);
signals:
    void itemClicked(const QString &itemName);
private slots:
    void onItemClicked(QListWidgetItem *item);
private:
    QListWidget *m_itemList;
    Ui::ToolFrame *ui;
};
#endif
