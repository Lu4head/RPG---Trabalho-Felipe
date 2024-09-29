//Luan Emanuel R. Argentato RA: 2184611
//Gustavo duzzi             RA: 2214047
//Guilherme Santos Gollino  RA: 2226090


// Arquivo para importação das funções de combate
#pragma once // pragma once para não espelhar os arquivos importados

#include "Personagem.h"
#include "Monstro.h"



void combate(Personagem& p, Monstro& m);
void salvar_dados_personagem(Personagem& p);
void trocar_arma_menu(Personagem& heroi);
