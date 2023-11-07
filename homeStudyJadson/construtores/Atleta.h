#ifndef ATLETA_H
#define ATLETA_H

//construindo a classe atleta
class Atleta{
  private:
    int acertos;
    int tentativas;
    float porcentual;

  public:
    Atleta();
    Atleta(int, int);
    void exibir() const;
    void acumular(Atleta& atletaSoma);
    void calcular();
    ~Atleta();
};

inline void Atleta:: calcular(){
    if(tentativas!=0){
        porcentual = 100.0 * (acertos/tentativas);
    }
    else
        porcentual = 0;
}

#endif