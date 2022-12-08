#ifndef VEC3_H
#define VEC3_H

#include <iostream>
#include <cmath>


using std::sqrt;


class vec3 {
    public:
        vec3(): value{0,0,0} {}

        vec3(double x, double y, double z): value{x,y,z} {}


        double lengthSquared() const {
            return value[0] * value[0] + value[1] * value[1] + value[2] * value[2];
        }

        double length() const {
            return sqrt(lengthSquared()); 
        }

        // operators

        double operator[](int i) const { return value[i]; }
        double& operator[](int i) { return value[i]; }
        vec3 operator-() const { return vec3(-value[0], -value[1], -value[2]); }

        vec3& operator+=(const vec3& a) {
            value[0] += a[0];
            value[1] += a[1];
            value[2] += a[2];
            return *this;
        }

        vec3& operator*=(const double t) {
            value[0] *= t;
            value[1] *= t;
            value[2] *= t;
            return *this;
        }

        vec3& operator/=(const double t) {
            value[0] /= t;
            value[1] /= t;
            value[2] /= t;
            return *this;
        }

    private:
        double value[3];
};


inline vec3 operator+(const vec3& a, const vec3& b) {
    return vec3(a[0] + b[0], a[1] + b[1], a[2] + b[2]);
}

inline vec3 operator-(const vec3& a, const vec3& b) {
    return vec3(a[0] - b[0], a[1] - b[1], a[2] - b[2]);
}

inline vec3 operator*(const vec3& a, double t) {
    return vec3(a[0] * t, a[1] * t, a[2] * t);
}

inline vec3 operator*(double t, const vec3& a) {
    return vec3(a[0] * t, a[1] * t, a[2] * t);
}

inline vec3 operator*(const vec3& a, const vec3& b) {
    return vec3(a[0] * b[0], a[1] * b[1], a[2] * b[2]);
}

inline vec3 operator/(const vec3& a, double t) {
    return (1/t) * a;
}

inline std::ostream& operator<<(std::ostream &out, const vec3& a) {
    return out << a[0] << " " << a[1] << " " << a[2];
}

inline double dot(const vec3& a, const vec3& b) {
    return a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
}



#endif