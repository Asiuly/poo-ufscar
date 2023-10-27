#include <iostream>
#include "circle.h"

using namespace std;

Circle:: Circle(){
    radius = 0;
    x = 0;
    y = 0;
}

Circle::Circle(float r, int x, int y){
    this->radius = r;
    this->x = x;
    this->y = y;
}

float Circle:: area(){
    float area = radius*radius*3.141592;
    return area;
}

void Circle:: set_radius(float f){
    if(f>0)
        this->radius = f;
    else
        this->radius=0;
}

void Circle:: set_origin(int x, int y){
    this->x = x;
    this->y = y;
}

float Circle:: get_radius(){
    return this->radius;
}

float Circle:: diameter(){
    float diameter = radius * 2;
    return diameter;

}

void Circle::imprime(){
    cout << "{" << radius << ":" << x << ":" << y << "}" << endl;
}