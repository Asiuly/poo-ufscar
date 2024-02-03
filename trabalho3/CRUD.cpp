#include "CRUD.h"
#include <algorithm>
#include <fstream>

using namespace std;

string CRUD:: lerString(ifstream& arquivoEntrada) {
    int tamanho;
    string aux;
    arquivoEntrada.read(reinterpret_cast<char*>(&tamanho), sizeof(tamanho));

    char buffer[tamanho + 1];
    arquivoEntrada.read(buffer, tamanho);
    buffer[tamanho] = '\0';
    aux = buffer;

    return aux;
}

void CRUD:: escreverString(ofstream& arquivoSaida, string AString){
    int tamanho = AString.size();
    arquivoSaida.write(reinterpret_cast<char*>(&tamanho), sizeof(tamanho));
    arquivoSaida.write(AString.data(), tamanho);
}

bool CRUD:: atualizaLista(string arquivo){
    int num;
    bool bin;
    double peso;
    string categoria;
    Pintura *pintura;
    Escultura* escultura;

    ofstream arquivoSaida(arquivo, ios::binary | ios:: trunc);

    if(arquivoSaida.is_open()){
        for(int i=0; i<obras.size(); i++){
            //colocando no arquivo os atributos gerais

            categoria = obras[i]->getCategoria();
            escreverString(arquivoSaida, categoria);
            
            num = obras[i]->getID();
            arquivoSaida.write(reinterpret_cast<char*>(&num), sizeof(int));

            //strings nao lidam muito bem com o método base, precisamos chamar uma função para serializar elas
            escreverString(arquivoSaida, obras[i]->getArtista());

            escreverString(arquivoSaida, obras[i]->getTitulo());

            escreverString(arquivoSaida, obras[i]->getGenero());

            num = obras[i]->getAnoPublicacao();
            arquivoSaida.write(reinterpret_cast<char*>(&num), sizeof(int));

            //escrever os métodos especificos de pintura
            if(categoria == "Pintura"){
                pintura = dynamic_cast<Pintura*>(obras[i]);

                escreverString(arquivoSaida, pintura->getMeio());

                escreverString(arquivoSaida, pintura->getPaletaCores());

                bin = pintura->getTemMoldura();
                arquivoSaida.write(reinterpret_cast<char*>(&bin), sizeof(bool));
            }

            //escrever os métodos especificos para escultura
            else if(obras[i]->getCategoria() == "Escultura"){
                escultura = dynamic_cast<Escultura*>(obras[i]);

                escreverString(arquivoSaida, escultura->getMaterial());

                escreverString(arquivoSaida, escultura->getRepresentacao());

                peso = escultura->getPeso();
                arquivoSaida.write(reinterpret_cast<char*>(&peso), sizeof(double));
            }//erro
            else{
                cout << "Categoria invalida";
                return false;
            }
        }   
    }else{
        cout << "Falha na abertura do arquivo em atualizar lista.." << endl;
        return false;
    }
    arquivoSaida.close();
    return true;
}

bool CRUD:: Create(ObrasDeArte* obra, string arquivo){
    //considere atributo da classe crud vector<ObrasDeArte*> obras;

    ObrasDeArte* auxObra;

    if(obra->getCategoria() == "Pintura"){
        Pintura* pinturaPassada= dynamic_cast<Pintura*>(obra);

        auxObra = new Pintura(pinturaPassada->getID(), pinturaPassada->getArtista(), pinturaPassada->getTitulo(), pinturaPassada->getGenero(), pinturaPassada->getAnoPublicacao(), pinturaPassada->getMeio(), pinturaPassada->getPaletaCores(), pinturaPassada->getTemMoldura());

    }
    else if(obra->getCategoria() == "Escultura"){
        Escultura* esculturaPassada= dynamic_cast<Escultura*>(obra);

        auxObra = new Escultura(esculturaPassada->getID(), esculturaPassada->getArtista(), esculturaPassada->getTitulo(), esculturaPassada->getGenero(), esculturaPassada->getAnoPublicacao(), esculturaPassada->getMaterial(), esculturaPassada->getRepresentacao(), esculturaPassada->getPeso());
    }

    obras.push_back(auxObra);

    atualizaLista(arquivo);

    return true;
}

vector<ObrasDeArte*> CRUD:: Read(string arquivo){
    ifstream arquivoEntrada(arquivo, ios::binary);

    if(arquivoEntrada.is_open()){
        int id, anoPublicacao;
        string artista, titulo, genero, categoria;
        
        obras.clear();

        int indice = 0;
        while (arquivoEntrada.peek() != EOF) {
            categoria = lerString(arquivoEntrada);
            
            arquivoEntrada.read(reinterpret_cast<char*>(&id), sizeof(id));

            artista = lerString(arquivoEntrada);

            titulo = lerString(arquivoEntrada);

            genero = lerString(arquivoEntrada);

            arquivoEntrada.read(reinterpret_cast<char*>(&anoPublicacao), sizeof(anoPublicacao));

            if (categoria == "Pintura") {
                string meio, paletaCores;
                bool temMoldura;

                meio = lerString(arquivoEntrada);

                paletaCores = lerString(arquivoEntrada);

                arquivoEntrada.read(reinterpret_cast<char*>(&temMoldura), sizeof(temMoldura));

                obras.push_back(new Pintura(id, artista, titulo, genero, anoPublicacao, meio, paletaCores, temMoldura));
            } 
            else if (categoria == "Escultura") {
                string material, representacao;
                double peso;

                material = lerString(arquivoEntrada);
                
                representacao = lerString(arquivoEntrada);
                
                arquivoEntrada.read(reinterpret_cast<char*>(&peso), sizeof(peso));
                
                obras.push_back(new Escultura(id, artista, titulo, genero, anoPublicacao, material, representacao, peso));
            } 
            else {
                cout << "categoria invalida" << endl;
                //erro
            }
            indice++;
        }
        
        arquivoEntrada.close();   
    }
    else{
        cout<< "Falha na abertura do arquivo em read..\n";
    }

    return obras;
}

bool CRUD:: Delete(int ID, string arquivo){
    obras.erase(remove_if(obras.begin(), obras.end(), [ID](ObrasDeArte* obra) { 
        return obra->getID() == ID; 
    }), obras.end());

    atualizaLista(arquivo);
    return true;
}

bool CRUD:: Update(int ID, ObrasDeArte* obra, string arquivo){
    for(int i=0; i < obras.size(); i++){
        if(obras[i]->getID() == ID){
            obras[i] = obra;
        }
    }
    
    atualizaLista(arquivo);
    return true;
}