#include "shape.hpp"
#include <algorithm>
#include <cmath>

std::optional<Ray> Shape::collide(const Ray input) const {
    std::optional<float> t = this->collision_time(input);
    if(!t.has_value()) return {};
    Vector col_pos = input.point_at_time(t.value());
    return Ray { .pos = col_pos, .vel = this->normal_at_point(col_pos) };
}

Shape::Shape(sRGB const &color, const float reflectivity) : color(color), reflectivity(reflectivity) {
}

Sphere::Sphere(sRGB const &color, const float reflectivity, const Vector centerpoint, const float radius)
    : Shape(color, reflectivity), centerpoint(centerpoint), radius(radius) {
}

float discriminant(float a, float b, float c) {
    return (b * b) - (4.0f * a * c);
}

std::optional<float> Sphere::collision_time(const Ray input) const {
    Vector delta = input.pos - this->centerpoint;
    float a = input.vel.length_squared();
    float b = 2 * input.vel.dot(delta);
    float c = delta.length_squared() - (radius * radius);

    float disc = discriminant(a, b, c);
    if(disc < 0) return {};

    float sqrt_disc = std::sqrt(disc);
    float t1 = (-b - sqrt_disc) / (2 * a);
    if(t1 < 0) t1 = INFINITY;
    float t2 = (-b + sqrt_disc) / (2 * a);
    if(t2 < 0) t2 = INFINITY;

    float min = std::min(t1, t2);
    if(min == INFINITY) return {};
    return min;
}

Vector Sphere::normal_at_point(const Vector point) const {
    Vector delta = point - this->centerpoint;
    return delta.normalized();
}

Plane::Plane(sRGB const &color, const float reflectivity, const Vector point, const Vector normal)
    : Shape(color, reflectivity), point(point), normal(normal) {
}

std::optional<float> Plane::collision_time(const Ray input) const {
    Vector delta = input.pos - this->point;
    float distance = delta.dot(this->normal);
    float vel_into_plane = input.vel.dot(this->normal);
    float t = vel_into_plane / distance;
    if(t < 0) return {};
    return t;
}

Vector Plane::normal_at_point(const Vector point) const {
    return this->normal;
}