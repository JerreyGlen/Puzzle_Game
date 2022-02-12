#include "startseite.h"
#include "ui_startseite.h"

startseite::startseite(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::startseite)
{
    ui->setupUi(this);
}

void startseite::on_pushButton_clicked()
{
    windows.show();
    this->hide();
}
void startseite::on_exitButton_clicked()
{
    close();
}

startseite::~startseite()
{
    delete ui;
}
