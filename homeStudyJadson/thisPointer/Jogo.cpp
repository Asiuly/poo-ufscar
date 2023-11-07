#include <iostream>
#include <string>
#include "jogo.h"
using namespace std;

Jogo:: Jogo(){
    this->nome = "";
    this->preco = 0;
    this->custo = 0;
    this->horas = 0;
}

Jogo:: Jogo(const string& titulo, float valor = 0.0, int tempo = 0){
    this->nome = titulo;
    this->preco = valor;
    this->horas = tempo;
    calcular();
}

Jogo:: ~Jogo(){

}

const Jogo& Jogo:: compararMaisJogado(const Jogo& jogo) const{
    if(jogo.horas > this->horas){
        return jogo;
    }
    else{
        return *this;
    }
}

void Jogo:: atualizar(float preco){
    this->preco = preco;
    calcular();
}

void Jogo:: jogar(int horasJogadas){
    this->horas += horasJogadas;
    calcular();
}

void Jogo:: exibir() const{
    cout << "Nome do Jogo: " << this->nome << endl;
    cout << "Preço: " << this->preco << endl;
    cout << "Horas Jogadas: " << this->horas << endl;
    cout << "Custo por hora: " << this->custo << endl;
}