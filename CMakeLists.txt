CMAKE_MINIMUM_REQUIRED(VERSION 4.0.0)
project(csci-221-raytracer)

set(CMAKE_C_STANDARD 23)
set(CMAKE_CXX_STANDARD 23)

set(comp_flags "-Wall -Werror -Wextra -pedantic")
set(link_flags "")
set(CMAKE_C_FLAGS ${comp_flags})
set(CMAKE_CXX_FLAGS ${comp_flags})
set(CMAKE_C_LINK_FLAGS ${link_flags})
set(CMAKE_CXX_LINK_FLAGS ${link_flags})

add_executable(
        main
        main.cpp
        src/color.hpp src/color.cpp
        src/vector.hpp src/vector.cpp
)
