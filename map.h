#ifndef MAP_H
#define MAP_H

#include "ticket.h"
#include <QDialog>

namespace Ui {
class Map;
}

class Map : public QDialog	//µØÍ¼
{
    Q_OBJECT

public:
    explicit Map(QWidget *parent = nullptr);
    ~Map();

protected:
    void closeEvent(QCloseEvent *) override;
    void keyPressEvent(QKeyEvent *) override;
    bool eventFilter(QObject *, QEvent *) override;

private:
    Ui::Map *ui;
    Ticket *ticket;
};

#endif // MAP_H
