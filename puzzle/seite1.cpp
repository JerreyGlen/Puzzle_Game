#include "seite1.h"
#include "ui_seite1.h"
#include "mainwindow.h"
#include <QDebug>

seite1::seite1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::seite1)
{
    ui->setupUi(this);
     setWindowTitle(tr("Puzzle Spiel"));
}

seite1::~seite1()
{
    delete ui;
}

void seite1::on_pushButton_clicked()
{
    pinBoxValue = ui->spinBox->value();
    QWidget *parent = nullptr;
 qDebug() << "You have obtained" << pinBoxValue << "apples!";
     emit change(pinBoxValue);
      MainWindow* windows = new MainWindow(parent, pinBoxValue);
    windows -> show();
    this->hide();
}

