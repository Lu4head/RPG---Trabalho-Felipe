
// Mapa.cpp
#include "./classes/Mapa.h"
#include "./classes/combate.h"
#include "./classes/mobs.h"
#include "./classes/item.h"
#include "./classes/equipamento.h"
#include "./classes/Personagem.h"
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

void Mapa::mostrar_mapa(Cinto& cinto) {
    for (int i = 0; i < mapa_largura; ++i) {
        for (int j = 0; j < mapa_altura; ++j) {
            std::cout << tamanho_mapa[j][i] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "Posição do herói: (" << posicao_x << ", " << posicao_y << ")" << std::endl;
    cinto.mostrar_itens();
};


void Mapa::mover_heroi(char x, Personagem& heroi, Cinto& cinto){
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
    eventos(heroi, cinto);
};


void Mapa::limpar_mapa() {
    // Opcional: Limpar o mapa de volta ao estado inicial, se necessário
    for (int i = 0; i < mapa_largura; ++i) {
        for (int j = 0; j < mapa_altura; ++j) {
            tamanho_mapa[j][i] ='.';
        }
    }
};

void Mapa::encotrar_itens(Personagem& heroi,Cinto& cinto){
    // Array fixo com todos os itens disponíveis
    Item* itens[] = {
        &Katana, &Adaga, &Manopla, &Machadinha,
        &pocao_de_cura_fraca, &pocao_de_cura_media, &pocao_de_cura_forte,
        &pocao_de_mana_fraca, &pocao_de_mana_media, &pocao_de_mana_forte
     };

    int tamanho_itens = sizeof(itens) / sizeof(itens[0]);

    srand(time(0));
    int escolha = rand() % tamanho_itens;
    Item* item_encontrado = itens[escolha];
    std::cout << "Você encontrou um(a) " << item_encontrado->get_nome() << ". Deseja pegar?" << std::endl;
    std::cout << "1. Sim" << std::endl;
    std::cout << "2. Não" << std::endl;

    int opcao;
    std::cin >> opcao;


    if (opcao == 1) {
        // Adicionar o item ao cinto
        if (cinto.Colocar_item(*item_encontrado, 1) == 0) { // Verifica se a inserção foi bem-sucedida
            std::cout << item_encontrado->get_nome() << " foi adicionado ao cinto!" << std::endl;
            cinto.mostrar_itens(); // Mostra os itens no cinto após a adição
        } else {
            std::cout << "Não foi possível adicionar o item ao cinto." << std::endl;
        }
    } else {
        std::cout << "Você deixou o(a) " << item_encontrado->get_nome() << " para trás." << std::endl;
    }
}



void Mapa::eventos(Personagem& heroi, Cinto& cinto) {
    int evento = rand() % 3; // para gerar um numero entre 0 e 2
    
    // Inicializar Monstro com valores de exemplo
    Monstro mob("Goblin", 50, 30, 5, 10);

    switch (evento) {
        case 0:
            std::cout << "Um pouco de Paz" << std::endl; // quando nada acontece
            break;
        case 1:
            std::cout << "Um inimigo apareceu!" << std::endl; // Implementar a lógica do combate - puxar de outro arquivo
            combate(heroi, mob);
            break;
        case 2:
            std::cout << "Você encontrou um item, pegue ou deixe para lá" << std::endl; // Implementar a lógica de achar item - puxar de outro arquivo
            encotrar_itens(heroi,cinto);
            break;
    }

    std::cout << "Aperte uma tecla para continuar" << std::endl;
    getch();
};
#endif 