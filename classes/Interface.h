#pragma once // pragma once para não espelhar os arquivos importados

#include "equipamento.h"
#include "colorir.h"
#include "Personagem.h"
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
	
	void interface_descanso(); // Exibe imagem para quando o personagem cai num SQM de descanso
	//void interface_descanso2();
	void interface_pocao(); // Interface para quando o personagem encontra uma poção em um SQM
    void interface_combate(std::string name, std::string& vida, std::string& WhoWon); // Exibe tela de combate
	void interface_Status_Heroi(Personagem &heroi);


