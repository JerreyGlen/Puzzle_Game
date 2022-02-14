#ifndef SEITE1_H
#define SEITE1_H

#include <QWidget>


namespace Ui {
class seite1;
}

class seite1 : public QWidget
{
    Q_OBJECT

signals:
    void change(int s);

public:
    explicit seite1(QWidget *parent = nullptr);
    ~seite1();
    int pinBoxValue =0;


private slots:
    void on_pushButton_clicked();



private:
    Ui::seite1 *ui;
};

#endif // SEITE1_H
