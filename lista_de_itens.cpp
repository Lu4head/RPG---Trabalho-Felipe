#include "./classes/Arma.h"
#include "./classes/Pocao.h"
#include "./classes/equipamento.h"

// criando armas e pocao

// Arma Katana("Nikana", 1.5,"Arma",20,1);
// Arma Adaga("Kriss", 0.5, "Arma", 12,2);
// Arma Manopla("Atlas", 3.0,"Arma", 38,3); 
// Arma Machadinha("Loki", 0.1,"Arma",18,4);
// Arma Espada_curta("Espada Curta", 1, "Arma" , 5,5);
// // Arma Adaga_enferrujada("Adaga enferrujada", 0.3, "Arma", 3);
// // Arma Varinha_quebrada("Varinha quebrada", 0.1, "Arma", 7);

// Pocao pocao_de_cura_fraca("Pocao de cura fraca", 1.0,"Pocao", 15, 0,1);
// Pocao pocao_de_cura_media("Pocao de cura media", 1.5, "Pocao", 25, 0,2);
// Pocao pocao_de_cura_forte("Pocao de cuura forte", 2.5, "Pocao", 45, 0,3);


// Pocao pocao_de_mana_fraca("Pocao de mana fraca", 1.0,"Pocao",15,0);
// Pocao pocao_de_mana_media("Pocao de mana media", 1.5, "Pocao", 25, 0);
// Pocao pocao_de_mana_forte("Pocao de mana forte", 2.5, "Pocao", 45, 0);

Pocao pocao_vida_pequena("Poção de Vida Pequena", 0.5f, "Pocao", 50.0f,0, 1);  // Nível 1
Pocao pocao_vida_grande("Poção de Vida Grande", 1.0f, "Pocao", 150.0f, 0,3);  // Nível 3
Pocao pocao_mana_pequena("Poção de Mana Pequena", 0.3f, "Pocao", 0,30.0f ,1);  // Nível 1
Pocao pocao_mana_grande("Poção de Mana Grande", 0.8f, "Pocao", 0, 100.0f,3);  // Nível 3

Arma espada_curta("Espada Curta", 5.0f, "Arma", 15.0f, 1);    // Arma de nível 1
Arma adaga("Adaga", 2.0f, "Arma", 10.0f, 1);    // Arma de nível 1
Arma varinha_quebrada("Varinha Quebrada", 1.0f, "Arma", 15.0f, 1);    // Arma de nível 1
Arma machado_guerreiro("Machado de Guerreiro", 10.0f, "Arma", 25.0f, 2); // Arma de nível 2
Arma espada_longa("Espada Longa", 8.0f, "Arma", 40.0f, 4);    // Arma de nível 4
Arma arco_elfico("Arco Élfico", 3.5f, "Arma", 35.0f, 3);        // Arma de nível 3
Arma cajado_arcano("Cajado Arcano", 2.0f, "Arma", 60.0f, 5);  // Arma de nível 5, dano mágico


// Itens de nível 1
Arma* armas_inciais[] = {
    &espada_curta, &adaga, &varinha_quebrada
};

Item* itens_nivel_1[] = {
    &espada_curta, &pocao_vida_pequena, &pocao_mana_pequena
};

// Itens de nível 2
Item* itens_nivel_2[] = {
    &machado_guerreiro
};

// Itens de nível 3
Item* itens_nivel_3[] = {
&arco_elfico, &pocao_vida_grande,&pocao_mana_grande
};

int tamanho_itens_nivel_1 = sizeof(itens_nivel_1) / sizeof(itens_nivel_1[0]);
int tamanho_itens_nivel_2 = sizeof(itens_nivel_2) / sizeof(itens_nivel_2[0]);
int tamanho_itens_nivel_3 = sizeof(itens_nivel_3) / sizeof(itens_nivel_3[0]);