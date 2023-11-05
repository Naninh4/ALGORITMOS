#include <iostream>
#include <chrono>
#include "array_list.hpp"
// push_back();
// pop_front();
// pop_back();

int main() {
    int n;
    std::cin >> n;
    array_list l1(8);
    auto beg = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        l1.push_front(x);
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = end - beg;
    if (not (l1.size() == n)) {
        std::cerr << "[ERROR] check push_front method!\n";
        exit(1);
    }
    std::cerr << "[INFO] " << "Elapsed time for "
        << n << " pushes front :"
        << elapsed.count() << std::endl;
    std:: cout<< l1.capacity() << std:: endl;
    return 0;
}