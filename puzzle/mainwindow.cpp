#include "mainwindow.h"
#include "piecesmodel.h"
#include "puzzlewidget.h"
#include "muster.h"

#include <QtWidgets>
#include <stdlib.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setupMenus();
    setupWidgets();

    SetupBar();
    model = new PiecesModel(puzzleWidget->pieceSize(), this);
    piecesList->setModel(model);


    setSizePolicy(QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed));
    setWindowTitle(tr("Puzzle"));
}

void MainWindow::openImage()
{
    const QString directory =
        QStandardPaths::standardLocations(QStandardPaths::PicturesLocation).value(0, QDir::homePath());
    QFileDialog dialog(this, tr("Open Image"), directory);
    dialog.setAcceptMode(QFileDialog::AcceptOpen);
    dialog.setFileMode(QFileDialog::ExistingFile);
    QStringList mimeTypeFilters;
    for (const QByteArray &mimeTypeName : QImageReader::supportedMimeTypes())
        mimeTypeFilters.append(mimeTypeName);
    mimeTypeFilters.sort();
    dialog.setMimeTypeFilters(mimeTypeFilters);
    dialog.selectMimeTypeFilter("image/jpeg");
    if (dialog.exec() == QDialog::Accepted)
        loadImage(dialog.selectedFiles().constFirst());
}

void MainWindow::loadImage(const QString &fileName)
{
    QPixmap newImage;
    if (!newImage.load(fileName)) {
        QMessageBox::warning(this, tr("Open Image"),
                             tr("The image file could not be loaded."),
                             QMessageBox::Close);
        return;
    }
    pImage=newImage;
    puzzleImage = newImage;
    setupPuzzle();
}

void MainWindow::setCompleted()
{
    QMessageBox::information(this, tr("Puzzle Completed"),
                             tr("Congratulations! You have completed the puzzle!\n"
                                "Click OK to start again."),
                             QMessageBox::Ok);

    setupPuzzle();
}

void MainWindow::setupPuzzle()
{
    int size = qMin(puzzleImage.width(), puzzleImage.height());
    puzzleImage = puzzleImage.copy((puzzleImage.width() - size) / 2,
        (puzzleImage.height() - size) / 2, size, size).scaled(puzzleWidget->imageSize(),
            puzzleWidget->imageSize(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

    pImage=puzzleImage;
    model->addPieces(puzzleImage);
    puzzleWidget->clear();
}

void MainWindow::setupMenus()
{
    QMenu *fileMenu = menuBar()->addMenu(tr("&File"));

    QAction *openAction = fileMenu->addAction(tr("&Open..."), this, &MainWindow::openImage);
    openAction->setShortcuts(QKeySequence::Open);

    QAction *exitAction = fileMenu->addAction(tr("E&xit"), qApp, &QCoreApplication::quit);
    exitAction->setShortcuts(QKeySequence::Quit);

    QMenu *gameMenu = menuBar()->addMenu(tr("&Game"));

    gameMenu->addAction(tr("&Restart"), this, &MainWindow::setupPuzzle);

    gameMenu->addAction(tr("&Muster"), this, &MainWindow::showMuster);
}

void MainWindow::showMuster()
{
    Muster w;
    w.show();

}


/*void MainWindow::createStatusBar()
{
    Info="Wählen Sie ein Bild aus";
    statusBar()->showMessage(tr(Info), 0);

}*/
//Hier die Statusbar eingestellt
void MainWindow::SetupBar()
{
    Info="Wählen Sie ein Bild aus";
    QLabel *label = new QLabel(this);
    label->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    label->setText(Info);
    label->setAlignment(Qt::AlignBottom | Qt::AlignRight);
    statusBar()->insertPermanentWidget(0, label, 0);//QStatusBar *barMenu =
    QLabel *label1 = new QLabel(this);
    label1->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    label1->setText(Info);
    label1->setAlignment(Qt::AlignBottom | Qt::AlignLeft);
    statusBar()->addPermanentWidget(label1, 0);
}


void MainWindow::setupWidgets()
{
    QFrame *frame = new QFrame;
    QHBoxLayout *frameLayout = new QHBoxLayout(frame);

    puzzleWidget = new PuzzleWidget(400);
    puzzleWidget1 = new PuzzleWidget(400);
    puzzleWidget1->setPixmap(pImage);

    QLabel *label = new QLabel(this);
    label->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    label->setPixmap(pImage);
    //label->setText("pImage ta");
    label->setFixedSize(465, 400);
    label->show();
    //label->heightForWidth(100);

    piecesList = new QListView;
    piecesList->setDragEnabled(true);
    piecesList->setViewMode(QListView::IconMode);
    piecesList->setIconSize(QSize(puzzleWidget->pieceSize() - 20, puzzleWidget->pieceSize() - 20));
    piecesList->setGridSize(QSize(puzzleWidget->pieceSize(), puzzleWidget->pieceSize()));
    piecesList->setSpacing(10);
    piecesList->setMovement(QListView::Snap);
    piecesList->setAcceptDrops(true);
    piecesList->setDropIndicatorShown(true);

    PiecesModel *model = new PiecesModel(puzzleWidget->pieceSize(), this);
    piecesList->setModel(model);

    connect(puzzleWidget, &PuzzleWidget::puzzleCompleted,
            this, &MainWindow::setCompleted, Qt::QueuedConnection);

    frameLayout->addWidget(piecesList);
    frameLayout->addWidget(puzzleWidget);
    frameLayout->addWidget(puzzleWidget1);

    frameLayout->addWidget(label);
    setCentralWidget(frame);
}
