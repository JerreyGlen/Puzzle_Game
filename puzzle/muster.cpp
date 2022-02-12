#include "muster.h"
#include "ui_muster.h"
#include "mainwindow.h"

Muster::Muster(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Muster)
{
    Image();
    ui->setupUi(this);
}
void Muster::Image()
{
    QPixmap Image;
    //Image = puzzleImage;
    Image = Image.scaledToWidth(ui->imagePlace->width(), Qt::SmoothTransformation);
    ui->imagePlace->setPixmap(Image);

}

Muster::~Muster()
{
    delete ui;
}
