#ifndef REFLECTIVE_MATERIAL_H
#define REFLECTIVE_MATERIAL_H


#include "materials/Material.hpp"
#include "math/Vec3.hpp"
#include "math/Ray.hpp"

#include "math/Random.hpp"


class ReflectiveMaterial: public Material {

    public:

        ReflectiveMaterial(Vec3 color): color(color) {}

        virtual void scatter(const Ray& ray, const Vec3& normal, Vec3& outDir) const override {
            outDir = normal + randomUnitCircle();
        }

        virtual Vec3 getColor(Vec3& c) const {
            return color;
        }

    private:

        Vec3 color;

};


#endif