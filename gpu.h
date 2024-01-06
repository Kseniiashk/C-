#include "ram.h"
#include <vector>

void display() {
    std::vector<int> ans = write_ram();
    for (int i = 0; i < 8; ++i) {
        std::cout << ans[i] << " ";
    }
    std::cout << std::endl;
}