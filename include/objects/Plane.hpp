#ifndef PLANE_H
#define PLANE_H

#include "math/Vec3.hpp"
#include "math/Ray.hpp"
#include "objects/Renderable.hpp"


class Plane: public Renderable {

    public:

        Plane(Vec3 normal): normal(normal) {}

        virtual bool hit(const Ray& ray, double tMin, double tMax, RenderableHit& hit) const override;

    private:

        Vec3 normal;

};


#endif