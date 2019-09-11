#include "facade.h"
#include "rectangulo.h"
#include "square.h"
#include <iostream>
using namespace std;
facade::facade()
{
}
void facade::comparacion(int number){
    if(number == 2){
        Rectangulo* rect = new Rectangulo();
        rect->dibuja_Rectangulo();
    }else{
        square* cuadro = new square();
        cuadro->crea_cuadro();
    }
}
