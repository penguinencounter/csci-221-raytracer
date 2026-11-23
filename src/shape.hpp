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

public:
    sRGB color;
    float reflectivity;

    [[nodiscard]] virtual std::optional<Ray> collide(Ray input, float t) const = 0;
};

class Sphere : public Shape {
public:
    Vector centerpoint;
    float radius;

    Sphere(sRGB const &color, float reflectivity, Vector centerpoint, float radius);

    ~Sphere() override = default;

    [[nodiscard]] std::optional<Ray> collide(Ray input, float t) const override;
};

class Plane : public Shape {
public:
    Vector point;
    Vector normal;

    Plane(sRGB const &color, float reflectivity, Vector point, Vector normal);

    ~Plane() override = default;

    [[nodiscard]] std::optional<Ray> collide(Ray input, float t) const override;
};
