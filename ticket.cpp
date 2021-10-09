#include <QMouseEvent>
#include <QMessageBox>
#include "info.h"
#include "ticket.h"
#include "ui_ticket.h"

#include <cmath>


Ticket::Ticket(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Ticket)
{
    ui->setupUi(this);
    setWindowTitle(tr("购票"));
    setWindowFlags(Qt::Dialog | Qt::WindowCloseButtonHint);
    ui->edit_begin->installEventFilter(this);
    ui->edit_end->installEventFilter(this);
    ui->edit_count->installEventFilter(this);
    ui->edit_money->installEventFilter(this);
    ui->widget->setVisible(false);

    connect(ui->btn_confirm, &QPushButton::clicked, this, [this]()	//选择起始站点和购票数
    {
        int begin = ui->edit_begin->text().toInt();
        int end = ui->edit_end->text().toInt();
        int count = ui->edit_count->text().toInt();
        if (begin == 0)	//空输入或错误输入反馈
        {
            QMessageBox::information(this, tr("提示"), tr("站点编号-始不能为空!"), tr("确定"));
            return;
        }
        if (end == 0)
        {
            QMessageBox::information(this, tr("提示"), tr("站点编号-终不能为空!"), tr("确定"));
            return;
        }
        if (count == 0)
        {
            QMessageBox::information(this, tr("提示"), tr("票数不能为空!"), tr("确定"));
            return;
        }
        if (begin == end)
        {
            QMessageBox::information(this, tr("提示"), tr("请确保起始的站点编号不一致!"), tr("确定"));
            return;
        }
        if (!map.contains(begin))
        {
            QMessageBox::information(this, tr("提示"), tr("不存在站点编号-始, 请重新输入!"), tr("确定"));
            return;
        }
        if (!map.contains(end))
        {
            QMessageBox::information(this, tr("提示"), tr("不存在站点编号-终, 请重新输入!"), tr("确定"));
            return;
        }
        price = (2 + abs(end - begin) - 1) * count; // 起步价2元, 每一站1元
        if (QMessageBox::question(this, tr("提示"), QString("起点: %1, 终点: %2, 需支付%3元!\n是否立即购买?").arg(map.value(begin)).arg(map.value(end)).arg(price), tr("是"), tr("否")))
        {
            return;
        }
        ui->widget->setVisible(true);
    });

    connect(ui->btn_pay, &QPushButton::clicked, this, [this]()	//投币付款以及找零
    {
        QString money = ui->edit_money->text();
        if (money.isEmpty())
        {
            QMessageBox::information(this, tr("提示"), tr("请输入支付金额!"), tr("确定"));
            return;
        }
        int remain = money.toInt() - price;
        if (remain < 0)
        {
            QMessageBox::information(this, tr("提示"), tr("钱币不足, 请继续投币!"), tr("确定"));
            return;
        }
        QMessageBox::information(this, tr("提示"), QString("支付成功, 找您%1元!").arg(remain), tr("确定"));
        ui->widget->setVisible(false);
        ui->edit_begin->clear();
        ui->edit_end->clear();
        ui->edit_count->clear();
        ui->edit_money->clear();
        this->close();
        this->parentWidget()->close();
        this->parentWidget()->parentWidget()->show();
    });
}

Ticket::~Ticket()
{
    delete ui;
}

void Ticket::closeEvent(QCloseEvent *)
{
    this->parentWidget()->show();
}

void Ticket::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
        case Qt::Key_Escape:
            this->close();
            break;
        default:
            QDialog::keyPressEvent(event);
    }
}

bool Ticket::eventFilter(QObject *watched, QEvent *event)	//鼠标左键点击事件过滤
{
    if (watched == ui->edit_begin || watched == ui->edit_end || watched == ui->edit_count || watched == ui->edit_money)
    {
        if (event->type() == QEvent::MouseButtonPress)
        {
            QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
            if (mouseEvent->button() == Qt::LeftButton)
            {
                ui->edit_begin->setCursorPosition(ui->edit_begin->text().count());
                ui->edit_end->setCursorPosition(ui->edit_end->text().count());
                ui->edit_count->setCursorPosition(ui->edit_count->text().count());
                ui->edit_money->setCursorPosition(ui->edit_money->text().count());
            }
            return true;
        }
    }
    return QDialog::eventFilter(watched, event);
}
