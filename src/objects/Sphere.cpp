#include "objects/Sphere.hpp"

#include "math/Vec3.hpp"
#include "math/Ray.hpp"


bool Sphere::hit(const Ray& ray, double tMin, double tMax, RenderableHit& hit) const {
    double aTerm = ray.direction().lengthSquared();
    
    Vec3 bRay = ray.origin() * ray.direction();
    Vec3 bCircle = center * ray.direction();
    double bTerm = bRay.sum() - bCircle.sum();

    Vec3 cRayCircle = ray.origin() * center;
    double cTerm = -(radius * radius) + ray.origin().lengthSquared() - 2 * cRayCircle.sum() + center.lengthSquared();

    double discriminant = bTerm * bTerm - aTerm * cTerm;

    if(discriminant < 0)
        return false;

    hit.t = (-bTerm - sqrt(discriminant)) / aTerm;
    if(hit.t > tMax) return false;
    if(hit.t < tMin) {
        hit.t = (-bTerm + sqrt(discriminant)) / aTerm;
        if(hit.t < tMin || hit.t > tMax) return false;
    }

    hit.position = ray.at(hit.t);
    hit.normal = toUnit(hit.position - center);

    return true;
}