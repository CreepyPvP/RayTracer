#ifndef SPHERE_H
#define SPHERE_H


#include "math/Vec3.hpp"
#include "math/Ray.hpp"

#include "objects/Renderable.hpp"


class Sphere: public Renderable {

    public:

        Sphere(Vec3 center, double radius): center(center), radius(radius) {}

        virtual bool hit(const Ray& ray, double tMin, double tMax, RenderableHit& hit) const override;

    private:
    
        Vec3 center;
        double radius;

};


#endif