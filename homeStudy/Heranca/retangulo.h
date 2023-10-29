#ifndef RETANGULO_H
#define RETANGULO_H
#include "forma.h"

class Retangulo: public Forma{
  private:
    double base, altura;

  public:     //x       y       base    altura
    Retangulo(double, double, double, double);
    ~Retangulo() { };

    void imprimirDados();
    double area();
};


#endif