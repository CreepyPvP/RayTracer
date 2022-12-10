#ifndef VEC3_H
#define VEC3_H

#include <iostream>
#include <cmath>


using std::sqrt;


class Vec3 {
    public:
        Vec3(): value{0,0,0} {}

        Vec3(double x, double y, double z): value{x,y,z} {}


        double lengthSquared() const {
            return value[0] * value[0] + value[1] * value[1] + value[2] * value[2];
        }

        double length() const {
            return sqrt(lengthSquared()); 
        }

        // operators

        double operator[](int i) const { return value[i]; }
        double& operator[](int i) { return value[i]; }
        Vec3 operator-() const { return Vec3(-value[0], -value[1], -value[2]); }

        Vec3& operator+=(const Vec3& a) {
            value[0] += a[0];
            value[1] += a[1];
            value[2] += a[2];
            return *this;
        }

        Vec3& operator*=(const double t) {
            value[0] *= t;
            value[1] *= t;
            value[2] *= t;
            return *this;
        }

        Vec3& operator/=(const double t) {
            value[0] /= t;
            value[1] /= t;
            value[2] /= t;
            return *this;
        }

    private:
        double value[3];
};


inline Vec3 operator+(const Vec3& a, const Vec3& b) {
    return Vec3(a[0] + b[0], a[1] + b[1], a[2] + b[2]);
}

inline Vec3 operator-(const Vec3& a, const Vec3& b) {
    return Vec3(a[0] - b[0], a[1] - b[1], a[2] - b[2]);
}

inline Vec3 operator*(const Vec3& a, double t) {
    return Vec3(a[0] * t, a[1] * t, a[2] * t);
}

inline Vec3 operator*(double t, const Vec3& a) {
    return Vec3(a[0] * t, a[1] * t, a[2] * t);
}

inline Vec3 operator*(const Vec3& a, const Vec3& b) {
    return Vec3(a[0] * b[0], a[1] * b[1], a[2] * b[2]);
}

inline Vec3 operator/(const Vec3& a, double t) {
    return (1/t) * a;
}

inline std::ostream& operator<<(std::ostream &out, const Vec3& a) {
    return out << a[0] << " " << a[1] << " " << a[2];
}

inline double dot(const Vec3& a, const Vec3& b) {
    return a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
}

inline Vec3 toUnit(const Vec3& a) {
    return a / a.length();
}


inline void printColor(const Vec3& color) {
    std::cout << static_cast<int>(color[0] *255.99) << " " <<
        static_cast<int>(color[1] * 255.99) << " " <<
        static_cast<int>(color[2] * 255.99) << " ";
}

#endif