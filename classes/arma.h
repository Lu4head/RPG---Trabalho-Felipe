#pragma once
#include "Item.h"
#include <string>

class Arma: public Item{
    public:
        Arma(std::string nome_item,float peso_item, std::string tipo_do_item, float dano,int nivel, int custo_mana);
        Arma();
        float get_dano();
        int get_custo_mana();
        std::string get_tipo();

    private:
        float dano;
        int custo_mana;
};
