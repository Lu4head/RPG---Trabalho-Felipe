#pragma once // pragma once para não espelhar os arquivos importados

#include "Item.h" 
#include "arma.h"
#include "pocao.h"
class Mochila {
    public: // Metodos publicos
        Mochila(); // Construtor padrão para Mochila
        ~Mochila(); // Destrutor padrão para Mochila

        bool MochilaVazia(); // Verifica se a Mochila está vazia

        int ColocarItem(Item* x); // Coloca um item na Mochila
        int RetirarItem(Item* &x); // Retira um item da Mochila

        int LimparMochila(); // Retira todos os itens da mochila
        int ItemMochila(Item* &x); // Retorna o elemento do topo da Mochila
        int equipar_arma(Arma* &arma); // Seta a arma no slot de uso do heroi
        int usar_pocao(Pocao* &pocao); // usar ou remover item, passado 
    private: // Atributos
        //Struct que armazena os elementos da Mochila
        struct MochilaNode {
            Item* Entry; // Ponteiro para o item na Mochila
            MochilaNode* NextNode; // ligação para próximo elemento na Mochila // um ponteiro (NextNode) do tipo Struct(MochilaNode)
        };
        typedef MochilaNode* MochilaPointer; // Definição de um ponteiro para a struct MochilaNode

        MochilaPointer top; // Posição topo da mochila
};