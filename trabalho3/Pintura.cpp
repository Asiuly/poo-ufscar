#include "Pintura.h"
using namespace std;

Pintura:: Pintura(int ID, string artista, string titulo, string genero, int anoPublicacao, string meio, string paletaDeCores, bool temMoldura): ObrasDeArte(ID, artista, titulo, genero, anoPublicacao), meio(meio), paletaCores(paletaDeCores), temMoldura(temMoldura){ }

string Pintura:: getPaletaCores() const{
    return paletaCores;
}   

void Pintura:: setPaletaCores(string paletaCores){
    this->paletaCores = paletaCores;
}


string Pintura:: getMeio() const{
    return meio;
}

void Pintura:: setMeio(string meio){
    this->meio = meio;
}


bool Pintura:: getTemMoldura() const{
    return temMoldura;
}

void Pintura:: removerMoldura(){
    this->temMoldura = false;
}


void Pintura:: adicionarMoldura(){
    this->temMoldura = true;
}

string Pintura:: getCategoria() const{
    return "Pintura";
}

void Pintura:: exibirInfos() const{
    ObrasDeArte::exibirInfos();
    cout << "Meio: " << this->getMeio() << endl;
    cout << "Paleta de cores: " << this->getPaletaCores() << endl;
    cout << "Moldura: " << (this->getTemMoldura() ? "Sim" : "Nao") << endl;
    cout << "---------- OBRA " << this->getTitulo() << " ----------" << endl;
}
