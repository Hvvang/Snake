#pragma once

#include <random>

class Random {
    /* A utility class that will be used to generate random numbers */
    std::random_device rd;
    std::mt19937 gen;
 public:

    Random() {
        gen.seed(rd());
    }

    int getRandomInt(int l, int u) {
        std::uniform_int_distribution<int> dist(l, u);
        return dist(gen);
    }
};
