#pragma once

#include <iostream>
#include <vector>

const int N = 8;

std::vector<int> a(N);

std::vector<int> write_ram() {
    return a;
}

void input_ram(std::vector<int>& b) {
    a = b;
}
