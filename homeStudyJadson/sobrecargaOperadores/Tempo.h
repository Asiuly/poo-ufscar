#ifndef TEMPO_H
#define TEMPPO_H

class Tempo {
  private:
    int horas;
    int minutos;
  public:
    Tempo();
    Tempo(int, int minutos = 0);

    void adicionar(int, int);
    void resetar(int h=0, int m=0);
    Tempo somar(const Tempo & t) const;
    Tempo operator+(const Tempo & t) const;
    void exibir() const;
};

#endif