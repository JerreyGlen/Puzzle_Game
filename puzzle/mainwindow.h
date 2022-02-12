#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPixmap>

class PuzzleWidget;
class PiecesModel;
QT_BEGIN_NAMESPACE
class QListView;
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

public slots:
    void openImage();
    void loadImage(const QString &path);
    void setupPuzzle();
    void showMuster();

private slots:
    void setCompleted();

private:
    void setupMenus();
    void setupWidgets();
    void createStatusBar();
    void SetupBar();

public:
    QPixmap puzzleImage;
    QPixmap pImage;

    QListView *piecesList;
    PuzzleWidget *puzzleWidget;
    PuzzleWidget *puzzleWidget1;
    PiecesModel *model;
    char *Info;
};

#endif // MAINWINDOW_H
