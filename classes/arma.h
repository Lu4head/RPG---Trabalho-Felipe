#include "Item.h"
#include <string>
using namespace std;

class Arma: public Item{
    public:

    Arma(string nome_item,float peso_item, float dano);

    private:

    float dano;
};  


