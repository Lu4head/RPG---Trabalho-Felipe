#include ".\classes\Monstro.h"

#include <iostream> // Biblioteca para entrada e saída de dados

Monstro::Monstro(std::string nome, float vida_total, float mana_total, float dano_fisico, float dano_magico, int nivel) 
    : nome(nome), vida_total(vida_total ),vida_atual(vida_total),mana_total(mana_total), mana_atual(mana_total),dano_fisico(dano_fisico ), dano_magico(dano_magico), nivel(nivel){};


void Monstro::recebe_dano(float x){ // Função para calcular dano recebido pelo monstro
   if(vida_atual - x > 0){
         vida_atual = vida_atual - x;
   } else {
      vida_atual = 0;
   }
}
void Monstro::gasta_mana(float custo){ // Função para calcular mana gasta por ataque mágicos do monstro
   if(mana_atual - custo < 0){
      std::cout << "Monstro está sem mana" << std::endl;
      return;
   }else{
      mana_atual = mana_atual - custo;
   }
} 
 
float Monstro::exibe_vida(){ // Função que retorna a vida atual do monstro
    return vida_atual;
 }

std::string Monstro::exibe_nome(){ // Função que retorna o nome do monstro
    return nome;
 }

 float Monstro::aplica_dano_fisico(){ // Função que retorna o dano físico do monstro
   return dano_fisico;
 }

 float Monstro::aplica_dano_magico(){ // Função que retorna o dano mágico do monstro
   return dano_magico;
 }

int Monstro::get_nivel(){ // Função que retorna o nível do monstro
   return nivel;
}

// Calcula a recompensa de XP com base no nível do monstro
int Monstro::get_recompensa_xp(){
   return 20 + (nivel * 10); // Exemplo: base de 20 XP, aumentando 10 XP por nível
}
