#include <iostream>
#include "tempo.h"

using namespace std;

int main(){
    Tempo projetando;
    Tempo codificando{2, 40};
    Tempo corrigindo{5, 55};
    Tempo total;

    cout << "tempo projetando: " << endl;
    projetando.exibir();

    cout << "tempo codificando: " << endl;
    codificando.exibir();
    
    cout << "tempo corrigindo: " << endl;
    corrigindo.exibir();

    //fazendo a soma para ver o total com a variavel soma
    total = codificando.somar(corrigindo);
    cout << "tempo total: " << endl;
    //sem alterar os objetos envolvidos na soma!!
    
    total.exibir();

    total.resetar();
    total.exibir();

    //fazendo a soma com o operador
    total = corrigindo + codificando;
    total.exibir();
    
    return 0;
}