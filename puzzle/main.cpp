#include "mainwindow.h"
#include "startseite.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    Q_INIT_RESOURCE(puzzle);

    QApplication app(argc, argv);
    startseite start;
    start.show();

    return app.exec();
}
