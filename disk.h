#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <ram.h>

void load() {
    std::vector<int> a(8);
    std::ifstream input;
    input.open("/Users/kseniashk/CLionProjects/untitled/data.txt");
    for (int i = 0; i < 8; ++i) {
        input >> a[i];
    }
    input.close();
    input_ram(a);
}

void save() {
    std::vector<int> a = write_ram();
    std::ofstream output;
    output.open("/Users/kseniashk/CLionProjects/untitled/data.txt");
    for (int i = 0; i < 8; ++i) {
        output << a[i] << " ";
    }
    output.close();
}