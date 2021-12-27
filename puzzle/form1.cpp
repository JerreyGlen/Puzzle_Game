#include "form1.h"
#include "ui_form1.h"
#include "form2.h"
#include <QDialog>
#include <form3.h>


Form1::Form1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form1)
{
    ui->setupUi(this);
}

Form1::~Form1()
{
    delete ui;
}

void Form1::on_pushButton_2_clicked()
{
    Form2* form2 = new Form2();
    Form3 forms;
    form2->show();
    this->hide();
   /* form2.setModal(true);
    form2.exec();*/

}

