//Luan Emanuel R. Argentato RA: 2184611
//Gustavo duzzi             RA: 2214047
//Guilherme Santos Gollino  RA: 2226090


#include "./classes/Item.h"
#include <string>

#ifndef ITEM_H
#define ITEM_H

Item::Item(std::string nome_item,float peso_item, std::string tipo_do_item,int nivel) : nome_item(nome_item), peso_item(peso_item), tipo_do_item(tipo_do_item),nivel(nivel) {}; // Construtor para item

Item::Item() : nome_item("Item desconhecido"), peso_item(0.0f) {}; // Construtor padrão para criação de array / Item temporário

std::string Item::get_nome()  { // Método para obter o nome do item
    return nome_item;
}

float Item::get_peso(){ // Método para obter o peso do item
    return peso_item;
}

std::string Item::get_tipo_do_item() { // Método para obter o tipo do item
    return tipo_do_item;
}

int Item::get_nivel(){ // Método para obter o nivel do item
    return nivel;
}

#endif
