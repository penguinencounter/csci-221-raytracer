#include "shape.hpp"

Shape::Shape(sRGB const &color, const float reflectivity) : color(color), reflectivity(reflectivity) {
}

Sphere::Sphere(sRGB const &color, const float reflectivity, const Vector centerpoint, const float radius)
    : Shape(color, reflectivity), centerpoint(centerpoint), radius(radius) {
}

std::optional<Ray> Sphere::collide([[maybe_unused]] const Ray input, [[maybe_unused]] const float t) const {
    return {};
}

Plane::Plane(sRGB const &color, const float reflectivity, const Vector point, const Vector normal)
    : Shape(color, reflectivity), point(point), normal(normal) {
}

std::optional<Ray> Plane::collide([[maybe_unused]] const Ray input, [[maybe_unused]] const float t) const {
    return {};
}
