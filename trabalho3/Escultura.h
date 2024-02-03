#ifndef ESCULTURA_H
#define ESCULTURA_H
#include <iostream>
#include <string>
#include "ObrasDeArte.h"
using namespace std;

class Escultura: public ObrasDeArte{
    private:
        string material;
        string representacao;
        double peso;

    public:
        Escultura(int, string, string, string, int, string, string, double);
        ~Escultura();
        string getMaterial() const;
        void setMaterial(string material);
        virtual string getCategoria() const;

        double getPeso() const;
        void setPeso(double);

        string getRepresentacao() const;
        void setRepresentacao(string representacao);

        bool isRepresentacao(string guessRepresentacao);
        void exibirInfos() const override;
};


#endif