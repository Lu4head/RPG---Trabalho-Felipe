#include ".\classes\Personagem.h"
#include ".\classes\Arma.h"
#include ".\classes\Pocao.h"


#include <iostream> // Biblioteca para entrada e saída de dados

#ifndef PERSONAGEM_H
#define PERSONAGEM_H

Personagem::Personagem(std::string nome): nome(nome){ // Construtor
    vida_Total = 100;
    vida_Atual = vida_Total;
    mana_Total = 100;
    mana_Atual = mana_Total;
    nivel = 1;
    exp_total = 100;
    exp_atual = 0;
    arma_equipada = Arma();
};

Personagem::~Personagem(){}; // Destrutor padrão

void Personagem::recebe_dano(float x){ // Calcula dano recebido subtraindo a vida atual do personagem
    if(vida_Atual - x > 0){
        vida_Atual = vida_Atual - x;
    } else{
        vida_Atual = 0;
    }
};

int Personagem::gasta_mana(float x){ // Calcula mana gasta subtraindo da mana atual do personagem
    if(mana_Atual - x < 0){ // Verifica se a mana atual é suficiente para o gasto
        std::cout << "Mana insuficiente" << std::endl;
        return 1; // Retorna 1 se a mana for insuficiente
    }
    else{
        mana_Atual = mana_Atual - x;
        return 0;
    }
};



float Personagem::exibe_vida(){ // Função que retorna a vida atual do personagem
    return vida_Atual;
};

std::string Personagem::exibe_nome(){ // Função que retorna o nome do personagem
    return nome;
}

void Personagem::aumenta_nivel() { // Calcula se o personagem tem XP suficiente para subir de nível e aumenta os status caso ele suba de nível
    if(exp_atual >= exp_total){
        float multiplicador_exp = 1.25;
        float multiplicador_vida = 1.25;
        float multiplicador_mana = 1.25;

        nivel++; // aumenta o nivel em 1
        exp_atual = exp_atual - exp_total; // calcula a XP que passou do max para manter ela pro prox nível
        exp_total = exp_total * multiplicador_exp; // aumenta o XP total necessario para o prox nivel
        vida_Total = vida_Total * multiplicador_vida; // aumenta a vida max
        mana_Total = mana_Total * multiplicador_mana; // aumenta a mana max
        vida_Atual = vida_Total; // enche a vida
        mana_Atual = mana_Total; // enche a mana
        cinto_personagem.definir_capacidade(5); // aumenta o peso maximo que o cinto pode carregar
    }
};


void Personagem::cura(float x) { // Função para curar o personagem
    if (vida_Atual + x < vida_Total) {
        vida_Atual = vida_Atual + x;
    } else {
        vida_Atual = vida_Total;
    }
    std::cout << "A vida atual agora é: " << vida_Atual << " / " << vida_Total << std::endl;
}

void Personagem::recupera_mana(float x){ // Função para recuperar a mana do personagem
    if(mana_Atual + x < mana_Total){
        mana_Atual = mana_Atual + x;
    } else {
        mana_Atual = mana_Total;
    }
}

void Personagem::usa_pocao() { // Recebe uma poção e calcula as alterações no personagem com base no efeito dela (cura/mana)
    Pocao* pocao = nullptr;
    if(cinto_personagem.usar_pocao(pocao) != 0){ // Verifica se foi possível usar a poção
        std::cout << "Não foi possivel usar a poção" << std::endl;
        return;
    }
    cinto_personagem.usar_pocao(pocao); // Usa a poção
    std::cout << pocao->get_cura(); // Exibe a quantidade de cura da poção
    cura(pocao->get_cura()); // Cura o personagem
    recupera_mana(pocao->get_cura()); // Recupera a mana do personagem
}


void Personagem::Inserir_cinto(Item* item, int posicao){ // Insere item no cinto do heroi
     if (cinto_personagem.Colocar_item(item, posicao) == 0) { // Verifica se foi possível adicionar o item
            std::cout << item->get_nome() << " foi adicionado ao cinto!" << std::endl;
        } else {
            std::cout << "Cinto cheio ou não foi possível adicionar o item." << std::endl;
        }
}

void Personagem::Remover_cinto(Item* item, int posicao){ // Remove item do cinto do heroi
    if(cinto_personagem.Remover_item(item, posicao) == 0){ // Verifica se foi possível remover o item
        std::cout << item->get_nome() << " foi removido do cinto" << std::endl;
    } else {
        std::cout << "Não foi possivel remover item da posição indicada." << std::endl;
    }
}

void Personagem::Trocar_posicao_cinto(int p1, int p2){ // Função para trocar a posição de 2 itens do cinto do heroi
    if(cinto_personagem.Trocar_posicao(p1, p2) == 0){ // Verifica se foi possível trocar os itens de posição
    } else {
        std::cout << "Não foi possivel realizar a troca." << std::endl;
    }
}

void Personagem::mostrar_cinto(){ // Mostra o cinto do heroi
    cinto_personagem.mostrar_itens(); // Chama a função para mostrar os itens do cinto
}

void Personagem::Equipar_arma(Arma* arma){ // Função para equipar a arma do heroi
    arma_equipada = *arma;
}   

void Personagem::trocar_arma(){ // Função para trocar a arma do heroi
    Arma* arma_temp = nullptr;
    if(cinto_personagem.equipar_arma(arma_temp) != 0){ // Verifica se foi possível equipar a arma
        std::cout << "Não foi possivel equipar a arma" << std::endl;
        return;
    }
    if (arma_equipada.get_nome() != "") {
        // Se já houver uma arma equipada, mova-a para a mochila antes de equipar a nova arma
        Item* item_para_mochila = dynamic_cast<Item*>(&arma_equipada);
        std::cout << "Guardando " << arma_equipada.get_nome() << " na mochila." << std::endl;
        mochila_personagem.ColocarItem(item_para_mochila);  // Coloca a arma antiga na mochila
    }
     Equipar_arma(arma_temp);
}

Arma Personagem::mostrar_arma_equipada(){ // Função que retorna a arma equipada
    return arma_equipada; 
}

void Personagem::ganha_xp(int xp) { // Função para calcular o ganho de XP e chama função para verificar se personagem subiu de nível
    exp_atual += xp;
    while (exp_atual >= exp_total) {
        aumenta_nivel();  // Função que sobe o nível
        std::cout << "Parabéns! " << exibe_nome() << " subiu para o nível " << nivel << std::endl;
    }
}

int Personagem::get_nivel(){ // Função que retorna o nível do personagem
    return nivel;
}

void Personagem::transfere_para_mochila(Item *x, int p){ // Função para transferir item do cinto para a mochila do personagem
    if(cinto_personagem.Remover_item(x, p) != 0){ // Verifica se foi possível remover o item do cinto
        std::cout << "Não foi possivel transferir o item" << std::endl;
        return; // Se não foi possivel remover o item encerra a função
    }
    if(mochila_personagem.ColocarItem(x) != 0){ // Verifica se foi possível adicionar o item à mochila
        cinto_personagem.Colocar_item(x, p); // Se não foi possível adicionar o item à mochila, o item é devolvido ao cinto
        std::cout << "Não foi possivel trasferir o item" << std::endl;
    }
};


void Personagem::retirar_item_mochila(Item* x){ // Função para retirar item da mochila do personagem
    if (mochila_personagem.RetirarItem(x) == 0) { // Verifica se foi possível retirar o item
            std::cout << x->get_nome() << " foi retirado da mochila!" << std::endl;
        } else {
            std::cout << "Mochila vazia impossivel retirar item" << std::endl;
        }
}

void Personagem::inserir_item_mochila(Item* x){ // Função para inserir item na mochila do personagem
    if (mochila_personagem.ColocarItem(x) == 0) { // Verifica se foi possível adicionar o item
            std::cout << x->get_nome() << " foi inserido da mochila!" << std::endl;
        } else {
            std::cout << "Não foi possivel adicionar o item à mochila" << std::endl;
        }   
}

void Personagem::mostrar_item_mochila(Item* &x) {
    // Verifica se a função ItemMochila retorna um item válido
    if (mochila_personagem.ItemMochila(x) == 0 && x != nullptr) {
        std::cout << "Item do topo da mochila: " << x->get_nome() << std::endl;
    } else {
        // Se não houver item ou x for nullptr, informe que a mochila está vazia
        std::cout << "A mochila está vazia ou o item não é válido." << std::endl;
    }
}

void Personagem::trocar_arma_mochila(){
    Arma* arma_temp = nullptr;
    if(mochila_personagem.equipar_arma(arma_temp) != 0){
        std::cout << "Não foi possivel equipar a arma" << std::endl;
        return;
    }
   if (arma_equipada.get_nome() != "") {
        // Se já houver uma arma equipada, mova-a para a mochila antes de equipar a nova arma
        Item* item_para_mochila = dynamic_cast<Item*>(&arma_equipada);
        std::cout << "Guardando " << arma_equipada.get_nome() << " na mochila." << std::endl;
        mochila_personagem.ColocarItem(item_para_mochila);  // Coloca a arma antiga na mochila
    }
     Equipar_arma(arma_temp);
}

void Personagem::usa_pocao_mochila(){
    Pocao* pocao = nullptr;
    if(mochila_personagem.usar_pocao(pocao) != 0){
        std::cout << "Não foi possivel usar a poção" << std::endl;
        return;
    }

    mochila_personagem.usar_pocao(pocao);
    std::cout << pocao->get_cura();
    cura(pocao->get_cura());
    recupera_mana(pocao->get_mana());
}

float Personagem::exibe_vida_total(){
    return vida_Total;
}

int Personagem::exibe_mana_atual(){
    return mana_Atual;
}

int Personagem::exibe_mana_total(){
    return mana_Total;
}
#endif