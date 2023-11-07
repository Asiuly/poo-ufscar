#ifndef JOGO_H
#define JOGO_H
#include <iostream>
#include <string>
using namespace std;

class Jogo {
  private:
    string nome;
    float preco;
    int horas;
    float custo;
    
    void calcular();

  public:
    Jogo();
    Jogo(const string& titulo, float valor = 0.0, int tempo = 0);
    ~Jogo();

    const Jogo& compararMaisJogado(const Jogo& jogo) const;
    void atualizar(float);
    void jogar(int);
    void exibir() const;

};

inline void Jogo:: calcular(){
    if (horas > 0){
        custo = preco / horas;
    }
    else 
        custo = preco;
}

#endif