/********************************************************************************
** Form generated from reading UI file 'form3.ui'
**
** Created by: Qt User Interface Compiler version 6.0.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM3_H
#define UI_FORM3_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form3
{
public:
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *Form3)
    {
        if (Form3->objectName().isEmpty())
            Form3->setObjectName(QString::fromUtf8("Form3"));
        Form3->resize(400, 300);
        lineEdit = new QLineEdit(Form3);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(110, 120, 113, 20));
        lineEdit->setReadOnly(true);
        pushButton = new QPushButton(Form3);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(279, 10, 101, 31));
        pushButton_2 = new QPushButton(Form3);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(290, 260, 101, 31));

        retranslateUi(Form3);

        QMetaObject::connectSlotsByName(Form3);
    } // setupUi

    void retranslateUi(QWidget *Form3)
    {
        Form3->setWindowTitle(QCoreApplication::translate("Form3", "Form", nullptr));
        lineEdit->setText(QCoreApplication::translate("Form3", "Nicht erfolgreich", nullptr));
        pushButton->setText(QCoreApplication::translate("Form3", "Spiel wiederholen", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Form3", "Neues Spiel starten", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form3: public Ui_Form3 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM3_H
