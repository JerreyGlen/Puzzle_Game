#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include <form1.h>
#include <QFileDialog>

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = nullptr);
    ~Form();

private slots:
    void on_pushButton_2_clicked();

    void on_chooseImage_clicked();

private:
    Ui::Form *ui;
    Form1 form1;
};

#endif // FORM_H
