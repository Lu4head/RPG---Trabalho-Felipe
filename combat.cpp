#include "./classes/Personagem.h"
#include "./classes/Monstro.h"
#include "./classes/equipamento.h"
#include <iostream>
#include "./classes/combate.h"
extern Pocao pocao_de_cura_forte;

void combate(Personagem &heroi, Monstro &mob){
    std::cout << "Iniciando o combate entre: " << heroi.exibe_nome() << " VS " <<  mob.exibe_nome() << std::endl;

    while(heroi.exibe_vida() > 0 && mob.exibe_vida() > 0){
        int escolha;
        std::cout << "Escolha uma opção:\n1 - atacar\n2 - Usar pocao\n3 - Trocar arma\n4 - Pegar item da mochila" << std::endl;
        std::cin >> escolha;

        switch(escolha) {
            case 1:
                std::cout << heroi.exibe_nome() << " atacou " << mob.exibe_nome() << std::endl;
                mob.recebe_dano(heroi.mostrar_arma_equipada().get_dano());
                std::cout << heroi.exibe_nome() << "causou um dano de: " << heroi.mostrar_arma_equipada().get_dano() << " O monstrou ficou com: " << mob.exibe_vida() << "de vida" << std::endl;
                break;
            case 2:
                std::cout << "Utilizando poção" << std::endl;
                heroi.usa_pocao();
                std::cout << "Ficou com um total de: " << heroi.exibe_vida() << " vida!" << std::endl;
                break;
            case 3:
                std::cout << "Trocando arma" << std::endl;
                heroi.trocar_arma();
                std::cout << "Arma nova: " << heroi.mostrar_arma_equipada().get_nome() << " - " << heroi.mostrar_arma_equipada().get_dano() << std::endl;
            default:
                std::cout << "Escolha invalida" << std::endl;
                continue;
        }
        if (mob.exibe_vida() > 0) {
            std::cout << mob.exibe_nome() << " ataca " << heroi.exibe_nome() << std::endl;
            heroi.recebe_dano(mob.aplica_dano_fisico()); 
            std::cout << mob.exibe_nome() << " causou um dano de: " << mob.aplica_dano_fisico() << ". " << heroi.exibe_nome() << " ficou com: " << heroi.exibe_vida() << " de vida" << std::endl;
        } else {
            std::cout << mob.exibe_nome() << " foi derrotado!" << std::endl;
        }
    }

    if (heroi.exibe_vida() <= 0) {
        std::cout << heroi.exibe_nome() << " foi derrotado!" << std::endl;
    } else if (mob.exibe_vida() <= 0) {
        std::cout << heroi.exibe_nome() << " venceu o combate!" << std::endl;
    }
}