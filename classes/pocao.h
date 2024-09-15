#include "Item.h"
#include <string>

class Pocao: public Item{
    public:
        Pocao(std::string nome_item, float peso_item, float cura,float mana,std::string tipo_da_pocao);

    private:

        float cura;
        float mana;
        std::string tipo_da_pocao;


};