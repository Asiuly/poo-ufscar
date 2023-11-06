#ifndef JOGO_H
#define JOGO_H

#include <string>
using namespace std;

class Jogo {
  private:
    string nome;
    float preco;
    int horas;
    float custo;

    void calcular() {if (horas>0) custo=preco/horas;}
    
  public:
    void adquirir(const string&, float);
    void atualizar(float);
    void jogar(int);
    void exibir();
};

#endif