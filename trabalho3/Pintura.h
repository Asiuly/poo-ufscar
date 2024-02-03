#ifndef PINTURA_H
#define PINTURA_H
#include <iostream>
#include <string>
#include "ObrasDeArte.h"
using namespace std;

class Pintura: public ObrasDeArte{
    private:
        string meio;
        string paletaCores;
        bool temMoldura;

    public:
        Pintura(int, string, string, string, int, string, string, bool);
        ~Pintura() { }
        

        //get set
        virtual string getCategoria() const;
        friend ostream& operator<<(ostream& os, const ObrasDeArte& obra);
        string getPaletaCores() const;
        void setPaletaCores(string);

        string getMeio() const;
        void setMeio(string);

        bool getTemMoldura() const;
        void removerMoldura();
        void adicionarMoldura();
};


#endif