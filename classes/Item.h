#pragma once
#include <string>

class Item {
public:
    Item(std::string nome_item, float peso_item);

    Item(); // para criar um array

    std::string get_nome();
    std::string get_tipo_do_item();

private:
    std::string nome_item;
    std::string tipo_do_item;
    float peso_item;
};

