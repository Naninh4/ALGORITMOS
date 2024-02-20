#include <iostream>
#include <cstdlib>

int main() {
    long long x = -1234567890123456789LL;
    long long result = std::abs(x);

    std::cout << "Absolute value of " << x << " is: " << result << std::endl;

    return 0;
}
