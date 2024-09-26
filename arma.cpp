#include <string>

#include "./classes/Arma.h"

#ifndef ARMA_H
#define ARMA_H

Arma::Arma(std::string nome_item,float peso_item, std::string tipo_do_item, float dano,int nivel, int custo_mana) : Item(nome_item,peso_item, tipo_do_item,nivel), dano(dano), custo_mana(custo_mana){}; // Constutor para arma já setando os atributos na inicialização do objeto
Arma::Arma(){}; // Cosntrutor padrão
Arma::~Arma(){};
float Arma::get_dano(){ // Função para retornar o dano da arma
    return dano;
};

int Arma::get_custo_mana(){ // Função para retornar o custo de mana da arma
    return custo_mana;
};

#endif