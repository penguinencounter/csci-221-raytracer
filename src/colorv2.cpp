#include "colorv2.hpp"

#include <algorithm>
#include <type_traits>

static uint8_t clamp8(const int i) {
    return static_cast<uint8_t>(std::clamp(i, 0, 255));
}

static float clampf(const float f) {
    return std::clamp(f, 0.f, 1.f);
}

static uint8_t f2i(const float f) {
    return static_cast<uint8_t>(std::clamp(f * 255.f, 0.f, 255.f));
}

static float i2f(const uint8_t i) {
    return static_cast<float>(i) / 255.f;
}

sRGB::sRGB(const uint8_t r, const uint8_t g, const uint8_t b) : rgb_impl(r, g, b) {
}

sRGB::sRGB(sRGBf const &other) : rgb_impl(f2i(other.r), f2i(other.g), f2i(other.b)) {
}

sRGB::sRGB(const uint32_t col) : rgb_impl((col & 0xFF0000) >> 16, (col & 0x00FF00) >> 8, col & 0x0000FF) {
}

sRGB sRGB::operator+(sRGB const &other) const {
    static_assert(std::is_same_v<decltype(this->r + other.r), int>,
                  "integer promotion is non-functional (may overflow)");
    return {
        clamp8(this->r + other.r),
        clamp8(this->g + other.g),
        clamp8(this->b + other.b),
    };
}

sRGB sRGB::operator*(sRGB const &other) const {
    // floating point math
    return sRGB(sRGBf(*this) * sRGBf(other));
}

sRGBf::sRGBf(const float r, const float g, const float b) : rgb_impl(clampf(r), clampf(g), clampf(b)) {
}

sRGBf::sRGBf(sRGB const &other) : rgb_impl(i2f(other.r), i2f(other.g), i2f(other.b)) {
}

sRGBf sRGBf::operator+(sRGBf const &other) const {
    return {
        clampf(this->r + other.r),
        clampf(this->g + other.g),
        clampf(this->b + other.b),
    };
}

sRGBf sRGBf::operator*(sRGBf const &other) const {
    return {
        this->r * other.r,
        this->g * other.g,
        this->b * other.b,
    };
}
