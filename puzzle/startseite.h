#ifndef STARTSEITE_H
#define STARTSEITE_H

#include <QWidget>
#include "mainwindow.h"

namespace Ui {
class startseite;
}

class startseite : public QWidget
{
    Q_OBJECT

public:
    explicit startseite(QWidget *parent = nullptr);
    ~startseite();

private slots:
    void on_pushButton_clicked();

    void on_exitButton_clicked();

private:
    Ui::startseite *ui;
    MainWindow windows;
};

#endif // STARTSEITE_H
