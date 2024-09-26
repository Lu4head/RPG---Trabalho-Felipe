#pragma once  // pragma once para não espelhar os arquivos importados

#include "Item.h" // Importação da classe item que vai ser usado para interagir o cinto, o cinto é uma lista de itens...
#include "pocao.h" // Importação da classe pocao, que vai ser usada para curar a vida ou recuperar a mana do personagem 
#include "arma.h" // Importação da classe arma, vai ser usada para passar uma arma para o slot de uso do heroi, para dar dano

const int MaxList = 9; // Tamanho da lista

class Cinto{
    public: // Metodos publicos
        // Construtor e destrutor  
        Cinto(); // construtor padrão
        ~Cinto(); // Destrutor padrão

        // Status
        bool Cinto_vazio(); // Verificação se o cinto está vazio
        bool Cinto_cheio(); // Verificação se o cinto está cheio

        // Operações Básicas
        int Colocar_item(Item* item, int posicao); // Operação de colocar um item no cinto, o cinto é um ponteiro para itens, por isso que é passado um ponteiro de itens como parametro e a posição na qual o usuario quer inserir
        int Remover_item(Item* &item_retorno, int posicao); // Operação para remover um item da lista, é passado novamente um item como ponteiro pq a lista é uma lista de ponteiros, porem tem uma referência, pois é necessário mudar esse item fora do escopo da função

        // Operações Extras
        int Trocar_posicao(int p1, int p2); // Troca a posição do item com algum outro da lista
        //int Esvaziar_cinto(); 
        int espacos_disponiveis(); // verificar se tem algum espaço disponivel 
        int mostrar_itens(); // Mostra todos os itens no cinto
        void definir_capacidade(int x); // Define a capacidade de peso do cinto
        int equipar_arma(Arma* &arma); // Seta a arma no slot de uso do heroi
        int usar_pocao(Pocao* &pocao); // usar ou remover item, passado 
    private:
        Item* Entry[MaxList + 1]; // Lista de itens, é um ponteiro para itens, pois a lista é uma lista de ponteiros
        int peso_max;
        int peso_ocupado;
        int count;
};