
// Mapa.cpp
#include "./classes/Mapa.h"
#include "./classes/combate.h"
#include "./classes/mobs.h"
#include "./classes/item.h"
#include "./classes/equipamento.h"
#include "./classes/Personagem.h"
#include "./classes/Interface.h"
#include ".\classes\colorir.h"

#include <iostream> // Biblioteca para entrada e saída de dados
#include <cstdlib> // Biblioteca padrão do C++
#include <ctime> // Biblioteca para manipulação de tempo
#include <conio.h> // Biblioteca para getch()
#include <windows.h>


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

    // Adiciona obstáculos aleatórios
    for (int i = 0; i < 5; ++i) { // Adiciona 5 obstáculos
        int x = rand() % mapa_largura;
        int y = rand() % mapa_altura;

        // Garante que o obstáculo não se sobreponha ao herói
        while ((x == posicao_x && y == posicao_y) || tamanho_mapa[x][y] != '.') {
            x = rand() % mapa_largura;
            y = rand() % mapa_altura;
        }

        // Seleciona um tipo de obstáculo aleatório
        int tipo_obstaculo = rand() % 3; // 0, 1 ou 2
        if (tipo_obstaculo == 0) {
            tamanho_mapa[x][y] = '#'; // Pedra
        } else if (tipo_obstaculo == 1) {
            tamanho_mapa[x][y] = '*'; // Árvore
        } else {
            tamanho_mapa[x][y] = '^'; // Montanha
        }
    }
}

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



void Mapa::mostrar_mapa(Personagem& heroi) {
    Item* item_temp;
    
 
setConsoleColor(10, 0); // Texto verde
    std::cout << "==================== MAPA ====================" << std::endl;

    // Exibe o mapa
    for (int j = 0; j < mapa_altura; ++j) {
        for (int i = 0; i < mapa_largura; ++i) {
            // Verifica se a posição é a do herói
            if (i == posicao_x && j == posicao_y) {
                std::cout << "🥷"; // Representa o herói
            } else if (tamanho_mapa[i][j] == '#') {
                std::cout << "🪨"; // Representa uma pedra
            } else if (tamanho_mapa[i][j] == '*') {
                std::cout << "🌳"; // Representa uma árvore
            } else if (tamanho_mapa[i][j] == '^') {
                std::cout << "⛰️"; // Representa uma montanha
            } else {
                std::cout << ". "; // Representa um espaço vazio
            }
        }
        std::cout << std::endl;
    }

    interface_Status_Heroi(heroi);
};




void Mapa::mover_heroi(char direcao, Personagem& heroi) {
    // Verifica se o herói está na posição válida antes de movê-lo
    if (posicao_x >= 0 && posicao_x < mapa_largura && posicao_y >= 0 && posicao_y < mapa_altura) {
        tamanho_mapa[posicao_x][posicao_y] = '.'; // Libera a posição anterior
    }

    int novo_x = posicao_x;
    int novo_y = posicao_y;

    // Atualiza a posição do herói com base na direção escolhida
    switch (direcao) {
        case 'w':
            novo_y--;
            break;
        case 's':
            novo_y++;
            break;
        case 'a':
            novo_x--;
            break;
        case 'd':
            novo_x++;
            break;
        default:
            std::cout << "Direção inválida! Use 'w', 'a', 's', ou 'd' para mover." << std::endl;
            return;
    }

    // Verifica se a nova posição é um obstáculo
    if (novo_x < 0 || novo_x >= mapa_largura || novo_y < 0 || novo_y >= mapa_altura || 
        (tamanho_mapa[novo_x][novo_y] == '#' || tamanho_mapa[novo_x][novo_y] == '*' || tamanho_mapa[novo_x][novo_y] == '^')) {
        std::cout << "Você não pode mover para essa posição, há um obstáculo!" << std::endl;
        return;
    }
    // Atualiza a posição do herói
    posicao_x = novo_x;
    posicao_y = novo_y;
    tamanho_mapa[posicao_x][posicao_y] = 'H'; // Coloca o herói na nova posição
    // Verifica se o herói chegou na última casa do mapa
    if (posicao_x == mapa_largura - 1 && posicao_y == mapa_altura - 1) {
        std::cout << "Você chegou na última casa! Reiniciando na posição inicial." << std::endl;
        posicao_x = 0; // Reinicia a posição X
        posicao_y = 0; // Reinicia a posição Y
    }

    
    std::cout << "Você se moveu para a nova posição: (" << posicao_x << ", " << posicao_y << ")" << std::endl;

    eventos(heroi); // Chama os eventos que podem ocorrer em cada SQM
}


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
    Item** itens_sorteio = nullptr;  
    int tamanho_itens = 0;
    int nivel_heroi = heroi.get_nivel(); // Obtém o nível do personagem
    int escolha;
    
    // Seleciona o vetor de itens apropriado com base no nível do herói
    if (nivel_heroi == 1) { 
        itens_sorteio = itens_nivel_1;
        tamanho_itens = tamanho_itens_nivel_1;
    } else if (nivel_heroi == 2) { 
        itens_sorteio = itens_nivel_2;
        tamanho_itens = tamanho_itens_nivel_2;
    } else if (nivel_heroi == 3) { 
        itens_sorteio = itens_nivel_3;
        tamanho_itens = tamanho_itens_nivel_3;
    } else if (nivel_heroi == 4){
        itens_sorteio = itens_nivel_4;
        tamanho_itens = tamanho_itens_nivel_4;
    } else if (nivel_heroi == 5){
        itens_sorteio = itens_nivel_5;
        tamanho_itens = tamanho_itens_nivel_5;
    } else if (nivel_heroi == 6){
        itens_sorteio = itens_nivel_6;
        tamanho_itens = tamanho_itens_nivel_6;
    } else if (nivel_heroi == 7){
        itens_sorteio = itens_nivel_7;
        tamanho_itens = tamanho_itens_nivel_7;
    } else if (nivel_heroi >= 8){
        itens_sorteio = itens_nivel_8;
        tamanho_itens = tamanho_itens_nivel_8;
    }

    srand(static_cast<unsigned>(time(0)));
    int indice = rand() % tamanho_itens; // Sorteia um índice para o vetor de itens
    Item* item_encontrado = itens_sorteio[indice]; // Seleciona um item aleatório do vetor

    // Apresenta o item encontrado
    colorirTexto(10); // Verde
    std::cout << "🎉 Você encontrou um(a) " << item_encontrado->get_nome() << "!" << std::endl;
    colorirTexto(7); // Branco padrão

    // Pergunta ao jogador se deseja pegar o item encontrado
    while (true) { 
        std::cout << "Deseja pegar? \n1. Sim \n2. Não" << std::endl;
        std::cin >> escolha;

        // Verifica se a entrada é válida
        if (std::cin.fail() || (escolha != 1 && escolha != 2)) {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            colorirTexto(12); // Vermelho
            std::cout << "⚠️ Entrada inválida. Digite 1 ou 2." << std::endl;
            colorirTexto(7); // Branco padrão
        } else {
            break;
        }
    }

    // Se o jogador deseja pegar o item
    if (escolha == 1) {
        while (true) { // Pergunta se deseja colocar o item no cinto ou na mochila
            std::cout << "Deseja colocar o item no cinto ou na mochila? \n1. Cinto \n2. Mochila" << std::endl;
            std::cin >> escolha;

            // Verifica se a entrada é válida
            if (std::cin.fail() || (escolha != 1 && escolha != 2)) {
                std::cin.clear();
                std::cin.ignore(32767, '\n');
                colorirTexto(12); // Vermelho
                std::cout << "⚠️ Entrada inválida. Digite 1 ou 2." << std::endl;
                colorirTexto(7); // Branco padrão
            } else {
                break;
            }
        }

        // Se o jogador deseja colocar o item no cinto
        if (escolha == 1) { 
            int posicao = 0;

            while (true) { // Pergunta ao jogador em qual posição do cinto deseja inserir o item
                std::cout << "Qual posição do cinto deseja inserir? (digite um número)" << std::endl;
                std::cin >> posicao;

                // Verifica se a entrada é válida
                if (std::cin.fail()) { 
                    std::cin.clear();
                    std::cin.ignore(32767, '\n');
                    colorirTexto(12); // Vermelho
                    std::cout << "⚠️ Entrada inválida. Por favor, digite um número." << std::endl;
                    colorirTexto(7); // Branco padrão
                } else {
                    break;
                }
            }
            heroi.Inserir_cinto(item_encontrado, posicao);  // O herói guarda o item no cinto
            colorirTexto(10); // Verde
            std::cout << "✔️ Você colocou " << item_encontrado->get_nome() << " no cinto." << std::endl;
            colorirTexto(7); // Branco padrão
        } 
        // Se o jogador deseja colocar o item na mochila
        else if (escolha == 2) { 
            heroi.inserir_item_mochila(item_encontrado); // O herói guarda o item na mochila
            colorirTexto(10); // Verde
            std::cout << "✔️ Você colocou " << item_encontrado->get_nome() << " na mochila." << std::endl;
            colorirTexto(7); // Branco padrão
        }
    } else { // Se o jogador não deseja pegar o item
        colorirTexto(14); // Amarelo
        std::cout << "❌ Você deixou o(a) " << item_encontrado->get_nome() << " para trás." << std::endl;
        colorirTexto(7); // Branco padrão
    }
}


void Mapa::encontrar_monstros(Personagem& heroi) {
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
        colorirTexto(12); // Vermelho
        std::cout << "⚠️ Nenhum monstro disponível para o seu nível." << std::endl;
        colorirTexto(7); // Branco padrão
        return;
    }

    srand(static_cast<unsigned>(time(0)));
    int indice = rand() % tamanho; // Sorteia um índice
    Monstro* monstro_sorteado = monstros_apropriados[indice]; // Seleciona um monstro aleatório
    
    // Mensagem de apresentação do monstro
    colorirTexto(10); // Verde
    std::cout << "\n🌟 Um " << monstro_sorteado->exibe_nome() << " de nível " 
              << monstro_sorteado->get_nivel() << " apareceu!" << std::endl;
    colorirTexto(7); // Branco padrão

    // Inicia o combate
    colorirTexto(14); // Amarelo
    std::cout << "⚔️ Preparando-se para o combate..." << std::endl;
    colorirTexto(7); // Branco padrão
    
    Monstro mob = *monstro_sorteado; 
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
        menu_descanso(heroi); // Chama a função para exibir o menu de opções quando o herói está no SQM de descanso
       ;
    }

    std::cout << "Aperte uma tecla para continuar" << std::endl;
    getch();
}



void Mapa::menu_descanso(Personagem& heroi) { 
    int escolha = 0;
    Item* item_temp = nullptr;
    heroi.mostrar_item_mochila(item_temp);

    std::cout << "Um pouco de Paz" << std::endl;
     interface_descanso();
    while (true) { // Menu de opções para o herói durante o descanso
        interface_descanso();
        interface_Status_Heroi(heroi);

        std::cout << "\nO que deseja fazer:\n";
        std::cout << "1 - Trocar arma\n";
        std::cout << "2 - Usar poção\n";
        std::cout << "3 - Gerenciar inventário\n";
        std::cout << "4 - Sair\n";
        std::cout << "Escolha uma opção: ";
        
        std::cin >> escolha;

        if (std::cin.fail()) { // Verifica se a entrada é válida
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            std::cout << "⚠️ Entrada inválida. Digite 1, 2, 3 ou 4." << std::endl;
            continue; // Volta ao início do loop
        }

        switch (escolha) {
            case 1: { // Trocar Arma
                std::cout << "🔄 Trocar arma" << std::endl;
                trocar_arma_menu(heroi);
                break;
            }
            case 2: { // Usar poção
                std::cout << "💧 Utilizando poção..." << std::endl;
                heroi.usa_pocao(); // Função para usar poção
                std::cout << "❤️ Você ficou com um total de: " << heroi.exibe_vida() << " de vida!" << std::endl;
                break;
            }
            case 3: { // Gerenciar inventário 
                std::cout << "📦 Abrindo inventário..." << std::endl;
                gerenciar_iventario(heroi); // Função para gerenciar o inventário do herói
                break;
            }
            case 4: { // Sair
                std::cout << "➡️ Voltando à aventura..." << std::endl;
                return; // Sai da função e retorna à aventura
            }
            default:
                std::cout << "⚠️ Opção inválida. Escolha 1, 2, 3 ou 4." << std::endl;
        }
    }
}


void Mapa::gerenciar_iventario(Personagem& heroi) { 
    // Função para gerenciar o inventário do herói durante o SQM de descanso
    int escolha = 0;
    interface_descanso(); // Exibe imagem para quando o personagem cai num SQM de descanso
    do { // Menu de opções para gerenciar o inventário
        interface_descanso(); // Exibe imagem para quando o personagem cai num SQM de descanso
        interface_Status_Heroi(heroi);

        int posicao1 = 0, posicao2 = 0;
        Item* item_temp = nullptr;

        while (true) { // Pede a escolha do jogador
            std::cout << "\nO que deseja fazer:\n";
            std::cout << "1 - Trocar posição no cinto\n";
            std::cout << "2 - Descartar item do cinto\n";
            std::cout << "3 - Colocar item do cinto na mochila\n";
            std::cout << "4 - Descartar item da mochila\n";
            std::cout << "5 - Sair\n";
            std::cout << "Escolha uma opção: ";
            std::cin >> escolha;

            if (std::cin.fail()) { // Verifica se a entrada é válida
                std::cin.clear();
                std::cin.ignore(32767, '\n');
                std::cout << "⚠️ Entrada inválida. Digite 1, 2, 3, 4 ou 5." << std::endl;
            } else {
                break;
            }
        }

        

        switch (escolha) { // Realiza a ação escolhida pelo jogador
            case 1: { // Trocar posição no cinto
                while (true) { // Pede a posição dos itens que o jogador deseja trocar
                    std::cout << "           Itens do Cinto do Herói:        " << std::endl;
                    std::cout << "-----------------------------------------------" << std::endl;
                    heroi.mostrar_cinto(); // Mostra o cinto do herói
                    std::cout << "-----------------------------------------------" << std::endl;
                    std::cout << "Qual item deseja trocar? Informe a posição: ";
                    std::cin >> posicao1;
                    if (std::cin.fail()) { // Verifica se a entrada é válida
                        std::cin.clear();
                        std::cin.ignore(32767, '\n');
                        std::cout << "⚠️ Entrada inválida." << std::endl;
                    } else {
                        break;
                    }
                }

                while (true) { // Pede a posição para colocar o item
                    std::cout << "Qual posição deseja colocar o item? ";
                    std::cin >> posicao2;
                    if (std::cin.fail()) { // Verifica se a entrada é válida
                        std::cin.clear();
                        std::cin.ignore(32767, '\n');
                        std::cout << "⚠️ Entrada inválida." << std::endl;
                    } else {
                        break;
                    }
                }

                std::cout << "🔄 Trocando o item de posição no cinto." << std::endl;
                heroi.Trocar_posicao_cinto(posicao1, posicao2); // Função para trocar a posição dos itens no cinto
                break;
            }
            case 2: { // Descartar item do cinto
                while (true) { // Pede a posição do item que o jogador deseja remover
                    std::cout << "           Itens do Cinto do Herói:        " << std::endl;
                    std::cout << "-----------------------------------------------" << std::endl;
                    heroi.mostrar_cinto(); // Mostra o cinto do herói
                    std::cout << "-----------------------------------------------" << std::endl;                    std::cout << "Informe a posição que deseja remover do cinto: ";
                    std::cin >> posicao1;
                    if (std::cin.fail()) { // Verifica se a entrada é válida
                        std::cin.clear();
                        std::cin.ignore(32767, '\n');
                        std::cout << "⚠️ Entrada inválida." << std::endl;
                    } else {
                        break;
                    }
                }

                heroi.Remover_cinto(item_temp, posicao1); // Função para remover o item do cinto
                std::cout << "🗑️ Item descartado do cinto." << std::endl;
                break;
            }
            case 3: { // Colocar item do cinto na mochila
                    std::cout << "           Itens do Cinto do Herói:        " << std::endl;
                    std::cout << "-----------------------------------------------" << std::endl;
                    heroi.mostrar_cinto(); // Mostra o cinto do herói
                    std::cout << "-----------------------------------------------" << std::endl;                while (true) { // Pede a posição do item que o jogador deseja transferir para a mochila
                    std::cout << "Informe a posição do item que será transferido para a mochila: ";
                    std::cin >> posicao1;
                    if (std::cin.fail()) { // Verifica se a entrada é válida
                        std::cin.clear();
                        std::cin.ignore(32767, '\n');
                        std::cout << "⚠️ Entrada inválida." << std::endl;
                    } else {
                        break;
                    }
                }

                heroi.transfere_para_mochila(item_temp, posicao1); // Função para transferir o item do cinto para a mochila
                break;
            }
            case 4: { // Descartar item da mochila
                std::cout << "Descartando o item da mochila..." << std::endl;
                heroi.retirar_item_mochila(item_temp); // Função para retirar o item da mochila
                std::cout << "🗑️ Item descartado da mochila." << std::endl;
                break;
            }
            case 5: { // Sair
                std::cout << "➡️ Saindo do gerenciamento de inventário..." << std::endl;
                break;
            }
            default:
                std::cout << "⚠️ Opção inválida. Escolha 1, 2, 3, 4 ou 5." << std::endl;
                break;
        }
    } while (escolha != 5);
}


// Função auxiliar para trocar arma
void Mapa::trocar_arma_menu(Personagem& heroi) {
    int escolha = 0;

    // Exibe a arma que está atualmente equipada (na mão)
    if (!heroi.mostrar_arma_equipada().get_nome().empty()) {
        std::cout << "🔫 Arma atualmente equipada: " 
                  << heroi.mostrar_arma_equipada().get_nome() 
                  << " (Dano: " << heroi.mostrar_arma_equipada().get_dano() << ")"
                  << std::endl;
    } else {
        std::cout << "⚠️ Você não tem nenhuma arma equipada." << std::endl;
    }

    // Pergunta se deseja trocar de arma
    std::cout << "Deseja trocar a arma? (1 - Sim, 2 - Não)" << std::endl;
    std::cin >> escolha;

    if (escolha == 1) {
        // Opção para escolher se quer pegar uma arma do cinto ou da mochila
        while (true) {
            std::cout << "\nEscolha de onde pegar a nova arma:\n1 - Cinto\n2 - Mochila" << std::endl;
            std::cin >> escolha;

            if (escolha == 1) {
                std::cout << "🔧 Exibindo armas disponíveis no cinto..." << std::endl;
                // Lógica para trocar a arma pelo cinto
                heroi.trocar_arma();
                std::cout << "✅ Nova arma equipada: " << heroi.mostrar_arma_equipada().get_nome() << std::endl;
                break; // Adicionado para sair do loop após a troca
            } else if (escolha == 2) {
                std::cout << "📦 Exibindo armas disponíveis na mochila..." << std::endl;
                // Lógica para trocar a arma pela mochila
                heroi.trocar_arma_mochila();
                std::cout << "✅ Nova arma equipada: " << heroi.mostrar_arma_equipada().get_nome() << std::endl;
                break; // Adicionado para sair do loop após a troca
            } else {
                std::cout << "⚠️ Escolha inválida. Digite 1 ou 2." << std::endl;
            }
        }
    } else {
        std::cout << "🔒 Mantendo a arma atual." << std::endl;
    }
}



#endif 