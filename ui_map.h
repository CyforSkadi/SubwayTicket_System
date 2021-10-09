/********************************************************************************
** Form generated from reading UI file 'map.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAP_H
#define UI_MAP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Map
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit;
    QPushButton *btn_query;
    QPushButton *btn_buy;
    QPushButton *btn_return;
    QSpacerItem *horizontalSpacer_2;
    QTextBrowser *textBrowser;

    void setupUi(QDialog *Map)
    {
        if (Map->objectName().isEmpty())
            Map->setObjectName(QString::fromUtf8("Map"));
        Map->resize(400, 400);
        verticalLayout = new QVBoxLayout(Map);
        verticalLayout->setSpacing(5);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(5);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lineEdit = new QLineEdit(Map);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setMaxLength(2);

        horizontalLayout->addWidget(lineEdit);

        btn_query = new QPushButton(Map);
        btn_query->setObjectName(QString::fromUtf8("btn_query"));

        horizontalLayout->addWidget(btn_query);

        btn_buy = new QPushButton(Map);
        btn_buy->setObjectName(QString::fromUtf8("btn_buy"));

        horizontalLayout->addWidget(btn_buy);

        btn_return = new QPushButton(Map);
        btn_return->setObjectName(QString::fromUtf8("btn_return"));

        horizontalLayout->addWidget(btn_return);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        textBrowser = new QTextBrowser(Map);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));

        verticalLayout->addWidget(textBrowser);


        retranslateUi(Map);

        QMetaObject::connectSlotsByName(Map);
    } // setupUi

    void retranslateUi(QDialog *Map)
    {
        Map->setWindowTitle(QApplication::translate("Map", "Dialog", nullptr));
        lineEdit->setInputMask(QApplication::translate("Map", "99", nullptr));
        lineEdit->setPlaceholderText(QApplication::translate("Map", "\347\253\231\347\202\271\347\274\226\345\217\267", nullptr));
        btn_query->setText(QApplication::translate("Map", "\346\237\245\350\257\242", nullptr));
        btn_buy->setText(QApplication::translate("Map", "\350\264\255\347\245\250", nullptr));
        btn_return->setText(QApplication::translate("Map", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Map: public Ui_Map {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAP_H
