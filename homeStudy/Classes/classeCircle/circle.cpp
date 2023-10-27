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
    float area = x*y;
    return area;
}

void Circle:: set_radius(float f){
    this->radius = f;
}

void Circle:: set_origin(int x, int y){
    this->x = x;
    this->y = y;
}

float Circle:: get_radius(){
    return this->radius;
}