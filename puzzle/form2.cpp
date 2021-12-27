#include "form2.h"
#include "ui_form2.h"

Form2::Form2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form2)
{
    ui->setupUi(this);
}

Form2::~Form2()
{
    delete ui;
}

void Form2::on_pushButton_2_clicked()
{
    form.show();
    this->hide();
}


/*void Form2::spielWiederholenclicked()
{
    form1.show();
    this->hide();
}*/


void Form2::on_pushButton_clicked()
{
    form1.show();
    this->hide();
}

