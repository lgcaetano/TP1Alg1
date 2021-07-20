#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <vector>
#include <algorithm>
#include "posto.h"
// #include "pessoa.h"

using namespace std;

Posto::Posto(){
    numPessoas = 0;
    _x = 0;
    _y = 0;
    _vagas = 0;
    _id = -1;
}

Posto::Posto(int id, int vagas, float x, float y){
    
    numPessoas = 0;
    _x = x;
    _y = y;
    _vagas = vagas;
    _id = id;

}

int Posto::getVagas(){
    return _vagas;
}

int Posto::getId(){
    return _id;
}

float Posto::getX(){
    return _x;
}

float Posto::getY(){
    return _y;
}

bool Posto::cheio(){
    return (numPessoas >= _vagas);
}

void Posto::alocarPessoa(int idPessoa){
    // cout << idPessoa << " P ";
    idsPessoasAlocadas.push_back(idPessoa);
    numPessoas++;

}

int Posto::getNumPessoas(){
    return numPessoas;
}

int Posto::getIdPessoaAlocada(int index){
    return idsPessoasAlocadas[index];
}