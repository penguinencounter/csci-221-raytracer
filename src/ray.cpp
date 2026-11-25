#include "ray.hpp"

float Ray::time_at_point(const Vector p) const {
    const Vector delta = p - this->pos;
    return delta.dot(this->vel) / this->vel.length_squared();
}

Vector Ray::point_at_time(const float t) const {
    return this->pos + t * this->vel;
}

Ray Ray::ray_at_time(const float t) const {
    return Ray { .pos = this->point_at_time(t), .vel = this->vel };
}

Ray Ray::reflect_off(const Ray &normal) const {
    auto [new_pos, new_vel] = this->ray_at_time(this->time_at_point(normal.pos));
    return Ray { .pos = new_pos, .vel = new_vel.reflect_off(normal.vel) };
}