#include "Data.hpp"
#include "Serializer.hpp"

int main() {
    Data da(50, "Chats");
    std::cout << da << std::endl;

    uintptr_t sz = Serializer::serialize(&da);
    std::cout << "Serialize data << operator: " << sz << std::endl;

    Data *new_da = Serializer::deserialize(sz);
    std::cout << *new_da << std::endl;
    return 0;
}