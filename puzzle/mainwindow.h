#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPixmap>
#include <QTimer>
#include <QTime>
#include <string>
#include <QtWidgets>
#include <stdlib.h>


class PuzzleWidget;
class PiecesModel;
QT_BEGIN_NAMESPACE
class QListView;
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr, int timeset =0);
    QTimer* timer;
    QTime time;
    int counter =0;


public slots:
    void openImage();
    void loadImage(const QString &path);
    void setupPuzzle();
    void showMuster();
     void timerUpdate();
     void startGame();
     void pinChange(int c);
      void startseiteGame();
       void seite1Game();

private slots:
    void setCompleted();
    void setNoCompleted();
    void setGameCompleted();

private:
    void setupMenus();
    void setupWidgets();
    void SetupBar();
    void SetupBar1();
    void setTime();


public:
    QPixmap puzzleImage;
    QPixmap pImage;

    QListView *piecesList;
    PuzzleWidget *puzzleWidget;
    PuzzleWidget *puzzleWidget1;
    PiecesModel *model;
    char *Info;

    QLabel *label1 = new QLabel(this);
    QLabel *label = new QLabel(this);
    int spielZeit =0;
};

#endif // MAINWINDOW_H
