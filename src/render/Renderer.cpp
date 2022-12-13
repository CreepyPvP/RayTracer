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
#include "materials/DiffuseMaterial.hpp"


using std::sqrt;
using std::shared_ptr;
using std::make_shared;


void Renderer::initialize() {
    auto scene = new SceneRenderable();

    DiffuseMaterial test(Vec3(0.0, 1.0, 0.0));
    auto ts = &test;

    test.getColor();
    ts->getColor();

    auto white = make_shared<DiffuseMaterial>(Vec3(0.5, 0.5, 0.5));
    white->getColor();
    auto red = make_shared<DiffuseMaterial>(Vec3(0.5, 0.1, 0.1));
    auto blue = make_shared<DiffuseMaterial>(Vec3(0.1, 0.1, 0.5));


    shared_ptr<Renderable> sphereRed = make_shared<Sphere>(Vec3(-2, 1, 0), 1, red);
    scene->add(sphereRed);

    shared_ptr<Renderable> sphereBlue = make_shared<Sphere>(Vec3(0, 1, 0), 1, blue);
    scene->add(sphereBlue);

    shared_ptr<Renderable> sphereBlue1 = make_shared<Sphere>(Vec3(-2, 1, 4), 1, blue);
    scene->add(sphereBlue1);

    shared_ptr<Renderable> ground = make_shared<Plane>(Vec3(0, 1, 0), white);
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
        std::cerr << "Rendering: " << y / double(outputHeight) * 100 << "%" << std::endl;
    }
}


Vec3 Renderer::raycast(const Ray& ray, int depth) const {
    if(depth >= REFLECTION_DEPTH) {
        return Vec3(0,0,0);
    }

    RenderableHit hit;
    if(renderable->hit(ray, 0.0001, INFINITY, hit)) {

        // Ray refelction(reflect(ray.direction(), hit.normal) + hit.material.metallic * randomUnitCircle(), hit.position);
        Vec3 scatteredDir(0,0,0);
        hit.material->scatter(ray, hit.normal, scatteredDir);
        Ray scatteredRay(scatteredDir, hit.position);
        return hit.material->getColor() * raycast(scatteredRay, depth + 1);
    }

    // TODO: Account for rotation of the camera
    double lerp = (toUnit(ray.direction())[1] + 1) / 2;
    return lerp * skyboxColor0 + (1 - lerp) * skyboxColor1;
}