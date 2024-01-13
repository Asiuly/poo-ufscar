#ifndef VEICULO_H
#define VEICULO_H
#include <iostream>
#include <string>
using namespace std;

class Veiculo{
    private:
        string placa;
        string marca;
        string cor;
        int ano;

    public:
        Veiculo(string, string, string, int);
        ~Veiculo() { }
        string getPlaca() const;
        string getMarca() const;
        string getCor() const;
        int getAno() const;
        void setPlaca(string);
        void setMarca(string);
        void setCor(string);
        void setAno(int);
        virtual int getCategoria() const = 0;
        virtual void imprime() const;
};

#endif