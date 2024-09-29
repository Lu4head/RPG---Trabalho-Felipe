//Luan Emanuel R. Argentato RA: 2184611
//Gustavo duzzi             RA: 2214047
//Guilherme Santos Gollino  RA: 2226090

#include "./classes/Monstro.h"
#include "./classes/mobs.h"

// Monstros de nível 1
Monstro Javali("Javali", 25.0, 25.0, 5.0, 6.0, 1);
Monstro Elfo_da_floresta("Elfo da Floresta", 20.0, 60.0, 12.0, 20.0, 1);
Monstro Goblin("Goblin", 15, 30, 10, 5, 1);       

// Monstros de nível 2
Monstro Soldado_do_forte("Soldado do Forte", 105.0, 70.0, 20.0, 15.0, 2);
Monstro Mago_de_luz("Mago de Luz", 90.0, 100.0, 10.0, 30.0, 2);
Monstro Soldado_decomposto("Soldado Decomposto", 80.0, 60, 35.0, 15.0, 2);

// Monstro de nível 3
Monstro Ogro("Ogro", 200, 30, 15, 5, 3);
Monstro Mimico("Baú Mimico", 210, 20, 5, 3);
Monstro Gargula("Gárgula", 220, 25, 22, 10, 3);

// Monstro de nível 4
Monstro Ciclope("Ciclope", 250, 45, 30, 35, 4);
Monstro Mago_das_sombras("Mago das Sombras", 140, 90, 20, 40, 4);
Monstro Lobisomem("Lobisomem", 260, 20, 25, 15, 4);

//Monstro de nível 5
Monstro Titan("Titan", 310, 50, 35, 20, 5);
Monstro Soldado_do_Rei("Soldado do Rei", 400, 30, 40, 25, 5);

//Monstro de nível 6
Monstro Cacador_de_recompensa("Caçador de Recompensa", 450, 50, 45, 50, 5);
Monstro Gigante("Gigante de aço", 480, 30, 50, 30, 5);

//Monstro de nível 7
Monstro Necromante("Necromante", 700, 420, 40, 60, 7);
Monstro Dragao("Dragão", 800, 200, 65, 50, 7); 
Monstro Mao_do_Rei("Mão do Rei", 750, 150, 60, 45, 7);


//Monstro de nível 8
Monstro ORei("O Rei", 5000, 1000, 80, 75, 8);





Monstro* monstro_nivel_1[] = {
    &Javali, &Elfo_da_floresta, &Goblin
};

Monstro* monstro_nivel_2[] = {
    &Soldado_do_forte, &Mago_de_luz, &Soldado_decomposto
};
Monstro* monstro_nivel_3[] = {
    &Ogro, &Mimico , &Gargula
};
Monstro* monstro_nivel_4[] = {
    &Ciclope, &Mago, &Lobisomem
}
Monstro* monstro_nivel_5[] = {
    &Titan, &Soldado_do_Rei
};
Monstro* monstro_nivel_6[] = {
    &cacador_de_recompensa, &Gigante
};
Monstro* monstro_nivel_7[] = {
    &Dragao, &Necromante, &Mao_do_Rei
};
Monstro* monstro_nivel_8[] = {
    &ORei
};



int tamanho_nivel_1 = sizeof(monstro_nivel_1) / sizeof(monstro_nivel_1[0]);
int tamanho_nivel_2 = sizeof(monstro_nivel_2) / sizeof(monstro_nivel_2[0]); 
int tamanho_nivel_3 = sizeof(monstro_nivel_3) / sizeof(monstro_nivel_3[0]);
int tamanho_nivel_4 = sizeof(monstro_nivel_4) / sizeof(monstro_nivel_4[0]);
int tamanho_nivel_5 = sizeof(monstro_nivel_5) / sizeof(monstro_nivel_5[0]);
int tamanho_nivel_6 = sizeof(monstro_nivel_6) / sizeof(monstro_nivel_6[0]);
int tamanho_nivel_7 = sizeof(monstro_nivel_7) / sizeof(monstro_nivel_7[0]);
int tamanho_nivel_8 = sizeof(monstro_nivel_8) / sizeof(monstro_nivel_8[0]);
