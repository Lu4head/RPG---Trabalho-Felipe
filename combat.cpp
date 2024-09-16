#pragma once
#include <iostream>
#include <random>
#include <cstdlib>
#include "./classes/Personagem.h"
#include "lista_de_monstros.cpp"
#include "lista_de_monstros.cpp"

using namespace std;

bool Batalha(Personagem heroi, Monstro monstro) {
	unsigned seed = time(0);
	int destreza;
	srand(seed);
	destreza = 1 + rand() % 20;
	if (destreza > 5) {
		cout << "Seu Primeiro ataque foi um sucesso ! " << endl;
		int ataque = 1 + rand() % 20;
		if (ataque < 15) {
			Monstro.HpMonstro -= danoHeroi;
		}
		else if (ataque >= 15) {
			Monstro.HpMonstro -= danoHeroi * 2;
		}

	}
	else (destreza <= 5) {
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


void simula_batalha() {
	Personagem heroi;
	Monstro monstro;
	int x, y;
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
			cout << "Op��o invalida!" << endl;

			break;
		}
	heroi.exibe_vida(x);
	} while ( x > 0 && monstro.HpMonstro > 0)


}
