#include ".\classes\Item.h"
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
        int Size();
        void Clear();
        void Retrieve(Item &item, int posicao);
        void Replace(Item item_retorno, int posicao);
    private:
        Item Entry[MaxList + 1];
        int count;
};