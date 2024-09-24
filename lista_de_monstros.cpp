#include "./classes/Monstro.h"
#include "./classes/mobs.h"


Monstro Orgro("Orgro", 10.0, 50.0, 20.0, 10.0, 1);
Monstro Elfo_da_floresta("Elfo da Floresta", 10.0, 60.0, 15.0, 25.0, 1);

// Monstros de nível 2
Monstro Soldado_do_forte("Soldado do Forte", 120.0, 70.0, 25.0, 15.0, 2);
Monstro Mago_de_luz("Mago de Luz", 90.0, 100.0, 10.0, 35.0, 2);




// Monstro goblin("Goblin", 100, 30, 10, 5, 1);       // Monstro de nível 1
// Monstro ogro("Ogro", 300, 50, 30, 10, 3);          // Monstro de nível 3
// Monstro dragao("Dragão", 1000, 200, 80, 50, 7);    // Monstro de nível 7
// Monstro necromante("Necromante", 500, 500, 40, 100, 8); // Monstro de nível 8, foco em dano mágico

Monstro* monstro_nivel_1[] = {
    &Orgro, &Elfo_da_floresta
};

Monstro* monstro_nivel_2[] = {
    &Soldado_do_forte, &Mago_de_luz
};


int tamanho_nivel_1 = sizeof(monstro_nivel_1) / sizeof(monstro_nivel_1[0]);
int tamanho_nivel_2 = sizeof(monstro_nivel_2) / sizeof(monstro_nivel_2[0]);