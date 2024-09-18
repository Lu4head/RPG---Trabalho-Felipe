#include ".\classes\Cinto.h"
#include <iostream>


using namespace std;

#ifndef CINTO_H
#define CINTO_H

Cinto::Cinto(){
    count = 0;
    peso_max = 20;
};

Cinto::~Cinto(){
    count = 0;
};

bool Cinto::Cinto_vazio(){
    return count == 0;
};

bool Cinto::Cinto_cheio(){
    return count == MaxList + 1;
};

int Cinto::Colocar_item(Item item, int posicao){
    if (Cinto_cheio()){
        cout << "Cinto está cheio!" << endl;
        return 1;
    }
    if(item.get_peso() > peso_max){
        std::cout << "Esse item não cabe no cinto, é pesado demais!" << std::endl;
        return 2;
    }
    if(posicao < 1 || posicao > count + 1){
        cout << "Posicao Invalida!" << endl;
        return 3;
    }
    for(int i = count ; i >= posicao ; i--){    
        Entry [ i + 1 ] = Entry[i];
    }
    Entry[posicao] = item;
    count++;
    return 0;
};

int Cinto::Remover_item(Item &item_retorno, int posicao){
    if(Cinto_vazio()){
        cout << "Cinto vazio!" << endl;
        return 1;
    }
    if(posicao < 1 || posicao > count){
        cout << "Posicao Invalida!" << endl;
        return 3;
    }
    item_retorno = Entry[posicao];
    for(int i = posicao; i < count; i++){
        Entry[i] = Entry[i + 1];
    }
    count--;
    return 0;
};

int Cinto::Esvaziar_cinto(){
    if(Cinto_vazio()){
        cout << "O cinto já está vazio!" << endl;
        return 1;
    }
    count = 0;
    cout << "Cinto foi esvaziado, todos itens foram descartados!";
    return 0;
};

int Cinto::usar_item(int posicao){
    if(Cinto_vazio()){
        cout << "Sem itens no cinto!";
        return 1;
    }
    
    if(posicao < 1 || posicao > count){
        cout << "Posicao Invalida!" << endl;
        return 3;
    }
    if(Entry[posicao].get_tipo_do_item() == "Cura" || Entry[posicao].get_tipo_do_item() == "mana"){
    cout << "Utilizando o item " << Entry[posicao].get_nome() << endl;
    // colocar a logica para usar o item aqui, tipo curar a vida ou recuperar mana
} 

    for(int i = posicao; i < count; i++){
        Entry[i] = Entry[i + 1];
    }
    count--;
    return 0;
};


int Cinto::espacos_disponiveis() {
    return MaxList - count;
};


int Cinto::mostrar_itens() {
    if (Cinto_vazio()) {
        std::cout << "O cinto está vazio!" << std::endl;
        return 1;
    }

    std::cout << "Itens no cinto:" << std::endl;
    for (int i = 1; i < count; i++) {
        std::cout << i << ": " << Entry[i].get_nome() << std::endl;
    }
    return 0;
};


#endif