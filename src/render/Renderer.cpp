#include "render/Renderer.hpp"

#include <iostream>

#include "math/Vec3.hpp"
#include "math/Ray.hpp"


void Renderer::render() const {
    // TODO move all this stuff to seperate camera interface
    // Camera
    Vec3 origin(0, 0, 0);
    Vec3 facing(0, 0, -1);
    Vec3 up(0, 1, 0);
    Vec3 right(1, 0, 0);
    
    double focalLength = 1;

    // Rendering
    std::cout << "P3\n" << outputWidth << " " << outputHeight << "\n255" << std::endl;
    for(int y = 0; y < outputHeight; y++) {
        for(int x = 0; x < outputWidth; x++) {
            double offsetX = x / double(outputWidth) * 2 - 1;
            double offsetY = -(y / double(outputHeight) * 2 - 1);

            Ray ray(facing * focalLength + offsetX * right + offsetY * up, origin);
            printColor(raycast(ray));
        }

        std::cout << std::endl;
    }
}


Vec3 Renderer::raycast(const Ray& ray) const {
    // TODO: Account for rotation of the camera
    double lerp = (toUnit(ray.direction())[1] + 1) / 2;
    return lerp * skyboxColor0 + (1 - lerp) * skyboxColor1;
}