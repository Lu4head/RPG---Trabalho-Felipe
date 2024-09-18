#include ".\classes\Pocao.h"
#include "string"

#ifndef POCAO_H
#define POCAO_H

Pocao::Pocao(std::string nome_item, float peso_item, float cura, float mana, std::string tipo_da_pocao) : Item(nome_item, peso_item), cura(cura), mana(mana), tipo_da_pocao(tipo_da_pocao){ };

void Pocao::usa_pocao(Personagem personagem){
    personagem.cura(cura);
    personagem.recupera_mana(mana);
}

#endif