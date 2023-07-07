/*#include "toolframe.h"
#include "ui_toolframe.h"

ToolFrame::ToolFrame(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::ToolFrame)
{
    ui->setupUi(this);
}

ToolFrame::~ToolFrame()
{
    delete ui;
}
*/
#include "toolframe.h"
#include "ui_toolframe.h"
ToolFrame::ToolFrame(QWidget *parent) : QFrame(parent),ui(new Ui::ToolFrame)
{
    setMinimumWidth(200);
    QLabel *titleLabel = new QLabel("Inventory");
    QFont titleFont = titleLabel->font();
    titleFont.setPointSize(16);
    titleLabel->setFont(titleFont);
    m_itemList = new QListWidget;
    m_itemList->setFixedSize(200, 300);
    m_itemList->setFlow(QListView::TopToBottom);
    m_itemList->setUniformItemSizes(true);
    m_itemList->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    m_itemList->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    m_itemList->setSpacing(10);
    m_itemList->setStyleSheet("QListWidget { background-color: rgb(244, 232, 198); border: none; }"
                              "QListWidget::item { border: none; margin: 5px; }"
                              "QListWidget::item:selected { background-color: rgb(184, 171, 151); }");
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(titleLabel);
    layout->addWidget(m_itemList, 1);
    layout->setSpacing(0);
    setLayout(layout);
    connect(m_itemList, &QListWidget::itemClicked, this, &ToolFrame::onItemClicked);
    ui->setupUi(this);
}
ToolFrame::~ToolFrame()
{
    delete ui;
}
void ToolFrame::addItem(const QString &itemName, const QPixmap &itemIcon)
{
    QListWidgetItem *item = new QListWidgetItem(itemName);
    item->setIcon(QIcon(itemIcon));
    m_itemList->addItem(item);
}
void ToolFrame::onItemClicked(QListWidgetItem *item)
{
    emit itemClicked(item->text());
}
