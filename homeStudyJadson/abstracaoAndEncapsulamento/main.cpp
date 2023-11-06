#include "jogo.h"
#include <iostream>
#include <string>

using namespace std;
int main(){
    Jogo kof;
    
    kof.adquirir("king of tokyo", 250);
    kof.jogar(50);
    kof.exibir();

    cout << &kof;
    
    return 0;
}