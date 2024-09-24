#pragma once
#include "Item.h"
#include <string>

class Arma: public Item{
    public:
        Arma(std::string nome_item,float peso_item, std::string tipo_do_item, float dano,int nivel);
        Arma();
        float get_dano();
        std::string get_tipo();

    private:
        float dano;
};
