#include ".\classes\Pocao.h"
#include "string"

#ifndef POCAO_H
#define POCAO_H

Pocao::Pocao(std::string nome_item, float peso_item, std::string tipo_do_item, float cura, float mana,int nivel) : Item(nome_item, peso_item, tipo_do_item,nivel), cura(cura), mana(mana){ };
Pocao::Pocao(){
    
}
float Pocao::get_cura(){
    return cura;
}

float Pocao::get_mana(){
    return mana;
}


#endif