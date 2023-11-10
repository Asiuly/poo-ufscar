#ifndef PROFESSOR_H
#define PROFESSOR_H
#include "pessoa.h"
#include <iostream>
#include <string>

using namespace std;

//organizando classe no namespace poo
namespace poo{ //subclasse de Pessoa
    class Professor: public Pessoa{
      private:
        string universidade; //universidade em que ele trabalha

      public:
        Professor(string, string, string);
        ~Professor();
        string getUniversidade() const;
        void imprime() const;
    };
}

#endif