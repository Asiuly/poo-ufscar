#include <iostream>

//biblioteca string
#include <string>

using namespace std;

int main(){
    //não é mais necessário vetor de char
    string nome = "";
    string sobrenome = "";

    cout << "entre com seu nome: ";
    //cin >> nome;

    //opção para quando se deseja escrever coisas com espaços
    getline(cin, nome);
    //essa função pega a linha inteira até o enter e coloca na variavel escolhida

    cout << "agora, com seu sobrenome: ";
    cin >> sobrenome;

    //concatenação de strings
    string nome_completo = nome + " " + sobrenome;

    cout << "Nome completo: " << nome_completo;

    return 0;
}