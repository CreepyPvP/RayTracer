#include "objects/Plane.hpp"

#include "math/Vec3.hpp"
#include "math/Ray.hpp"
#include "objects/Renderable.hpp"


bool Plane::hit(const Ray& ray, double tMin, double tMax, RenderableHit& hit) const {
    double det = dot(ray.direction(), normal);
    if(det == 0)
        return false;

    hit.t = -dot(normal, ray.origin()) / det;

    if(hit.t < tMin || hit.t > tMax) return false;

    hit.position = ray.at(hit.t);
    hit.normal = normal;
    hit.material = material;

    return true;
}