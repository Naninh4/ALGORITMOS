#include "linked_list.hpp"
#include <iostream>

int main()
{
    linked_list lista1 ;
    for (int i = 0; i < 10; i+=1)
    {
        lista1.push_back(i);
    }

    lista1.remove_at(0); 
    lista1.insert_at(0,99 ); 
    lista1.insert_at(5, 99); 
    lista1.insert_at(10,99);

    int size = lista1.size();
    std::cout << "Esta vazio? 1-Sim | 0-Nao -> " << lista1.empty() << std::endl;
    std::cout << "Size: " << size << std::endl;
    std::cout << "Soma: " << lista1.sum() << std::endl;
    std::cout << "Count: " << lista1.count(99) << std::endl;
    std::cout << "Find: " << lista1.find(1) << std::endl;
    std::cout << "Capacidade: " << lista1.capacity() << std::endl;
    std::cout << "Porcentagem Usada: " << lista1.percent_occupied() << std::endl;
    std::cout << "Valor: " << lista1.get_at(5) << std::endl;
    std::cout << "lista1 = { ";
    lista1.remove(5);
    size = lista1.size();
    for (int i=0 ; i< size; i++){
        std::cout << lista1.front() << " "; // Testando popfront
        lista1.pop_front();
    }
    // for (int i=0 ; i< size; i++){
    //     std::cout << lista1.back() << " "; // Testando popback
    //     lista1.pop_back();
    // }


    std::cout << "}" << std::endl;
    std::cout << "Size: " << lista1.size() << std::endl;
    std::cout << "Porcentagem Usada: " << lista1.percent_occupied() << std::endl;
    for (int i = 0; i < 10; i+=1)
    {
        lista1.push_back(i);
    }
    return 0;
}
