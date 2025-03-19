#ifndef RANDOM_H
#define RANDOM_H
#include <random>
/**
     * Random number generator
     */
class Random {
public:

    /**
         * Generate a random integer between min and max
         * @param min
         * @param max
         * @return
         */
    static int randInt(const int & min, const int & max) {
        std::random_device rd;
        std::mt19937_64 gen {rd()};
        std::uniform_int_distribution<int> dist(min, max-1);
        return dist(gen);
    }
};
#endif // RANDOM_H
