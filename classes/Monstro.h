//Luan Emanuel R. Argentato RA: 2184611
//Gustavo duzzi             RA: 2214047
//Guilherme Santos Gollino  RA: 2226090

#pragma once // pragma once para não espelhar os arquivos importados

#include <string>
#include <iostream>

class Monstro {
    public: // Metodos publicos
        // Construtores e Destutores
        Monstro(std::string nome, float vida_total, float mana_total, float dano_fisico, float dano_magico, int nivel); // Construtor para Monstro
        Monstro(); // Construtor padrão para criação de array / variável temporária


        // Métodos para modificar o estado do monstro
        void recebe_dano(float dano); // Função para calcular dano recebido pelo monstro
        void gasta_mana(float custo); // Função para calcular mana gasta por ataque mágicos do monstro
        float aplica_dano_fisico(); // Função que retorna o dano físico do monstro
        float aplica_dano_magico(); // Função que retorna o dano mágico do monstro
        int get_recompensa_xp(); // Função que retorna a recompensa de XP ao derrotar o monstro
        int get_nivel(); // Função que retorna o nível do monstro

        // Métodos para exibir informações
        float exibe_vida(); // Função que retorna a vida atual do monstro

        std::string exibe_nome(); // Função que retorna o nome do monstro

    private: // Atributos
        std::string nome;
        float vida_total;
        float vida_atual;
        float mana_total;
        float mana_atual;
        int nivel;
        float dano_fisico;
        float dano_magico;
};
