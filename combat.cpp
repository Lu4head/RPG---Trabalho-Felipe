#include <iostream> // Biblioteca para entrada e saída de dados
#include <fstream> // Biblioteca para manipulação de arquivos
#include <ctime> // Biblioteca para manipulação de tempo

#include "./classes/Personagem.h"
#include "./classes/Monstro.h"
#include "./classes/equipamento.h"
#include "./classes/combate.h"

void combate(Personagem &heroi, Monstro &mob) { // Função para controlar as ações do combate
    std::cout << "Iniciando o combate entre: " << heroi.exibe_nome() << " VS " << mob.exibe_nome() << std::endl;

    while (heroi.exibe_vida() > 0 && mob.exibe_vida() > 0) { // Verifica se ambos monstro e heroi estão vivos
        int escolha;
        int custo_mana = 0;

        while(true){ // Pede a escolha do jogador
            std::cout << "Escolha uma opção:\n1 - Atacar \n2 - Usar pocao\n3 - Trocar arma" << std::endl;
            std::cin >> escolha;
            if(std::cin.fail()){ // Verifica se a entrada é válida
                std::cin.clear();
                std::cin.ignore(32767, '\n');
                std::cout << "Entrada inválida." << std::endl;
            } else { // Se a entrada for válida, sai do loop
                break;
            }
        }        

        switch (escolha) { // Realiza a ação escolhida pelo jogador
            case 1: // Ataque físico
                std::cout << heroi.exibe_nome() << " atacou " << mob.exibe_nome() << std::endl;
                custo_mana = heroi.mostrar_arma_equipada().get_custo_mana();
                if(heroi.gasta_mana(custo_mana) == 0){
                    mob.recebe_dano(heroi.mostrar_arma_equipada().get_dano());
                }
                std::cout << heroi.exibe_nome() << " causou um dano de: " << heroi.mostrar_arma_equipada().get_dano() << ". O monstro ficou com: " << mob.exibe_vida() << " de vida" << std::endl;
                break;
            case 2: // Usar poção
                std::cout << "Utilizando poção" << std::endl;
                heroi.usa_pocao(); // Função para usar poção
                std::cout << "Ficou com um total de: " << heroi.exibe_vida() << " de vida!" << std::endl;
                break;
            case 3: // Trocar arma
                std::cout << "Trocando arma" << std::endl;
                heroi.trocar_arma();
                std::cout << "Nova arma: " << heroi.mostrar_arma_equipada().get_nome() << " - Dano: " << heroi.mostrar_arma_equipada().get_dano() << std::endl;
                break;
            default:
                std::cout << "Escolha inválida" << std::endl;
                continue;
        }

        // Verifica se o monstro ainda está vivo e realiza contra-ataque
        if (mob.exibe_vida() > 0) { // Verifica se o monstro ainda está vivo
            std::cout << mob.exibe_nome() << " ataca " << heroi.exibe_nome() << std::endl;
            heroi.recebe_dano(mob.aplica_dano_fisico()); // Função para calcular dano recebido pelo herói com base no dano do monstro
            std::cout << mob.exibe_nome() << " causou um dano de: " << mob.aplica_dano_fisico() << ". " << heroi.exibe_nome() << " ficou com: " << heroi.exibe_vida() << " de vida" << std::endl;
        } else { // Se o monstro foi derrotado
            std::cout << mob.exibe_nome() << " foi derrotado!" << std::endl;
            // Herói ganha XP ao derrotar o monstro
            int xp_ganho = mob.get_recompensa_xp(); // Função para calcular a recompensa de XP ao derrotar o monstro
            std::cout << heroi.exibe_nome() << " ganhou " << xp_ganho << " XP!" << std::endl;
            heroi.ganha_xp(xp_ganho);  // Função para adicionar XP  ao herói
        }
    }

    // Resultado do combate
    if (heroi.exibe_vida() <= 0) { // Se o herói foi derrotado
        std::cout << heroi.exibe_nome() << " foi derrotado!" << std::endl;
        salvar_dados_personagem(heroi); // Salva os dados do personagem no arquivo high_scores.txt
        abort(); // Encerra o programa
    } else if (mob.exibe_vida() <= 0) { // Se o monstro foi derrotado
        std::cout << heroi.exibe_nome() << " venceu o combate!" << std::endl; // Mensagem de vitória
    }
}


void salvar_dados_personagem(Personagem& p){ // Função para salvar os dados do personagem no arquivo high_scores.txt
    std::ofstream arquivo_saida("High_scores.txt", std::ios::app); // Abre o arquivo para escrita
     if (arquivo_saida.is_open()) { // Verifica se o arquivo foi aberto
        std::time_t t = std::time(nullptr); // Pega o tempo atual
        char buffer[100]; // Buffer para armazenar a data e hora
        std::strftime(buffer, sizeof(buffer), "%d/%m/%Y %H:%M:%S", std::localtime(&t)); // Formatar a data e hora

        arquivo_saida << "Personagem: " << p.exibe_nome() << "\n"; // Escreve os dados do personagem no arquivo
        arquivo_saida << "Nível final: " << p.get_nivel() << "\n"; // Escreve o nível final do personagem
        arquivo_saida << "Salvo em: " << buffer << "\n"; // Escreve a data e hora da última jogada
        arquivo_saida << "-------------------" << "\n"; 
        arquivo_saida.close(); // Fecha o arquivo
        std::cout << "Os dados do personagem foram salvos com sucesso!" << std::endl;
    } else { // Se o arquivo não foi aberto
        std::cerr << "Erro ao abrir o arquivo!" << std::endl;
    }
}