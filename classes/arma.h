#include "Item.h"
#include <string>
using namespace std;

class Arma: public Item{
    public:

    Arma(string nome_item,float peso_item, float dano, string tipo_da_arma);

    private:

    float dano;
    std::string tipo_da_arma;
};
