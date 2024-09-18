#pragma once
#include "Item.h"
#include "Personagem.h"
#include <string>

class Pocao: public Item{
    public:
        Pocao(std::string nome_item, float peso_item, float cura,float mana,std::string tipo_da_pocao);
        std::string get_tipo_do_item();
        void usa_pocao(Personagem personagem);

    private:
        float cura;
        float mana;
        std::string tipo_da_pocao;


};