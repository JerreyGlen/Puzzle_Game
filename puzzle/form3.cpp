#include "form3.h"
#include "ui_form3.h"

Form3::Form3(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form3)
{
    ui->setupUi(this);
}

Form3::~Form3()
{
    delete ui;
}

void Form3::on_pushButton_2_clicked()
{
    form.show();
    this->hide();
}


void Form3::spielWiederholeclicked()
{
    form1.show();
    this->hide();
}

