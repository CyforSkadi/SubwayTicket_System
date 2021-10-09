#include <QKeyEvent>
#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
	setWindowTitle(tr("主界面"));
    setWindowFlags(Qt::Dialog | Qt::WindowCloseButtonHint);

    ticket = new Ticket(this);
    connect(ui->btn_buy, &QPushButton::clicked, this, [this]()	//点击进入购票界面
    {
        this->hide();
        ticket->show();
    });

    map = new Map(this);
    connect(ui->btn_query, &QPushButton::clicked, this, [this]()	//点击进入地图查询界面
    {
        this->hide();
        map->show();
    });

    connect(ui->btn_exit, &QPushButton::clicked, this, []()	//点击退出界面
    {
        qApp->exit();
    });
}

Dialog::~Dialog()
{
    delete ui;
    delete map;
    delete ticket;
}

void Dialog::closeEvent(QCloseEvent *)
{
    this->parentWidget()->show();
}

void Dialog::keyPressEvent(QKeyEvent *event)
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
