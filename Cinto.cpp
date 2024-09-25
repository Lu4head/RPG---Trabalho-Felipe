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

int Cinto::Colocar_item(Item* item, int posicao) {
    if (Cinto_cheio()) {
        std::cout << "Cinto está cheio!" << std::endl;
        return 1;
    }

    if (item->get_peso() + peso_ocupado > peso_max) {
        std::cout << "O cinto não tem mais capacidade suficiente para o peso desse item." << std::endl;
        std::cout << "Libere mais espaço removendo um item ou suba de nível para aumentar o peso máximo que consegue carregar." << std::endl;
        return 2;
    }

    if (posicao < 1 || posicao > count + 1) { // Permite inserção na última posição válida
        std::cout << "Posição Inválida!" << std::endl;
        return 3;
    }

    // Deslocar itens para abrir espaço, se necessário
    for (int i = count; i >= posicao; i--) {
        Entry[i + 1] = Entry[i]; // Aumenta o índice para o próximo
    }

    Entry[posicao] = item; // Insere o novo item
    peso_ocupado += item->get_peso(); // Incrementa o peso ocupado
    count++; // Incrementa o número de itens
    std::cout << "Item inserido com sucesso!" << std::endl;
    return 0;
}

int Cinto::Remover_item(Item* &item_retorno, int posicao){
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
    Entry[count] = nullptr;
    peso_ocupado -= item_retorno->get_peso();
    count--;
    return 0;
};

int Cinto::Trocar_posicao(int p1, int p2){
    if(Cinto_vazio()){
        std::cout << "Cinto vazio!" << std::endl;
        return 1;
    }

    if( count <= 1 ){
        std::cout << "Só há 1 item no cinto, não é possivel realizar essa operação." << std::endl;
        return 2;
    }

    if(p1 < 1 || p1 > count || p2 < 1 || p2 > count || p1 == p2){
        std::cout << "Posicao Invalida!" << std::endl;
        return 3;
    }

    Item* item_temp = Entry[p2];
    Entry[p2] = Entry[p1];
    Entry[p1] = item_temp;

    return 0;
}

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

int Cinto::usar_pocao(Pocao* &pocao){
    if(Cinto_vazio()){
        std::cout << "Sem itens no cinto!";
        return 1;;
    }

    
    int posicao;
    
    for(int i = 1; i <= count; i++){
        if(Entry[i]->get_tipo_do_item() == "Pocao"){
            std::cout << i << ": " << Entry[i]->get_nome() << std::endl;
        }
    }

    do{
        while(true){
            std::cout << "Escolha a posição do item que deseja usar (1,2,3..) : " << std::endl;
            std::cin >> posicao;
            if(std::cin.fail()){
                std::cin.clear();
                std::cin.ignore(32767, '\n');
                std::cout << "Entrada inválida." << std::endl;
            } else {
                break;
            }
        }    

        if(posicao < 1 || posicao > count){
            std::cout << "Posicao Invalida!" << std::endl;
            return 2;
        }
        if(Entry[posicao]->get_tipo_do_item() != "Pocao"){
            std::cout << "Item não é uma poção!" << std::endl;
            return 3;
        }
    } while(Entry[posicao]->get_tipo_do_item() != "Pocao");

    std::cout << "Utilizando o item " << Entry[posicao]->get_nome() << std::endl;
    pocao = dynamic_cast<Pocao*>(Entry[posicao]);
    Item* item_temp;
    Remover_item(item_temp, posicao);
    return 0;
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
        std::cout << i << ": " << Entry[i]->get_nome() << std::endl;
    }

    return 0;
}

void Cinto::definir_capacidade(int x){
    peso_max += x;
    return;
}

int Cinto::equipar_arma(Arma* &arma_equipada){
    if(Cinto_vazio()){
        std::cout << "Sem itens no cinto!";
        return 1;
    }

    int posicao;
    bool encontrou_arma = false;
    for (int i = 1; i <= count; i++) {
        if (Entry[i]->get_tipo_do_item() == "Arma") {
            // Faz o cast de Item para Arma
            Arma* arma = dynamic_cast<Arma*>(Entry[i]);

            std::cout << i << ": " << arma->get_nome() << " - Dano: " << arma->get_dano() << std::endl;
            encontrou_arma = true;
        }
    }

    if (!encontrou_arma) {
        std::cout << "Nenhuma arma disponível no cinto!" << std::endl;
        return 2;
    }

    do {
        while(true){
            std::cout << "Escolha a posição da arma que deseja equipar (1, 2, 3...): ";
            std::cin >> posicao;    
            if(std::cin.fail()){
                std::cin.clear();
                std::cin.ignore(32767, '\n');
                std::cout << "Entrada inválida." << std::endl;
            } else {
                break;
            }
        }            

        if (posicao < 1 || posicao > count) {
            std::cout << "Posição inválida!" << std::endl;
            return 3;
        }

        if (Entry[posicao]->get_tipo_do_item() != "Arma") {
            std::cout << "Item selecionado não é uma arma!" << std::endl;
            return 4;
        }

    } while (Entry[posicao]->get_tipo_do_item() != "Arma");

    // Equipar a arma
    arma_equipada = dynamic_cast<Arma*>(Entry[posicao]);
    Item* item_temp;
    Remover_item(item_temp,posicao);
    return 0;
}
#endif