#include "vector.hpp"
#include <cmath>

Vector::Vector() : x(0.0), y(0.0), z(0.0) {}

Vector::Vector(float x, float y, float z) : x(x), y(y), z(z){}

Vector Vector::operator+(Vector const &v) const {
    return Vector(this->x + v.x, this->y + v.y, this->z + v.z);
}

Vector Vector::operator-(Vector const &v) const {
    return Vector(this->x - v.x, this->y - v.y, this->z - v.z);
}

Vector Vector::operator*(float s) const {
    return Vector(this->x * s, this->y * s, this->z * s);
}

Vector Vector::operator/(float s) const {
    return *this * (1 / s);
}

Vector operator*(float s, Vector const &v) {
    return v * s;
}

float Vector::dot(Vector const &v) const {
    return (this->x * v.x) + (this->y * v.y) + (this->z * v.z);
}

float Vector::length_squared() const {
    return this->dot(*this);
}

float Vector::length() const {
    return std::sqrt(this->length_squared());
}

const float NORMAL_EPSILON = 0.00001f;

bool Vector::is_normal() const {
    float l = this->length_squared();
    return l + NORMAL_EPSILON >= 1 && l - NORMAL_EPSILON <= 1;
}

Vector Vector::normalized() const {
    return *this / this->length();
}

Vector Vector::project_onto(Vector const &v) const {
    return v * (this->dot(v) / v.length_squared());
}

Vector Vector::project_onto_normal(Vector const &normal) const {
    return normal * this->dot(normal);
}

Vector Vector::reflect_off(Vector const &v) const {
    return *this - (this->project_onto(v) * 2.0);
}

Vector Vector::reflect_off_normal(Vector const &normal) const {
    return *this - (this->project_onto_normal(normal) * 2.0);
}