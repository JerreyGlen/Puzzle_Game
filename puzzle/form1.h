#ifndef FORM1_H
#define FORM1_H

#include <QWidget>
//#include <form2.h>
//#include <form3.h>


namespace Ui {
class Form1;
}

class Form1 : public QWidget
{
    Q_OBJECT

public:
    explicit Form1(QWidget *parent = nullptr);
    ~Form1();

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::Form1 *ui;
  /*  Form2 form2;
    Form3 form3;*/
};

#endif // FORM1_H
