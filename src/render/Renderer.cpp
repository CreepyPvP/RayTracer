#include "render/Renderer.hpp"


#define SAMPLES 100
#define REFLECTION_DEPTH 20

#include <iostream>
#include <cmath>
#include <memory>

#include "math/Vec3.hpp"
#include "math/Ray.hpp"
#include "objects/Renderable.hpp"
#include "objects/Sphere.hpp"
#include "objects/Plane.hpp"
#include "math/Random.hpp"

using std::sqrt;
using std::shared_ptr;
using std::make_shared;


void Renderer::initialize() {
    auto scene = new SceneRenderable();

    for(int i = 0; i <= 0; i++) {
        shared_ptr<Renderable> sphere = make_shared<Sphere>(Vec3(2 * i, 1, 0), 1);
        scene->add(sphere);
    }
    shared_ptr<Renderable> ground = make_shared<Plane>(Vec3(0, 1, 0));
    scene->add(ground);

    renderable = scene;
}


void Renderer::dispose() {
    delete renderable;
}


void Renderer::render() const {
    // TODO move all this stuff to seperate camera interface
    // Camera
    Vec3 origin(0, 1, 3);
    Vec3 facing(0, 0, -1);
    Vec3 up(0, 1, 0);
    Vec3 right(1, 0, 0);
    
    double focalLength = 1;

    // Rendering
    std::cout << "P3\n" << outputWidth << " " << outputHeight << "\n255" << std::endl;
    for(int y = 0; y < outputHeight; y++) {
        for(int x = 0; x < outputWidth; x++) {
            Vec3 color(0,0,0);
            for(int s = 0; s < SAMPLES; s++) {
                double offsetX = (x + randomDouble()) / double(outputWidth) * 2 - 1;
                double offsetY = -((y + randomDouble()) / double(outputHeight) * 2 - 1);

                Ray ray(facing * focalLength + offsetX * right * viewportWidth + offsetY * up * viewportHeight, origin);
                color += raycast(ray, 0);
            }

            printColor(color / SAMPLES);
        }

        std::cout << std::endl;
    }
}


Vec3 Renderer::raycast(const Ray& ray, int depth) const {
    if(depth >= REFLECTION_DEPTH) {
        return Vec3(0,0,0);
    }

    RenderableHit hit;
    if(renderable->hit(ray, 0.0001, INFINITY, hit)) {
        Ray refelction(hit.normal + randomUnitCircle(), hit.position);
        return 0.5 * raycast(refelction, depth + 1);
    }

    // TODO: Account for rotation of the camera
    double lerp = (toUnit(ray.direction())[1] + 1) / 2;
    return lerp * skyboxColor0 + (1 - lerp) * skyboxColor1;
}