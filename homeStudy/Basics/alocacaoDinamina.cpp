#include <iostream>

//biblioteca de alocação dinamica: vinda do c
#include <cstdlib>
using namespace std;

#define TAMANHO 10

//commits sem email - contabilizando
int main(){
    int *vet = nullptr; //criando um ponteiro

    vet = new int[TAMANHO]; //ALOCAÇÃO DINAMICA DO TAMANHO DO VETOR

    for(int i; i<TAMANHO; i++){
        vet[i] = rand()%10; //numero randomico de 1 a 9
    }

    cout << "Vetor dinamico criado" << "\n";
    for(int i=0; i<TAMANHO; i++){
        cout << vet[i] << " ";
    }

    //free
    delete[]vet;
    return 0;
}