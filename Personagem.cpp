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

void Personagem::transfere_para_mochila(Item &x, int p){
    if(cinto_personagem.Remover_item(x, p) != 0){
        std::cout << "Não foi possivel transferir o item" << std::endl;
        return;
    }
    if(mochila_personagem.ColocarItem(x) != 0){
        cinto_personagem.Colocar_item(x, p);
        std::cout << "Não foi possivel trasferir o item" << std::endl;
        return;
    }
};

void Personagem::transfere_para_cinto(Item &x, int p){
    if(mochila_personagem.RetirarItem(x) != 0){
        std::cout << "Não foi possivel transferir o item" << std::endl;
        return;
    }
    if(cinto_personagem.Colocar_item(x,p) != 0){
        mochila_personagem.ColocarItem(x);
        std::cout << "Não foi possivel trasferir o item" << std::endl;
        return;
    }
}

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
    Pocao pc = Pocao("Pocao", 0, "cura", 0, 0);
    cinto_personagem.usar_pocao(pc);
    cura(pc.get_cura());
    recupera_mana(pc.get_mana());
}

Arma Personagem::arma_equipada(){
Arma Katana("Nikana", 1.5,"Destreza", 20);
Arma Adaga("Kriss", 0.5, "Destreza", 12);
Arma Manopla("Atlas", 3.0,"Forca", 38); 
Arma Machadinha("Loki", 0.1,"Forca",18);
return Katana;
}

void Personagem::Inserir_cinto(Item& item, int posicao){
     if (cinto_personagem.Colocar_item(item, posicao) == 0) {
            std::cout << item.get_nome() << " foi adicionado ao cinto!" << std::endl;
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


#endif