#include "Mochila.h"
#include <iostream>

using namespace std;

#ifndef MOCHILA_H
#define MOCHILA_H

Stack::Mochila() {
    top = NULL;// diferente do estatico, que colocamos o top, na posiçao zero, aqui na dinamica, iniciamos ele com NULL; "A pilha deve iniciar vazia, ou seja, top está “aterrado”"

};

Stack::~Mochila() {
    while (!empty()) {
        Pop(x);
    }
};

bool Stack::MochilaCheia() {
    return false; //não há limite quanto ao número máximo de elementos da pilha

};

bool Stack::MochilaVazia() {
    return (top == NULL);
};

int Stack::ColocarItem(int x) {
    MochilaPointer p; // criamos um ponteiro novo, p, que aponta para uma struct MochilaNode
    p = New MochilaNode; // alocamos esse "p" de forma dinamica
    if (p == Null) { // verificamos se ainda temos memoria para alocar
        cout << "Limite de memória excedido" << endl;
        abort();
    }
    p->Entry = x; //como o p esta apontando para MochilaNode, temos acesso ao Item, e NextNode. Usamos desse acesso, para guardar o valor "x" no Item
    p->NextNode = top; // e colocamos no NextNode, apontando para o mesmo lugar que o top estava antes, pro inicio da Mochila
    top = p; // o top agora passa a ser o que o p estava apontando, nesse caso o a struct, Mochila Node, que agora é o primeiro item da Mochila

};

int Stack::RetirarItem(int& x) {
    MochilaPointer p
        if (Empty()) {
            cout << "Mochila vazia!" << endl;
            abort();
        }
    x = top->Entry; // passamos o valor que esta no Item, para o x, com cópia, "&"
    p = top; // o ponteiro p que criamos, apontamos ele para onde o top esta apontando para nao perdemos, quando formos trocar o top
    top = top->NextNode; // apontas o top, para o NextNode, nesse caso o que estava em baixo do top anterior
    delete p;
};

int Stack::Size() {
    return top;
};

void Stack::LimparMochila() {// segue o mesmo Principio do RetirarItem(), porem, nesse caso, não guardamos o valor de Item em lugar nenhum
    MochilaPointer p;
    while (top != NULL) {
        p = top;
        top = top->NextNode;
        delete p;
    }

};

int Stack::ItemMochila(int& x) {

    if (top == NULL) {
        cout << "Mochila Vazia!!" << endl;
        abort();
    }
    x = top->Entry;
};


#endif
