#ifndef MATERIAL_H
#define MATERIAL_H

#include "math/Vec3.hpp"
#include "math/Ray.hpp"


class Material {

    public:

        virtual void scatter(const Ray& ray, const Vec3& normal, Vec3& outDir) {

        }

        virtual Vec3 getColor() {
            return Vec3(0,0,0);
        }


};


#endif