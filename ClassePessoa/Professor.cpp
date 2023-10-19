#include "Professor.h"
#include <iostream>
#include <string>

using namespace std;

Professor::Professor(string nome, int idade, float salrio): Pessoa(nome, idade){
    this->salario = salario;
}

float Professor::getSalario(){
    return this->salario;
}

void Professor::setSalario(float salario){
    this->salario = salario;
}

void Professor::imprime(){
    Pessoa::imprime();
    cout << "Salario: " << this->salario << endl;
}