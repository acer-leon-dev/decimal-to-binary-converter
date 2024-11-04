#include <iostream>
#include <vector>
#include <string>
#include <array> 
#include "list.hpp"

int main()
{
    std::array<int, 10> example_data1 = {2, 4, 8, 16, 64, 128, 256, 512, 1024, 2048};
    std::array<int, 10> example_data2 = {2, 4, 8, 16, 64, 128, 256, 512, 1024, 2048};
    list * exampleList = new list;
    
    for (int &data : example_data1) {
        exampleList->insert(data);
        exampleList->next();
    }

    for (int &data : example_data2) {
        exampleList->prev();
        exampleList->prev();
        exampleList->insert(data);
    }

    std::cout << "List: " << exampleList << std::endl;
    return 0;
}
