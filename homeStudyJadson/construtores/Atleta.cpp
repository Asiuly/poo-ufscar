#include "Atleta.h"
#include <iostream>

using namespace std;

Atleta:: Atleta(){
    acertos = 0;
    tentativas = 0;
    porcentual = 0;
}

Atleta:: Atleta(int acertos, int tentativas): acertos{acertos}, tentativas{tentativas} { }

void Atleta:: exibir() const{
    cout << "Acertos: " << acertos;
    cout << "Tentativas: " << tentativas;
    cout << "Porcentual: " << porcentual << endl;
}

void Atleta:: acumular(Atleta& atletaSoma){
    atletaSoma.tentativas += tentativas;
    atletaSoma.acertos += acertos;
    atletaSoma.calcular();
}
