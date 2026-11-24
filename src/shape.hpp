#pragma once
#include <optional>

#include "colorv2.hpp"
#include "ray.hpp"

class Shape {
public:
    Shape() = delete;

    Shape(Shape const &) = default;

    Shape(Shape &&) = default;

    Shape &operator=(Shape const &) = delete;

    Shape &operator=(Shape &&) = delete;

    virtual ~Shape() = default;

protected:
    Shape(sRGB const &color, float reflectivity);

    virtual std::optional<float> collision_time(Ray input) const = 0;
    virtual Vector normal_at_point(Vector p) const = 0;

public:
    sRGB color;
    float reflectivity;

    // Returns "collision ray" containing collision position and normal w/ input ray.
    [[nodiscard]] std::optional<Ray> collide(Ray input) const;
};

class Sphere : public Shape {
protected:
    std::optional<float> collision_time(Ray input) const override;
    Vector normal_at_point(Vector p) const override;
public:
    Vector centerpoint;
    float radius;

    Sphere(sRGB const &color, float reflectivity, Vector centerpoint, float radius);

    ~Sphere() override = default;
};

class Plane : public Shape {
protected:
    std::optional<float> collision_time(Ray input) const override;
    Vector normal_at_point(Vector p) const override;
public:
    Vector point;
    Vector normal;

    Plane(sRGB const &color, float reflectivity, Vector point, Vector normal);

    ~Plane() override = default;
};
