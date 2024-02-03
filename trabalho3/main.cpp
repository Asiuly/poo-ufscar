#include <iostream>
#include <iomanip> // Para formatar a saída
#include "Pintura.h"
#include "Escultura.h"
#include "CRUD.h"

int main() {
    CRUD crud;

    // Criando instâncias de Pintura e Escultura
    Pintura pintura(1, "Van Gogh", "Noite Estrelada", "Impressionismo", 1889, "Óleo sobre tela", "Azul, Amarelo", true);
    Escultura escultura(2, "Michelangelo", "David", "Renascimento", 1504, "Mármore", "Humano", 500.0);

    // Adicionando obras ao CRUD
    crud.Create(&pintura, "obras.txt");
    crud.Create(&escultura, "obras.txt");

    // Lendo e exitxtdo todas as obras
    vector<ObrasDeArte*> todasObras = crud.Read("obras.txt");
    cout << "Lista de todas as obras:" << endl;
    for (const auto& obra : todasObras) {
        cout << *obra << endl;
    }
    cout << "------------------------" << endl;

    // Atualizando uma obra (por exemplo, alterando o título)
    pintura.setTitulo("Noite Estrelada 2.0");
    pintura.setAnoPublicacao(1890);
    pintura.removerMoldura();
    pintura.setPaletaCores("Azul, Amarelo, Branco");

    crud.Update(1, &pintura, "obras.txt");

    // Lendo e exitxtdo todas as obras novamente após a atualização
    todasObras = crud.Read("obras.txt");
    cout << "Lista de obras após atualização:" << endl;
    for (const auto& obra : todasObras) {
        cout << *obra << endl;
    }
    cout << "------------------------" << endl;

    // Criando mais uma instância de Escultura e adicionando ao CRUD
    Escultura novaEscultura(3, "Auguste Rodin", "O Pensador", "Escultura", 1902, "Bronze", "Humano", 200.0);
    crud.Create(&novaEscultura, "obras.txt");

    // Lendo e exitxtdo todas as obras novamente após adição
    todasObras = crud.Read("obras.txt");
    cout << "Lista de obras após adição:" << endl;
    for (const auto& obra : todasObras) {
        cout << *obra << endl;
    }
    cout << "------------------------" << endl;

    // Deletando uma obra pelo ID
    crud.Delete(2, "obras.txt");

    // Lendo e exitxtdo todas as obras após a exclusão
    todasObras = crud.Read("obras.txt");
    cout << "Lista de obras após exclusão:" << endl;
    for (const auto& obra : todasObras) {
        cout << *obra << endl;
    }
    cout << "------------------------" << endl;

    crud.Delete(1, "obras.txt");

    return 0;
}
