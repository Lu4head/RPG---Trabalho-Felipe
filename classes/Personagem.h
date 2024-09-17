#pragma once
#include <string>
#include "Mochila.h"
#include "Cinto.h"
#include "Item.h"

using namespace std;

class Personagem{
    public:
        Personagem(string nome);
        ~Personagem();
        void recebe_dano(float x);
        void gasta_mana(int x);
        void transfere_para_mochila(Item &x, int p);
        void transfere_para_cinto(Item &x, int p);
        void exibe_vida(float &x);
        void aumenta_nivel();
        Mochila mochila_personagem;
        Cinto cinto_personagem;
    private:
        string nome;
        float vida_Total;
        float vida_Atual;
        int mana_Total;
        int mana_Atual;
        int nivel;
        int exp_total;
        int exp_atual;    
};