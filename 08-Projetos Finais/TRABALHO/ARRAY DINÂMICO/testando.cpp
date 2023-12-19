#include "array_list.hpp"
#include <iostream>

int main()
{
    array_list lista1(100);
    for (int i = 0; i < 10; i+=1)
    {
        lista1.push_back(i);
    }
    lista1.insert_at(10,99 ); // Inserindo no final funcionando.
    lista1.remove_at(0); // Removendo do começo funcionando
    lista1.insert_at(0,99 ); // Inserindo no Final funcionando
    lista1.insert_at(5, 99); // Inserindo no meio funcionando

    int size = lista1.size();
    std::cout << "Size: " << size << std::endl;
    std::cout << "Soma: " << lista1.sum() << std::endl;
    std::cout << "Count: " << lista1.count(99) << std::endl;
    std::cout << "Find: " << lista1.find(1) << std::endl;
    std::cout << "Capacidade: " << lista1.capacity() << std::endl;
    std::cout << "Porcentagem Usada: " << lista1.percent_occupied() << std::endl;
    std::cout << "Valor: " << lista1.get_at(5) << std::endl;
    lista1.remove(5);
    std::cout << "Size: " << lista1.size() << std::endl;
    size = lista1.size();
    std::cout << "lista1 = { ";
    // for (int i=0 ; i< size; i++){
    //     std::cout << lista1.front() << " "; // Testando popfront
    //     lista1.pop_front();
    // }
    for (int i=0 ; i< size; i++){
        std::cout << lista1.back() << " "; // Testando popback
        lista1.pop_back();
    }
    std::cout << "}" << std::endl;
    std::cout << "Size: " << lista1.size() << std::endl;
    std::cout << "Porcentagem Usada: " << lista1.percent_occupied() << std::endl;

    return 0;
}
