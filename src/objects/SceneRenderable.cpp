#include "objects/SceneRenderable.hpp"
#include "objects/Renderable.hpp"

#include <iostream>


bool SceneRenderable::hit(const Ray& ray, double tMin, double tMax, RenderableHit& hit) const {
    RenderableHit tmp;
    bool success = false;
    double nearest = tMax;

    for(const auto& renderable: renderables) {
        if(renderable->hit(ray, tMin, tMax, tmp)) {
            if(tmp.t < nearest) {
                nearest = tmp.t;
                hit = tmp;
                success = true;
            }
        }
    }

    return success;
}