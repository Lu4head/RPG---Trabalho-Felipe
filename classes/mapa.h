//Luan Emanuel R. Argentato RA: 2184611
//Gustavo duzzi             RA: 2214047
//Guilherme Santos Gollino  RA: 2226090

#pragma once // pragma once para não espelhar os arquivos importados

#include "Cinto.h"
#include "Personagem.h"

const int mapa_altura = 10; // Altura do Mapa
const int mapa_largura = 10; // Largura do Mapa

class Mapa {
    public: // Metodos publicos
        // Construtores e Destrutores
        Mapa(); // Construtor padrão

        void inicializar_mapa(); // Inicializa o mapa com zeros
        void colocar_heroi(int x, int y); // Coloca o herói em uma posição específica
        void mostrar_mapa(Personagem& heroi); // Exibe interface do mapa na tela com a posição do personagem
        void mover_heroi(char x, Personagem& heroi); // Move o herói no mapa
        void encotrar_itens(Personagem &heroi); // Função para encontrar itens no SQM
        void encontrar_monstros(Personagem& heroi); // Função para encontrar monstros no SQM
        void menu_descanso(Personagem& heroi); // Função para exibir menu de opções quando o herói está no SQM de descanso
        void gerenciar_iventario(Personagem& heroi); // Função para gerenciar o inventário do herói durante o SQM de descanso
        void trocar_arma_menu(Personagem& heroi);
    private: // Atributos e métodos privados
        char tamanho_mapa[mapa_largura][mapa_altura]; // Matriz que representa o mapa
        int posicao_x, posicao_y; // posicao do heroi 
        void limpar_mapa(); // Retorna o mapa para o estado inicial
        void eventos(Personagem& heroi); // Função para chamar os eventos aleatórios de acontecerão em casa SQM
};


