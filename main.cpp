
#include ".\classes\mapa.h"
#include <iostream>
#include <conio.h> // função getch()
#include <cstdlib>  // função system()
#include <locale.h> // Definir linguagem do terminal - setlocale()
using namespace std;

int main() {
    setlocale(LC_ALL, "pt_BR.UTF-8");
    Mapa mapa;
    mapa.colocar_heroi(0, 0); // Coloca o herói na posição (0, 0) - INICIAL
    mapa.mostrar_mapa(); // Exibe o mapa 
char movimento;
    while (true) {
        cout << "Digite a direção para mover o herói (w = cima, s = baixo, a = esquerda, d = direita, q = sair): ";
        movimento = getch();

        if (movimento == 'q') {
            break; // Sai do loop se 'q' for pressionado
        }

        mapa.mover_heroi(movimento);

        cout << "Mapa Após Movimento:" << endl;
        system("cls");
        mapa.mostrar_mapa();
    }

    return 0;
}
