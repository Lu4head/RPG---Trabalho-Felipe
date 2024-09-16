#pragma once
#include <string>
#include "Mochila.h"
#include "Cinto.h"
#include "Item.h"

using namespace std;

class Personagem{
    public:
        void define_nome(string x);
        void define_vida(int x);
        void recebe_dano(int x);
        void define_mana(int x);
        void gasta_mana(int x);
        void transfere_para_mochila(Item x);
        void transfere_para_cinto(Item x);
        void exibe_vida(int &x);
        Mochila Mochila;
        Cinto Cinto;
    private:
        string nome;
        int vida_Total;
        int vida_Atual;
        int mana_Total;
        int mana_Atual;
        int nivel;
        int exp_total;
        int exp_atual;    
};