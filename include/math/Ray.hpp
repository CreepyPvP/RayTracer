#ifndef RAY_H
#define RAY_H


class Ray {
    public:
        Ray() {}

        Ray(const Vec3& dir, const Vec3& start): dir(dir), start(start) {}

        Vec3 at(double t) const {
            return start + dir * t;
        }

        Vec3 direction() const {
            return dir;
        }

    private:
        Vec3 dir;
        Vec3 start;
};


#endif