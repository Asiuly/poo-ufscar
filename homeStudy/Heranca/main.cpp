#include "forma.h"
#include "retangulo.h"
#include "circulo.h"
#include <iostream>
using namespace std;

int main(){       //quando usar um ponteiro, usar NEW PARA INSTANCIAS
    Forma* ponto1 = new Forma{10.0, 20.0};
    ponto1->imprimirDados();
    cout << "Area: " << ponto1->area() << endl;

    //filhos de forma (retangulo e circulo) sendo definidos
    //como ponteiros de Forma apontando pra classe especializadora
    //forma consegue chamar os metodos de retangulo personalizados pcausa do polimorfismo
    cout << "Retangulo:\n";
    Forma*  re1 = new Retangulo{0, 0, 10, 50};
    re1->imprimirDados();

    cout << "Circulo:\n";
    Forma* circ = new Circulo{0, 0, 10};
    circ->imprimirDados();

    //vetor de formas diferentes
    Forma* vetor_formas[3];
    vetor_formas[0] = new Retangulo{10, 30, 40, 21};
    vetor_formas[1] = new Forma{100, 140};
    vetor_formas[2] = new Circulo{2.0, 0.54, 12};

    //podem ser usados como tipos da classe de boas!!!
    vetor_formas[2]->imprimirDados();
    
    //para cada forma nesse vetor de formas, imprima os dados
    for(auto forma : vetor_formas){
        cout<< "Forma: "<<endl;
        forma->imprimirDados();
        cout<< "\n\n";
    }

}