#include "./classes/item.h"
#include <string>
using namespace std;


#ifndef ITEM_H
#define ITEM_H

Item::Item(string nome_item,float peso_item) : nome_item(nome_item), peso_item(peso_item){
}

Item::Item() : nome_item("Item desconhecido"), peso_item(0.0f) {}

string Item::get_nome()  {
    return nome_item;
}

// Método para obter o tipo do item
string Item::get_tipo_do_item() {
    return tipo_do_item;
}

#endif
