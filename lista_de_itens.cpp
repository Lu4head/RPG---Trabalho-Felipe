#include "./classes/Arma.h"
#include "./classes/Pocao.h"


// criando armas e pocao

Arma Katana("Nikana", 1.5, 20,"Destreza");
Arma Adaga("Kriss", 0.5, 12, "Destreza");
Arma Manopla("Atlas", 3.0, 38,"Forca"); 
Arma Machadinha("Loki", 0.1,18,"Forca");

Pocao pocao_de_cura_fraca("Pocao de cura fraca", 1.0,15,0,"Cura");
Pocao pocao_de_cura_media("Pocao de cura media", 1.5, 25, 0, "cura");
Pocao pocao_de_cura_forte("Pocao de cuura forte", 2.5, 45, 0, "cura");


Pocao pocao_de_mana_fraca("Pocao de mana fraca", 1.0,15,0,"mana");
Pocao pocao_de_mana_media("Pocao de mana media", 1.5, 25, 0, "mana");
Pocao pocao_de_mana_forte("Pocao de mana forte", 2.5, 45, 0, "mana");

