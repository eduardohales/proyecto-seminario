#include "mainwindow.h"
#include <QApplication>
#include "Grafo.h"
#include "Simulador.h"
#include "Scheduler.h"

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

   return a.exec();
}
