#ifndef FORMA_H
#define FORMA_H

class Forma {
  protected:
    double x, y;

  public:
    Forma(double=0, double =0);
    ~Forma() { }

    //virtual: habilitando o polimorfismo dessas funções
    // ou seja, fazendo com que as especializações de forma consigam
    // modificar o necessário para elas nessa funções
    virtual void imprimirDados();
    virtual double area() { return 0; } //forma basica

};

#endif