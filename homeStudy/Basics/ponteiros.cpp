#include <iostream>
using namespace std;

void soma(int* a);
void soma2(int &a);

int main(){
    int a = 50;
    cout << "Valor de a: " << a << "\n";
    cout << "valor do endereco de a: " << &a << "\n";

    //nullptr utilizado para inicializar ponteiros em c++, aponta para o nulo, muito util para verificacoes if(ptr_a == nullptr)
    int *ptr_a = nullptr;
    ptr_a = &a;

    cout << "Endereco de A = valor de ptr_a: " << ptr_a << "\n";
    cout << "Conteudo da variavel que ptr_a aponta = a: " << *ptr_a << "\n";    //repare no *

    // REFERENCIAS - NOVIDADE C++
    int &ref_a = a;

    cout << "valor apontado pela referencia: " << ref_a << "\n";
    //repare que usar a variavel que foi criada com & (como referencia), é utilizada com seu nome normal e mostra o conteúdo do que ela está passando

    //PARAMETROS COM REFERENCIA E COM PONTEIRO
    soma(&a); //modificando a com um ponteiro de parametro

    soma2(a); //observe que com a passagem por referencia, so colocamos o & la no parametro e utilizamos a variavel como se ela nem fosse um ponteiro, mas tem o mesmo efeito que um

    cout << "\n" << a; //52: duas somas por ponteiro


    return 0;
}

void soma(int* a){
    *a += 1;
}

void soma2(int &a){
    a += 1;
}