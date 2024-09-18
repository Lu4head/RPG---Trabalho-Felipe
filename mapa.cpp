
// Mapa.cpp
#include ".\classes\Mapa.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>


#ifndef MAPA_H
#define MAPA_H
// Construtor que inicializa o mapa
Mapa::Mapa() {
    inicializar_mapa();
    posicao_x = -1;
    posicao_y = -1;
};

// Inicializa o mapa com zeros
void Mapa::inicializar_mapa() {
    for (int i = 0; i < mapa_largura; ++i) {
        for (int j = 0; j < mapa_altura; ++j) {
            tamanho_mapa[i][j] = '.'; // '.' representa um espaço vazio
        }
    }
};

// Coloca o heróiv em uma posição específica
void Mapa::colocar_heroi(int x, int y) {
    // Verifica se as coordenadas estão dentro dos limites do mapa
    if (x >= 0 && x < mapa_largura && y >= 0 && y < mapa_altura) {
        posicao_x = x;
        posicao_y = y;
        tamanho_mapa[posicao_x][posicao_y] = 'H'; // Coloca o herói na posição especificada
    } else {
        std::cout << "Coordenadas fora dos limites do mapa." << std::endl;
    }
};

void Mapa::mostrar_mapa() {
    for (int i = 0; i < mapa_largura; ++i) {
        for (int j = 0; j < mapa_altura; ++j) {
            std::cout << tamanho_mapa[j][i] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "Posição do herói: (" << posicao_x << ", " << posicao_y << ")" << std::endl;
};


void Mapa::mover_heroi(char x){
    if (posicao_x >= 0 && posicao_x < mapa_largura && posicao_y >= 0 && posicao_y < mapa_altura){
        tamanho_mapa[posicao_x][posicao_y] = '.';
    }
    // Atualiza a posição do herói com base na direção
    switch (x) {
        case 'w': // Mover para cima
            if (posicao_y > 0) posicao_y--;
            break;
        case 's': // Mover para baixo
            if (posicao_y < mapa_altura - 1) posicao_y++;
            break;
        case 'a': // Mover para a esquerda
            if (posicao_x > 0) posicao_x--;
            break;
        case 'd': // Mover para a direita
            if (posicao_x < mapa_largura){
                posicao_x++;
                if (posicao_x == mapa_largura){
                    posicao_x = 0; // para ir para a primeira posição da proxima linha
                    posicao_y ++;
                    if (posicao_y >= mapa_altura){
                        posicao_y = mapa_altura -1;
                        posicao_x = mapa_largura -1;
                    }
                }
            }

            break;
        default:
            std::cout << "Direção inválida!" << std::endl;
            return;
    }

    // Coloca o herói na nova posição
    tamanho_mapa[posicao_x][posicao_y] = 'H';

    eventos();
};


void Mapa::limpar_mapa() {
    // Opcional: Limpar o mapa de volta ao estado inicial, se necessário
    for (int i = 0; i < mapa_largura; ++i) {
        for (int j = 0; j < mapa_altura; ++j) {
            tamanho_mapa[j][i] ='.';
        }
    }
};

void Mapa::eventos(){
    int evento = rand() % 3; // para gerar um numero entre 0 e 2

    switch (evento) {
        case 0: 
            std::cout << "Um pouco de Paz" << std::endl; // quando nada acontece
            break;
        case 1:
            std::cout << "Um inimigo preparar" << std::endl; // Implementar a logica do combate - puxar de outro arquivo
            break;
        case 2:
            std::cout << "Um item, pegue ou deixa para lá" << std::endl; // Implementar a logica de achar item - puxar de outro arquivo
            break;
    } 

    std::cout << "Aperte uma tecla para sair" << std::endl;
    getch();
};

#endif 