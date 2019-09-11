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
    fachada->comparacion(5); //si es 2 se dibuja rectangulo y si no un cuadrado
    return 0;
}
