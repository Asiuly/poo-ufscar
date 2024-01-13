#ifndef PESSOA_H
#define PESSOA_h
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Veiculo;

class Pessoa{
    private:
        string nome;
        string CPF;
        vector<Veiculo*> frota;

    public:
        Pessoa(string, string);
        ~Pessoa() { }
        string getNome() const;
        string getCPF() const;
        void setNome(string);
        void setCPF(string);
        bool adicionaVeiculo(Veiculo&);
        bool removeVeiculo(string);
        Veiculo* obtemVeiculo(string) const;
        int qtdeVeiculos() const;
        int qtdeCarros() const;
        int qtdeCaminhoes() const;
        void ordenarFrota(vector<Veiculo*>&, int) const;
        void imprime(int) const;

};

#endif