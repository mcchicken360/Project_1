/***********************************************************************************
 * Authors      : David Mei, Matthew Mirbasoo, You Lyu, Ruitau He
 * Project #1   : Super Warehouse
 * Class        : CS008
 * Due Date     : 03/03/2022
***********************************************************************************/
#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
