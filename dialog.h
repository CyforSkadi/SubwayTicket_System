#ifndef DIALOG_H
#define DIALOG_H

#include "map.h"
#include "ticket.h"
#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog	//½»»¥¶Ô»°¿ò
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

protected:
    void closeEvent(QCloseEvent *) override;
    void keyPressEvent(QKeyEvent *) override;

private:
    Ui::Dialog *ui;
    Ticket *ticket;
    Map *map;
};

#endif // DIALOG_H
