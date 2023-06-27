#pragma once

#include <cmath>
#include <cassert>

// OPTIONAL
#include <string>

#include "Utils.h"

namespace aie
{
    struct Vector4
    {
        union
        {
            struct
            {
                float x, y, z, w;
            };

            float v[4];
        };

        Vector4()
        {

        }

        Vector4(float inX, float inY, float inZ, float inW)
        {

        }

        float Magnitude() const
        {

        }

        float Dot(const Vector4& rhs) const
        {

        }

        Vector4 Cross(const Vector4& rhs) const
        {

        }

        void Normalise()
        {

        }

        Vector4 Normalised() const
        {

        }

        Vector4 operator +(const Vector4& rhs) const
        {

        }

        Vector4& operator +=(const Vector4& rhs)
        {

        }

        Vector4 operator -(const Vector4& rhs) const
        {

        }

        Vector4& operator -=(const Vector4& rhs)
        {

        }

        Vector4 operator *(const Vector4& rhs) const
        {

        }

        Vector4& operator *=(const Vector4& rhs)
        {

        }

        Vector4 operator /(const Vector4& rhs) const
        {

        }

        Vector4& operator /=(const Vector4& rhs)
        {

        }

        Vector4 operator *(float rhs) const
        {

        }

        Vector4& operator *=(float rhs)
        {

        }

        // NOTE: (float * Vector4) implemented as a free-function below

        Vector4 operator /(float rhs) const
        {

        }

        Vector4 operator -() const
        {

        }

        bool operator == (const Vector4& rhs) const
        {

        }

        bool operator != (const Vector4& rhs) const
        {

        }

        std::string ToString() const
        {
            return std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + ", " + std::to_string(w);
        }

        //
        // OPTIONAL
        //

        float& operator [](int dim)
        {

        }

        const float& operator [](int dim) const
        {

        }

        float MagnitudeSqr() const
        {
            
        }
    };

    inline Vector4 operator*(float scalar, const Vector4& vector)
    {
        
    }
}