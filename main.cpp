/*
*       Based on: https://raytracing.github.io/books/RayTracingInOneWeekend.html
*       This is inteded mainly as a c++ practice for myself :D
*/

#include <iostream>

#include "render/Renderer.hpp"


using namespace std;

int main() {
    int width = 400;
    int height = 300;

    Renderer r(width, height, 2);
    r.render();
}