#include "Pessoa.h"
#include <iostream>
#include <string>

using namespace std;

Pessoa:: Pessoa(string nome, int idade){
    this->nome = nome;
    this->idade = idade;
}

string Pessoa:: getNome(){
    return nome;
}

void Pessoa::setNome(string nome){
    this->nome = nome;
}

int Pessoa::getIdade(){
    return idade;
}

void Pessoa::setIdade(int idade){
    this->idade = idade;
}

void Pessoa::imprime(){
    cout << "O seu nome: " << nome << endl;
    cout << "A sua idade: " << idade << endl;
}