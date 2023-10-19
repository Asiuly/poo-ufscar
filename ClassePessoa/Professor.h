#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "Pessoa.h"

#include <string>
using namespace std;

class Professor: public Pessoa{
    private:
        float salario;
    
    public:
        Professor(string, int, float);
        float getSalario();
        void setSalario(float);
        void imprime();
};
#endif