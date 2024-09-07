#include <iostream>
#include <random>
#include <cstdlib>
#include "heroi.h"
#include "monstro.h"

using namespace std;

const double danoHeroi = 5;
const double danoMonstro = 3.5;

bool Lutar(int hp, int hpmonstro, int ataque) {
	int Destreza = 0;
	unsigned seed = time(0);
	Monstro Monstro;

	srand(seed);
	Destreza = 1 + rand() % 20;
	if (Destreza > 5) {
		cout << "Seu Primeiro ataque foi um sucesso ! " << endl;
		ataque = 1 + rand() % 20;
		if (ataque < 15) {
			Monstro.HpMonstro -= danoHeroi;
		}
		else if (ataque >= 15) {
			Monstro.HpMonstro -= danoHeroi * 2;
		}

	}
	else (Destreza <= 5) {
		cout << "Voce foi muito lento!" << endl;

		ataque = 1 + rand() % 20;
		if (ataque < 18) {
			meuHeroi.hp -= danoMonstro;
		}
		else(ataque >= 18) {
			meuHeroi.hp -= danoMonstro * 1.25;
		}

	}


}


int main() {
	Heroi meuHeroi;
	Monstro Monstro;
	cout << "Voce encontrou um monstro, o que voce deseja fazer? " << endl;
	int escolha = 0;
	do {
		cout << "===============================" << endl;
		cout << "1. Lutar " << endl;
		cout << "2. Usar Item " << endl;
		cout << "3. Fugir " << endl;
		cout << "===============================" << endl;
		cin >> escolha;
		switch (escolha) {

		case 1: Lutar();
			break;
		case 2: UsarItem();
			break;
		case 3: Fugir();
			break;

		default:
			cout << "Opção invalida!" << endl;

			break;
		}
	} while (meuHeroi.hp > 0 && Monstro.HpMonstro > 0)


}
