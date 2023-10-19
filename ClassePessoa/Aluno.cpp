#include "Aluno.h"
#include "Pessoa.h"
#include <iostream>
#include <string>

using namespace std;

Aluno:: Aluno(string nome, int idade, int RA): Pessoa(nome, idade){
    this->RA = RA;
}

int Aluno:: getRA(){
    return this->RA;
}

void Aluno::setRA(int RA){
    this->RA = RA;
}

void Aluno::imprime(){
    Pessoa::imprime();
    cout << "RA: " << this->RA << endl;
}