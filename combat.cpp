#include "./classes/Personagem.h"
#include "./classes/Monstro.h"
#include "./classes/equipamento.h"
#include <iostream>
#include "./classes/combate.h"
extern Pocao pocao_de_cura_forte;

void combate(Personagem &heroi, Monstro &mob) {
    std::cout << "Iniciando o combate entre: " << heroi.exibe_nome() << " VS " << mob.exibe_nome() << std::endl;

    while (heroi.exibe_vida() > 0 && mob.exibe_vida() > 0) {
        int escolha;
        std::cout << "Escolha uma opção:\n1 - Atacar fisicamente\n2 - Usar pocao\n3 - Trocar arma\n4 - Usar ataque mágico\n5 - Pegar item da mochila" << std::endl;
        std::cin >> escolha;

        switch (escolha) {
            case 1:
                std::cout << heroi.exibe_nome() << " atacou " << mob.exibe_nome() << std::endl;
                mob.recebe_dano(heroi.mostrar_arma_equipada().get_dano());
                std::cout << heroi.exibe_nome() << " causou um dano de: " << heroi.mostrar_arma_equipada().get_dano() << ". O monstro ficou com: " << mob.exibe_vida() << " de vida" << std::endl;
                break;
            case 2:
                std::cout << "Utilizando poção" << std::endl;
                heroi.usa_pocao();
                std::cout << "Ficou com um total de: " << heroi.exibe_vida() << " de vida!" << std::endl;
                break;
            case 3:
                std::cout << "Trocando arma" << std::endl;
                heroi.trocar_arma();
                std::cout << "Nova arma: " << heroi.mostrar_arma_equipada().get_nome() << " - Dano: " << heroi.mostrar_arma_equipada().get_dano() << std::endl;
                break;
            case 4:
                // Novo ataque mágico
                if (heroi.gasta_mana(20)) {  // Supondo que o custo de mana seja 20
                    std::cout << heroi.exibe_nome() << " usou ataque mágico contra " << mob.exibe_nome() << std::endl;
                    mob.recebe_dano(heroi.mostrar_arma_equipada().get_dano() * 1.5);  // 50% mais dano
                    std::cout << "Ataque mágico causou dano de: " << heroi.mostrar_arma_equipada().get_dano() * 1.5 << ". O monstro ficou com: " << mob.exibe_vida() << " de vida" << std::endl;
                } else {
                    std::cout << "Mana insuficiente!" << std::endl;
                }
                break;
            default:
                std::cout << "Escolha inválida" << std::endl;
                continue;
        }

        // Verifica se o monstro ainda está vivo e realiza contra-ataque
        if (mob.exibe_vida() > 0) {
            std::cout << mob.exibe_nome() << " ataca " << heroi.exibe_nome() << std::endl;
            heroi.recebe_dano(mob.aplica_dano_fisico());
            std::cout << mob.exibe_nome() << " causou um dano de: " << mob.aplica_dano_fisico() << ". " << heroi.exibe_nome() << " ficou com: " << heroi.exibe_vida() << " de vida" << std::endl;
        } else {
            std::cout << mob.exibe_nome() << " foi derrotado!" << std::endl;
            // Herói ganha XP ao derrotar o monstro
            int xp_ganho = mob.get_recompensa_xp();
            std::cout << heroi.exibe_nome() << " ganhou " << xp_ganho << " XP!" << std::endl;
            heroi.ganha_xp(xp_ganho);  // Função para adicionar XP  ao herói
        }
    }

    // Resultado do combate
    if (heroi.exibe_vida() <= 0) {
        std::cout << heroi.exibe_nome() << " foi derrotado!" << std::endl;
        abort();
    } else if (mob.exibe_vida() <= 0) {
        std::cout << heroi.exibe_nome() << " venceu o combate!" << std::endl;
    }
}
