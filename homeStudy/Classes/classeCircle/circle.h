#ifndef CIRCLE_H
#define CIRCLE_H

class Circle{
    private:
        float radius;
        int x;
        int y;

    public:
    Circle();
    Circle(float, int, int);
    float area();
    float diameter();
    void set_radius(float);
    void set_origin(int, int);
    float get_radius();
    void imprime();
};

#endif