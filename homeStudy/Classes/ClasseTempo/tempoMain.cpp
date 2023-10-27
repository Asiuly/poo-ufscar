#include <iostream>
#include "tempo.h"

using namespace std;

int main(){
    Tempo t1;
    Tempo tCustomizado(11, 20, 36);

    cout << "Tempo t1: ";
    t1.imprime();

    cout << "Hora do customizado: ";
    tCustomizado.imprime();

    t1.setTempo(12, 35, 65);
    t1.imprime();

    return 0;
}