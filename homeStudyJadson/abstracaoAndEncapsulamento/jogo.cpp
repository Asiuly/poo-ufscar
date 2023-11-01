#include <iostream>
#include <string>
#include "jogo.h"

using namespace std;

void Jogo:: adquirir(const string& titulo, float valor){
    nome = titulo;
    preco = valor;
    horas = 0;
    custo = valor;
}

void Jogo:: atualizar(float valor){
    preco = valor;
    calcular();
}

void Jogo:: jogar(int tempoJogado){
    horas += tempoJogado;
    calcular();
}

void Jogo:: exibir(){
    cout << "Nome do jogo: " << nome
         << "\nPreço do jogo: " << preco
         << "\nHoras jogadas: " << horas
         << "\nCusto por hora: " << custo << endl;
}