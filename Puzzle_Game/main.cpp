#include "puzzle_game.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Puzzle_Game w;
    w.show();
    return a.exec();
}
