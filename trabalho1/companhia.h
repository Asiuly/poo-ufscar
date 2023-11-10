#ifndef COMPANHIA_H
#define COMPANHIA_H
#include <iostream>
#include <string>
using namespace std;

//organizando classes no namespace poo
namespace poo{
    class Companhia{
      private:
        string CNPJ; //cnpj da empresa
        string nome; //nome da empresa

      public:
        Companhia(string, string);
        ~Companhia();
        string getCNPJ() const;
        string getNome() const;
        void imprime() const;
    };
}


#endif