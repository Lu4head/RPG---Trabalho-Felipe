#include "./classes/Arma.h"
#include "./classes/Pocao.h"
#include "./classes/equipamento.h"

// criando armas e pocao

Arma Katana("Nikana", 1.5,"Arma",20);
Arma Adaga("Kriss", 0.5, "Arma", 12);
Arma Manopla("Atlas", 3.0,"Arma", 38); 
Arma Machadinha("Loki", 0.1,"Arma",18);
Arma Espada_curta("Espada Curta", 1, "Arma" , 5);
Arma Adaga_enferrujada("Adaga enferrujada", 0.3, "Arma", 3);
Arma Varinha_quebrada("Varinha quebrada", 0.1, "Arma", 7);


Pocao pocao_de_cura_fraca("Pocao de cura fraca", 1.0,"Pocao", 15, 0);
Pocao pocao_de_cura_media("Pocao de cura media", 1.5, "Pocao", 25, 0);
Pocao pocao_de_cura_forte("Pocao de cuura forte", 2.5, "Pocao", 45, 0);


Pocao pocao_de_mana_fraca("Pocao de mana fraca", 1.0,"Pocao",15,0);
Pocao pocao_de_mana_media("Pocao de mana media", 1.5, "Pocao", 25, 0);
Pocao pocao_de_mana_forte("Pocao de mana forte", 2.5, "Pocao", 45, 0);
