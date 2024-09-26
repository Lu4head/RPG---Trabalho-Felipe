#pragma once // pragma once para não espelhar os arquivos importados

#include "Item.h" // Importação da classe item, para criar a classe arma como herança
#include <string> // Importação da String

class Arma: public Item{ // criação da classe Arma, essa sintaxe serve para criar uma herança, Arma herda a classe item, facilitando a integração de ambos
    public: 
        // Metodos publicos

        // Construtores e Destrutores
        Arma(std::string nome_item,float peso_item, std::string tipo_do_item, float dano,int nivel, int custo_mana); // Construtor para a classe item, construtor com parametros, na hora da criação sou obrigado a passar esses pontos para ele
        //nome_item, peso_item, tipo_do_item,nivel são heranças da classe item, já que poção tambem vai usar
        Arma(); // Construtor padrão, utilizado para algumas circustancias (criar uma arma temporária)
        ~Arma(); // Destrutor padrão

        float get_dano(); // Função criada para retornar o dano da arma
        int get_custo_mana(); // Função criada para retornar o custo da mana
    
    private: 
        // Atributos
        float dano; // dano da arma
        int custo_mana; // custo de mana da arma
};
