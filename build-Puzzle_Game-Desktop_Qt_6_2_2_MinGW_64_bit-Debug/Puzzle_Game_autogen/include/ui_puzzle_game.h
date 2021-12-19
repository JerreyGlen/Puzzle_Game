/********************************************************************************
** Form generated from reading UI file 'puzzle_game.ui'
**
** Created by: Qt User Interface Compiler version 6.2.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PUZZLE_GAME_H
#define UI_PUZZLE_GAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Puzzle_Game
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Puzzle_Game)
    {
        if (Puzzle_Game->objectName().isEmpty())
            Puzzle_Game->setObjectName(QString::fromUtf8("Puzzle_Game"));
        Puzzle_Game->resize(800, 600);
        centralwidget = new QWidget(Puzzle_Game);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Puzzle_Game->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Puzzle_Game);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        Puzzle_Game->setMenuBar(menubar);
        statusbar = new QStatusBar(Puzzle_Game);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Puzzle_Game->setStatusBar(statusbar);

        retranslateUi(Puzzle_Game);

        QMetaObject::connectSlotsByName(Puzzle_Game);
    } // setupUi

    void retranslateUi(QMainWindow *Puzzle_Game)
    {
        Puzzle_Game->setWindowTitle(QCoreApplication::translate("Puzzle_Game", "Puzzle_Game", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Puzzle_Game: public Ui_Puzzle_Game {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PUZZLE_GAME_H
