#ifndef FORM2_H
#define FORM2_H

#include <QWidget>
#include <form.h>
//#include <form1.h>

namespace Ui {
class Form2;
}

class Form2 : public QWidget
{
    Q_OBJECT

public:
    explicit Form2(QWidget *parent = nullptr);
    ~Form2();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::Form2 *ui;
   /* Form form;
    Form1 form1;*/
};

#endif // FORM2_H
