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
    cout<< "Entrei em atualizar lista..\n";

    int num;
    bool bin;
    double peso;
    string categoria;
    Pintura *pintura;
    Escultura* escultura;

    ofstream arquivoSaida(arquivo, ios::binary | ios:: trunc);

    if(arquivoSaida.is_open()){
        cout<< "Arquivo de saida aberto..\n";

        cout << "Numero de obras: " << obras.size() << endl;
        for(int i=0; i<obras.size(); i++){

            cout<< "Escrevevendo obra.." << i << endl;
            //colocando no arquivo os atributos gerais

            categoria = obras[i]->getCategoria();
            escreverString(arquivoSaida, categoria);
            
            cout<< "OBRAS ID.." << obras[i]->getID() << endl;
            num = obras[i]->getID();
            arquivoSaida.write(reinterpret_cast<char*>(&num), sizeof(int));
            cout<< "ID escrito.." << obras[i]->getID() << endl;

            //strings nao lidam muito bem com o método base, precisamos chamar uma função para serializar elas
            escreverString(arquivoSaida, obras[i]->getArtista());
            cout<< "Artista escrito.." << obras[i]->getArtista() << endl;

            escreverString(arquivoSaida, obras[i]->getTitulo());
            cout<< "Titulo escrito.." << obras[i]->getTitulo() << endl;

            escreverString(arquivoSaida, obras[i]->getGenero());
            cout<< "Genero escrito.." << obras[i]->getGenero() << endl;

            num = obras[i]->getAnoPublicacao();
            arquivoSaida.write(reinterpret_cast<char*>(&num), sizeof(int));
            cout<< "Ano escrito.." << obras[i]->getAnoPublicacao() << endl;

            cout<< "Categoria para exibir: " << obras[i]->getCategoria() << endl;
            //escrever os métodos especificos de pintura
            if(categoria == "Pintura"){
                pintura = dynamic_cast<Pintura*>(obras[i]);
                cout << "Obra convertida para Pintura.." << endl;

                escreverString(arquivoSaida, pintura->getMeio());
                cout<< "Meio escrito.." << pintura->getMeio() << endl;

                escreverString(arquivoSaida, pintura->getPaletaCores());
                cout<< "Paleta de cores escrita.." << pintura->getPaletaCores() << endl;

                bin = pintura->getTemMoldura();
                arquivoSaida.write(reinterpret_cast<char*>(&bin), sizeof(bool));
                cout<< "Moldura escrita.." << (pintura->getTemMoldura()? "Sim" : "Não") << endl;
            }

            //escrever os métodos especificos para escultura
            else if(obras[i]->getCategoria() == "Escultura"){
                escultura = dynamic_cast<Escultura*>(obras[i]);
                cout << "Obra convertida para Escultura.." << endl;

                escreverString(arquivoSaida, escultura->getMaterial());
                cout<< "Material escrito.." << escultura->getMaterial() << endl;

                peso = escultura->getPeso();
                arquivoSaida.write(reinterpret_cast<char*>(&peso), sizeof(double));
                cout<< "Peso escrito.." << escultura->getPeso() << endl;

                escreverString(arquivoSaida, escultura->getRepresentacao());
                cout<< "Representação escrita.." << escultura->getRepresentacao() << endl;

            }//erro
            else{
                cout << "Categoria inválida";
                return false;
            }
        }   
    }else{
        cout << "Falha na abertura do arquivo em atualizar lista.." << endl;
        return false;
    }
    cout<< "Fechando Arquivo.." << endl;
    arquivoSaida.close();
    return true;
}

bool CRUD:: Create(ObrasDeArte* obra, string arquivo){
    //considere atributo da classe crud vector<ObrasDeArte*> obras;
    cout<< "Entrando em create..\n";

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
    cout<< "Entrando em read..\n";

    ifstream arquivoEntrada(arquivo, ios::binary);

    if(arquivoEntrada.is_open()){
        int id, anoPublicacao;
        string artista, titulo, genero, categoria;
        
        obras.clear();

        cout<< "Arquivo aberto..\n";
        int indice = 0;
        while (arquivoEntrada.good()) {
            cout<< "Entrei no while..\n";
            
            arquivoEntrada.read(reinterpret_cast<char*>(&id), sizeof(id));
            cout << "exibindo id: " << id << endl;

            artista = lerString(arquivoEntrada);
            cout << "exibindo artista: " << artista << endl;

            titulo = lerString(arquivoEntrada);
            cout << "exibindo titulo: " << titulo << endl;

            genero = lerString(arquivoEntrada);
            cout << "exibindo genero: " << genero << endl;

            arquivoEntrada.read(reinterpret_cast<char*>(&anoPublicacao), sizeof(anoPublicacao));
            cout << "exibindo Ano: " << anoPublicacao << endl;


            categoria = lerString(arquivoEntrada);


            if (categoria == "Pintura") {
                cout << "exibindo categoria: " << categoria << endl;

                string meio, paletaCores;
                bool temMoldura;

                meio = lerString(arquivoEntrada);
                cout << "exibindo meio: " << meio << endl;

                paletaCores = lerString(arquivoEntrada);
                cout << "exibindo Paleta de Cores: " << paletaCores << endl;

                arquivoEntrada.read(reinterpret_cast<char*>(&temMoldura), sizeof(temMoldura));
                cout << "exibindo se Tem Moldura: " << (temMoldura? "Sim" : "Nao") << endl;

                obras.push_back(new Pintura(id, artista, titulo, genero, anoPublicacao, meio, paletaCores, temMoldura));
                cout << obras[indice]->getTitulo() << "Adicionada no vetor..." << endl;

                cout << *obras[0];

            } else if (categoria == "Escultura") {
                string material, representacao;
                double peso;

                material = lerString(arquivoEntrada);
                cout << "exibindo material: " << material << endl;
                
                representacao = lerString(arquivoEntrada);
                cout << "exibindo representação: " << representacao << endl;
                
                arquivoEntrada.read(reinterpret_cast<char*>(&peso), sizeof(peso));
                cout << "exibindo peso: " << peso << endl;
                
                obras.push_back(new Escultura(id, artista, titulo, genero, anoPublicacao, material, representacao, peso));
                cout << "Escultura " << obras[indice]->getTitulo() << "Adicionada no vetor..." << endl;
                
            } else {
                cout << "categoria invalida" << endl;
                //erro
            }
            indice++;
        }
        
        arquivoEntrada.close();
        cout<< "Fechando arquivo de entrada..\n";
    }
    else{
        cout<< "Falha na abertura do arquivo..\n";
    }

    cout<< "Prestes a retornar obra..\n";
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