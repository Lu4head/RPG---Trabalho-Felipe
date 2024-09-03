#include "mochila.h"
#include <iostream>

using namespace std;

#ifndef STACK_H
#define STACK_H

Stack::Stack(){
    top = 0;
};

Stack::~Stack(){
    cout << "Pilha destruida." << endl;
};

bool Stack::Full(){
    return (top == MaxStackSize);
};

bool Stack::Empty(){
    return (top == 0);
};

int Stack::Push(int x){
    if(!Full()){
        top++;
        entry[top] = x;
        return 0;
    }
    else return -1; 
};

int Stack::Pop(int &x){
    if(!Empty()){
        x = entry[top];
        top--;
        return 0;
    }
    else return -1;
};


int Stack::Size(){
    return top;
};

void Stack::Clear(){
    top = 0;
};

int Stack::Top(int &x){
    if(!Empty()){
        x = entry[top];
        return 0;
    }
    else return -1;
};


#endif
