#pragma once

#pragma once

#include <cassert>
#include <cstdint>

#include <string>

namespace aie
{
    struct Color
    {
        union
        {
            // char8_t not available until C++20
            struct
            {
                unsigned char r, g, b, a;
            };

            unsigned char v[4];

            // use fixed-size type for portability
            int32_t rgba;
        };

        Color()
        {

        }

        Color(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha)
        {

        }

        std::string ToString() const
        {

        }

        bool operator==(const Color& rhs) const
        {

        }

        // OPTIONAL
        unsigned char& operator [](int dim)
        {

        }

        unsigned char operator [](int dim) const
        {

        }
    };
}