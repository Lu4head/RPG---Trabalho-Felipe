//Luan Emanuel R. Argentato RA: 2184611
//Gustavo duzzi             RA: 2214047
//Guilherme Santos Gollino  RA: 2226090

#pragma once // pragma once para não espelhar os arquivos importados

#include "Item.h"

#include <string>

class Pocao: public Item{
    public: // Metodos publicos
        // Construtores e Destrutores
        Pocao(std::string nome_item, float peso_item, std::string tipo_do_item, float cura,float mana,int nivel); // Construtor de pocao
        Pocao(); // Construtor padrão para criação de arrays / variaveis temporarias

        // Getters
        float get_cura(); // Retorna atributo de cura da poção
        float get_mana(); // Retorna atributo de mana da poção (quantidade de mana que será recuperada)

    private: // Atributos
        float cura;
        float mana;
};
