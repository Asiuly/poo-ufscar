#include <iostream>
#include "tempo.h"
using namespace std;

Tempo:: Tempo(){
    horas = 0;
    minutos = 0;
}

Tempo:: Tempo(int horas, int minutos){
    this->horas = horas;
    this->minutos = minutos;
}

void Tempo:: adicionar(int horas, int minutos){
    this->horas += horas;
    this->minutos += minutos;

    horas += minutos/60;
    minutos %= 60;
}

void Tempo:: resetar(int horas, int minutos){
    this->horas = horas;
    this->minutos = minutos;
}

Tempo Tempo:: somar(const Tempo & tempo) const {
    Tempo soma;
    soma.horas = this->horas + tempo.horas;
    soma.minutos = this->minutos + tempo.minutos;

    soma.horas += soma.minutos /60;
    soma.minutos %= 60;

    return soma;
}

//faz a mesma coisa que o somar mas possibilita usar o operador que soma
//objetos da classe na chamada da função (tempo1 + tempo 2) vai chamar esse operador
Tempo Tempo:: operator+(const Tempo & tempo) const {
    Tempo soma;
    soma.horas = this->horas + tempo.horas;
    soma.minutos = this->minutos + tempo.minutos;

    soma.horas += soma.minutos /60;
    soma.minutos %= 60;

    return soma;
}


void Tempo:: exibir() const{
    cout << horas << " horas, " <<
            minutos << " minutos" << endl;
}