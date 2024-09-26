
#include ".\classes\Mapa.h"
#include ".\classes\Cinto.h"
#include ".\classes\Arma.h"
#include ".\classes\Pocao.h"
#include ".\classes\Item.h"
#include ".\classes\Interface.h"
#include ".\classes\combate.h"

#include <iostream> // Biblioteca para entrada e saída de dados
#include <conio.h> // função getch()
#include <cstdlib> // funções system() e rand()
#include <ctime>   // função time()
#include <locale.h> // Definir linguagem do terminal - setlocale()

int main() {
    setlocale(LC_ALL, "pt_BR.UTF-8");
    
    // Inicializa o gerador de números aleatórios
    srand(static_cast<unsigned int>(time(0)));

    // Variáveis auxiliares para inicização do personagem
    std::string nome_personagem = "";
    Arma arma_inicial;

    // Interface inicial
    interface_creditos(); // Exibe os créditos do jogo
    interface_abertura(); // Exibe tela inicial do jogo
    interface_personagem(nome_personagem); // Exibe tela para escolha do nome do personagem

    Personagem heroi(nome_personagem); // Instancia o personagem heroi
    
    interface_arma_inicial(nome_personagem, arma_inicial); // Interfape para escolha da arma inicial do heroi

    heroi.Equipar_arma(&arma_inicial); // Equipa a arma inicial escolhida no heroi

    // Colocar herói no mapa
    Mapa mapa; // Instancia o mapa
    mapa.colocar_heroi(0, 0); // Coloca o herói na posição (0, 0) do mapa
    mapa.mostrar_mapa(heroi); // Mostra o mapa com a posição do herói
    
    char movimento;

    while (true) { // Loop principal do jogo - Solicitando o movimento do personagem no mapa
        std::cout << "Digite a direção para mover o herói (w = cima, s = baixo, a = esquerda, d = direita, q = sair): ";
        movimento = getch();

        if (movimento == 'q') { // Verifica se o jogador deseja sair do jogo
            std::cout << "Deseja mesmo encerrar o jogo? (s/n): ";
            char resposta = getch();
            if (resposta == 's') {
                salvar_dados_personagem(heroi); // Salva os dados do personagem
                break; // Encerra o jogo
            }
        }

        mapa.mover_heroi(movimento, heroi); // Move o herói no mapa de acordo com o movimento escolhido
        
        // Sorteia se um item será encontrado
        int sorteio = rand() % 3; // Pode resultar em 0 (nada), 1 (item), ou 2 (combate)
        
        if (sorteio == 1) { // Encontrou item
            std::cout << "Você encontrou um item!" << std::endl;
            system("cls"); // Limpar a tela do console
            mapa.mostrar_mapa(heroi); // Mostra o mapa com a posição do herói
        }
    }
    return 0;
}
