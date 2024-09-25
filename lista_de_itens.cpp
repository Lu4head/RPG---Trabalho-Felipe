#include "./classes/Arma.h"
#include "./classes/Pocao.h"
#include "./classes/equipamento.h"

// criando armas e pocoes

Pocao pocao_vida_pequena("Poção de Vida Pequena", 0.5f, "Pocao", 50.0f,0, 1);  // Nível 1
Pocao pocao_vida_grande("Poção de Vida Grande", 1.0f, "Pocao", 150.0f, 0,3);  // Nível 3
Pocao pocao_mana_pequena("Poção de Mana Pequena", 0.3f, "Pocao", 0,30.0f ,1);  // Nível 1
Pocao pocao_mana_grande("Poção de Mana Grande", 0.8f, "Pocao", 0, 100.0f,3);  // Nível 3

Arma espada_curta("Espada Curta", 5.0f, "Arma", 15.0f, 1, 0);    // Arma de nível 1
Arma adaga("Adaga", 2.0f, "Arma", 10.0f, 1, 0);    // Arma de nível 1
Arma varinha_quebrada("Varinha Quebrada", 1.0f, "Arma", 15.0f, 1, 5);    // Arma de nível 1
Arma machado_guerreiro("Machado de Guerreiro", 10.0f, "Arma", 25.0f, 2, 0); // Arma de nível 2
Arma espada_longa("Espada Longa", 8.0f, "Arma", 40.0f, 4, 0);    // Arma de nível 4
Arma arco_elfico("Arco Élfico", 3.5f, "Arma", 35.0f, 3, 0);        // Arma de nível 3
Arma cajado_arcano("Cajado Arcano", 2.0f, "Arma", 60.0f, 5, 0);  // Arma de nível 5, dano mágico


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