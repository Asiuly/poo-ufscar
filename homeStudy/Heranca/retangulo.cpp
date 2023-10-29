#include "retangulo.h"
#include <iostream>

using namespace std;

Retangulo:: Retangulo(double x, double y, double base, double altura):
                        Forma{x, y}, base{base}, altura{altura} { }
//utilizando o construtor de forma para setar x e y, depois setando this.base com base e etc.

double Retangulo:: area(){
    return base*altura;
}

void Retangulo:: imprimirDados(){
    //para imprimir x e y, usamos a função pai do retangulo (forma) que ja faz isso
    Forma::imprimirDados();

    //imprimundo coisas especificas do retangulo (polimorfando a função imprimirDadosde forma)
    cout << "Base: " << base << "\nAltura: " << altura << endl;
    
    //para imprimir a área, chamei a função que calcula a área
    cout << "Area: " << area() << endl;
}