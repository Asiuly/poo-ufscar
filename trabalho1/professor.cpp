#include <string>
#include <iostream>
#include "professor.h"

using namespace std;

//namespace onde organizo minhas classes
namespace poo{

    //construtor de Professor que reutiliza o construtor da classe pessoa para atribuir CPF e Nome(atributos herdados pela subclasse professor), universidade é atribuida no construtor da classe professor mesmo
    Professor:: Professor(string CPF, string nome, string universidade): Pessoa(CPF, nome), universidade{universidade} { }

    Professor:: ~Professor(){

    }

    //retorna a universidade do objeto da classe professor que chamar a função
    string Professor:: getUniversidade() const{
        return this->universidade;
    }

    //imprime as informações do objeto professor reutilizando a impressão de CPF e Nome realizadas na superclasse Pessoa
    void Professor:: imprime() const{
        Pessoa:: imprime();
        cout << "Universidade: " << this->universidade;
    }
}