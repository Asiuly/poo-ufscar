#ifndef ALUNO_H
#define ALUNO_H
#include <string>
#include <iostream>
#include "pessoa.h"

using namespace std;
//organizando classe no namespace poo
namespace poo{ //aluno: subclasse de pessoa
    class Aluno: public Pessoa{
      private:
        int RA; //RA da pessoa
        double nP1; //Nota da 1ª prova
        double nP2; //Nota da 2ª prova
        double nT1; //Nota do 1º trabalho
        double nT2; //Nota do 2º trabalho
        double nT3; //Nota do 3º trabalho

      public: //CPF, Nome: de pessoa, RA, nP1, nP2, nT1, nT2, nT#
        Aluno(string, string, int, double, double, double, double, double);
        ~Aluno();

        int getRA() const;
        void imprime() const;
        double media() const;
        bool aprovado() const;
        bool pac() const;
        double notaPAC() const;
    };
}

#endif