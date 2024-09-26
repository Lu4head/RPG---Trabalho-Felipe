#pragma once // pragma once para não espelhar os arquivos importados

#include <string>

class Item {
    public: // Metodos publicos
        // Construtores e Destrutores
        Item(std::string nome_item, float peso_item, std::string tipo_do_item,int nivel); // Construtor para item
        Item(); // Construtor padrão para criação de array / Item temporário
        virtual ~Item() = default; // Destrutor padrão
        
        // Getters
        std::string get_nome(); // Função para retornar o nome do item
        std::string get_tipo_do_item(); // Função para retornar o tipo do item
        float get_peso(); // Função para retornar o peso do item
        int get_nivel(); // Função para retornar o nivel do item
        
    protected: // Atributos
        int nivel;
        std::string nome_item;
        std::string tipo_do_item;
        float peso_item;
};

