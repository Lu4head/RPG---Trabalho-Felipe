#pragma once

#include "equipamento.h"
#include "Arma.h"
#include <iostream>
#include <string>

	void interface_creditos(); // Exibe os créditos do jogo com nome dos membos do grupo
	void interface_abertura(); // Exibe tela inicial do jogo
	
	void interface_personagem(std::string& name); // Exibe tela para escolha do nome do personagem
    
	void Exibe_Espada_Curta(std::string name,  int indice, int indice_anterior);
    void Exibe_Adaga(std::string name, int indice, int indice_anterior);
    void Exibe_Varinha(std::string varinha, int indice, int indice_anterior);
	
	void interface_arma_inicial(std::string name, Arma &escolhaarma); // Interfape para escolha da arma inicial do heroi
	
	// void Combate(std::string name, std::string& vida, std::string& WhoWon);
    void interface_combate(std::string name, std::string& vida, std::string& WhoWon);
