#include "item.h"
const int MaxList = 9;

class Cinto{
    public:
        // Construtor e destrutor  
        Cinto();
        ~Cinto(); // O proprio compilador se encarrega de destruir se esse não for criado
        // Status
        bool Empty();
        bool Full();
        // Operações Básicas
        void Insert(Item item, int posicao);
        void Delete(Item &item_retorno, int posicao);
        // Operações Extras
        void Clear();
        void usar_item(int posicao); // usar ou remover item
        int espaco_disponivel(); // verificar se tem algum espaço disponivel 
        void mostrar_itens(); // Mostra todos os itens no cinto

    private:
        Item Entry[MaxList + 1];
        int count;
};