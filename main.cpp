#include <iostream>

#include "src/colorv2.hpp"

int main([[maybe_unused]] int argc, [[maybe_unused]] char **argv) {
    std::cout << "Hello, world!\n";
    sRGB myColor(0xFFFFFF);
    [[maybe_unused]] auto myOtherColor = myColor.with({}, 2, {});
}
