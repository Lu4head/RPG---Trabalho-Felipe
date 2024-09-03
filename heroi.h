#include <string>
#include "Mochila.cpp"
#include "Cinta.h"

using namespace std;

class Heroi{
    public:
        void define_nome(string x);
        void adiciona_item_mochila();
        void adiciona_item_cinta();
    private:
        string nome;
        int vida_Total;
        int vida_Atual;
        int mana_Total;
        int mana_Atual;
        Stack Mochila;
        List Cinta;
};