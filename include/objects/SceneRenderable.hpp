#ifndef SCENE_RENDERABLE_H
#define SCENE_RENDERABLE_H

#include <vector>
#include <memory>

#include "objects/Renderable.hpp"

using std::vector;
using std::shared_ptr;


class SceneRenderable: public Renderable {
    public:

        SceneRenderable() {

        }

        void add(shared_ptr<Renderable> renderable) {
            renderables.push_back(renderable);
        }

        virtual bool hit(const Ray& ray, double tMin, double tMax, RenderableHit& hit) const override;

    private:
        vector<shared_ptr<Renderable>> renderables;

};


#endif