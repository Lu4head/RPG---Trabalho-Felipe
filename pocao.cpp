#include ".\classes\pocao.h"
#include "string"
using namespace std;

#ifndef POCAO_H
#define POCAO_H

Pocao::Pocao(string nome_item, float peso_item, float cura, float mana, string tipo_da_pocao) : Item(nome_item, peso_item), cura(cura), mana(mana), tipo_da_pocao(tipo_da_pocao){ 
}

#endif