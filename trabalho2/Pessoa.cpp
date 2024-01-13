#include "Pessoa.h"
#include "Veiculo.h"
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;


Pessoa:: Pessoa(string nome, string CPF): nome(nome), CPF(CPF) { }

string Pessoa::  getNome() const{
    return this->nome;
}

string Pessoa:: getCPF() const{
    return this->CPF;
}

void Pessoa:: setNome(string nome){
    this->nome = nome;
}

void Pessoa:: setCPF(string CPF){
    this->CPF = CPF;
}

bool Pessoa:: adicionaVeiculo(Veiculo& veiculo){
    //percorre todos os veiculos da pessoa para ver se o veiculo passado ja é dela
    for(const auto& veiculoFrota: frota){
        if(veiculoFrota->getPlaca() == veiculo.getPlaca()){
            cout << "Veiculo com placa " << veiculo.getPlaca() << " ja pertence a frota de "<< getNome() << ".\n";
            return false; //esse veiculo ja existe na frota
        }
    }

    //veiculo pode ser adicionado à frota.
    frota.push_back(&veiculo);
    cout << "Veiculo com placa " << veiculo.getPlaca() << " adicionado com sucesso a frota de "<< getNome() << ".\n";
    return true;
}

bool Pessoa:: removeVeiculo(string placa){
    //percorrendo  tamanho da frota da pessoa
    for(int i = 0; i<frota.size(); i++){
        //se o veiculo existir na frota, apaga ele da frota
        if(frota[i]->getPlaca() == placa){
            frota.erase(frota.begin() + i);
            return true;
        }
    }

    //veiculo nao existia na frota
    return false;
}

Veiculo* Pessoa::  obtemVeiculo(string placa) const{
    //percorre frota para procurar carro com placa informada
    for(const auto& veiculoFrota: frota){
        if(veiculoFrota->getPlaca() == placa){
            return veiculoFrota;
        }
    }//se sair do loop, veiculo nao existe na frota

    cout << "Veiculo nao encontrado na frota de " << getNome() << endl;
    return nullptr;
}

int Pessoa:: qtdeVeiculos() const{
    return frota.size();
}

int Pessoa:: qtdeCarros() const{
    int contCarros = 0;
    //percorre frota buscando todos veiculos da categoria 1(carros)
    for(const auto& veiculoFrota : frota){
        if(veiculoFrota->getCategoria() == 1){
            contCarros++;
        }
    }
    
    return contCarros;
}

int Pessoa:: qtdeCaminhoes() const{
    int contCaminhoes = 0;
    //percorre frota buscando todos veiculos da categoria 1(carros)
    for(const auto& veiculoFrota : frota){
        if(veiculoFrota->getCategoria() == 2){
            contCaminhoes++;
        }
    }
    
    return contCaminhoes;
}

void Pessoa:: ordenarFrota(vector<Veiculo*>& frotaOrdenada, int criterio) const{

     switch (criterio)
    {
        //imprime sem ordenação
        case 1:
            //mantem ordenação original
            break;
        
        //Imprime os veículos ordenados pela placa dos veículos.
        case 2:
            sort(frotaOrdenada.begin(), frotaOrdenada.end(), [](Veiculo* a, Veiculo* b) {
                return a->getPlaca() < b->getPlaca();
            });
            break;
        
        //Imprime os veículos ordenados pelo ano dos veículos. Caso dois veículos tenham o mesmo ano, então são ordenadas pela placa.
        case 3:
            sort(frotaOrdenada.begin(), frotaOrdenada.end(), [](Veiculo* a, Veiculo* b) {
                    if(a->getAno() != b->getAno()){
                        return a->getAno() < b->getAno();
                    }
                    else{
                        return a->getPlaca() < b->getPlaca();
                    }
                });
            break;
        
        //Imprime os veículos ordenados pela categoria dos veículos. Caso dois veículos tenham a mesma categoria, então são ordenadas pela placa.
        case 4:
            sort(frotaOrdenada.begin(), frotaOrdenada.end(), [](Veiculo*a, Veiculo*b){
                if(a->getCategoria()!= b->getCategoria()){
                    return a->getCategoria() < b->getCategoria();
                }
                else{
                    return a->getPlaca() < b->getPlaca();
                }
            }); 
            break;
        
        default:
            cout << "criterio invalido, escolha um criterio de 1 a 4";
            break;
    }
}

void Pessoa:: imprime(int criterio) const{
    vector<Veiculo*> frotaOrdenada = frota;

    ordenarFrota(frotaOrdenada, criterio);

    cout << "Nome: " << getNome() << endl;
    cout << "CPF: " << getCPF() << endl;

    cout << "Informacoes sobre a frota: " << endl;
    for (const auto& veiculoFrota : frotaOrdenada) {
        veiculoFrota->imprime();
    }
}

