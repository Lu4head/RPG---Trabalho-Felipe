
#include "item.h"
#include <string>


class Arma: public Item{
    public:

    Arma(std::string nome_item,float peso_item, float dano, std::string tipo_da_arma);

    private:

    float dano;
    std::string tipo_da_arma;
};
