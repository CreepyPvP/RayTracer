#include <iostream>

#include "headers/math/vec3.hpp"


using namespace std;

int main() {
    int width = 400;
    int height = 300;
    double aspectRatio = width / height;

    // Rendering
    cout << "P3\n" << width << " " << height << "\n255" << endl;
    for(int y = 0; y < height; y++) {
        for(int x = 0; x < width; x++) {
            int r = static_cast<int>((width - x) / double(width) * 255);
            int g = static_cast<int>((height - y) / double(height) * 255);
            int b = 0;

            cout << r << " " << g << " " << b << " ";
        }

        cout << endl;
    }
}