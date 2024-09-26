#include "./classes/Mochila.h"

#include <iostream> // Biblioteca para entrada e saída de dados


#ifndef MOCHILA_H
#define MOCHILA_H

Mochila::Mochila() { // Construtor da Mochila
    top = NULL;// diferente do estatico, que colocamos o top, na posiçao zero, aqui na dinamica, iniciamos ele com NULL; "A pilha deve iniciar vazia, ou seja, top esta aterrado"
};

bool Mochila::MochilaVazia() { // Verifica se a Mochila está vazia
    return (top == NULL);
};

int Mochila::ColocarItem(Item* x) { // Coloca um item na Mochila
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

int Mochila::RetirarItem(Item* &x) { // Retira um item da Mochila
    MochilaPointer p;
    if (MochilaVazia()) { // verificamos se a mochila esta vazia
        std::cout << "Mochila vazia!" << std::endl;
        return 1;
    }
    x = top->Entry; // passamos o valor que esta no Item, para o x, com c�pia, "&"
    p = top; // o ponteiro p que criamos, apontamos ele para onde o top esta apontando para nao perdemos, quando formos trocar o top
    top = top->NextNode; // apontas o top, para o NextNode, nesse caso o que estava em baixo do top anterior
    delete p; // deletamos o p, que era o top anterior, e agora � um item que foi retirado
    return 0;
};


int Mochila::LimparMochila() {// segue o mesmo Principio do RetirarItem(), porem, nesse caso, n�o guardamos o valor de Item em lugar nenhum
    MochilaPointer p; 
    if(MochilaVazia()){ // verificamos se a mochila esta vazia
        std::cout << "A mochila já esta vazia!" << std::endl;
        return 1;
    }
    while (!MochilaVazia()) { // enquanto a mochila n�o estiver vazia, retiramos o item
        p = top;
        top = top->NextNode;
        delete p;
    }
    return 0;
};

int Mochila::ItemMochila(Item* &x) { // Retorna o elemento do topo da Mochila
    if (top == NULL) { // verificamos se a mochila esta vazia
        std::cout << "Mochila Vazia!!" << std::endl;
        return 1;
    }
    x = top->Entry; // passamos o valor que esta no Item, para o x, com c�pia, "&"
    return 0;
};

Mochila::~Mochila() { // Destrutor da Mochila
    Item* x;
    while (!MochilaVazia()) { // enquanto a mochila n�o estiver vazia, retiramos o item
        RetirarItem(x);
    }
};

int Mochila::usar_pocao(Pocao* &pocao){
    if(MochilaVazia()){// verifica se a mochila está vazia
        std::cout << "Mochila sem itens!" << std::endl;
        return 1;
    }
    
    std::string tipo = top->Entry->get_tipo_do_item();
    
    if(tipo != "Pocao"){
        std::cout << "O item não é uma poção!" << std::endl;
        return 2;
    }

    std::cout << "Utilizando o item" << top->Entry->get_nome() << std::endl;
    pocao = dynamic_cast<Pocao*>(top->Entry);
    Item* item_temp;
    RetirarItem(item_temp);
    return 0;
}

int Mochila::equipar_arma(Arma* &arma_equipada){
    if(MochilaVazia()){// verifica se a mochila está vazia
        std::cout << "Mochila sem itens!" << std::endl;
        return 1;
    }

    std::string tipo = top->Entry->get_tipo_do_item();

    if(tipo != "Arma"){
        std::cout << "O item não é uma arma!" << std::endl;
        return 2;
    }

    Arma* arma = dynamic_cast<Arma*>(top->Entry);

    std::cout << arma->get_nome() << " - Dano: " << arma->get_dano() << std::endl;
}


#endif
