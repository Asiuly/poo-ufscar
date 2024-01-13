#ifndef CARRO_H
#define CARRO_H
#include "Veiculo.h"
#include <iostream>
#include <string>
using namespace std;

class Carro: public Veiculo{
    private:
        double volume;
    public:
        Carro(string, string, string, int, double);
        ~Carro() { }
        double getVolume() const;
        void setvolume(double);
        int getCategoria() const override;
        void imprime() const override;
};  

#endif