#include "circle.h"
#include <iostream>

using namespace std;

int main(){
    Circle c1; //define tudo com 0
    Circle c2(15, 9, -5);

    cout << "Circle c1: ";
    c1.imprime();

    cout << "Circle c2: ";
    c2.imprime();

    c1.set_radius(10.0);
    c1.set_origin(5, 4);
    
    c1.imprime();

    cout << "Area: " << c1.area() << endl;
    cout << "Diametro: " << c1.diameter();


    return 0;
}