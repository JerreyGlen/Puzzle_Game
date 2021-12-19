#include "puzzle_game.h"
#include "./ui_puzzle_game.h"

Puzzle_Game::Puzzle_Game(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Puzzle_Game)
{
    ui->setupUi(this);
}

Puzzle_Game::~Puzzle_Game()
{
    delete ui;
}

