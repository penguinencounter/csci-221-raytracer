#pragma once
#include "vector.hpp"

// TODO: do we need more props for this? -m

struct Ray {
    Vector pos;
    Vector vel;

    // Gets value of t at a point p along the ray.
    float time_at_point(Vector p) const;

    // Gets a ray in the same line as this one but at a later time.
    Ray at_time(float t) const;

    // Reflects the ray off of a point on a surface described by the given normal ray.
    Ray reflect_off(Ray normal) const;
};
