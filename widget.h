#ifndef WIDGET_H
#define WIDGET_H

#include "dialog.h"
#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget	//基本单元窗口
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *) override;
    void mousePressEvent(QMouseEvent *) override;

private:
    Ui::Widget *ui;
    Dialog *dialog;
};

#endif // WIDGET_H
