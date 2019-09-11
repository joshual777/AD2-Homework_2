#include "mainwindow.h"
#include <QApplication>
#include "rectangulo.h"
#include <iostream>
#include "square.h"
#include "facade.h"
using namespace std;

int main(int argc, char *argv[])
{
    facade* fachada = new facade();
    fachada->comparacion(5);

    /*
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
*/
    //return a.exec();
    return 0;
}
