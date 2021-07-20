#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <vector>
#include <algorithm>
#include "pessoa.h"
#include "posto.h"

using namespace std;


int main(){

    int i = 0, j = 0;

    int numPostos, numPessoas;

    int vagas, idade;

    float x, y;

    cin >> numPostos;

    Posto* postosDeSaude = new Posto[numPostos];

    for(i = 0; i < numPostos; i++){
        cin >> vagas >> x >> y;
        postosDeSaude[i] = Posto(i, vagas, x, y);
    }

    cin >> numPessoas;

    Pessoa* pessoas = new Pessoa[numPessoas];

    for(i = 0; i < numPessoas; i++){
        
        cin >> idade >> x >> y; //lendo linha representando paciente

        pessoas[i] = Pessoa(i, idade, x, y);
        for(j = 0; j < numPostos; j++){
            pessoas[i].inserirPosto(postosDeSaude[j]); //Isto é feito para que a classe pessoa ordene os diversos postos 
        }                                               // em termos de proximidade em relação à residência do paciente

        pessoas[i].ordenarPostosPreferidos();         //Aqui se ordena os postos de acordo com a proximidade à pessoa 
    }

    sort(pessoas, pessoas + numPessoas); //ordenando as pessoas em termos de idade

    int idPostoDePreferencia;

    bool postosCheios = false;

    for(i = numPessoas - 1; i >= 0; i--){
        
        while(!pessoas[i].pessoaJaAlocada()){
            
            if(pessoas[i].postosEsgotados()){
                postosCheios = true;
                break;
            }
            
            idPostoDePreferencia = pessoas[i].popPostoPreferido(); //recebe o id do posto de preferência do paciente
            
            if(!postosDeSaude[idPostoDePreferencia].cheio()){
                postosDeSaude[idPostoDePreferencia].alocarPessoa(pessoas[i].getId()); //
                pessoas[i].alocarPosto(postosDeSaude[idPostoDePreferencia]);
            }

        }

        if(postosCheios)    // quebra o loop quando os postos se esgotam
            break;

    }

    int numPessoasNoPosto;

    for(i = 0; i < numPostos; i++){
        if(postosDeSaude[i].getNumPessoas() > 0){   
            cout << i << endl;
            numPessoasNoPosto = postosDeSaude[i].getNumPessoas();
            for(j = 0; j < numPessoasNoPosto; j++)
                cout << postosDeSaude[i].getIdPessoaAlocada(j) << " ";
            cout << endl;
        }
    }

    delete[] pessoas;

    delete[] postosDeSaude;

    return 1;
}