#include "Veiculo.h"
#include <iostream>
#include <string>
using namespace std;

Veiculo:: Veiculo(string placa, string marca, string cor, int ano): placa(placa), marca(marca), cor(cor), ano(ano) { }

string Veiculo:: getPlaca() const{
    return this->placa;
}

string Veiculo:: getMarca() const{
    return this->marca;
}

string Veiculo:: getCor() const{
    return this->cor;
}

int Veiculo:: getAno() const{
    return this->ano;
}

void Veiculo:: setPlaca(string placa){
    this->placa = placa;
}

void Veiculo:: setMarca(string marca){
    this->marca = marca;
}

void Veiculo:: setCor(string cor){
    this->cor = cor;
}

void Veiculo:: setAno(int ano){
    this->ano = ano;
}


void Veiculo:: imprime() const{
    cout << "Marca: " << getMarca() << ", Placa: " << getPlaca() 
    << ", Ano: " << getAno() << ", Cor: " << getCor();
    if(getCategoria() == 1){
        cout << ", Categoria: Carro";
    }
    else{
        cout << ", Categoria: Caminhao";
    }
}

