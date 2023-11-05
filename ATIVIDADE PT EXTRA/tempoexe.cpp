#include <iostream>
#include <chrono>
#include "array_set.hpp"

int main(){
    array_set as;
    int n; std::cin >> n;
    auto begin_array = std::chrono::high_resolution_clock::now();
    for (int i=0 ; i<n ; ++i)
        as.insert(i);
    auto end_array = std::chrono::high_resolution_clock::now();

    auto duration = (end_array-begin_array);
    std::cout << "Inserção de " << n << "elementos: " <<
                duration.count() << std::endl;
    return 0;
}