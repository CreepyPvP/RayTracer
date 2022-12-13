#ifndef DIFFUSE_MATERIAL_H
#define DIFFUSE_MATERIAL_H

#include <iostream>

#include "materials/Material.hpp"
#include "math/Vec3.hpp"
#include "math/Ray.hpp"

#include "math/Random.hpp"


class DiffuseMaterial: public Material {

    public:

        DiffuseMaterial(Vec3 color): color(color) {}

        void scatter(const Ray& ray, const Vec3& normal, Vec3& outDir) {
            outDir = normal + randomUnitCircle();
            std::cerr << "test" << std::endl;
        }

        Vec3 getColor() {
            return color;
            std::cerr << "ts2" << std::endl;
        }

    private:

        Vec3 color;

};


#endif