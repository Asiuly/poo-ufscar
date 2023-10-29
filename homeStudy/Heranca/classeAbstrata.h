#ifndef CLASSEABSTRATA_H
#define CLASSEABSTRATA_H

//uma classe que nao cria objetos, apenas é uma estruturação
//para que outras classes herdem seus métodos e atributos DE FORMA
// OBRIGATÓRIA, a classe definida é obrigada a modificar o método da classe abstrata
class ClasseAbstrata{
    public:
        virtual double area() = 0;
        //função virtual PURA: obrigada a ser puxada pelos seus filhos

        // quando algm fazer uma classe concreta que herda essa abstrata, tem que implementar area
        // alem disso, não é possivel criar um objeto do tipo classeAbstrata

};

#endif