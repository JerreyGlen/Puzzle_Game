#include "startseite.h"
#include "ui_startseite.h"
#include "seite1.h"

startseite::startseite(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::startseite)
{
    ui->setupUi(this);
     setWindowTitle(tr("Puzzle Spiel"));
}

void startseite::on_pushButton_clicked()
{

      seite1* seite1a = new  seite1();
    seite1a->show();
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
