//Luan Emanuel R. Argentato RA: 2184611
//Gustavo duzzi             RA: 2214047
//Guilherme Santos Gollino  RA: 2226090

#include "./classes/Arma.h"
#include "./classes/Pocao.h"
#include "./classes/equipamento.h"

// criando armas e pocoes

Pocao pocao_vida_pequena("Poção de Vida Pequena", 0.5f, "Pocao", 50.0f,0, 1);    // Nível 1
Pocao pocao_mana_pequena("Poção de Mana Pequena", 0.3f, "Pocao", 0, 30.0f, 1);  // Nível 1
Pocao pocao_vida_media("Poção de Vida Média", 0.75f, "Pocao", 100.0f, 0, 2);    // Nível 2
Pocao pocao_mana_media("Poção de Mana Média", 0.55f, "Pocao", 0, 70.0f, 2);  // Nível 2
Pocao pocao_vida_grande("Poção de Vida Grande", 1.0f, "Pocao", 150.0f, 0, 3);    // Nível 3
Pocao pocao_mana_grande("Poção de Mana Grande", 0.8f, "Pocao", 0, 100.0f,3);  // Nível 3

Arma espada_curta("Espada Curta", 5.0f, "Arma", 15.0f, 1, 0);                            // Arma de nível 1
Arma adaga("Adaga", 2.0f, "Arma", 10.0f, 1, 0);                                         // Arma de nível 1
Arma varinha_quebrada("Varinha Quebrada", 1.0f, "Arma", 15.0f, 1, 5);                  // Arma de nível 1
Arma machado_guerreiro("Machado de Guerreiro", 10.0f, "Arma", 25.0f, 2, 0);           // Arma de nível 2
Arma rapieira("Rapieira", 5.0f, "Arma", 25.0f, 2, 0);                                // Arma de nível 2
Arma machado_açougueiro("Machado do Açougueiro", 11.0f, "Arma", 27.0f, 2, 0);       // Arma de nível 2
Arma arco_elfico("Arco Élfico", 4.5f, "Arma", 40.0f, 3, 0);                        // Arma de nível 3
Arma espada_bastarda("Espada Bastarda", 6.5f, "Arma", 42.0f, 3, 0);               // Arma de nível 3 
Arma adaga_bandido("Adaga de Bandido", 3.5f, "Arma", 35.0f, 3, 0);               // Arma de nível 3
Arma espada_longa("Espada Longa", 8.0f, "Arma", 50.0f, 4, 0);                   // Arma de nível 4
Arma espada_encantanda("Espada Encantada", 8.0f, "Arma", 60.0f, 4, 15);        // Arma de nível 4
Arma machado_honrado("Machado do Honrado", 12.0, "Arma", 55.0f, 4, 0);        // Arma de nível 4  
Arma cajado_arcano("Cajado Arcano", 2.0f, "Arma", 70.0f, 5, 25);             // Arma de nível 5, dano mágico
Arma espada_vanguarda("Espada da Vanguarda", 7.5f, "Arma", 80.0f, 5, 0);    // Arma de nível 5
Arma machado_do_golem("Machado do Golem", 15.0f, "Arma", 105.0f , 6, 0);    // Arma de nível 6
Arma adaga_umbral("Adaga Umbral", 8.0f, "Arma", 90.0f, 6, 0);             // Arma de nível 6
Arma adaga_tesouro("Caçadora de Tesouros", 10.0f, "Arma", 125.0f, 7, 0); // Arma de nível 7
Arma espada_ouro("Corrida do ouro", 12.0f, "Arma", 130.0f, 7, 0);       // Arma de nível 7
Arma cajado_criacao("Cajado da Criação", 8.0f, "Arma", 125.0f, 7, 55); // Arma de nível 7
Arma machado_dragao("Dente de Dragão", 20.0f, "Arma", 150.0f, 7, 0);  // Arma de nível 7 
Arma espada_desejo("A vontade do Rei", 20.0f, "Arma", 725.0f, 8, 50) // Arma de nível 8

// Itens de nível 1
Arma* armas_inciais[] = {
    &espada_curta, &adaga, &varinha_quebrada
};

Item* itens_nivel_1[] = {
    &espada_curta, &pocao_vida_pequena, &pocao_mana_pequena
};

// Itens de nível 2
Item* itens_nivel_2[] = {
    &machado_guerreiro, &rapieira, &machado_açougueiro, &pocao_vida_media, &pocao_mana_media
};

// Itens de nível 3
Item* itens_nivel_3[] = {
&arco_elfico, &pocao_vida_grande,&pocao_mana_grande, &espada_bastarda, &adaga_bandido
};

//Itens de nível 4
Item* itens_nivel_4[] = {
    &espada_longa, &espada_encantanda, &machado_honrado
};

//Itens de nível 5
Item* itens_nivel_5[] =
{
    &cajado_arcano, &espada_vanguarda
};
//Itens de nível 6
Item* itens_nivel_6[] =
{
    &machado_do_golem, &adaga_umbral
};
//Itens de nível 7
Item* itens_nivel_7[] =
{
    &adaga_tesouro, &espada_ouro, &cajado_criacao, &machado_dragao
};

//Itens de nível 8
Item* itens_nivel_8[] =
{
    &espada_desejo
};

int tamanho_itens_nivel_1 = sizeof(itens_nivel_1) / sizeof(itens_nivel_1[0]);
int tamanho_itens_nivel_2 = sizeof(itens_nivel_2) / sizeof(itens_nivel_2[0]);
int tamanho_itens_nivel_3 = sizeof(itens_nivel_3) / sizeof(itens_nivel_3[0]);
int tamanho_itens_nivel_4 = sizeof(itens_nivel_4) / sizeof(itens_nivel_4[0]);
int tamanho_itens_nivel_5 = sizeof(itens_nivel_5) / sizeof(itens_nivel_5[0]);
int tamanho_itens_nivel_6 = sizeof(itens_nivel_6) / sizeof(itens_nivel_6[0]);
int tamanho_itens_nivel_7 = sizeof(itens_nivel_7) / sizeof(itens_nivel_7[0]);
int tamanho_itens_nivel_8 = sizeof(itens_nivel_8) / sizeof(itens_nivel_8[0]);
