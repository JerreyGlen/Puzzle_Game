#include "form.h"
#include "ui_form.h"

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
}

Form::~Form()
{
    delete ui;
}

void Form::on_pushButton_2_clicked()
{
    form1.show();
    this->hide();
}


//Load an image
void Form::on_chooseImage_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Choose"), "", tr("Images (*.png *.jpg *jpeg *.bmp *.gif)"));

    if(QString::compare(filename, QString()) != 0){

        QImage image;
        bool valid = image.load(filename);

        if(valid)
        {
            //scale the size of the image to our Gui
            image = image.scaledToWidth(ui->imagePlace->width(), Qt::SmoothTransformation);
            ui->imagePlace->setPixmap(QPixmap::fromImage(image));
        }
        else
        {
            //Error handling

        }
    }
}

