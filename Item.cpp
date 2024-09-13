<<<<<<< HEAD
#include ".\classes\arma.h"
#include <iostream>
#include <string>
using namespace std;


#ifndef ARMA_H
#define ARMA_H

Arma::Arma(string nome_item,float peso_item, float dano) : Item(nome_item,peso_item), dano(dano){
    cout << "Sua espada: ";
}



#endif
=======
#include "Item.h"

Item::Item(){
    
}
>>>>>>> 493b08574ab6565e87176b67fb0f14161663a959
