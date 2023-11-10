#ifndef DATAHORARIO_H
#define DATAHORARIO_H

#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

namespace poo {

    class DataHorario {
    
    private:
        bool valida(int, int, int, int, int, int);
        bool checaQtdeDias(int, int, int);
        int dia;
        int mes;
        int ano;
        int hora;
        int minuto;
        int segundo;
        
    public:
        DataHorario(int, int, int, int, int, int);
        virtual ~DataHorario();
        void imprime(bool);
    };
}
#endif /* DATAHORARIO_H */