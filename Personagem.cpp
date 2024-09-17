#include ".\classes\Personagem.h"
#include <iostream>

#ifndef PERSONAGEM_H
#define PERSONAGEM_H

Personagem::Personagem(string nome){
    nome = this->nome;
    vida_Total = 100;
    vida_Atual = vida_Total;
    mana_Total = 100;
    mana_Atual = mana_Total;
    nivel = 1;
    exp_total = 100;
    exp_atual = 0;
};

Personagem::~Personagem(){};

void Personagem::recebe_dano(float x){
    if(vida_Atual - x > 0){
        vida_Atual = vida_Atual - x;
    } else{
        vida_Atual = 0;
    }
};

void Personagem::gasta_mana(int x){
    if(mana_Atual - x < 0){
        std::cout << "Mana insuficiente" << std::endl;
        return;
    }
    else{
        mana_Atual = mana_Atual - x;
    }
};

void Personagem::transfere_para_mochila(Item &x, int p){
    Item item_transferido;
    cinto_personagem.Remover_item(item_transferido, p);
    mochila_personagem.ColocarItem(item_transferido);
};

void Personagem::transfere_para_cinto(Item &x, int p){
    Item item_transferido;
    mochila_personagem.RetirarItem(item_transferido);
    cinto_personagem.Colocar_item(item_transferido,p);
}

void Personagem::exibe_vida(float &x){
    x = vida_Atual;
    std::cout << "Vida: " << vida_Atual << " / " << vida_Total << std::endl;
};

void Personagem::aumenta_nivel(){
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
};

#endif