#include <string>
#include "Mochila.cpp"
#include "Cinta.h"
#include "Item.cpp"

using namespace std;

class Heroi{
    public:
        void define_nome(string x);
        void define_vida(int x);
        void recebe_dano(int x);
        void define_mana(int x);
        void gasta_mana(int x);
        void transfere_para_mochila(Item x);
        void transfere_para_cinta(Item x);
    private:
        string nome;
        int vida_Total;
        int vida_Atual;
        int mana_Total;
        int mana_Atual;
        Mochila Mochila;
        List Cinta;
};