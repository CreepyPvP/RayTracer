#ifndef RENDERABLE_H
#define RENDERABLE_H

#include <iostream>

#include "math/Vec3.hpp"
#include "math/Ray.hpp"


struct RenderableHit {
    double t;
    Vec3 position;
    Vec3 normal;
};


class Renderable {
    public:

        virtual bool hit(const Ray& ray, double tMin, double tMax, RenderableHit& hit) const { 
            return false; 
        };

    private:

};


#endif