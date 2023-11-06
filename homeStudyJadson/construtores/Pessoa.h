#ifndef PESSOA_H
#define PESSOA_H
#include <iostream>

using namespace std;

class Pessoa{
  private:
    string nome;
    string sobrenome;

  public:
    Pessoa();
    Pessoa(const string& nome, const string& sobrenome = "");

    void Exibir();
    void Formal();
};

#endif