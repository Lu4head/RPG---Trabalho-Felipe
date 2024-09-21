#include "./classes/Arma.h"
#include "./classes/Pocao.h"
#include "./classes/equipamento.h"

// criando armas e pocao

Arma Katana("Nikana", 1.5,"Destreza",20);
Arma Adaga("Kriss", 0.5, "Destreza", 12);
Arma Manopla("Atlas", 3.0,"Forca", 38); 
Arma Machadinha("Loki", 0.1,"Forca",18);
Arma Espada_curta("Espada Curta", 1, "Forca" , 5);
Arma Adaga_enferrujada("Adaga enferrujada", 0.3, "Destreza", 3);
Arma Varinha_quebrada("Varinha quebrada", 0.1, "Magica", 7);


Pocao pocao_de_cura_fraca("Pocao de cura fraca", 1.0,"cura", 15, 0);
Pocao pocao_de_cura_media("Pocao de cura media", 1.5, "cura", 25, 0);
Pocao pocao_de_cura_forte("Pocao de cuura forte", 2.5, "cura", 45, 0);


Pocao pocao_de_mana_fraca("Pocao de mana fraca", 1.0,"mana",15,0);
Pocao pocao_de_mana_media("Pocao de mana media", 1.5, "mana", 25, 0);
Pocao pocao_de_mana_forte("Pocao de mana forte", 2.5, "mana", 45, 0);
