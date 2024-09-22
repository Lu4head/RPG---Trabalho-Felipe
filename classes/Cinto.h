#pragma once
#include "Item.h"
#include "pocao.h"
#include "arma.h"
const int MaxList = 9;

class Cinto{
    public:
        // Construtor e destrutor  
        Cinto();
        ~Cinto();

        // Status
        bool Cinto_vazio();
        bool Cinto_cheio();

        // Operações Básicas
        int Colocar_item(Item* item, int posicao);
        int Remover_item(Item* &item_retorno, int posicao);

        // Operações Extras
        int Esvaziar_cinto();
        int usar_pocao(Pocao* &pocao); // usar ou remover item
        int espacos_disponiveis(); // verificar se tem algum espaço disponivel 
        int mostrar_itens(); // Mostra todos os itens no cinto
        void definir_capacidade(int x); // Define a capacidade de peso do cinto
        int equipar_arma(Arma* &arma);
    private:
        Item* Entry[MaxList + 1];;
        int peso_max;
        int peso_ocupado;
        int count;
};