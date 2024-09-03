// Arquivo de definição da Classe Stack
// Definir o tamanho máximo da pilha
#pragma once
#include "Item.cpp"
//Tamanho máximo da pilha

class Mochila {
    //* Métodos *//
public:
    //Construtor - Garante que sua Stack (pilha) começe vazia
    Mochila();

    //Destrutor - Como utilizaremos alocação dinâmica, faremos implementação do destrutor.
    ~Mochila();

    //Status
    bool MochilaCheia();
    bool MochilaVazia();

    //Operações básicas
    int ColocarItem(Item x);
    int RetirarItem(Item& x);

    //Outras Operações (Clear,Top,Size)
    //int Size();
    void LimparMochila();
    int ItemMochila(Item& x); // Retorna o elemento do topo da Mochila

    //* Campos de dados *//
private:
    //Struct que armazena os elementos da Mochila
    struct MochilaNode {
        Item Entry;// AJUSTAR, COLOCAR O ITEM COMO TIPO;
        MochilaNode* NextNode; //// ligação para próximo elemento na Mochila // um ponteiro (NextNode) do tipo Struct(MochilaNode)
    };
    typedef MochilaNode* MochilaPointer;

    //Posição topo da pilha
    MochilaPointer top;
};