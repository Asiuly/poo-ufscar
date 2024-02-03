#ifndef OBRASDEARTE_H
#define OBRASDEARTE_H
#include <iostream>
#include <string>
using namespace std;
#define ANO 2024

class ObrasDeArte{
    private:
        int ID;
        string artista;
        string titulo;
        string genero;
        int anoPublicacao;

    public:
        ObrasDeArte(int, string, string, string, int);
        virtual ~ObrasDeArte() { }

        int getID() const;
        void setID(int);
        
        string getArtista() const;
        void setArtista(string);

        string getTitulo() const;
        void setTitulo(string);

        string getGenero() const;
        void setGenero(string);

        int getAnoPublicacao() const;
        void setAnoPublicacao(int);
        
        int calcularIdade() const;
        double avaliarValor() const; //com base no ano igual whisky
        
        friend ostream& operator<<(ostream& os, const ObrasDeArte& obra);
        virtual string getCategoria() const = 0;
};


#endif