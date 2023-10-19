#ifndef PESSOA_H
#define PESSOA_H

#include <string>
using namespace std;

class Pessoa{
    private:
        string nome;
        int idade;
    
    public:
        Pessoa(string, int);
        string getNome();
        void setNome(string);
        int getIdade();
        void setIdade(int);
        void imprime();
};

#endif