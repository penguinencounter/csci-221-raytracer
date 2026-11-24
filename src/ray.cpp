#include "ray.hpp"

float Ray::time_at_point(Vector p) const {
    Vector delta = p - this->pos;
    return delta.dot(this->vel) / this->vel.length_squared();
}

Ray Ray::at_time(float t) const {
    return Ray { .pos = this->pos + t * this->vel, .vel = this->vel };
}

Ray Ray::reflect_off(Ray normal) const {
    Ray through = this->at_time(this->time_at_point(normal.pos));
    return Ray { .pos = through.pos, .vel = through.vel.reflect_off(normal.vel) };
}