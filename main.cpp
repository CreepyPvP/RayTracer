/*
*       Based on: https://raytracing.github.io/books/RayTracingInOneWeekend.html
*       This is inteded mainly as a c++ practice for myself :D
*/

#include <iostream>

#include "math/Vec3.hpp"
#include "render/Renderer.hpp"


using namespace std;

int main() {
    int width = 800;
    int height = width * 9 / 16;

    Renderer r(width, height, 2, Vec3(0.5, 0.7, 1.0), Vec3(1, 1, 1));
    r.render();
}