#pragma once
#include <cstdint>

struct sRGB;
struct sRGBf;

// int8 sRGB color vector (0 to 255)
struct sRGB {
    const uint8_t r;
    const uint8_t g;
    const uint8_t b;

    sRGB() = delete;
    sRGB(sRGB&) = default;
    sRGB(sRGB&&) = default;

    // Construct a sRGB color from Red, Green, and Blue components.
    sRGB(uint8_t r, uint8_t g, uint8_t b);

    // Construct an int8 sRGB color from a float sRGB color.
    explicit sRGB(sRGBf const&);

    // Add colors, clamping the result at 255.
    sRGB operator+(sRGB const &other) const;
    // Multiply colors
    sRGB operator*(sRGB const &other) const;

    ~sRGB() = default;
};

// float sRGB color vector (0 to 1)
struct sRGBf {
    const float r;
    const float g;
    const float b;

    sRGBf() = delete;
    sRGBf(sRGBf&) = default;
    sRGBf(sRGBf&&) = default;

    // Construct a sRGBf color from Red, Green, and Blue components.
    sRGBf(float r, float g, float b);

    explicit sRGBf(sRGB const&);

    sRGBf operator+(sRGBf const &other) const;
    sRGBf operator*(sRGBf const &other) const;

    ~sRGBf() = default;
};