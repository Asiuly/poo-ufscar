#ifndef CRUD_H
#define CRUD_H
#include <vector>
#include <fstream>
#include "Pintura.h"
#include "Escultura.h"
using namespace std;

class CRUD {
private:
    bool atualizaLista(string arquivo);
    void escreverString(ofstream& arquivoSaida, string AString);
    string lerString(ifstream& arquivoEntrada);
    vector<ObrasDeArte*> obras;
    
public:
    bool Create(ObrasDeArte* obra, string arquivo);

    vector<ObrasDeArte*> Read(string arquivo);

    bool Delete(int ID, string arquivo);

    bool Update(int ID, ObrasDeArte* obra, string arquivo);
};

#endif