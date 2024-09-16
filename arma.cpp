#include "./classes/arma.h"
#include <string>
using namespace std;


#ifndef ARMA_H
#define ARMA_H

Arma::Arma(string nome_item,float peso_item, float dano, string tipo_da_arma) : Item(nome_item,peso_item), dano(dano), tipo_da_arma(tipo_da_arma){
}


#endif