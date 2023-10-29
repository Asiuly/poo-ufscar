#include "complexo.h"
#include <iostream>

using namespace std;

int main(){
    Complexo n1 {10,20};
    Complexo n2 {5,15};

    cout << "n1 = ";
    n1.print();
    cout << "n2 = ";
    n2.print();

    Complexo n3 = n1 + n2;
    cout << "n1+n2 = ";
    n3.print();

    return 0;
}