#include <iostream>
#include "Pintura.h"
#include "Escultura.h"
#include "CRUD.h"

//TRABALHO REALIZADO EM CONJUNTO
//JULIA E LUISA TAVARES DOS SANTOS
//820872  &  820990

int main() {
    CRUD crud;

    Pintura pintura(1, "Van Gogh", "Noite Estrelada", "Impressionismo", 1889, "Oleo sobre tela", "Azul, Amarelo", true);
    Escultura escultura(2, "Michelangelo", "David", "Renascimento", 1504, "Marmore", "Humano", 500.0);

    crud.Create(&pintura, "obras.txt");
    crud.Create(&escultura, "obras.txt");

    vector<ObrasDeArte*> todasObras = crud.Read("obras.txt");
    cout << "\nLista de todas as obras:\n" << endl;
    for (int i=0; i< todasObras.size(); i++){
        todasObras[i]->exibirInfos();
    }
    cout << "------------------------" << endl;

    pintura.setTitulo("Noite Estrelada 2.0");
    pintura.setAnoPublicacao(1890);
    pintura.removerMoldura();
    pintura.setPaletaCores("Azul, Amarelo, Branco");

    crud.Update(1, &pintura, "obras.txt");

    todasObras = crud.Read("obras.txt");
    cout << "\nLista de obras apos atualizacao:\n" << endl;
    for (int i=0; i< todasObras.size(); i++){
        todasObras[i]->exibirInfos();
    }
    cout << "------------------------" << endl;

    Escultura novaEscultura(3, "Auguste Rodin", "O Pensador", "Escultura", 1902, "Bronze", "Humano", 200.0);
    crud.Create(&novaEscultura, "obras.txt");

    todasObras = crud.Read("obras.txt");
    cout << "\nLista de obras apos adicao:" << endl << endl;
    for (int i=0; i< todasObras.size(); i++){
        todasObras[i]->exibirInfos();
    }
    cout << "------------------------" << endl;

    crud.Delete(2, "obras.txt");

    todasObras = crud.Read("obras.txt");
    cout << "\nLista de obras apos exclusao:\n" << endl;
    for (int i=0; i< todasObras.size(); i++){
        todasObras[i]->exibirInfos();
    }
    cout << "Fim execucao." << endl;

    crud.Delete(1, "obras.txt");
    crud.Delete(3, "obras.txt");

    return 0;
}
