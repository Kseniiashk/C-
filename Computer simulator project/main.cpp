#include "cpu.h"
#include "gpu.h"
#include "kbd.h"
#include "disk.h"

signed main() {
    std::string s;
    while (true) {
        std::cin >> s;
        if (s == "exit") {
            std::cout << "OK\n";
            exit(0);
        } else if (s == "sum") {
            std::cout << sum() << std::endl;
            std::cout << "OK\n";
        } else if (s == "save") {
            save();
            std::cout << "OK\n";
        } else if (s == "load") {
            load();
            std::cout << "OK\n";
        } else if (s == "input") {
            input();
            std::cout << "OK\n";
        } else if (s == "display") {
            display();
            std::cout << "OK\n";
        } else {
            std::cout << "Invalid request\n";
        }
    }
}
