// Arquivo de definição da Classe Stack
// Definir o tamanho máximo da pilha
#pragma once
//Tamanho máximo da pilha
const int MaxStackSize = 100;

class Stack{
    //* Métodos *//
    public:
        //Construtor - Garante que sua Stack (pilha) começe vazia
        Stack();

        //Destrutor - é desnecessário caso não haja alocação dinâmica de memória
        ~Stack();

        //Status
        bool Full();
        bool Empty();

        //Operações básicas
        int Push(int x);
        int Pop(int &x);

        //Outras Operações (Clear,Top,Size)
        int Size();
        void Clear();
        int Top(int &x); // Retorna o elemento do topo da pilha
        
    //* Campos de dados *//
    private:
        //Vetor que armazena os elementos da pilha
        int entry[MaxStackSize + 1]; // MaxStackSize + 1 pois o índice 0 não é utilizado

        //Posição topo da pilha
        int top;
};