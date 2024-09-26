#include ".\classes\Pocao.h"

#ifndef POCAO_H
#define POCAO_H

Pocao::Pocao(std::string nome_item, float peso_item, std::string tipo_do_item, float cura, float mana,int nivel) : Item(nome_item, peso_item, tipo_do_item,nivel), cura(cura), mana(mana){ }; // Construtor de pocao
Pocao::Pocao(){}; // Construtor padrão para criação de arrays / variaveis temporarias

float Pocao::get_cura(){ // Retorna atributo de cura da poção
    return cura;
}

float Pocao::get_mana(){ // Retorna atributo de mana da poção (quantidade de mana que será recuperada)
    return mana;
}


#endif