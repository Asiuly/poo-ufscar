#ifndef CAMINHAO_H
#define CAMINHAO_H
#include "Veiculo.h"
#include <iostream>
#include <string>
using namespace std;

class Caminhao: public Veiculo{
    private:
        int nroEixos;

    public:
        Caminhao(string, string, string, int, int);
        ~Caminhao() { }
        int getEixos() const;
        void setEixos(int);
        int getCategoria() const override;
        void imprime() const override;


};

#endif