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
            cout<< "Escrevevendo categoria" << categoria  << endl;
            
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

                escreverString(arquivoSaida, escultura->getRepresentacao());
                cout<< "Representação escrita.." << escultura->getRepresentacao() << endl;

                peso = escultura->getPeso();
                arquivoSaida.write(reinterpret_cast<char*>(&peso), sizeof(double));
                cout<< "Peso escrito.." << escultura->getPeso() << endl;
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
        cout << "entrei if pintura em create..\n";
        Pintura* pinturaPassada= dynamic_cast<Pintura*>(obra);

        auxObra = new Pintura(pinturaPassada->getID(), pinturaPassada->getArtista(), pinturaPassada->getTitulo(), pinturaPassada->getGenero(), pinturaPassada->getAnoPublicacao(), pinturaPassada->getMeio(), pinturaPassada->getPaletaCores(), pinturaPassada->getTemMoldura());
        
        cout << "finalizei transferencia pintura para obra em create if pintura..\n";

    }
    else if(obra->getCategoria() == "Escultura"){
        cout << "entrei if escultura em create..\n";
        Escultura* esculturaPassada= dynamic_cast<Escultura*>(obra);

        auxObra = new Escultura(esculturaPassada->getID(), esculturaPassada->getArtista(), esculturaPassada->getTitulo(), esculturaPassada->getGenero(), esculturaPassada->getAnoPublicacao(), esculturaPassada->getMaterial(), esculturaPassada->getRepresentacao(), esculturaPassada->getPeso());
        
        cout << "finalizei transferencia escultura para obra em create if escultura..\n";
    }

    obras.push_back(auxObra);
    cout << "empurrei no create..\n";

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
        while (arquivoEntrada.peek() != EOF) {
            cout<< "Entrei no while read..\n" << endl;
            
            
            categoria = lerString(arquivoEntrada);
            cout<< "Exibindo categoria: " << categoria << endl;
            
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

            if (categoria == "Pintura") {
                cout << "exibindo: " << categoria << endl;

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

                cout << *obras[indice];

            } else if (categoria == "Escultura") {
                cout << "exibindo: " << categoria << endl;
                string material, representacao;
                double peso;

                material = lerString(arquivoEntrada);
                cout << "exibindo material: " << material << endl;
                
                representacao = lerString(arquivoEntrada);
                cout << "exibindo representacao: " << representacao << endl;
                
                arquivoEntrada.read(reinterpret_cast<char*>(&peso), sizeof(peso));
                cout << "exibindo peso: " << peso << endl;
                
                obras.push_back(new Escultura(id, artista, titulo, genero, anoPublicacao, material, representacao, peso));
                cout << "Escultura " << obras[indice]->getTitulo() << " Adicionada no vetor..." << endl;
                cout << *obras[indice];
                
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
    cout << "entrando delete..." << endl;
    obras.erase(remove_if(obras.begin(), obras.end(), [ID](ObrasDeArte* obra) { 
        return obra->getID() == ID; 
    }), obras.end());

    atualizaLista(arquivo);
    cout << "delete realizado..." << endl;
    return true;
}

bool CRUD:: Update(int ID, ObrasDeArte* obra, string arquivo){
    cout << "Entrando update.." << endl;

        for(int i=0; i < obras.size(); i++){
            if(obras[i]->getID() == ID){
                cout << "ID encontrado" << endl;
                obras[i] = obra;
            }
        }
    cout << "Obra atualizada" << endl;
    atualizaLista(arquivo);
    return true;
}