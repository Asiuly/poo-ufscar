#include <iostream>
#include <string>
#include "companhia.h"
//namespace utilizado para stirngs e saída de dados
using namespace std;

//namespace onde estou organizando minhas classes
namespace poo{

    //construtor utilizado para pegar parametros passados para o usuario e atribuir em this->CPF e this->nome
    Companhia:: Companhia(string nome, string CNPJ): nome{nome}, CNPJ{CNPJ}  { }


    Companhia:: ~Companhia(){

    }

    //retorna o CNPJ do objeto da classe Companhia que chamou esta função
    string Companhia:: getCNPJ() const{
        return this->CNPJ;
    }

    //retorna o nome da companhia
    string Companhia:: getNome() const{
        return this->nome;
    }

    //imprime todas as informações do objeto
    void Companhia:: imprime() const{
        cout << "Companhia: " << this->nome <<
                "\nCNPJ: " << this->CNPJ << endl;
    }
}