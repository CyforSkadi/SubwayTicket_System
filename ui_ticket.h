/********************************************************************************
** Form generated from reading UI file 'ticket.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TICKET_H
#define UI_TICKET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Ticket
{
public:
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QComboBox *comboBox;
    QLineEdit *edit_begin;
    QLineEdit *edit_end;
    QLineEdit *edit_count;
    QPushButton *btn_confirm;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *edit_money;
    QPushButton *btn_pay;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *Ticket)
    {
        if (Ticket->objectName().isEmpty())
            Ticket->setObjectName(QString::fromUtf8("Ticket"));
        Ticket->resize(400, 400);
        horizontalLayout = new QHBoxLayout(Ticket);
        horizontalLayout->setSpacing(5);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(5);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        comboBox = new QComboBox(Ticket);
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        verticalLayout->addWidget(comboBox);

        edit_begin = new QLineEdit(Ticket);
        edit_begin->setObjectName(QString::fromUtf8("edit_begin"));
        edit_begin->setMaxLength(2);

        verticalLayout->addWidget(edit_begin);

        edit_end = new QLineEdit(Ticket);
        edit_end->setObjectName(QString::fromUtf8("edit_end"));
        edit_end->setMaxLength(2);

        verticalLayout->addWidget(edit_end);

        edit_count = new QLineEdit(Ticket);
        edit_count->setObjectName(QString::fromUtf8("edit_count"));

        verticalLayout->addWidget(edit_count);

        btn_confirm = new QPushButton(Ticket);
        btn_confirm->setObjectName(QString::fromUtf8("btn_confirm"));

        verticalLayout->addWidget(btn_confirm);

        widget = new QWidget(Ticket);
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setSpacing(5);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        edit_money = new QLineEdit(widget);
        edit_money->setObjectName(QString::fromUtf8("edit_money"));

        verticalLayout_2->addWidget(edit_money);

        btn_pay = new QPushButton(widget);
        btn_pay->setObjectName(QString::fromUtf8("btn_pay"));

        verticalLayout_2->addWidget(btn_pay);


        verticalLayout->addWidget(widget);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);


        horizontalLayout->addLayout(verticalLayout);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        retranslateUi(Ticket);

        QMetaObject::connectSlotsByName(Ticket);
    } // setupUi

    void retranslateUi(QDialog *Ticket)
    {
        Ticket->setWindowTitle(QApplication::translate("Ticket", "Dialog", nullptr));
        comboBox->setItemText(0, QApplication::translate("Ticket", "5\345\217\267\347\272\277", nullptr));

        edit_begin->setInputMask(QApplication::translate("Ticket", "99", nullptr));
        edit_begin->setText(QString());
        edit_begin->setPlaceholderText(QApplication::translate("Ticket", "\347\253\231\347\202\271\347\274\226\345\217\267-\345\247\213", nullptr));
        edit_end->setInputMask(QApplication::translate("Ticket", "99", nullptr));
        edit_end->setPlaceholderText(QApplication::translate("Ticket", "\347\253\231\347\202\271\347\274\226\345\217\267-\347\273\210", nullptr));
        edit_count->setInputMask(QApplication::translate("Ticket", "99", nullptr));
        edit_count->setText(QString());
        edit_count->setPlaceholderText(QApplication::translate("Ticket", "\347\245\250\346\225\260", nullptr));
        btn_confirm->setText(QApplication::translate("Ticket", "\347\241\256\350\256\244", nullptr));
        edit_money->setInputMask(QApplication::translate("Ticket", "9999", nullptr));
        edit_money->setPlaceholderText(QApplication::translate("Ticket", "\351\207\221\351\242\235", nullptr));
        btn_pay->setText(QApplication::translate("Ticket", "\346\224\257\344\273\230", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Ticket: public Ui_Ticket {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TICKET_H
