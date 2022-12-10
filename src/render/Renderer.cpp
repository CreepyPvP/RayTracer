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

            Ray ray(facing * focalLength + offsetX * right * viewportWidth + offsetY * up * viewportHeight, origin);
            printColor(raycast(ray));
        }

        std::cout << std::endl;
    }
}


Vec3 Renderer::raycast(const Ray& ray) const {
    Vec3 circleMiddle(0, 0, -3);
    double radius = 1;

    double aTerm = ray.direction().lengthSquared();
    
    Vec3 bRay = ray.origin() * ray.direction();
    Vec3 bCircle = circleMiddle * ray.direction();
    double bTerm = 2 * (bRay.sum() - bCircle.sum());

    Vec3 cRayCircle = ray.origin() * circleMiddle;
    double cTerm = -(radius * radius) + ray.origin().lengthSquared() - 2 * cRayCircle.sum() + circleMiddle.lengthSquared();

    double determinant = bTerm * bTerm - 4 * aTerm * cTerm;

    if(determinant >= 0) return Vec3(1, 0, 0);

    // TODO: Account for rotation of the camera
    double lerp = (toUnit(ray.direction())[1] + 1) / 2;
    return lerp * skyboxColor0 + (1 - lerp) * skyboxColor1;
}