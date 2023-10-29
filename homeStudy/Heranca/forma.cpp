#include "forma.h"
#include <iostream>

using namespace std;
                    //this.x recebe x parametro, this.y recebe y parametro
Forma:: Forma(double x, double y) : x{x}, y{y} {}

void Forma:: imprimirDados(){
    cout << "Origem: (" << x << ", " << y << ")" << endl;
}