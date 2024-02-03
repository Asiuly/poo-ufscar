#include "ObrasDeArte.h"
using namespace std;

ObrasDeArte:: ObrasDeArte(int ID, string artista, string titulo, string genero, int anoPublicacao): 
    ID{ID}, artista{artista}, titulo{titulo}, genero{genero}, anoPublicacao{anoPublicacao} {}

int ObrasDeArte:: getID() const{
    return ID;
}

void ObrasDeArte:: setID(int ID){
    this->ID = ID;
}


string ObrasDeArte:: getArtista() const{
    return artista;
}

void ObrasDeArte:: setArtista(string artista){
    this->artista = artista;
}

string ObrasDeArte:: getTitulo() const{
    return titulo;
}

void ObrasDeArte:: setTitulo(string titulo){
    this->titulo = titulo;
}

string ObrasDeArte:: getGenero() const{
    return genero;
}

void ObrasDeArte:: setGenero(string genero){
    this->genero = genero;
}

int ObrasDeArte:: getAnoPublicacao() const{
    return anoPublicacao;
}

void ObrasDeArte:: setAnoPublicacao(int ano){
    this->anoPublicacao = ano;
}

void ObrasDeArte::exibirInfos() const{
    cout << "---------- OBRA " << this->getTitulo() << " ----------" << endl;
    cout << "ID: " << this->getID() << endl;
    cout << "Artista: " << this->getArtista() << endl;
    cout << "Titulo: " << this->getTitulo() << endl;
    cout << "Genero: " << this->getGenero() << endl;
    cout << "Ano: " << this->getAnoPublicacao() << endl;
    cout << "Valor: " << this->avaliarValor() << endl;
}

int ObrasDeArte:: calcularIdade() const{
    int idadePeca = ANO - getAnoPublicacao();
    return idadePeca; 
}

double ObrasDeArte:: avaliarValor() const{
    int valor;

    if(calcularIdade()<5){
        valor = 255.0;
    }
    else if(calcularIdade()<10){
        valor = 535.6;
    }
    else if(calcularIdade()<25){
        valor = 1560.7;
    }
    else if(calcularIdade()<50){
        valor = 10020.4;
    }
    else{
        valor = 10020.4;

        for(int i=50; i<calcularIdade(); i++){
            valor += 1500.0;
        }
    }

    return valor;
}