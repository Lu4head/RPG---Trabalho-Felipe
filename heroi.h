#include <string>
#include <Mochila.cpp>
#include <Cinta.cpp>

using namespace std;

class Heroi{
    public:
        void define_nome(string x);
        void adiciona_item_mochila();
        void remove_item_mochila();
        void adiciona_item_cinta();
        void remove_item_cinta();

    private:
        string nome;
        int pontos_de_vida;
        int dano;
        int esquiva;
        Stack mochila;
        List cinta;
};