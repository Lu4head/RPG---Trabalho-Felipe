#pragma once
#include <string>
#include "Mochila.h"
#include "Cinto.h"
#include "Item.h"
#include "arma.h"
#include "pocao.h"

class Personagem{
    public:
        Personagem(std::string nome);
        ~Personagem();
        void recebe_dano(float x);
        int gasta_mana(float x);
        void usa_pocao();
        void cura(float x);
        void recupera_mana(float x);
        void transfere_para_mochila(Item* x, int p);
        void transfere_para_cinto(Item& x, int p);
        float exibe_vida();
        std::string exibe_nome();
        void aumenta_nivel();
        void Equipar_arma(Arma* arma);
        Arma mostrar_arma_equipada();
        void trocar_arma();
        void Inserir_cinto(Item* item, int posicao);
        void usar_item_cinto(int posicao);
        void mostrar_cinto(); 
        
    private:
        std::string nome;
        float vida_Total;
        float vida_Atual;
        int mana_Total;
        int mana_Atual;
        int nivel;
        int exp_total;
        int exp_atual;  
        Arma arma_equipada;
        Cinto cinto_personagem; 
        Mochila mochila_personagem; 

};