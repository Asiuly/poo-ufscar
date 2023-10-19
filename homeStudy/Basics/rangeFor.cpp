#include <iostream>
using namespace std;

int main(){
    //inicializando um vetor com 10 números
    int vetor[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    cout << "Percorrendo vetor de forma tradicional: \n";
    for(int i = 0; i<10; i++){
        cout << vetor[i] << " ";
    }

    //RANGE FOR - NOVIDADE
    cout << "\n\nPercorrendo vetor com Range For: \n";

    //Para cada valor X em VETOR, imprima x:: == foreach em outras linguagens
    for(int x: vetor){
        cout << x << " ";
    }
    
    return 0;
}