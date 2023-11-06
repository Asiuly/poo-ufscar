#include "Pessoa.h"
#include <iostream>

using namespace std;

int main(){

    Pessoa ana;
    Pessoa Joao{"Joao"};
    Pessoa jose {"Jose", "Santos"};
    Pessoa pedro {"Pedro", "Silva"};

    ana.Exibir();
    Joao.Exibir();
    jose.Formal();
    pedro.Formal();

    return 0;
}