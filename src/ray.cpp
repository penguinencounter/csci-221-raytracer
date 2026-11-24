#include "ray.hpp"

float Ray::time_at_point(Vector p) const {
    Vector delta = p - this->pos;
    return delta.dot(this->vel) / this->vel.length_squared();
}

Vector Ray::point_at_time(float t) const {
    return this->pos + t * this->vel;
}

Ray Ray::ray_at_time(float t) const {
    return Ray { .pos = this->point_at_time(t), .vel = this->vel };
}

Ray Ray::reflect_off(Ray normal) const {
    Ray through = this->ray_at_time(this->time_at_point(normal.pos));
    return Ray { .pos = through.pos, .vel = through.vel.reflect_off(normal.vel) };
}