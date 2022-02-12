QT += widgets
requires(qtConfig(listview))

HEADERS     = mainwindow.h \
              muster.h \
              piecesmodel.h \
              puzzlewidget.h \
              startseite.h
RESOURCES   = \
    puzzle.qrc
SOURCES     = main.cpp \
              mainwindow.cpp \
              muster.cpp \
              piecesmodel.cpp \
              puzzlewidget.cpp \
              startseite.cpp

# install
target.path = $$[QT_INSTALL_EXAMPLES]/widgets/itemviews/puzzle
INSTALLS += target

FORMS += \
    muster.ui \
    startseite.ui
