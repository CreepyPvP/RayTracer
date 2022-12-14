#ifndef REFLECTIVE_MATERIAL_H
#define REFLECTIVE_MATERIAL_H


#include "materials/Material.hpp"
#include "math/Vec3.hpp"
#include "math/Ray.hpp"

#include "math/Random.hpp"


class ReflectiveMaterial: public Material {

    public:

        ReflectiveMaterial(Vec3 color): color(color) {}

        void scatter(const Ray& ray, const Vec3& normal, Vec3& outDir, Vec3& c) {
            outDir = reflect(ray.direction(), normal);
            c = color;
        }   

    private:

        Vec3 color;
};


#endif