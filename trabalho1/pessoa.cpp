#include <string>
#include <iostream>
#include "pessoa.h"

//namespace para strings e chamadas de saída de dados
using namespace std;

//namespace onde organizei minhas classes
namespace poo{

    //construtor de pessoa iniciando CPF e Nome com parametros passados pelo usuario
    Pessoa:: Pessoa(string CPF, string nome): CPF{CPF}, nome{nome} { }

    Pessoa:: ~Pessoa() {
        
    }

    //retorna CPF do objeto pessoa que chamou a função
    string Pessoa:: getCPF() const {
        return this->CPF;
    }

    //retorna o nome
    string Pessoa:: getNome() const {
        return this->nome;
    }

    //imprime todas as informações do objeto
    void Pessoa:: imprime() const {
        cout << "CPF: " << this->nome <<
            "\nNome: " << this->CPF << endl;
    }
}