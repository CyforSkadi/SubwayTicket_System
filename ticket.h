#ifndef TICKET_H
#define TICKET_H

#include <QDialog>

namespace Ui {
class Ticket;
}

class Ticket : public QDialog	//³µÆ±
{
    Q_OBJECT

public:
    explicit Ticket(QWidget *parent = nullptr);
    ~Ticket();

protected:
    void closeEvent(QCloseEvent *) override;
    void keyPressEvent(QKeyEvent *) override;
    bool eventFilter(QObject *, QEvent *) override;

private:
    Ui::Ticket *ui;
    int price = 0;
};

#endif // TICKET_H
