#include <string>
#include <iostream>
#include "aluno.h"

//utilizando namespace necessario para strings e saidas de dados
using namespace std;

//namespace onde organizei minhas classes
namespace poo{

    //construtor utiliza o construtor da classe pessoa para atribuir o nome e o CPF, já os atributos especificos de alunos são atribuidos no construtor da classe aluno
    Aluno:: Aluno(string CPF, string nome, int RA, double notaP1, double notaP2, double notaT1, double notaT2, double notaT3): Pessoa(CPF, nome), RA{RA}, nP1{notaP1}, nP2{notaP2}, nT1{notaT1}, nT2{notaT2}, nT3{notaT3} { }

    Aluno:: ~Aluno(){

    }

    //retorna o RA do objeto da classe aluno que chamar essa função
    int Aluno:: getRA() const{
        return this->RA;
    }

    //imprime todos os dados do objeto aluno, reutilizando a função imprime da classe pessoa que já imprime CPF e NOME, atributos herdados pela subclasse aluno
    void Aluno:: imprime() const{
        Pessoa:: imprime();
        cout << "RA: " << RA <<
                "\nNotas: " << 
                "P1: " << nP1 << ", P2: " << nP2 << ", T1: " << nT1 << ", T2: " << nT2 << ", T3: " << nT3 << endl;
    }

    //calcula media das provas e dos trabalhos, depois calcula a media final e a retorna
    double Aluno:: media() const{
        double mediaProvas = (nP1 + nP2) / 2;
        double mediaTrabalhos = (nT1 + (nT2 * 2) + (nT3 * 3)) / 6;
        double mediaFinal = ((mediaProvas*8) + (mediaTrabalhos*2)) / 10;

        return mediaFinal;  
    }

    //retorna true se o aluno for aprovado e false se não estiver aprovado
    bool Aluno:: aprovado() const{
        double mediaAluno = media();

        if (mediaAluno >= 6.0)
            return true;
        else
            return false;
    }

    //retorna true se o aluno precisar de uma nota PAC para recalcular sua media e conseguir ser aprovado
    bool Aluno:: pac() const{
        double mediaAluno = media();

        if (aprovado() == false && mediaAluno >= 5.0)
            return true;
        else
            return false;
    }

    //retorna quanto o aluno precisa tirar de nota PAC para que consiga ser aprovado com media 6
    double Aluno:: notaPAC() const{
        double mediaAluno = media();

        if (pac() == false)
            return 0;
        
        //MF+PAC/2 = 6 --> 6*2 - MF = PAC
        //nota minima para ter nota 6 na media final
        double notaPac = (6 * 2) - mediaAluno;

        return notaPac;
    }
}