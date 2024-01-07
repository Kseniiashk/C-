#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <ram.h>

int sum() {
    std::vector<int> a = write_ram();
    int x, s = 0;
    for (int i = 0; i < 8; ++i) {
        s += a[i];
    }
    return s;
}
