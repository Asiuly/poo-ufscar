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
    void set_radius();
    void set_origin();
    float get_radius();
};

#endif