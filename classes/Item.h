#pragma once
#include <string>

class Item {
    public:
        Item(std::string nome_item, float peso_item, std::string tipo_do_item,int nivel);

        Item(); // para criar um array
        
        virtual ~Item() = default;

        std::string get_nome();
        std::string get_tipo_do_item();
        float get_peso();
        int get_nivel();
        
    protected:
        int nivel;
        std::string nome_item;
        std::string tipo_do_item;
        float peso_item;
        bool vazio;
};

