#include "voo.h"
#include <iostream>
#include <string>

//namespace para saidas de dados e strings
using namespace std;

//namespace onde estou organizando as classes
namespace poo {

    //função que pega os valores da matriz em int e formata para [1-25][A-E]
    string Voo::formatarPoltronaIntToString(int linha, int coluna) const {
    string numero = to_string(linha + 1);
    char letra = static_cast<char>('A' + coluna);

    //CASO o numero for menor que 10, adiciona 0 a direita para encaixar na formatação
    numero.insert(0, 2 - numero.size(), '0');

    return numero + letra; //ex: 02C, 01A, 15B
    }

    //função que pega uma poltrona em string [1-25][A-E] e fornece o indice i e o indice j dela na matriz
    void Voo:: formatarPoltronaStringToInt(string poltrona, int& linha, int& coluna) const{
    //calcula qual indice i da matriz a partir da string fornecida no formato [1-25][A-E]
    linha = stoi(poltrona.substr(0,2)) - 1; 
    //calcula qual indice j da matriz a partir da string fornecida
    coluna = poltrona[2] - 'A'; 
    }

    //verifica formatação da poltrona em string
    bool Voo:: isPoltronaCorreta(string poltrona) const{
    //verificando se a string passada estq nos parametros corretos para conversão
    //(3 digitos, 2 sendo numeros e 1 sendo letra)
    if (poltrona.size() != 3 || (poltrona[0] < '0' || poltrona[0] > '9') || 
    (poltrona[1] < '0' || poltrona[1] > '9') || (poltrona[2] < 'A' || poltrona[2] > 'E')) {
    //caso nao esteja nos parametros corretos, retorna falso;
    return false;
    }

    //caso esteja:
    return true;
    }

    //construtor de voo inicializando as variaveis do objeto com os parametros passados pelo usuario
    Voo:: Voo(Companhia& companhiaAerea, string origem, string destino, DataHorario& dataHorarioVoo):
    companhia{companhiaAerea}, origem{origem}, destino{destino}, dataHorario{dataHorarioVoo} {

    //Inicializando todas as poltronas como desocupadas.
        for (int i=0; i<25; i++){
            for(int j=0; j<5; j++){
                poltronas[i][j]= nullptr;
            }
        }            
    }

    Voo:: ~Voo(){

    }

    //verificar qual é a poltrona livre de "valor" mais baixo (1<2 ; A<B)
    string Voo:: proximoLivre() const{
        //rode as poltronas até achar uma desocupada(nao aponta para nenhuma pessoa)
        for(int i=0; i<25; i++){
            for(int j=0; j<5; j++){
                if(poltronas[i][j] == nullptr){
                    //ao achar, formatar sua posição na matriz para [1-25][A-E]
                    string poltronaLivre = formatarPoltronaIntToString(i, j);
                    //retornar a poltrona livre
                    return poltronaLivre;
                }
            }
        }

        //se rodar todas e nao retornar poltrona livre
        return "cheio";
    }

    //dada uma poltrona string no formato [1-25][A-E], verificar se ela esta ocupada na matriz poltronas
    bool Voo:: verifica(string poltrona) const{
        int linha;
        int coluna;

        //se a poltrona não estiver nos parametros corretos para conversão, ocupada.
        if(isPoltronaCorreta(poltrona) == false){
            return true;
        }

        //pegando os indices da matriz da poltrona fornecida em string
        formatarPoltronaStringToInt(poltrona, linha, coluna);

        //se a poltrona fornecida existir, verificar retornar true(ocupada) ou false(desocupada)
        if (linha >= 0 && linha < 25 && coluna >= 0 && coluna < 5) {
                if(poltronas[linha][coluna] == nullptr)
                    return false;
                else
                    return true;
            }
        
        //se a poltrona não existir, retornar ocupada.
        return true;
    }

    bool Voo:: ocupa(string poltrona, Pessoa& expectador){
        //se a poltrona não estiver certa para conversão, considere que a operação falhou 
        if(isPoltronaCorreta(poltrona) == false){
            return false;
        }

        int linha; //indice i
        int coluna; //indice j

        //pegando indices da matriz atraves da string fornecida
        formatarPoltronaStringToInt(poltrona, linha, coluna);

        //se a poltrona estiver desocupada
        if(verifica(poltrona) == false){
            //coloca a poltrona como ocupada pela pessoa passada de parametro
            poltronas[linha][coluna] = &expectador;
            //operação bem sucedida
            return true;
        }
        else{
            //operação não realizada - poltrona ocupada
            return false;
        }
    }

    bool Voo:: desocupa(string poltrona){
        //se a poltrona não estiver certa para conversão, considere que a operação falhou 
        if(isPoltronaCorreta(poltrona) == false){
            return false;
        }

        int linha; //indice i
        int coluna; //indice j

        //pegando indices da matriz atraves da string fornecida
        formatarPoltronaStringToInt(poltrona, linha, coluna);
        
        if ((linha >= 0 && linha < 25 && coluna >= 0 && coluna < 5)==false) {
            return false; //poltrona fora dos limites, não existe.
        }

        //se a poltrona estiver ocupada e dentro dos limites
        if(verifica(poltrona) == true){
            //faz a poltrona apontar para o nulo e desapontar do antigo expectador
            poltronas[linha][coluna] = nullptr;
            //operação bem sucedida
            return true;
        }
        else{//operação falhou - ja estava desocupada
            return false;
        }
    }

    int Voo:: vagas() const{
        int cont = 0;
        //roda todas as poltronas e soma 1 no contador para cada uma que nao aponta para um expectador
        for(int i=0; i<25; i++){
            for(int j=0; j<5; j++){
                if(poltronas[i][j] == nullptr)
                cont++;
            }
        }
        //retorna o tanto de poltronas vazias
        return cont;
    }

    void Voo:: imprime(){
        cout << "\nVoo cadastrado" << endl;
        companhia.imprime();
        cout << "Origem: " << origem << ", Destino: " << destino << endl;
        cout << "Data: ";
        dataHorario.imprime(false);
        
        cout << "\nLista de Passageiros do voo:" << endl;

        for(int i=0; i<25;i++){
            for(int j=0;j<5;j++){
                if(poltronas[i][j]!=nullptr){
                    string poltrona = formatarPoltronaIntToString(i, j);
                    cout << "Poltrona " << poltrona << " ocupada por: " 
                    << poltronas[i][j]->getNome() << endl;
                }
            }//end for colunas
        }//end for linhas
        cout << "Fim da lista de passageiros" << endl;
    }//end função imprime
}//end namespace poo