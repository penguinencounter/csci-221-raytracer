#pragma once

struct Vector {
    const float x;
    const float y;
    const float z;

    Vector();
    Vector(float x, float y, float z);
    Vector(Vector const &v) = default;
    Vector(Vector &&v) = default; // I hate C++

    float dot(Vector const &v) const;
    float length_squared() const;
    float length() const;
    bool is_normal() const;
    Vector normalized() const;

    Vector operator+(Vector const &v) const;
    Vector operator-(Vector const &v) const;
    Vector operator*(float s) const;
    Vector operator/(float s) const;

    friend Vector operator*(float x, Vector const &v);

    Vector project_onto(Vector const &v) const;
    Vector project_onto_normal(Vector const &normal) const;
    Vector reflect_off(Vector const &v) const;
    Vector reflect_off_normal(Vector const &v) const;

    ~Vector() = default;
};