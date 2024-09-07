#include <string>

using namespace std;

class Item{
    public:
        Item();
        void CriaArma(string nome, string descricao, float peso, float damage);
        void CriaPocaoHP(string nome, string descricao, float peso, float cura );
        void CriaPocaoMP(string nome, string descricao, float peso, float mana);
        void CriaEscudo(string nome, string descricao, float peso, float def);
        void CriaMagica(string nome, string descricao, float peso, float mp_cost , float damage);
    private:
        string nome_item;
        string descricao_item;
        string tipo_item; // arma, pocao, magico
        float peso;
        float dano;
        float custo_de_mana;
        float defesa;
        int recuperacao_hp;
        int recuperacao_mana;
};