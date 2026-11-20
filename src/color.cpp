#include "color.hpp"

#include <algorithm>

using std::ranges::clamp;

static uint8_t ftoint8(const float f) {
    return static_cast<uint8_t>(clamp(255.f * f, 0.f, 255.f));
}

static float int8tof(const uint8_t i) {
    return static_cast<float>(i) / 255.f;
}

sRGB::sRGB(const uint8_t r, const uint8_t g, const uint8_t b) : r(r), g(g), b(b) {
}

sRGB::sRGB(sRGBf const &floaty) : r(ftoint8(floaty.r)), g(ftoint8(floaty.g)), b(ftoint8(floaty.b)) {
}

sRGB sRGB::operator+(sRGB const &other) const {
    return {
        static_cast<uint8_t>(clamp(this->r + other.r, 0, 255)),
        static_cast<uint8_t>(clamp(this->g + other.g, 0, 255)),
        static_cast<uint8_t>(clamp(this->b + other.b, 0, 255)),
    };
}

sRGB sRGB::operator*(sRGB const &other) const {
    return sRGB(sRGBf(*this) * sRGBf(other));
}

sRGBf::sRGBf(const float r, const float g, const float b) : r(r), g(g), b(b) {
}

sRGBf::sRGBf(sRGB const &other) : r(int8tof(other.r)), g(int8tof(other.g)), b(int8tof(other.b)) {
}

sRGBf sRGBf::operator+(sRGBf const &other) const {
    return {
        clamp(this->r + other.r, 0.f, 1.f),
        clamp(this->g + other.g, 0.f, 1.f),
        clamp(this->b + other.b, 0.f, 1.f),
    };
}

sRGBf sRGBf::operator*(sRGBf const &other) const {
    return {
        this->r * other.r,
        this->g * other.g,
        this->b * other.b,
    };
}
