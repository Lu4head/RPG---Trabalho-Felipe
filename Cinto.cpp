//Luan Emanuel R. Argentato RA: 2184611
//Gustavo duzzi             RA: 2214047
//Guilherme Santos Gollino  RA: 2226090

#include <iostream>

#include ".\classes\Cinto.h"

#ifndef CINTO_H
#define CINTO_H

Cinto::Cinto(){ // Construtor para Cinto settando valores iniciais
    count = 0;
    peso_max = 20;
    peso_ocupado = 0;
};

Cinto::~Cinto(){}; // Destrutor padrão para cinto

bool Cinto::Cinto_vazio(){ // Verifica se o cinto está vazio
    return count == 0;
};

bool Cinto::Cinto_cheio(){ // Verifica se o cinto está cheio
    return count == MaxList + 1;
};

int Cinto::Colocar_item(Item* item, int posicao) { // Coloca um item no cinto
    if (Cinto_cheio()) { // Verifica se o cinto está cheio
        std::cout << "Cinto está cheio!" << std::endl;
        return 1;
    }

    if (item->get_peso() + peso_ocupado > peso_max) { // Verifica se o peso do item somado com o peso atual excede o peso máximo do cinto
        std::cout << "O cinto não tem mais capacidade suficiente para o peso desse item." << std::endl;
        std::cout << "Libere mais espaço removendo um item ou suba de nível para aumentar o peso máximo que consegue carregar." << std::endl;
        return 2;
    }

    if (posicao < 1 || posicao > count + 1) { // Verifica se a posição de inserção do item é valida (não pode ser menor que 1 e nem maior que o número de itens + 1)
        std::cout << "Posição Inválida!" << std::endl;
        return 3;
    }

    // Deslocar itens para abrir espaço, se necessário
    for (int i = count; i >= posicao; i--) {
        Entry[i + 1] = Entry[i]; // Aumenta o índice para o próximo
    }

    peso_ocupado += item->get_peso(); // Incrementa o peso ocupado
    count++; // Incrementa o número de itens
    Entry[posicao] = item; // Insere o novo item
    return 0;
}

int Cinto::Remover_item(Item* &item_retorno, int posicao){ // Remove item da mochila na posição especificada e retorna o item removido
    if(Cinto_vazio()){ // Verifica se o cinto está vazio
        std::cout << "Cinto vazio!" << std::endl;
        return 1;
    }
    
    if(posicao < 1 || posicao > count){ // Verifica se a posição de remoção é válida
        std::cout << "Posicao Invalida!" << std::endl;
        return 3;
    }

    item_retorno = Entry[posicao];
    
    for(int i = posicao; i < count; i++){
        Entry[i] = Entry[i + 1];
    }

    Entry[count] = nullptr; // Remove o item da lista
    
    peso_ocupado -= item_retorno->get_peso(); // Subtrai o peso do item removido de peso_ocupado
    
    count--; // Decrementa o número de itens
    std::cout << item_retorno->get_nome() << " removido do cinto com sucesso!" << std::endl;
    return 0;
};

int Cinto::Trocar_posicao(int p1, int p2){ // Troca a posição de dois itens na lista
    if(Cinto_vazio()){ // Verifica se o cinto está vazio
        std::cout << "Cinto vazio!" << std::endl;
        return 1;
    }

    if( count <= 1 ){ // Verifica se há mais de 1 item no cinto antes de tentar trocar posições
        std::cout << "Só há 1 item no cinto, não é possivel realizar essa operação." << std::endl;
        return 2;
    }

    if(p1 < 1 || p1 > count || p2 < 1 || p2 > count || p1 == p2){ // Verifica se as posições são válidas
        std::cout << "Posicao Invalida!" << std::endl;
        return 3;
    }

    // Troca a posição dos dois itens utilizando uma variável auxiliar
    Item* item_temp = Entry[p2];
    Entry[p2] = Entry[p1];
    Entry[p1] = item_temp;

    return 0;
};

int Cinto::usar_pocao(Pocao* &pocao){
    int posicao;
    
    if(Cinto_vazio()){ // Verifica se o cinto está vazio
        std::cout << "Sem itens no cinto!";
        return 1;
    }
    
    for(int i = 1; i <= count; i++){ // Mostra as poções disponíveis no cinto
        if(Entry[i]->get_tipo_do_item() == "Pocao"){
            std::cout << i << ": " << Entry[i]->get_nome() << std::endl;
        }
    }

    do{ // Pede a posição da poção que o usuário deseja usar
        while(true){
            std::cout << "Escolha a posição do item que deseja usar (1,2,3..) : " << std::endl;
            std::cin >> posicao;
            if(std::cin.fail()){ // Verifica se a entrada é válida
                std::cin.clear();
                std::cin.ignore(32767, '\n');
                std::cout << "Entrada inválida." << std::endl;
            } else {
                break;
            }
        }    

        if(posicao < 1 || posicao > count){ // Verifica se a posição é válida
            std::cout << "Posicao Invalida!" << std::endl;
            return 2;
        }

        if(Entry[posicao]->get_tipo_do_item() != "Pocao"){ // Verifica se o item na posição escolhida é uma poção
            std::cout << "Item não é uma poção!" << std::endl;
            return 3;
        }

    } while(Entry[posicao]->get_tipo_do_item() != "Pocao");

    std::cout << "Utilizando o item " << Entry[posicao]->get_nome() << std::endl; 
    pocao = dynamic_cast<Pocao*>(Entry[posicao]); // Faz o cast do ponteiro de Item para Pocao
    Item* item_temp; 
    Remover_item(item_temp, posicao); // Remove a poção do cinto
    return 0;
};


int Cinto::espacos_disponiveis() { // Retorna a quantidade de espaços disponíveis no cinto
    return MaxList - count;
};


int Cinto::mostrar_itens() { // Mostra os itens no cinto
    if (Cinto_vazio()) { // Verifica se o cinto está vazio
        std::cout << "O cinto está vazio!" << std::endl;
        return 1; // Retorna 1 se o cinto estiver vazio
    }
    std::cout << "Capacidade do cinto: " << peso_ocupado << "/" << peso_max  << " kg" << std::endl; // Mostra a capacidade do cinto
    std::cout << "Itens no cinto:" << std::endl;
    for (int i = 1; i <= count; i++) { // Mostra os itens no cinto
        std::cout << i << ": " << Entry[i]->get_nome() << std::endl;
    }

    return 0;
}

void Cinto::definir_capacidade(float x){ // Incrementa a capacidade de peso do cinto
    peso_max += x;
    return;
}

int Cinto::equipar_arma(Arma* &arma_equipada){ // Retorna armas no cinto que podem ser equipadas e solicita que o usuario escolha qual será equipada
    if(Cinto_vazio()){ // Verifica se o cinto está vazio
        std::cout << "Sem itens no cinto!";
        return 1;
    }

    int posicao;
    bool encontrou_arma = false; // Indica se encontrou uma arma no cinto

    for (int i = 1; i <= count; i++) { // Mostra as armas disponíveis no cinto
        if (Entry[i]->get_tipo_do_item() == "Arma") {
            // Faz o cast de Item para Arma
            Arma* arma = dynamic_cast<Arma*>(Entry[i]);

            std::cout << i << ": " << arma->get_nome() << " - Dano: " << arma->get_dano() << std::endl;
            encontrou_arma = true; // Indica que encontrou uma arma
        }
    }

    if (!encontrou_arma) { // Se não encontrou nenhuma arma no cinto
        std::cout << "Nenhuma arma disponível no cinto!" << std::endl;
        return 2; // Retorna 2 caso não tenha armas no cinto
    }

    do { // Pede a posição da arma que o usuário deseja equipar
        while(true){
            std::cout << "Escolha a posição da arma que deseja equipar (1, 2, 3...): ";
            std::cin >> posicao;    
            if(std::cin.fail()){ // Verifica se a entrada é válida
                std::cin.clear();
                std::cin.ignore(32767, '\n');
                std::cout << "Entrada inválida." << std::endl;
            } else {
                break;
            }
        }            

        if (posicao < 1 || posicao > count) { // Verifica se a posição é válida
            std::cout << "Posição inválida!" << std::endl;
            return 3;
        }

        if (Entry[posicao]->get_tipo_do_item() != "Arma") { // Verifica se o item na posição escolhida é uma arma
            std::cout << "Item selecionado não é uma arma!" << std::endl;
            return 4;
        }

    } while (Entry[posicao]->get_tipo_do_item() != "Arma");

    // Equipar a arma
    arma_equipada = dynamic_cast<Arma*>(Entry[posicao]); // Faz o cast do ponteiro de Item para Arma
    Item* item_temp;
    Remover_item(item_temp,posicao); // Remove a arma do cinto
    return 0;
}


#endif
