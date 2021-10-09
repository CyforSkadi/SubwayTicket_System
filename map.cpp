#include <QtWidgets>
#include "info.h"
#include "map.h"
#include "ui_map.h"

Map::Map(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Map)
{
    ui->setupUi(this);
    setWindowTitle(tr("地图查询"));
    setWindowFlags(Qt::Dialog | Qt::WindowCloseButtonHint);
    ui->lineEdit->installEventFilter(this);

    connect(ui->btn_query, &QPushButton::clicked, this, [this]()	//地图查询
    {
        QString str = ui->lineEdit->text();
        if (str.isEmpty())
        {
            QMessageBox::information(this, tr("提示"), tr("请输入站点编号!"), tr("确定"));
            return;
        }
        bool found = false;
        for (auto it = map.begin(); it != map.end(); ++it)
        {
            if (str.toInt() == it.key())
            {
                found = true;
                ui->textBrowser->setText(QString("5号线, 站点编号: %1, 站点名称: %2").arg(it.key()).arg(it.value()));
                break;
            }
        }
        if (!found)
        {
            ui->textBrowser->setText(tr("未找到相关信息!"));
        }
    });

    ticket = new Ticket(this->parentWidget());
    connect(ui->btn_buy, &QPushButton::clicked, this, [this]()	//进入购票事件
    {
        this->hide();
        ticket->show();
    });

    connect(ui->btn_return, &QPushButton::clicked, this, [this]()	//返回事件
    {
        this->close();
    });
}

Map::~Map()
{
    delete ui;
    delete ticket;
}

void Map::closeEvent(QCloseEvent *)
{
    ui->lineEdit->clear();
    ui->textBrowser->clear();
    this->parentWidget()->show();
}

void Map::keyPressEvent(QKeyEvent *event)
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

bool Map::eventFilter(QObject *watched, QEvent *event)	//鼠标左键点击事件过滤
{
    if (watched == ui->lineEdit)
    {
        if (event->type() == QEvent::MouseButtonPress)
        {
            QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
            if (mouseEvent->button() == Qt::LeftButton)
            {
                ui->lineEdit->setCursorPosition(ui->lineEdit->text().count());
            }
            return true;
        }
    }
    return QDialog::eventFilter(watched, event);
}
