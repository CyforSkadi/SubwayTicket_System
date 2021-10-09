#include <QtWidgets>
#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :	//欢迎界面窗口
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    setWindowTitle(tr("欢迎界面"));
    dialog = new Dialog(this);
}

void Widget::paintEvent(QPaintEvent *)	//绘图事件
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

void Widget::mousePressEvent(QMouseEvent *)	//鼠标点击事件
{
    this->hide();
    dialog->show();
}
