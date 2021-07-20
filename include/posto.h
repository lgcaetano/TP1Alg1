#ifndef POSTO_H
#define POSTO_H
#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <vector>
#include <algorithm>
// #include "pessoa.h"

using namespace std;

class Posto{
    
    public:

        Posto();
        Posto(int id, int vagas, float x, float y);
        int getVagas();
        float getX();
        float getY();
        int getId();
        int getNumPessoas();
        bool cheio();
        void alocarPessoa(int idPessoa);
        int getIdPessoaAlocada(int index);

    private:

        vector<int> idsPessoasAlocadas;
        int numPessoas;
        float _x;
        float _y;
        int _vagas;
        int _id;

};


#endif 