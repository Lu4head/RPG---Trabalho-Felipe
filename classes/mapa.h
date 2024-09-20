#pragma once
#include "Cinto.h"
#include "Personagem.h"
const int mapa_altura = 10;
const int mapa_largura = 10;

class Mapa {
    public:
        Mapa(); // Construtor

        void inicializar_mapa(); // Inicializa o mapa com zeros
        void colocar_heroi(int x, int y); // Coloca o herói em uma posição específica
        void mostrar_mapa(Personagem& heroi);
        void mover_heroi(char x, Personagem& heroi);
        void encotrar_itens(Personagem &heroi);
    private:
        char tamanho_mapa[mapa_largura][mapa_altura]; // Matriz que representa o mapa
        int posicao_x, posicao_y; // posicao do heroi 
        void limpar_mapa();

        void eventos(Personagem& heroi);
};


