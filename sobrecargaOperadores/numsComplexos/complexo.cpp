#include "complexo.h"
#include <iostream>

using namespace std;

Complexo::Complexo(float real, float imaginaria)
{
    this->real = real;
    this->imaginaria = imaginaria;
}
// protótipos
void Complexo::print(){
    cout << real << "+ (" << imaginaria << ")i" << endl;
}
Complexo Complexo::add(Complexo& num){
    float x = this->real + num.real;
    float y = this->imaginaria + num.imaginaria;
    return Complexo {x,y};
}

Complexo Complexo::sub(Complexo& num){
    float x = this->real - num.real;
    float y = this->imaginaria - num.imaginaria;
    return Complexo {x,y};
}