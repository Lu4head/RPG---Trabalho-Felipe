#include ".\classes\Cinto.h"
#include <iostream>

#ifndef CINTO_H
#define CINTO_H

Cinto::Cinto(){
    count = 0;
    peso_max = 20;
    peso_ocupado = 0;
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

int Cinto::Colocar_item(Item item, int posicao) {
    if (Cinto_cheio()) {
        std::cout << "Cinto está cheio!" << std::endl;
        return 1;
    }
    if(item.get_peso() + peso_ocupado > peso_max) {
        std::cout << "O cinto não tem mais capacidade suficiente para o peso desse item." << std::endl;
        std::cout << "Libere mais espaço removendo um item ou suba de nível para aumentar o peso máximo que consegue carregar." << std::endl;
        return 2;
    }
    if(posicao < 1 || posicao > count + 1) { // Permite inserção na última posição válida
        std::cout << "Posição Inválida!" << std::endl;
        return 3;
    }
    
    // Verifica se já existe um item na posição especificada
    if (Entry[posicao].get_peso() != 0) { // Supondo que Entry[posicao] seja um ponteiro para o Item
        char escolha;
        std::cout << "Já existe um item na posição " << posicao << ". Deseja substituí-lo? (s/n): ";
        std::cin >> escolha;
        
        if (escolha != 's' && escolha != 'S') {
            std::cout << "Item não substituído." << std::endl;
            return 4; // Código para item não substituído
        }
    }
    
    // Deslocar itens para abrir espaço, se necessário
    for(int i = count; i >= posicao; i--) {    
        Entry[i + 1] = Entry[i]; // Aumenta o índice para o próximo
    }
    
    Entry[posicao] = item; // Insere o novo item
    peso_ocupado += item.get_peso(); // Incrementa o peso ocupado
    count++; // Incrementa o número de itens
    std::cout << "Item inserido com sucesso!" << std::endl;
    return 0;
}

int Cinto::Remover_item(Item &item_retorno, int posicao){
    if(Cinto_vazio()){
        std::cout << "Cinto vazio!" << std::endl;
        return 1;
    }
    if(posicao < 1 || posicao > count){
        std::cout << "Posicao Invalida!" << std::endl;
        return 3;
    }
    item_retorno = Entry[posicao];
    for(int i = posicao; i < count; i++){
        Entry[i] = Entry[i + 1];
    }
    peso_ocupado -= item_retorno.get_peso();
    count--;
    return 0;
};

int Cinto::Esvaziar_cinto(){
    if(Cinto_vazio()){
        std::cout << "O cinto já está vazio!" << std::endl;
        return 1;
    }
    peso_ocupado = 0;
    count = 0;
    std::cout << "Cinto foi esvaziado, todos itens foram descartados!";
    return 0;
};

int Cinto::usar_pocao(Pocao &pocao){
    if(Cinto_vazio()){
        std::cout << "Sem itens no cinto!";
        return 1;;
    }
    
    int posicao;
    
    for(int i = 1; i <= count; i++){
        if(Entry[i].get_tipo_do_item() == "cura" || Entry[i].get_tipo_do_item() == "mana"){
            std::cout << i << ": " << Entry[i].get_nome() << std::endl;
        }
    }

    do{
        std::cout << "Escolha a posição do item que deseja usar (1,2,3..) : " << std::endl;
        std::cin >> posicao;
        if(posicao < 1 || posicao > count){
            std::cout << "Posicao Invalida!" << std::endl;
            return 2;
        }
        if(Entry[posicao].get_tipo_do_item() != "Pocao"){
            std::cout << "Item não é uma poção!" << std::endl;
            return 3;
        }
    } while(Entry[posicao].get_tipo_do_item() == "Pocao");

    std::cout << "Utilizando o item " << Entry[posicao].get_nome() << std::endl;
    Remover_item(pocao, posicao);
    pocao = dynamic_cast<Pocao&>(Entry[posicao]);
    return 0;
    
    // if(posicao < 1 || posicao > count){
    //     std::cout << "Posicao Invalida!" << std::endl;
    //     return 3;
    // }
    // if(Entry[posicao].get_tipo_do_item() == "Cura" || Entry[posicao].get_tipo_do_item() == "mana"){
    // std::cout << "Utilizando o item " << Entry[posicao].get_nome() << std::endl;
    // // colocar a logica para usar o item aqui, tipo curar a vida ou recuperar mana
};


int Cinto::espacos_disponiveis() {
    return MaxList - count;
};


int Cinto::mostrar_itens() {
    if (Cinto_vazio()) {
        std::cout << "O cinto está vazio!" << std::endl;
        return 1; // Retorna 1 se o cinto estiver vazio
    }
    std::cout << "Capacidade do cinto: " << peso_ocupado << "/" << peso_max << std::endl;
    std::cout << "Itens no cinto:" << std::endl;
    for (int i = 1; i <= count; i++) { // Alterar para contar até count
        std::cout << i << ": " << Entry[i].get_nome() << std::endl;
    }

    return 0;
}

void Cinto::definir_capacidade(int x){
    peso_max += x;
    return;
}


#endif