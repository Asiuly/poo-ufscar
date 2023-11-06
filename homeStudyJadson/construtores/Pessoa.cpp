#include <iostream>
#include "Pessoa.h"

using namespace std;

Pessoa:: Pessoa(){
    nome = "";
    sobrenome = "";
}

Pessoa:: Pessoa(const string& nome, const string& sobrenome = ""){
    this->nome = nome;
    this->sobrenome = sobrenome;
}

//implementação alternativa de construtor
//Pessoa:: Pessoa(const string& nome, const string& sobrenome = ""): nome{nome}, sobrenome{sobrenome} {}

void Pessoa:: Exibir(){
    cout << nome << endl;
}

void Pessoa:: Formal(){
     cout << nome << " " << sobrenome <<endl;
}