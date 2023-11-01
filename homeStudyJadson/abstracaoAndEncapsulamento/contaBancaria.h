#ifndef CONTABANCARIA_H
#define CONTABANCARIA_h
#include <iostream>
#include <string>

using namespace std;

class contaBancaria {
  private:
    string nomeCliente;
    int numConta;
    float saldo;
    
  public:
    contaBancaria(string, int);
    string getNomeCliente() const;
    int getNumConta() const;
    float getSaldo() const;
    void deposito(float);
    void saque(float);
};

#endif