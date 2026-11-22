#pragma once
#include <cstdint>
#include <optional>

template<typename value>
struct rgb_impl {
    const value r;
    const value g;
    const value b;

    rgb_impl() = delete;

    rgb_impl(rgb_impl const &) = default;

    rgb_impl(rgb_impl &&) = default;

    rgb_impl &operator=(rgb_impl const &) = delete;

    rgb_impl &operator=(rgb_impl &&) = delete;

    [[nodiscard]] rgb_impl with(std::optional<value> r_, std::optional<value> g_, std::optional<value> b_) {
        return {
            r_.value_or(this->r),
            g_.value_or(this->g),
            b_.value_or(this->b),
        };
    }

protected:
    rgb_impl(value r, value g, value b): r(r), g(g), b(b) {}
};

struct sRGB;
struct sRGBf;

struct sRGB : rgb_impl<uint8_t> {
    sRGB(uint8_t r, uint8_t g, uint8_t b);

    explicit sRGB(sRGBf const&);
    explicit sRGB(uint32_t);

    sRGB operator+(sRGB const&) const;
    sRGB operator*(sRGB const&) const;
};

struct sRGBf : rgb_impl<float> {
    sRGBf(float r, float g, float b);

    explicit sRGBf(sRGB const&);

    sRGBf operator+(sRGBf const&) const;
    sRGBf operator*(sRGBf const&) const;
};
