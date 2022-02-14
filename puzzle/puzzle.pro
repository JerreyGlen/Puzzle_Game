QT += widgets
requires(qtConfig(listview))

HEADERS     = mainwindow.h \
              muster.h \
              piecesmodel.h \
              puzzlewidget.h \
              seite1.h \
              startseite.h
RESOURCES   = \
    puzzle.qrc \
    puzzle.qrc
SOURCES     = main.cpp \
              mainwindow.cpp \
              muster.cpp \
              piecesmodel.cpp \
              puzzlewidget.cpp \
              seite1.cpp \
              startseite.cpp

# install
target.path = $$[QT_INSTALL_EXAMPLES]/widgets/itemviews/puzzle
INSTALLS += target

FORMS += \
    muster.ui \
    seite1.ui \
    startseite.ui
