#include "ram.h"
#include <vector>

void input() {
    std::cout << "Enter 8 numbers:\n";
    std::vector<int> a(8);
    for (int i = 0; i < 8; ++i) {
        std::cin >> a[i];
    }
    input_ram(a);
}