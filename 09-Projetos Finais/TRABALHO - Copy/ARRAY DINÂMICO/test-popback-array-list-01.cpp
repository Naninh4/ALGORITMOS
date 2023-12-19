#include <iostream>
#include <chrono>
#include "array_list.hpp"

int main() {
    unsigned int n;
    std::cin >> n;
    array_list l1;
    for (unsigned int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        l1.push_back(x);
    }
    unsigned int m;
    std::cin >> m;
    unsigned int removed = 0, not_removed = 0;
    auto beg = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < m; ++i) {
        if (l1.pop_back())
            removed++;
        else{
            not_removed++;
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = end - beg;
    std::cerr << "[DEBUG] Tried to remove " << m << " element(s)\n";
    std::cerr << "[DEBUG] removed " << removed << " element(s)\n";
    std::cerr << "[DEBUG] not removed " << not_removed << " element(s)\n";
    if (not (l1.size() == n - removed) or (not_removed + removed != m)) {
        std::cerr << "[ERROR] check pop_front method!\n";
        exit(1);
    }
    std::cerr << "[INFO] " << "Elapsed time for "
        << removed << " pop_fronts success : "
        << elapsed.count() << std::endl;
    return 0;
}