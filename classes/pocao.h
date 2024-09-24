#pragma once
#include "Item.h"
#include <string>

class Pocao: public Item{
    public:
        Pocao(std::string nome_item, float peso_item, std::string tipo_do_item, float cura,float mana,int nivel);
        float get_cura();
        float get_mana();
        void usar();
        Pocao();
    private:
        float cura;
        float mana;


};