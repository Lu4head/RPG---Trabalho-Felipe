#pragma once
#include "Item.h"
#include <string>

class Arma: public Item{
    public:
        Arma(std::string nome_item,float peso_item, float dano, std::string tipo_da_arma);
        float get_dano();
        std::string get_tipo();

    private:
        float dano;
        std::string tipo_da_arma;
};
