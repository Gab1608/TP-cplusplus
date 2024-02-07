TEMPLATE = app
TARGET = UtilisationQt
QT += core \
    gui
HEADERS += supprimervehiculegui.h \
    ajoutercamiongui.h \
    ajouterpromenadegui.h \
    utilisationqt.h
SOURCES += supprimervehiculegui.cpp \
    ajoutercamiongui.cpp \
    ajouterpromenadegui.cpp \
    main.cpp \
    utilisationqt.cpp
FORMS += supprimervehiculegui.ui \
    ajoutercamiongui.ui \
    ajouterpromenadegui.ui \
    utilisationqt.ui
RESOURCES += 
LIBS += "../source/Debug/libsource.a"
INCLUDEPATH += "../source/."
