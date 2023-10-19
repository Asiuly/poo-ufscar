#include "Pessoa.h"
#include "Aluno.h"
#include "Professor.h"
#include <iostream>

using namespace std;

int main(){
    Pessoa p1("Luisa", 18);
    p1.imprime();

    p1.setIdade(21);
    int idade = p1.getIdade();
    cout << endl << idade << endl;

    p1.setNome("Victor");
    string newName = p1.getNome();
    cout << newName << endl << endl;

    p1.imprime();

    Aluno a1("Julia", 18, 999887);
    a1.imprime();
    a1.setNome("AlunoUsandoMetodoDePessoaOMG");

    a1.imprime();

    Professor prof1("Delano", 45, 1500);
    prof1.setNome("OMGprofessorUsandoMetodoHeranca");
    prof1.imprime();

    prof1.setSalario(1800);
    float newSalario = prof1.getSalario();
    cout << "oloco ficou mais rico? : " << newSalario << endl;

    return 0;
}