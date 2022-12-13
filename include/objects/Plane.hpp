#ifndef PLANE_H
#define PLANE_H

#include <memory>

#include "materials/Material.hpp"
#include "math/Vec3.hpp"
#include "math/Ray.hpp"
#include "objects/Renderable.hpp"


using std::shared_ptr;


class Plane: public Renderable {

    public:

        Plane(Vec3 normal, shared_ptr<Material> material): normal(normal), material(material) {}

        virtual bool hit(const Ray& ray, double tMin, double tMax, RenderableHit& hit) const override;

    private:
 
        Vec3 normal;
        shared_ptr<Material> material;

};


#endif