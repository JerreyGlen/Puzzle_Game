#ifndef PUZZLE_GAME_H
#define PUZZLE_GAME_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Puzzle_Game; }
QT_END_NAMESPACE

class Puzzle_Game : public QMainWindow
{
    Q_OBJECT

public:
    Puzzle_Game(QWidget *parent = nullptr);
    ~Puzzle_Game();

private:
    Ui::Puzzle_Game *ui;
};
#endif // PUZZLE_GAME_H
