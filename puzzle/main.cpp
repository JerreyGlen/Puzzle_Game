#include "mainwindow.h"
#include "startseite.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    Q_INIT_RESOURCE(puzzle);

    QApplication app(argc, argv);
    startseite start;
    start.show();
    /*MainWindow window;
    window.loadImage(QStringLiteral(":/images/example.jpg"));
    window.show();*/
    return app.exec();
}
