#include "Caminhao.h"
#include <iostream>
#include <string>
using namespace std;

Caminhao:: Caminhao(string placa, string marca, string cor, int ano, int nroEixos):
                 Veiculo(placa, marca, cor, ano), nroEixos(nroEixos) { }

int Caminhao:: getEixos() const{
    return this->nroEixos;
}

void Caminhao:: setEixos(int nroEixos){
    this->nroEixos = nroEixos;
}

int Caminhao:: getCategoria() const{
    return 2;
}

void Caminhao:: imprime() const{
    Veiculo:: imprime();
    cout << ", Numero de eixos: " << getEixos() << endl;
}