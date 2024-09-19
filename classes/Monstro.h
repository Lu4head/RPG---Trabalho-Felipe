#pragma once
#include <string>
#include <iostream>

class Monstro {
    public:
        // Construtor
        Monstro(std::string nome, float vida_total, float mana_total, float dano_fisico, float dano_magico);

        // Métodos para modificar o estado do monstro
        void recebe_dano(float dano);
        void gasta_mana(float custo);
        float aplica_dano_fisico();
        float aplica_dano_magico();

        // Métodos para exibir informações
        float exibe_vida();

        std::string exibe_nome();

    private:
        std::string nome;
        float vida_total;
        float vida_atual;
        float mana_total;
        float mana_atual;
        int nivel;
        float dano_fisico;
        float dano_magico;
};
