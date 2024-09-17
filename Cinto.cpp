#include ".\classes\Cinto.h"
#include <iostream>


using namespace std;

#ifndef CINTO_H
#define CINTO_H

Cinto::Cinto(){
    count = 0;
    peso_max = 20;
}

Cinto::~Cinto(){
    Clear();
}

bool Cinto::Empty(){
    return count == 0;
}

bool Cinto::Full(){
    return count == MaxList + 1;
}

void Cinto::Colocar_item(Item item, int posicao){
    if (Full()){
        cout << "Cinto está cheio!" << endl;
        return;
    }
    if(item.get_peso() > peso_max){
        std::cout << "Esse item não cabe no cinto, é pesado demais!" << std::endl;
        return;
    }
    if(posicao < 1 || posicao > count + 1){
        cout << "Posicao Invalida!" << endl;
        return;
    }
    for(int i = count ; i >= posicao ; i--){    
        Entry [ i + 1 ] = Entry[i];
    }
    Entry[posicao] = item;
    count++;
};

void Cinto::Remover_item(Item &item_retorno, int posicao){
    if(Empty()){
        cout << "Cinto vazio!" << endl;
        return;
    }
    if(posicao < 1 || posicao > count){
        cout << "Posicao Invalida!" << endl;
        return;
    }
    item_retorno = Entry[posicao];
    for(int i = posicao; i < count; i++){
        Entry[i] = Entry[i + 1];
    }
    count--;
};

void Cinto::Clear(){
    count = 0;
    cout << "Cinto foi esvaziado, todos itens foram descartados!";
}

void Cinto::usar_item(int posicao){
    if(Empty()){
        cout << "Sem itens no cinto!";
        return;
    }
    
    if(posicao < 1 || posicao > count){
        cout << "Posicao Invalida!" << endl;
        return;
    }
    if(Entry[posicao].get_tipo_do_item() == "Cura" || Entry[posicao].get_tipo_do_item() == "mana"){
    cout << "Utilizando o item " << Entry[posicao].get_nome() << endl;
    // colocar a logica para usar o item aqui, tipo curar a vida ou recuperar mana
}

    for(int i = posicao; i < count; i++){
        Entry[i] = Entry[i + 1];
    }
    count--;
}


int Cinto::espaco_disponivel() {
    return MaxList - count;
}


void Cinto::mostrar_itens() {
    if (Empty()) {
        std::cout << "O cinto está vazio!" << std::endl;
        return;
    }

    std::cout << "Itens no cinto:" << std::endl;
    for (int i = 1; i < count; i++) {
        std::cout << i << ": " << Entry[i].get_nome() << std::endl;
    }
}


#endif