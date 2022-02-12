#ifndef MUSTER_H
#define MUSTER_H

#include <QWidget>

namespace Ui {
class Muster;
}

class Muster : public QWidget
{
    Q_OBJECT

public:
    explicit Muster(QWidget *parent = nullptr);
    ~Muster();

public:
    void Image();

private:
    Ui::Muster *ui;
};

#endif // MUSTER_H
