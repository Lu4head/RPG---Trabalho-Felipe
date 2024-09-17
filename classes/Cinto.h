#pragma once
#include "Item.h"
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
        void Colocar_item(Item item, int posicao);
        void Remover_item(Item &item_retorno, int posicao);
        // Operações Extras
        void Clear();
        void usar_item(int posicao); // usar ou remover item
        int espaco_disponivel(); // verificar se tem algum espaço disponivel 
        void mostrar_itens(); // Mostra todos os itens no cinto

    private:
        Item Entry[MaxList + 1];
        int peso_max;
        int count;
};