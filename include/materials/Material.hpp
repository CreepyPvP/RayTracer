#ifndef MATERIAL_H
#define MATERIAL_H


#include <iostream>

#include "math/Vec3.hpp"
#include "math/Ray.hpp"


class Material {

    public:

        virtual void scatter(const Ray& ray, const Vec3& normal, Vec3& outDir, Vec3& color) {
            std::cerr << "material" << std::endl;
        }

};


#endif