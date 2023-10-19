#ifndef ALUNO_H
#define ALUNO_H

#include "Pessoa.h"

#include <string>
using namespace std;

class Aluno: public Pessoa{
    private:
        int RA;
    
    public:
        Aluno(string, int, int);
        int getRA();
        void setRA(int);
        void imprime();
};

#endif