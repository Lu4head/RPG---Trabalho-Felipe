#include "./classes/Item.h"
#include <string>

#ifndef ITEM_H
#define ITEM_H

Item::Item(std::string nome_item,float peso_item) : nome_item(nome_item), peso_item(peso_item){
}

Item::Item() : nome_item("Item desconhecido"), peso_item(0.0f) {}

std::string Item::get_nome()  {
    return nome_item;
}

int Item::get_peso(){
    return peso_item;
}

// Método para obter o tipo do item
std::string Item::get_tipo_do_item() {
    return tipo_do_item;
}



#endif
