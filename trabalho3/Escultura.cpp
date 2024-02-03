#include "Escultura.h"
using namespace std;

Escultura:: Escultura(int ID, string artista, string titulo, string genero, int anoPublicacao, string material, string representacao, double peso): 
            ObrasDeArte(ID, artista, titulo, genero, anoPublicacao), material(material), representacao(representacao), peso(peso) { }

Escultura:: ~Escultura(){ }

string Escultura:: getMaterial() const{
    return material;
}

void Escultura:: setMaterial(string material){
    this->material = material;
}


double Escultura:: getPeso() const{
    return peso;
}

void Escultura:: setPeso(double peso){
    this->peso = peso;
}


string Escultura:: getRepresentacao() const{
    return representacao;
}

void Escultura:: setRepresentacao(string representacao){
    this->representacao = representacao;
}


bool Escultura:: isRepresentacao(string guessRepresentacao){
    if (guessRepresentacao == getRepresentacao())
        return 1;
    else
        return 0;
}

string Escultura:: getCategoria() const{
    return "Escultura";
}

ostream& operator<<(ostream& os, Escultura& escultura) {
    os << "---------- OBRA " << escultura.getTitulo() << " ----------" << endl << "ID: " << escultura.getID() << endl << "Artista: " << escultura.getArtista() << endl << "Titulo: " << escultura.getTitulo() << endl << "Genero: " << escultura.getGenero() << endl << "Ano: " << escultura.getAnoPublicacao() << endl << "Valor: " << escultura.avaliarValor() << endl << "Material: " << escultura.getMaterial() << endl << "Peso: " << escultura.getPeso() << endl << "Representação: " << escultura.getRepresentacao() << endl << "---------- OBRA " << escultura.getTitulo() << " ----------" << endl;

    return os;
}