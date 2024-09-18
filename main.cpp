
#include ".\classes\Mapa.h"
#include ".\classes\Cinto.h"
#include ".\classes\Arma.h"
#include ".\classes\Pocao.h"
#include ".\classes\Item.h"
#include <iostream>
#include <conio.h> // função getch()
#include <cstdlib>  // função system()
#include <locale.h> // Definir linguagem do terminal - setlocale()
using namespace std;

int main() {
    setlocale(LC_ALL, "pt_BR.UTF-8");
    
    // Instanciando o cinto
    Cinto cinto;

    // Criando alguns itens de exemplo
    Arma Katana("Nikana", 1.5f, 20.0f,"Destreza");
    Pocao pocao_de_cura_fraca("Pocao de cura fraca", 1.0,15,0,"Cura");

    // Colocar herói no mapa
    Mapa mapa;
    mapa.colocar_heroi(0, 0);
    mapa.mostrar_mapa();
    
    char movimento;
    while (true) {
        cout << "Digite a direção para mover o herói (w = cima, s = baixo, a = esquerda, d = direita, q = sair): ";
        movimento = getch();

        if (movimento == 'q') {
            break; 
        }

        mapa.mover_heroi(movimento);
        
        // Sorteia se um item será encontrado
        int sorteio = rand() % 3; // Pode resultar em 0 (nada), 1 (item), ou 2 (combate)
        
        if (sorteio == 1) { // Encontrou item
            cout << "Você encontrou um item!" << endl;

            // Podemos adicionar itens ao cinto
            if (!cinto.Cinto_cheio()) {
                cinto.Colocar_item(Katana, cinto.espacos_disponiveis());
                cout << "Você adicionou " << Katana.get_nome() << " ao cinto!" << endl;
            } else {
                cout << "Cinto cheio! Não foi possível pegar o item." << endl;
            }
        } else if (sorteio == 2) {
            cout << "Você entrou em combate!" << endl;
        } else {
            cout << "Nada aconteceu..." << endl;
        }
        
        system("cls");
        mapa.mostrar_mapa();
    }

    return 0;
}
