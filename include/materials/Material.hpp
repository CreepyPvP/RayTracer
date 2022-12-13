#ifndef MATERIAL_H
#define MATERIAL_H

#include "math/Vec3.hpp"

struct Material {
    Vec3 diffuse;
};


inline Material diffuse(Vec3 color) {
    Material material;
    material.diffuse = color;

    return material;
}


#endif