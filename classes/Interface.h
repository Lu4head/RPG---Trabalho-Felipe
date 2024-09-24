#pragma once
#include <iostream>
#include <string>

class Interface {
public:
	void EscolherArmaInicial(std::string name, std::string& escolhaarma);

	void personagem(std::string& name);

	void abertura();

	void creditos();

	// void Combate(std::string name, std::string& vida, std::string& WhoWon);
    void Exibe_Espada_Curta(std::string name,  int indice, int indice_anterior);
    void Exibe_Adaga(std::string name, int indice, int indice_anterior);
    void Exibe_Varinha(std::string varinha, int indice, int indice_anterior);
    void Combate(std::string name, std::string& vida, std::string& WhoWon);
};