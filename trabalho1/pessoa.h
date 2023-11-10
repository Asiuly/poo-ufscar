#ifndef PESSOA_H
#define PESSOA_H
#include <string>
#include <iostream>

using namespace std;

//Organizando classe no namespace poo
namespace poo {
    class Pessoa{
      private:
        string CPF; //CPF da pessoa
        string nome; //Nome da Pessoa

      public:
        Pessoa(string, string);
        ~Pessoa();
        string getCPF() const;
        string getNome() const;
        void imprime() const;
    };
}

#endif