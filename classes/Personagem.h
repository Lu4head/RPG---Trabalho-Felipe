#pragma once // pragma once para não espelhar os arquivos importados

#include <string>

#include "Mochila.h"
#include "Cinto.h"
#include "Item.h"
#include "arma.h"
#include "pocao.h"

class Personagem{
    public: // Metodos publicos
        // Construtores e Destrutores
        Personagem(std::string nome); // Construtor
        ~Personagem(); // Destrutor padrão

        // Getters
        std::string exibe_nome();
        float exibe_vida();
        Arma mostrar_arma_equipada();
        int get_nivel();
        void mostrar_cinto();   
        void mostrar_item_mochila(Item* x);
        
        // Setter
        void Equipar_arma(Arma* arma); // 
        
        // Função para modificar o estado do personagem
        void recebe_dano(float x); // Calcula dano recebido subtraindo a vida atual do personagem
        int gasta_mana(float x); // Calcula mana gasta subtraindo da mana atual do personagem
        void ganha_xp(int quantidade); // Calcula o ganho de XP e chama função para verificar se personagem subiu de nível

        void cura(float x);
        void recupera_mana(float x);
        

        void usa_pocao(); // Recebe uma poção e calcula as alterações no personagem com base no efeito dela (cura/mana)
        void trocar_arma(); // Chama função do cinto para identificar armas no cinto e equipar a escolhida
        
        // Manipulação de inventários
        void Inserir_cinto(Item* item, int posicao); // Insere item no cinto do heroi
        void Remover_cinto(Item* item, int posicao); // Remove item do cinto do heroi
        void Trocar_posicao_cinto(int p1, int p2); // Troca a posição de 2 itens no cinto
        void transfere_para_mochila(Item* x, int p); // Transfere item do cinto para a mochila
        void inserir_item_mochila(Item* x); // Insere item na mochila do heroi
        void retirar_item_mochila(Item* x); // Remove item da mochila do heroi
        
        
        void aumenta_nivel(); // Calcula se o personagem tem XP suficiente para subir de nível e aumenta os status caso ele suba de nível
        
    private: // Atributos
        std::string nome;

        float vida_Total;
        float vida_Atual;

        int mana_Total;
        int mana_Atual;

        int nivel;
        int exp_total;
        int exp_atual;  

        Arma arma_equipada;
        Cinto cinto_personagem; 
        Mochila mochila_personagem; 
};