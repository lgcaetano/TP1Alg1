#ifndef PESSOA_H
#define PESSOA_H
#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <vector>
#include <algorithm>
#include "posto.h"

using namespace std;




class PostoDistancia {

    public: 

        PostoDistancia(int _id, float _dist);
        int id;
        float distancia;
        bool operator < (PostoDistancia& postoDistancia) const;

};

class Pessoa{
    
    public:

        Pessoa();
        // Pessoa(int id);
        // Pessoa(int id, int idade);
        Pessoa(int id, int idade, float x, float y);
        int getIdade();
        int getId();
        void inserirPosto(Posto postoNovo);
        void alocarPosto(Posto postoAlocado);
        int popPostoPreferido();
        void ordenarPostosPreferidos();
        
        bool pessoaJaAlocada();

        bool postosEsgotados(); 

        bool operator < (Pessoa& pessoa) const; 

    private:

        float _x;
        float _y;
        int _idade;
        int _id;
        int idPostoAlocado;
        vector<PostoDistancia> postosPreferidos;

};





#endif 