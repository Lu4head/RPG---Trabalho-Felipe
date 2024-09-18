#include "./classes/Arma.h"
#include <string>



#ifndef ARMA_H
#define ARMA_H

Arma::Arma(std::string nome_item,float peso_item, float dano, std::string tipo_da_arma) : Item(nome_item,peso_item), dano(dano), tipo_da_arma(tipo_da_arma){};

float Arma::get_dano(){
    return dano;
};

std::string Arma::get_tipo(){
    return tipo_da_arma;
};

#endif