#ifndef CIRCULO_H
#define CIRCULO_H

#include "forma.h"

class Circulo: public Forma{
  private:
    double raio;

  public: 
    Circulo(double, double, double);
    ~Circulo(){ }
    double area();
    void imprimirDados();
};

#endif