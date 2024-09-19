#include ".\classes\Pocao.h"
#include "string"

#ifndef POCAO_H
#define POCAO_H

Pocao::Pocao(std::string nome_item, float peso_item, float cura, float mana, std::string tipo_da_pocao) : Item(nome_item, peso_item), cura(cura), mana(mana), tipo_da_pocao(tipo_da_pocao){ };

std::string Pocao::get_tipo_do_item(){
    return tipo_da_pocao;
}
float Pocao::get_cura(){
    return cura;
}

#endif