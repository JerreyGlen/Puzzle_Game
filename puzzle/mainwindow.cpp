#include "mainwindow.h"
#include "piecesmodel.h"
#include "puzzlewidget.h"
#include "muster.h"
#include "seite1.h"
#include "startseite.h"
#include "seite1.h"

#include <QtWidgets>
#include <stdlib.h>

MainWindow::MainWindow(QWidget *parent, int timeset)
    : QMainWindow(parent)
{
//Das Menu wird angezeit
    spielZeit = timeset;
    setupMenus();
    setupWidgets();
    setTime();
    SetupBar();
    model = new PiecesModel(puzzleWidget->pieceSize(), this);
    piecesList->setModel(model);

    setSizePolicy(QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed));
    setWindowTitle(tr("Puzzle Spiel"));
}

void MainWindow::setTime(){

    seite1* seite1b = new seite1();
    QObject::connect(seite1b, SIGNAL(change(int)), this, SLOT(pinChange(int)));
}

void MainWindow::pinChange(int c){
    spielZeit = c;
}
//Der explorer des Rechners wird geöffnet
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

//Das ausgewählte Bild wird hochgeladen
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
    label1->setText("");
      label->setText("Führer: Klicken Sie auf \"Game\" und wählen Sie \"Start\", um eine Spielzeit zu setzen!");
}

//Beim erfolgreichen Lösen des Puzzels
void MainWindow::setCompleted()
{
    QMessageBox::information(this, tr("Vollständiges Puzzle"),
                             tr("Herzlichen Glückwunsch! Du hast das Puzzel gelöst!\n"
                                "Klicken Sie auf OK, um erneut zu starten!"),
                             QMessageBox::Ok);


    setupPuzzle();
}

void MainWindow::setGameCompleted()
{
    QMessageBox::information(this, tr("Nicht vollständiges Puzzle"),
                             tr("Die Spielzeit ist abgelaufen.!\n"
                                "Klicken Sie auf OK, um erneut zu starten!"),
                             QMessageBox::Ok);


    setupPuzzle();
}

//Beim nicht erfolgreichen Lösen des Puzzels
void MainWindow::setNoCompleted(){

  if (QMessageBox::Ok ==   QMessageBox::information(this, tr("Nicht vollständiges Puzzle"),
                                                    tr("Klicken Sie auf OK, um erneut zu starten!\n"
                                                       "Klicken Sie auf No, um das Spiel fortzusetzen!"),
                                                    QMessageBox::Ok,
                                                    QMessageBox::No)){
       setupPuzzle();
  }else{

  }



}


//Beim Klick auf "Restart", werden die bewegte Bilder wie am Anfang positioniert
void MainWindow::setupPuzzle()
{
    int size = qMin(puzzleImage.width(), puzzleImage.height());
    puzzleImage = puzzleImage.copy((puzzleImage.width() - size) / 2,
        (puzzleImage.height() - size) / 2, size, size).scaled(puzzleWidget->imageSize(),
            puzzleWidget->imageSize(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

    pImage=puzzleImage;
    model->addPieces(puzzleImage);
    puzzleWidget->clear();

  //  label->setText("Führer: Bewegen Sie die zugeschnitten Bilder per Drag and Drop, um sie zuzuordnen !");
//Beim Klick auf "Restart", wird die Restzeit zurückgesetzt
  time.setHMS(0,spielZeit,0,0);
}

void MainWindow:: startGame(){
    SetupBar1();
    label->setText("Führer: Bewegen Sie die zugeschnitten Bilder per Drag and Drop, um sie zuzuordnen !");
}

//Das Oben-Menu wird erstellt
void MainWindow::setupMenus()
{
    //Das Menu "file" wird erstellt
    QMenu *fileMenu = menuBar()->addMenu(tr("&File"));

    //Das Untermenu "Open" wird erstellt
    QAction *openAction = fileMenu->addAction(tr("&Öffnen..."), this, &MainWindow::openImage);
    openAction->setShortcuts(QKeySequence::Open);

     //Das Untermenu "Exit" wird erstellt
    QAction *exitAction = fileMenu->addAction(tr("E&xit"), qApp, &QCoreApplication::quit);
    exitAction->setShortcuts(QKeySequence::Quit);


    QMenu *gameMenu = menuBar()->addMenu(tr("&Game"));

     gameMenu->addAction(tr("&Start"), this, &MainWindow::startGame);
    gameMenu->addAction(tr("&Restart"), this, &MainWindow::setupPuzzle);

    gameMenu->addAction(tr("&Muster"), this, &MainWindow::showMuster);
    gameMenu->addAction(tr("Bewerten"), this, &MainWindow::setNoCompleted);

     QMenu *naviMenu = menuBar()->addMenu(tr("&Schnelle Navigation"));
     naviMenu->addAction(tr("&Startseite"), this, &MainWindow::startseiteGame);
     naviMenu->addAction(tr("&Spielzeit"), this, &MainWindow::seite1Game);
}

void MainWindow::startseiteGame(){

    startseite* seite = new startseite();
    seite->show();
    this->hide();
}

void MainWindow::seite1Game(){
  seite1* seite1c = new seite1();
  seite1c->show();
  this->hide();

}

void MainWindow::showMuster()
{
    Muster w;
    w.show();

}



//Hier die Statusbar eingestellt
void MainWindow::SetupBar()
{
    //Info="Wählen Sie ein Bild aus";

    label->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    label->setText("Führer: Klicken Sie auf \"File\" und wählen Sie \"Open\", um ein Bild hochzuladen!");
    label->setAlignment(Qt::AlignBottom | Qt::AlignRight);
    statusBar()->insertPermanentWidget(0, label, 0);//QStatusBar *barMenu =

}

void MainWindow::SetupBar1(){

    label1->setFrameStyle(QFrame::Panel | QFrame::Sunken);

    //Game-zeit wird hinzugefügt
    time.setHMS(0,spielZeit,0,0);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(timerUpdate()));
    timer->start(1000);

    label1->setAlignment(Qt::AlignBottom | Qt::AlignLeft);
    label1->setStyleSheet("background-color:green;");
    statusBar()->addPermanentWidget(label1, 0);

}

//Damit die Restzeit sich alle Sekunden ändern kann.
void MainWindow::timerUpdate(){
    time = time.addSecs(-1);

    label1->setText("Restzeit: " + time.toString("m:ss").arg(counter));
    counter++;
    //To end the game
    if(counter== spielZeit*60){
         label1->setText("Game Over: 00:00");
         label1->setStyleSheet("background-color:red;");

         //  delay of 3s
           QEventLoop loop;
           QTimer::singleShot(3000, &loop, &QEventLoop::quit);
           loop.exec();
         setGameCompleted();
         counter =0;
    }
    label1->setStyleSheet("background-color:green;");



}


void MainWindow::setupWidgets()
{
    QFrame *frame = new QFrame;
    QHBoxLayout *frameLayout = new QHBoxLayout(frame);

    puzzleWidget = new PuzzleWidget(600);
    /*puzzleWidget1 = new PuzzleWidget(400);
    puzzleWidget1->setPixmap(pImage);*/

    QLabel *label = new QLabel(this);
    label->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    label->setPixmap(pImage);
    //label->setText("pImage ta");
    label->setFixedSize(350, 600);
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
 //   frameLayout->addWidget(puzzleWidget1);

    frameLayout->addWidget(label);
    setCentralWidget(frame);
}
