#include "mainwindow.h"
#include <QApplication>
#include <start.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    start w;
    w.show();

    return a.exec();
}
