#pragma once
#include "Item.h"

class Mochila {
    //* Métodos *//
public:
    Mochila();
    ~Mochila();

    bool MochilaVazia();

    int ColocarItem(Item x);
    int RetirarItem(Item& x);

    int LimparMochila();
    int ItemMochila(Item& x); // Retorna o elemento do topo da Mochila

    //* Campos de dados *//
private:
    //Struct que armazena os elementos da Mochila
    struct MochilaNode {
        Item Entry;
        MochilaNode* NextNode; // ligação para próximo elemento na Mochila // um ponteiro (NextNode) do tipo Struct(MochilaNode)
    };
    typedef MochilaNode* MochilaPointer;

    MochilaPointer top; // Posição topo da mochila
};