#ifndef FORM3_H
#define FORM3_H

#include <QWidget>
#include <form.h>
//#include <form1.h>

namespace Ui {
class Form3;
}

class Form3 : public QWidget
{
    Q_OBJECT

public:
    explicit Form3(QWidget *parent = nullptr);
    ~Form3();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::Form3 *ui;
   /* Form form;
    Form1 form1;*/
};

#endif // FORM3_H
