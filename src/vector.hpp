#pragma once

struct Vector {
    const float x;
    const float y;
    const float z;

    // Constructs a zero vector.
    Vector();
    Vector(Vector const &v) = default;
    Vector(Vector &&v) = default; // I hate C++

    // Constructs a Vector from x, y, and z components.
    Vector(float x, float y, float z);

    // Returns dot product with another vector.
    float dot(Vector const &v) const;

    // Returns the square of the vector's magnitude (fast).
    float length_squared() const;

    // Returns the vector's magnitude (slow).
    float length() const;

    // Returns true iff the vector's magnitude is approximately equal to 1.
    bool is_normal() const;

    // Gets a vector pointing in the same direction w/ length 1.
    Vector normalized() const;

    Vector operator+(Vector const &v) const;
    Vector operator-(Vector const &v) const;
    Vector operator*(float s) const;
    Vector operator/(float s) const;

    friend Vector operator*(float x, Vector const &v);

    // Projects the vector along another vector.
    Vector project_onto(Vector const &v) const;

    // Projects the vector along another vector, which is assumed to be normalized.
    Vector project_onto_normal(Vector const &normal) const;

    // Reflects the vector off of a plane described by the given normal vector.
    Vector reflect_off(Vector const &v) const;

    // Reflects the vector off of a plane described by the given normal vector, which is assumed to be normalized.
    Vector reflect_off_normal(Vector const &v) const;

    ~Vector() = default;
};