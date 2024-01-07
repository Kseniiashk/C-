#include <iostream>
#include <vector>
#include "operation.h"

int main() {
    std::vector<Point> cuts;
    std::vector<Point> clamps;
    std::vector<Point> tweezers;
    while (true) {
        std::cout << "LET'S START A NEW OPERATION ? ('yes'\'no')" << std::endl;
        std::string answer;
        std::cin >> answer;
        if (answer == "no") break;
        scalpel(cuts);
        hemostat(clamps);
        tweezer(tweezers);
        suture(cuts);
    }
    return 0;
}
