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

ostream& operator<<(ostream& os, Pintura& pintura) {
    os << "---------- OBRA " << pintura.getTitulo() << " ----------" << endl << "ID: " << pintura.getID() << endl << "Artista: " << pintura.getArtista() << endl << "Titulo: " << pintura.getTitulo() << endl << "Genero: " << pintura.getGenero() << endl << "Ano: " << pintura.getAnoPublicacao() << endl << "Valor: " << pintura.avaliarValor() << endl << "Meio: " << pintura.getMeio() << endl << "Paleta de cores: " << pintura.getPaletaCores() << endl << "Moldura: " << (pintura.getTemMoldura() ? "Sim" : "Não") << endl << "---------- OBRA " << pintura.getTitulo() << " ----------" << endl;

    return os;
}
