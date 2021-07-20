#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <vector>
#include <algorithm>
#include "pessoa.h"
#include "posto.h"

using namespace std;

float calcularDistancia (float x1, float y1, float x2, float y2){
    return sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
}

bool Pessoa::operator < (Pessoa& pessoa) const{
    if(_idade == pessoa.getIdade()){ // garante a estabilidade do sort
        return _id > pessoa.getId(); // como o menor identificador tem prioridade, a lógica se inverte aqui 
    }
    return _idade < pessoa.getIdade();
}

bool PostoDistancia::operator < (PostoDistancia& postoDistancia) const{
    if(distancia == postoDistancia.distancia){
        return id > postoDistancia.id; // idem Pessoa
    }
    return distancia > postoDistancia.distancia;//inverte-se a lógica para deixar os postos de maior relevância no final do vector
}



PostoDistancia::PostoDistancia(int _id, float _dist){
    id = _id;
    distancia = _dist;
}



Pessoa::Pessoa(){
    _x = 0;
    _y = 0;
    _idade = 0;
    _id = 0;
    idPostoAlocado = -1;     
}

Pessoa::Pessoa(int id, int idade, float x, float y){
    _id = id;
    _idade = idade;
    _x = x;
    _y = y;
    idPostoAlocado = -1;
}

int Pessoa::getIdade(){
    return _idade;
}

int Pessoa::getId(){
    return _id;
}


void Pessoa::inserirPosto(Posto postoNovo){

    // cout << "VECTOR: " << postosPreferidos.size() << endl;

    float distanciaDoPosto = calcularDistancia(_x, _y, postoNovo.getX(), postoNovo.getY());
    
    postosPreferidos.push_back(PostoDistancia(postoNovo.getId(), distanciaDoPosto));

    
}

void Pessoa::ordenarPostosPreferidos(){
    sort(postosPreferidos.begin(), postosPreferidos.end());
}




void Pessoa::alocarPosto(Posto postoAlocado){
    idPostoAlocado = postoAlocado.getId();
}

int Pessoa::popPostoPreferido(){
    // cout << " POP POSTO " << endl; 
    int retorno = postosPreferidos.back().id;
    postosPreferidos.pop_back();
    return retorno;
}


bool Pessoa::postosEsgotados(){
    if(postosPreferidos.size() > 0)
        return false;
    return true;
}

bool Pessoa::pessoaJaAlocada(){
    return idPostoAlocado > -1;
}