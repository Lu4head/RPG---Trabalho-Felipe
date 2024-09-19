#include ".\classes\Monstro.h"
#include <iostream>
#include <string>

Monstro::Monstro(std::string nome, float vida_total, float mana_total, float dano_fisico, float dano_magico) 
    : nome(nome), vida_total(vida_total),vida_atual(vida_total),mana_total(mana_total), mana_atual(mana_total),dano_fisico(dano_fisico), dano_magico(dano_magico), nivel(1){
    }


void Monstro::recebe_dano(float x){
   if(vida_atual - x > 0){
         vida_atual = vida_atual - x;
   } else {
      vida_atual = 0;
   }
}
void Monstro::gasta_mana(float custo){
   if(mana_atual - custo < 0){
      std::cout << "Monstro está sem mana" << std::endl;
      return;
   }else{
      mana_atual = mana_atual - custo;
   }
} 
 
float Monstro::exibe_vida(){
    return vida_atual;
 }

std::string Monstro::exibe_nome(){
    return nome;
 }

 float Monstro::aplica_dano_fisico(){
   return dano_fisico;
 }

 float Monstro::aplica_dano_magico(){
   return dano_magico;
 }
