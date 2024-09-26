
// Mapa.cpp
#include "./classes/Mapa.h"
#include "./classes/combate.h"
#include "./classes/mobs.h"
#include "./classes/item.h"
#include "./classes/equipamento.h"
#include "./classes/Personagem.h"
#include "./classes/Interface.h"

#include <iostream> // Biblioteca para entrada e saída de dados
#include <cstdlib> // Biblioteca padrão do C++
#include <ctime> // Biblioteca para manipulação de tempo
#include <conio.h> // Biblioteca para getch()


#ifndef MAPA_H
#define MAPA_H
// Construtor que inicializa o mapa
Mapa::Mapa() {
    inicializar_mapa();
    posicao_x = -1;
    posicao_y = -1;
};

// Inicializa o mapa com valores iniciais
void Mapa::inicializar_mapa() {
    for (int i = 0; i < mapa_largura; ++i) {
        for (int j = 0; j < mapa_altura; ++j) {
            tamanho_mapa[i][j] = '.'; // '.' representa um espaço vazio
        }
    }
};

// Coloca o herói em uma posição específica
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

void Mapa::mostrar_mapa(Personagem& heroi) { // Exibe o mapa na tela
    Item* item_itemp;
    for (int i = 0; i < mapa_largura; ++i) {
        for (int j = 0; j < mapa_altura; ++j) {
            std::cout << tamanho_mapa[j][i] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "Posição do herói: (" << posicao_x << ", " << posicao_y << ")" << std::endl; // Exibe a posição do herói
    heroi.mostrar_cinto(); // Mostra o cinto do herói
    heroi.mostrar_item_mochila(item_itemp); // Mostra os itens na mochila do herói
};


void Mapa::mover_heroi(char x, Personagem& heroi){ // Move o herói no mapa
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
        default: // Direção inválida
            std::cout << "Direção inválida!" << std::endl;
            return;
    }

    // Coloca o herói na nova posição
    tamanho_mapa[posicao_x][posicao_y] = 'H'; // 'H' representa a posição do herói
    eventos(heroi); // Chama os eventos que podem ocorrer em cada SQM
};


void Mapa::limpar_mapa() {
    // Opcional: Limpar o mapa de volta ao estado inicial, se necessário
    for (int i = 0; i < mapa_largura; ++i) {
        for (int j = 0; j < mapa_altura; ++j) {
            tamanho_mapa[j][i] ='.';
        }
    }
};

void Mapa::encotrar_itens(Personagem& heroi) { // Função para encontrar itens no SQM
    // Array fixo com todos os itens disponíveis
    Item** itens_sorteio = nullptr;  // Item** para apontar para um array de ponteiros para Item
    int tamanho_itens = 0;
    int nivel_heroi = heroi.get_nivel(); // Verifica o nível do personagem (itens são apropriados ao nível do herói)
    int escolha;

    if (nivel_heroi == 1) { // Seleciona o vetor de itens apropriado com base no nível do herói
        itens_sorteio = itens_nivel_1;
        tamanho_itens = tamanho_itens_nivel_1;
    } else if (nivel_heroi == 2) { // Seleciona o vetor de itens apropriado com base no nível do herói
        itens_sorteio = itens_nivel_2;
        tamanho_itens = tamanho_itens_nivel_2;
    } else if (nivel_heroi >= 3) { // Seleciona o vetor de itens apropriado com base no nível do herói
        itens_sorteio = itens_nivel_3;
        tamanho_itens = tamanho_itens_nivel_3;
    }

    srand(time(0));
    int indice = rand() % tamanho_itens; // Sorteia um índice para o vetor de itens
    int opcao;
    Item* item_encontrado = itens_sorteio[indice]; // Seleciona um item aleatório do vetor de itens

    while(true){ // Pergunta ao jogador se deseja pegar o item encontrado
        std::cout << "Você encontrou um(a) " << item_encontrado->get_nome() << ". Deseja pegar? \n1. Sim \n 2.Não" << std::endl;
        std::cin >> opcao;
        if(std::cin.fail() || (opcao != 1 && opcao != 2)){ // Verifica se a entrada é válida
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            std::cout << "Entrada inválida. Digite 1 ou 2." << std::endl;
        } else {
            break;
        }
    }

    if (opcao == 1) { // Se o jogador deseja pegar o item

        while(true){ // Pergunta ao jogador se deseja colocar o item no cinto ou na mochila
            std::cout << "Deseja colocar o item no cinto ou na mochila? (digite 1 para cinto, ou 2 para mochila)" << std::endl;
            std::cin >> escolha;
            if(std::cin.fail() || (opcao != 1 && opcao != 2)){ // Verifica se a entrada é válida
                std::cin.clear();
                std::cin.ignore(32767, '\n');
                std::cout << "Entrada inválida. Digite 1 ou 2." << std::endl;
            } else {
                break;
            }
        }

        if(escolha ==  1){ // Se o jogador deseja colocar o item no cinto
            int posicao = 0;

            while(true){ // Pergunta ao jogador em qual posição do cinto deseja inserir o item
                std::cout << "Qual posicao do cinto deseja inserir" << std::endl;
                std::cin >> posicao;
                if(std::cin.fail() || (opcao != 1 && opcao != 2)){ // Verifica se a entrada é válida
                    std::cin.clear();
                    std::cin.ignore(32767, '\n');
                    std::cout << "Entrada inválida. Digite 1 ou 2." << std::endl;
                } else {
                    break;
                }
            }

            heroi.Inserir_cinto(item_encontrado, posicao);  // Agora o herói guarda o item no cinto
        } else if ( escolha == 2){ // Se o jogador deseja colocar o item na mochila
            heroi.inserir_item_mochila(item_encontrado); // Agora o herói guarda o item na mochila
        }
    } else { // Se o jogador não deseja pegar o item
        std::cout << "Você deixou o(a) " << item_encontrado->get_nome() << " para trás." << std::endl; // Mensagem de item deixado para trás
    }
}


void Mapa::encontrar_monstros(Personagem& heroi){ // Função para encontrar monstros no SQM

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
    Monstro* monstro_sorteado = monstros_apropriados[indice]; // Seleciona um monstro aleatório
    
    Monstro mob = *monstro_sorteado; 
    std::cout << "Um " << monstro_sorteado->exibe_nome() << " de nível " << monstro_sorteado->get_nivel() << " apareceu!" << std::endl;
    combate(heroi, mob); // Inicia o combate com o monstro sorteado
}



void Mapa::eventos(Personagem& heroi) { // Função para chamar os eventos aleatórios de acontecerão em casa SQM
    int evento = rand() % 100; // Sorteia um número entre 0 e 99

    // Defina a chance de cada evento
    if (evento < 70) { // 70% de chance de encontrar um item
        encotrar_itens(heroi); // Chama a função para encontrar itens
    } else if (evento < 90) { // 20% de chance de encontrar um monstro
        encontrar_monstros(heroi); // Chama a função para encontrar monstros
    } else { // fica parado
        menu_parado(heroi); // Chama a função para exibir o menu de opções quando o herói está no SQM de descanso
       ;
    }

    std::cout << "Aperte uma tecla para continuar" << std::endl;
    getch();
}



void Mapa::menu_parado(Personagem& heroi){ // Função para exibir menu de opções quando o herói está no SQM de descanso
    int escolha = 0;
    std::cout << "Um pouco de Paz" << std::endl;
    
    while(true){ // Menu de opções para o herói durante o descanso
        std::cout << "O que deseja fazer: \n1 - Trocar arma\n2 - Usar pocao\n3 - Gerenciar inventario\n4 - Sair" << std::endl;
        std::cin >> escolha;
        if(std::cin.fail()){ // Verifica se a entrada é válida
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            std::cout << "Entrada inválida. Digite 1, 2, 3 ou 4." << std::endl;
        } else {
            break;
        }
    }
    
    interface_descanso(); // Exibe imagem para quando o personagem cai num SQM de descanso

    switch(escolha){ // Realiza a ação escolhida pelo jogador
        case 1: // Trocar Arma
            std::cout << "Trocando arma" << std::endl;
            heroi.trocar_arma(); // Função para trocar a arma do herói
            std::cout << "Nova arma: " << heroi.mostrar_arma_equipada().get_nome() << " - Dano: " << heroi.mostrar_arma_equipada().get_dano() << std::endl;
            break;
        case 2: // Usar poção
            std::cout << "Utilizando poção" << std::endl;
            heroi.usa_pocao(); // Função para usar poção
            std::cout << "Ficou com um total de: " << heroi.exibe_vida() << " de vida!" << std::endl;
            break;
        case 3: // Gerenciar inventário 
            std::cout << "Abrindo inventario..." << std::endl;
            gerenciar_iventario(heroi); // Função para gerenciar o inventário do herói durante o SQM de descanso
        case 4: // Sair
            std::cout << "Voltando a aventura..." << std::endl; // Mensagem de saída
            break;
        default:
            break;
    }


}

void Mapa::gerenciar_iventario(Personagem& heroi){ // Função para gerenciar o inventário do herói durante o SQM de descanso
    int escolha = 0;
    
    do{ // Menu de opções para gerenciar o inventário
        int posicao1 = 0,posicao2 = 0;
        Item* item_temp = nullptr;
    
        
        while(true){ // Pede a escolha do jogador
            std::cout << "O que deseja fazer: \n1 - Trocar posição no cinto\n2 - Descartar item do cinto\n3 - Colocar item do cinto na mochila\n4 - Descartar item da mochila\n5 - Sair" << std::endl;
            std::cin >> escolha;
            if(std::cin.fail()){ // Verifica se a entrada é válida
                std::cin.clear();
                std::cin.ignore(32767, '\n');
                std::cout << "Entrada inválida. Digite 1, 2, 3, 4 ou 5." << std::endl;
            } else {
                break;
            }
        }

        interface_descanso(); // Exibe imagem para quando o personagem cai num SQM de descanso

        switch(escolha){ // Realiza a ação escolhida pelo jogador
            case 1:
                while(true){ // Pede a posição dos itens que o jogador deseja trocar
                    std::cout << "Qual item deseja trocar?" << std::endl;
                    std::cin >> posicao1;  
                    if(std::cin.fail()){ // Verifica se a entrada é válida
                        std::cin.clear();
                        std::cin.ignore(32767, '\n');
                        std::cout << "Entrada inválida." << std::endl;
                    } else {
                        break;
                    }
                } 
                
                while(true){ // Pede a posição dos itens que o jogador deseja trocar
                    std::cout << "Qual posição deseja colocar o item?" << std::endl;
                    std::cin >> posicao2;
                    if(std::cin.fail()){ // Verifica se a entrada é válida
                        std::cin.clear();
                        std::cin.ignore(32767, '\n');
                        std::cout << "Entrada inválida." << std::endl;
                    } else {
                        break;
                    }
                }           

                std::cout << "Trocando o item de posição no cinto." << std::endl;
                heroi.Trocar_posicao_cinto(posicao1,posicao2); // Função para trocar a posição dos itens no cinto
                break;
            case 2: // Descartar item do cinto
                while(true){ // Pede a posição do item que o jogador deseja remover
                    std::cout << "Informe a posição que deseja remover: " << std::endl;
                    std::cin >> posicao1;
                    if(std::cin.fail()){ // Verifica se a entrada é válida
                        std::cin.clear(); 
                        std::cin.ignore(32767, '\n');
                        std::cout << "Entrada inválida." << std::endl;
                    } else {
                        break;
                    }
                }    
                
                heroi.Remover_cinto(item_temp,posicao1); // Função para remover o item do cinto
                break;
            case 3: // Colocar item do cinto na mochila
                while(true){ // Pede a posição do item que o jogador deseja transferir para a mochila
                    std::cout << "Informe qual item será transferido para a mochila: " << std::endl;                
                    std::cin >> posicao1;
                    if(std::cin.fail()){ // Verifica se a entrada é válida
                        std::cin.clear();
                        std::cin.ignore(32767, '\n');
                        std::cout << "Entrada inválida." << std::endl;
                    } else {
                        break;
                    }
                }    

                Item* item_temp;
                heroi.transfere_para_mochila(item_temp, posicao1); // Função para transferir o item do cinto para a mochila
                break;
            case 4: // Descartar item da mochila
                std::cout << "Descartando o item da mochila" << std::endl;
                heroi.retirar_item_mochila(item_temp); // Função para retirar o item da mochila
            case 5: // Sair
                std::cout << "Saindo..." << std::endl;
                break;
            default:
                break;
        }
    }while(escolha != 5);
}


#endif 