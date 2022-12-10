#ifndef SCENE_RENDERABLE_H
#define SCENE_RENDERABLE_H

#include <vector>

#include "objects/Renderable.hpp"

using std::vector;


class SceneRenderable: public Renderable {
    public:

        SceneRenderable() {

        }

        void add(const Renderable& renderable) {
            renderables.push_back(renderable);
        }

        bool hit(const Ray& ray, double tMin, double tMax, RenderableHit& hit) const override;

    private:
        vector<Renderable> renderables;

};


#endif