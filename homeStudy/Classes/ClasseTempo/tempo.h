#ifndef TEMPO_H
#define TEMPO_H

class Tempo
{
private:
    int hora;
    int minuto;
    int segundo;

public:
    Tempo();              // construtor-inicializar
    Tempo(int, int, int); // construtor com parametros
    void setTempo(int, int, int);
    void imprime();
    ~Tempo() { } ; // destrutor serve para desalocar memoria caso necessario
};

#endif