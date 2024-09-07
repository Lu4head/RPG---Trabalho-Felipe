#include ".\classes\Cinto.h"
#include <iostream>


using namespace std;

#ifndef LIST_H
#define LIST_H

Cinto::Cinto(){
    count = 0;
}

Cinto::~Cinto(){
    cout << "Lista Destruida!" << endl;
}

bool Cinto::Empty(){
    return count == 0;
}

bool Cinto::Full(){
    return count == MaxList;
}

void Cinto::Insert(Item item, int posicao){
    if(Full()){
        cout << "Lista cheia! Sem espaco para novo elemento!" << endl;
        abort();
    }
    if(posicao < 1 || posicao > count + 1){
        cout << "Posicao Invalida!" << endl;
        abort();
    }
    for(int i = count ; i >= posicao ; i--){    
        Entry [ i + 1 ] = Entry[i];
    }
    Entry[posicao] = item;
    count++;
};

void Cinto::Delete(Item &item_retorno, int posicao){
    if(Empty()){
        cout << "Lista vazia! nao ha elementos para serem removidos!" << endl;
        abort();
    }
    if(posicao < 1 || posicao > count){
        cout << "Posicao Invalida!" << endl;
        abort();
    }
    item_retorno = Entry[posicao];
    for(int i = posicao; i < count; i++){
        Entry[i] = Entry[i + 1];
    }
    count--;
};

int Cinto::Size(){
    return count;
};

void Cinto::Clear(){
    count = 0;
    /* ...ou...
    int x;
    while(!Empty()){
        Delete(x, count);
    }
    */
};

void Cinto::Retrieve(Item &item_retorno, int posicao){
    if(posicao < 1 || posicao > count){
        cout << "Posicao Invalida!" << endl;
        abort();
    }
    item_retorno = Entry[posicao];
};

void Cinto::Replace(Item item, int posicao){
    if(posicao < 1 || posicao > count){
        cout << "Posicao Invalida!" << endl;
        abort();
    }
    Entry[posicao] = item;
};


#endif