
#include ".\classes\mapa.h"
#include <iostream>
using namespace std;

int main() {
    Mapa mapa;
    mapa.colocar_heroi(0, 0); // Coloca o herói na posição (0, 0) - INICIAL
    mapa.mostrar_mapa(); // Exibe o mapa 
char movimento;
    while (true) {
        cout << "Digite a direção para mover o herói (w = cima, s = baixo, a = esquerda, d = direita, q = sair): ";
        cin >> movimento;

        if (movimento == 'q') {
            break; // Sai do loop se 'q' for pressionado
        }

        mapa.mover_heroi(movimento);

        cout << "Mapa Após Movimento:" << endl;
        mapa.mostrar_mapa();
    }

    return 0;
}
