#include "Carro.h"
#include <iostream>
#include <string>
using namespace std;

Carro:: Carro(string placa, string marca, string cor, int ano, double volume): 
            Veiculo(placa, marca, cor, ano), volume(volume) { }

double Carro:: getVolume() const{
    return this->volume;
}

void Carro:: setvolume(double volumeBagageiro){
    this->volume = volumeBagageiro;
}

int Carro:: getCategoria() const{
    return 1;
}

void Carro:: imprime() const{
    Veiculo:: imprime();
    cout << ", Bagageiro: " << getVolume() << endl;
}