#ifndef SPHERE_H
#define SPHERE_H


#include <memory>

#include "math/Vec3.hpp"
#include "math/Ray.hpp"

#include "materials/Material.hpp"
#include "objects/Renderable.hpp"


using std::shared_ptr;

class Sphere: public Renderable {

    public:

        Sphere(Vec3 center, double radius, shared_ptr<Material> material): center(center), radius(radius), material(material) {}

        virtual bool hit(const Ray& ray, double tMin, double tMax, RenderableHit& hit) const override;

    private:
    
        Vec3 center;
        double radius;

        shared_ptr<Material> material;

};


#endif