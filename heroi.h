#include <string>
#include "Mochila.cpp"
#include "Cinta.cpp"

using namespace std;

class Heroi{
    public:
    private:
        string nome;
        int vida_Total;
        int vida_Atual;
        int mana_Total;
        int mana_Atual;
        Stack Mochila;
        List Cinta;
};