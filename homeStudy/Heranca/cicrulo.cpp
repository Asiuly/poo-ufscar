#include <iostream>
#include "circulo.h"

using namespace std;

Circulo:: Circulo (double x, double y, double raio): 
                        Forma{x,y}, raio{raio} { }

void Circulo:: imprimirDados(){
    Forma::imprimirDados();
    cout << "Raio: " << this->raio << endl;
    cout << "Area = " << area() << endl;
}

double Circulo::area(){
    return 3,141592*this->raio*this->raio;
}