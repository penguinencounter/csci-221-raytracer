#pragma once
#include "vector.hpp"

// TODO: do we need more props for this? -m

struct Ray {
    Vector pos;
    Vector vel;

    // Gets value of t at a point p along the ray.
    [[nodiscard]] float time_at_point(Vector p) const;

    // Gets point along the ray at time t.
    [[nodiscard]] Vector point_at_time(float t) const;

    // Gets a ray in the same line as this one but at a later time.
    [[nodiscard]] Ray ray_at_time(float t) const;

    // Reflects the ray off of a point on a surface described by the given normal ray.
    [[nodiscard]] Ray reflect_off(const Ray &normal) const;
};
