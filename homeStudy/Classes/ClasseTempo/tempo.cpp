// arquivo de implementação das funções definidas no header
#include "tempo.h"
#include <iostream>

using namespace std;

Tempo::Tempo(){
    hora = 0;
    minuto = 0;
    segundo = 0;
}

Tempo::Tempo(int hora, int minuto, int segundo){
    this->hora = hora;
    this->minuto = minuto;
    this->segundo = segundo;
}

void Tempo:: setTempo(int hora, int minuto, int segundo) {
    if(hora>=0 && hora<=23)
        this->hora = hora;
    else
        this->hora = 0;
    
    if(minuto>=0 && minuto<=60)
        this->minuto = minuto;
    else
        this->minuto = 0;

    if(segundo>=0 && segundo<=60)
        this->segundo = segundo;
    else
        this->segundo = 0;

}

void Tempo:: imprime() {
    cout << "{" << hora << ":" << minuto << ":" << segundo << "}" << endl;
}