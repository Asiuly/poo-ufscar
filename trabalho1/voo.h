#ifndef VOO_H
#define VOO_H
#include <string>
#include <iostream>
#include "pessoa.h"
#include "companhia.h"
#include "dataHorario.h"

using namespace std;

namespace poo{
    class Voo{
      private:
        Companhia companhia; //companhia que está realizando o voo
        string origem; //origem do voo
        string destino; //pouso, destino do voo
        DataHorario dataHorario; //data e horario de saida do voo
        Pessoa* poltronas[25][6]; //poltronas do voo

        string formatarPoltronaIntToString(int, int) const; 
        void formatarPoltronaStringToInt(string, int&, int&) const;
        bool isPoltronaCorreta(string poltrona) const;

      public:
        Voo(Companhia&, string, string, DataHorario&);
        ~Voo();

        string proximoLivre() const;
        bool verifica(string) const;
        bool ocupa(string, Pessoa&);
        bool desocupa(string);
        int vagas() const;
        void imprime();
    };
}

#endif