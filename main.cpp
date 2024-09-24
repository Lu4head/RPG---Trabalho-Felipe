
#include ".\classes\Mapa.h"
#include ".\classes\Cinto.h"
#include ".\classes\Arma.h"
#include ".\classes\Pocao.h"
#include ".\classes\Item.h"
#include ".\classes\Interface.h"
#include <iostream>
#include <conio.h> // função getch()
#include <cstdlib> // funções system() e rand()
#include <ctime>   // função time()
#include <locale.h> // Definir linguagem do terminal - setlocale()

using namespace std;

int main() {
    setlocale(LC_ALL, "pt_BR.UTF-8");
    
    // Inicializa o gerador de números aleatórios
    srand(static_cast<unsigned int>(time(0)));

    Interface interface_jogo;

    std::string nome_personagem = "";
    std::string arma_inicial = "";

    interface_jogo.creditos();
    interface_jogo.abertura();
    interface_jogo.personagem(nome_personagem);

    Personagem heroi(nome_personagem);
    
    interface_jogo.EscolherArmaInicial(nome_personagem, arma_inicial);
    // Instanciando o cinto e o heroi
    cout << "Arma inicial = " << arma_inicial << endl;


    // Criando alguns itens de exemplo
    Arma Katana("Nikana", 1.5f, "Destreza", 20.0f);
    heroi.Equipar_arma(&Katana);

    // Colocar herói no mapa
    Mapa mapa;
    mapa.colocar_heroi(0, 0);
    mapa.mostrar_mapa(heroi);
    
    char movimento;
    while (true) {
        cout << "Digite a direção para mover o herói (w = cima, s = baixo, a = esquerda, d = direita, q = sair): ";
        movimento = getch();

        if (movimento == 'q') {
            break; 
        }

        mapa.mover_heroi(movimento, heroi);
        
        // Sorteia se um item será encontrado
        int sorteio = rand() % 3; // Pode resultar em 0 (nada), 1 (item), ou 2 (combate)
        
        if (sorteio == 1) { // Encontrou item
            cout << "Você encontrou um item!" << endl;


        
        system("cls"); // Limpar a tela do console
        mapa.mostrar_mapa(heroi);
    }

    
    }
    return 0;
}
