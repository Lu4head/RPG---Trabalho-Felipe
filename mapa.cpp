
// Mapa.cpp
#include "./classes/Mapa.h"
#include "./classes/combate.h"
#include "./classes/mobs.h"
#include "./classes/item.h"
#include "./classes/equipamento.h"
#include "./classes/Personagem.h"
#include "./classes/Interface.h"
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

void Mapa::mostrar_mapa(Personagem& heroi) {
    for (int i = 0; i < mapa_largura; ++i) {
        for (int j = 0; j < mapa_altura; ++j) {
            std::cout << tamanho_mapa[j][i] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "Posição do herói: (" << posicao_x << ", " << posicao_y << ")" << std::endl;
    heroi.mostrar_cinto();
    Item* item_itemp;
    heroi.mostrar_item_mochila(item_itemp);
};


void Mapa::mover_heroi(char x, Personagem& heroi){
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
    eventos(heroi);
};


void Mapa::limpar_mapa() {
    // Opcional: Limpar o mapa de volta ao estado inicial, se necessário
    for (int i = 0; i < mapa_largura; ++i) {
        for (int j = 0; j < mapa_altura; ++j) {
            tamanho_mapa[j][i] ='.';
        }
    }
};

void Mapa::encotrar_itens(Personagem& heroi) {
    // Array fixo com todos os itens disponíveis
    Item** itens_sorteio = nullptr;  // Item** para apontar para um array de ponteiros para Item
    int tamanho_itens = 0;
    int nivel_heroi = heroi.get_nivel();
    int escolha;

    if (nivel_heroi == 1) {
        itens_sorteio = itens_nivel_1;
        tamanho_itens = tamanho_itens_nivel_1;
    } else if (nivel_heroi == 2) {
        itens_sorteio = itens_nivel_2;
        tamanho_itens = tamanho_itens_nivel_2;
    } else if (nivel_heroi >= 3) {
        itens_sorteio = itens_nivel_3;
        tamanho_itens = tamanho_itens_nivel_3;
    }

    srand(time(0));
    int indice = rand() % tamanho_itens;
    Item* item_encontrado = itens_sorteio[indice];
    std::cout << "Você encontrou um(a) " << item_encontrado->get_nome() << ". Deseja pegar?" << std::endl;
    std::cout << "1. Sim" << std::endl;
    std::cout << "2. Não" << std::endl;

    int opcao;
    std::cin >> opcao;

    if (opcao == 1) {
        std::cout << "Deseja colocar o item no cinto ou na mochila? (digite 1 para cinto, ou 2 para mochila)" << std::endl;
        std::cin >> escolha;
        if(escolha == 1){
            int posicao = 0;
            std::cout << "Qual posicao do cinto deseja inserir" << std::endl;
            std::cin >> posicao;
            heroi.Inserir_cinto(item_encontrado, posicao);  // Agora o herói guarda o item no cinto
        } else if ( escolha == 2){
            heroi.inserir_item_mochila(item_encontrado);
        }
    } else {
        std::cout << "Você deixou o(a) " << item_encontrado->get_nome() << " para trás." << std::endl;
    }
}


void Mapa::encontrar_monstros(Personagem& heroi){

    // Sorteando monstro apropriado ao nível do herói
    Monstro** monstros_apropriados = nullptr;
    int nivel_heroi = heroi.get_nivel(); // Supondo que Personagem tenha um método get_nivel()
    int tamanho = 0;

    // Seleciona o vetor de monstros apropriado com base no nível do herói
    if (nivel_heroi == 1) {
        monstros_apropriados = monstro_nivel_1;
        tamanho = tamanho_nivel_1;
    } else if (nivel_heroi == 2) {
        monstros_apropriados = monstro_nivel_2;
        tamanho = tamanho_nivel_2;
    } else {
        std::cout << "Nenhum monstro disponível para o seu nível." << std::endl;
        return;
    }

    srand(time(0));

    int indice = rand() % tamanho; // Sorteia um índice
    Monstro* monstro_sorteado = monstros_apropriados[indice];
    
    Monstro mob = *monstro_sorteado; 
    std::cout << "Um " << monstro_sorteado->exibe_nome() << " de nível " << monstro_sorteado->get_nivel() << " apareceu!" << std::endl;
    combate(heroi, mob); // Inicia o combate com o monstro sorteado
}



void Mapa::eventos(Personagem& heroi) {
    int evento = rand() % 100; // Sorteia um número entre 0 e 99

    // Defina a chance de cada evento
    if (evento < 70) { // 70% de chance de encontrar um item
        encotrar_itens(heroi);
    } else if (evento < 90) { // 20% de chance de encontrar um monstro
        menu_parado(heroi);
    } else { // fica parado
        encontrar_monstros(heroi);
    }

    std::cout << "Aperte uma tecla para continuar" << std::endl;
    getch();
}



void Mapa::menu_parado(Personagem& heroi){
    int escolha = 0;
    std::cout << "Um pouco de Paz" << std::endl;
    std::cout << "O que deseja fazer: \n1 - Trocar arma\n2 - Usar pocao\n3 - Gerenciar inventario\n4 - Sair" << std::endl;
    std::cin >> escolha;
    interface_descanso();
    switch(escolha){
        case 1:
            std::cout << "Trocando arma" << std::endl;
            heroi.trocar_arma();
            std::cout << "Nova arma: " << heroi.mostrar_arma_equipada().get_nome() << " - Dano: " << heroi.mostrar_arma_equipada().get_dano() << std::endl;
            break;
        case 2:
            std::cout << "Utilizando poção" << std::endl;
            heroi.usa_pocao();
            std::cout << "Ficou com um total de: " << heroi.exibe_vida() << " de vida!" << std::endl;
            break;
        case 3:
            std::cout << "Abrindo inventario..." << std::endl;
            gerenciar_iventario(heroi);
        case 4:
            std::cout << "Voltando a aventura..." << std::endl;
            break;

    }


}

void Mapa::gerenciar_iventario(Personagem& heroi){
    int escolha = 0;
    
    do{
        int posicao1 = 0,posicao2 = 0;
        Item* item_temp = nullptr;
    
        std::cout << "O que deseja fazer: \n1 - Trocar posição no cinto\n2 - Descartar item do cinto\n3 - Colocar item do cinto na mochila\n4 - Descartar item da mochila\n5 - Sair" << std::endl;
        std::cin >> escolha;
        interface_descanso();
        switch(escolha){
            case 1:
                std::cout << "Qual item deseja trocar?" << std::endl;
                std::cin >> posicao1;
                std::cout << "Qual posição deseja colocar o item?" << std::endl;
                std::cin >> posicao2;
                std::cout << "Trocando o item de posição no cinto: " << std::endl;
                heroi.Trocar_posicao_cinto(posicao1,posicao2);
                break;
            case 2:
                std::cout << "Informe a posição que deseja remover: " << std::endl;
                std::cin >> posicao1;
                heroi.Remover_cinto(item_temp,posicao1);
                break;
            case 3:
                std::cout << "Informe qual item será transferido para a mochila: " << std::endl;
                std::cin >> posicao1;
                Item* item_temp;
                heroi.transfere_para_mochila(item_temp, posicao1);
                break;
            case 4:
                std::cout << "Descartando o item da mochila" << std::endl;
                heroi.retirar_item_mochila(item_temp);
            case 5:
                std::cout << "Saindo..." << std::endl;
                break;
            default:
                break;
        }
    }while(escolha != 5);
}


#endif 