#include "./classes/Mochila.h"
#include <iostream>


#ifndef MOCHILA_H
#define MOCHILA_H

Mochila::Mochila() {
    top = NULL;// diferente do estatico, que colocamos o top, na posi�ao zero, aqui na dinamica, iniciamos ele com NULL; "A pilha deve iniciar vazia, ou seja, top est� �aterrado�"
};

bool Mochila::MochilaVazia() {
    return (top == NULL);
};

int Mochila::ColocarItem(Item* x) {
    MochilaPointer p; // criamos um ponteiro novo, p, que aponta para uma struct MochilaNode
    p = new MochilaNode; // alocamos esse "p" de forma dinamica
    if (p == NULL) { // verificamos se ainda temos memoria para alocar
        std::cout << "Limite de memoria excedido" << std::endl;
        return 1;
    }
    p->Entry = x; //como o p esta apontando para MochilaNode, temos acesso ao Item, e NextNode. Usamos desse acesso, para guardar o valor "x" no Item
    p->NextNode = top; // e colocamos no NextNode, apontando para o mesmo lugar que o top estava antes, pro inicio da Mochila
    top = p; // o top agora passa a ser o que o p estava apontando, nesse caso o a struct, Mochila Node, que agora � o primeiro item da Mochila
    return 0;
};

int Mochila::RetirarItem(Item* &x) {
    MochilaPointer p;
    if (MochilaVazia()) {
        std::cout << "Mochila vazia!" << std::endl;
        return 1;
    }
    x = top->Entry; // passamos o valor que esta no Item, para o x, com c�pia, "&"
    p = top; // o ponteiro p que criamos, apontamos ele para onde o top esta apontando para nao perdemos, quando formos trocar o top
    top = top->NextNode; // apontas o top, para o NextNode, nesse caso o que estava em baixo do top anterior
    delete p;
    return 0;
};


int Mochila::LimparMochila() {// segue o mesmo Principio do RetirarItem(), porem, nesse caso, n�o guardamos o valor de Item em lugar nenhum
    MochilaPointer p;
    if(MochilaVazia()){
        std::cout << "A mochila já esta vazia!" << std::endl;
        return 1;
    }
    while (!MochilaVazia()) {
        p = top;
        top = top->NextNode;
        delete p;
    }
    return 0;
};

int Mochila::ItemMochila(Item* &x) {
    if (top == NULL) {
        std::cout << "Mochila Vazia!!" << std::endl;
        return 1;
    }
    x = top->Entry;
    return 0;
};

Mochila::~Mochila() {
    Item* x;
    while (!MochilaVazia()) {
        RetirarItem(x);
    }
};


#endif
