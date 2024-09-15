#include <string>
class Item {
public:
    Item(std::string nome_item, float peso_item);

private:
    std::string nome_item;
    float peso_item;
};