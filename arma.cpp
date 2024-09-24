#include "./classes/Arma.h"
#include <string>

#ifndef ARMA_H
#define ARMA_H

Arma::Arma(std::string nome_item,float peso_item, std::string tipo_do_item, float dano,int nivel) : Item(nome_item,peso_item, tipo_do_item,nivel), dano(dano){};
Arma::Arma(){

};
float Arma::get_dano(){
    return dano;
};



#endif