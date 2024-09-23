#include ".\classes\Personagem.h"
#include ".\classes\Arma.h"
#include ".\classes\Pocao.h"
#include <iostream>

#ifndef PERSONAGEM_H
#define PERSONAGEM_H

Personagem::Personagem(std::string nome): nome(nome){
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

int Personagem::gasta_mana(float x){
    if(mana_Atual - x < 0){
        std::cout << "Mana insuficiente" << std::endl;
        return 1;
    }
    else{
        mana_Atual = mana_Atual - x;
        return 0;
    }
};



float Personagem::exibe_vida(){
    return vida_Atual;
};

std::string Personagem::exibe_nome(){
    return nome;
}

void Personagem::aumenta_nivel() {
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


void Personagem::cura(float x) {
    if (vida_Atual + x < vida_Total) {
        vida_Atual = vida_Atual + x;
    } else {
        vida_Atual = vida_Total;
    }
    std::cout << "A vida atual agora é: " << vida_Atual << " / " << vida_Total << std::endl;
}

void Personagem::recupera_mana(float x){
    if(mana_Atual + x < mana_Total){
        mana_Atual = mana_Atual + x;
    } else {
        mana_Atual = mana_Total;
    }
}

void Personagem::usa_pocao() {
    Pocao* pocao = nullptr;
    cinto_personagem.usar_pocao(pocao);
    std::cout << pocao->get_cura();
    cura(pocao->get_cura());
    recupera_mana(pocao->get_cura());
}


void Personagem::Inserir_cinto(Item* item, int posicao){
     if (cinto_personagem.Colocar_item(item, posicao) == 0) {
            std::cout << item->get_nome() << " foi adicionado ao cinto!" << std::endl;
        } else {
            std::cout << "Cinto cheio ou não foi possível adicionar o item." << std::endl;
        }
    };



void Personagem::usar_item_cinto(int posicao){
    // cinto_personagem.usar_pocao();
}

void Personagem::mostrar_cinto(){
    cinto_personagem.mostrar_itens();
}

void Personagem::Equipar_arma(Arma* arma){
    arma_equipada = *arma;
}

void Personagem::trocar_arma(){
    Arma* arma_temp = nullptr;
    cinto_personagem.equipar_arma(arma_temp);
    Equipar_arma(arma_temp);
}

Arma Personagem::mostrar_arma_equipada(){
    return arma_equipada;
}

void Personagem::ganha_xp(int xp) {
    exp_atual += xp;
    while (exp_atual >= exp_total) {
        aumenta_nivel();  // Função que sobe o nível
        std::cout << "Parabéns! " << exibe_nome() << " subiu para o nível " << nivel << std::endl;
    }
}

int Personagem::get_nivel(){
    return nivel;
}


#endif