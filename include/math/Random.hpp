#ifndef RANDOM_H
#define RANDOM_H

#define TRUE_LAMBERTIAN

#include <random>

#include "math/Vec3.hpp"


inline double randomDouble() {
    static std::uniform_real_distribution<double> distribution(0.0, 1.0);
    static std::mt19937 generator;
    return distribution(generator);
}


inline Vec3 randomUnitCircle() {
    #ifndef TRUE_LAMBERTIAN
        while(true) {
            Vec3 pos(randomDouble() * 2 - 1, randomDouble() * 2 - 1, randomDouble() * 2 - 1);
            if(pos.lengthSquared() <= 1)
                return pos;
        }
    #endif
    #ifdef TRUE_LAMBERTIAN
        return toUnit(Vec3(randomDouble() * 2 - 1, randomDouble() * 2 - 1, randomDouble() * 2 - 1));
    #endif
}


#endif