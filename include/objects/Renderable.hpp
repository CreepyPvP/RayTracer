#ifndef RENDERABLE_H
#define RENDERABLE_H

#include <iostream>
#include <memory>

#include "math/Vec3.hpp"
#include "math/Ray.hpp"
#include "materials/Material.hpp"


using std::shared_ptr;


struct RenderableHit {
    double t;
    Vec3 position;
    Vec3 normal;

    shared_ptr<Material> material;
};


class Renderable {
    public:

        Renderable() {}

        virtual bool hit(const Ray& ray, double tMin, double tMax, RenderableHit& hit) const {
            return false;
        };

    private:

};


#endif