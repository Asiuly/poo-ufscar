#include <iostream>
#include "contaBancaria.h"
#include <string>

using namespace std;

contaBancaria::contaBancaria(string nome, int conta){
    nomeCliente = nome;
    numConta = conta;
    saldo = 0;
}

void contaBancaria:: deposito(float valor){
    saldo += valor;
}

void contaBancaria:: saque(float valor){
    saldo -= valor;
}

string contaBancaria:: getNomeCliente() const{
    return nomeCliente;
}

int contaBancaria:: getNumConta() const{
    return numConta;
}

float contaBancaria:: getSaldo() const{
    return saldo;
}

