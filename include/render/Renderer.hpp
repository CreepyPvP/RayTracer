#ifndef RENDERER_H
#define RENDERER_H


#include "math/Vec3.hpp"
#include "math/Ray.hpp"

class Renderer {
    public:

        Renderer(int width, int height, double viewportWidth, Vec3 skyboxUpperColor, Vec3 skyboxLowerColor): 
            outputWidth(width), 
            outputHeight(height), 
            viewportWidth(viewportWidth),
            viewportHeight(viewportWidth * height / width),
            skyboxColor0(skyboxUpperColor),
            skyboxColor1(skyboxLowerColor) {}

        void render() const;

        Vec3 raycast(const Ray& ray) const;

    private:
        int outputWidth;
        int outputHeight;

        double viewportWidth;
        double viewportHeight;

        Vec3 skyboxColor0;
        Vec3 skyboxColor1;
};


#endif