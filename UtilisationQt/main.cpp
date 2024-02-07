#include "utilisationqt.h"

#include <QtGui>
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    UtilisationQt w;
    w.show();
    return a.exec();
}
