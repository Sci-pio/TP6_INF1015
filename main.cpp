// Auteurs: Leonard Pouliot (2150965) et Kamil Maarite (2152653)
// Date: 4 decembre 2022
// Cours: INF1015
// Nom de la classe: main.cpp

#include "mainwindow.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
