#pragma once

#include <cmath>
#include <cassert>

// OPTIONAL
#include <string>

#include "Utils.h"
#include "Vector3.h"
#include "Vector4.h"

namespace aie
{
    struct Matrix4
    {
        union
        {
            // 16 individual in column-order
            struct
            {
                float m1, m2, m3, m4,
                      m5, m6, m7, m8,
                      m9, m10, m11, m12,
                      m13, m14, m15, m16;
            };

            // 16-float-wide array in column-order
            float v[16];
            // every inner array represents a column
            float mm[4][4];
        };

        Matrix4()
        {
            
        }

        Matrix4(float inM1, float inM2, float inM3, float inM4,
               float inM5, float inM6, float inM7, float inM8,
               float inM9, float inM10, float inM11, float inM12,
               float inM13, float inM14, float inM15, float inM16)
        {

        }

        Matrix4(float* inArr)
        {

        }

        Vector4 operator *(Vector4 rhs)
        {

        }

        Matrix4 operator *(Matrix4 rhs)
        {

        }

        bool operator == (const Matrix4& rhs) const
        {

        }

        //
        // Transform Factory Methods
        //

        static Matrix4 MakeIdentity()
        {

        }

        static Matrix4 MakeTranslation(float x, float y, float z)
        {
            
        }

        static Matrix4 MakeTranslation(Vector3 vec)
        {
            
        }

        static Matrix4 MakeRotateX(float a)
        {
            
        }

        static Matrix4 MakeRotateY(float a)
        {
            
        }

        static Matrix4 MakeRotateZ(float a)
        {
            
        }

        static Matrix4 MakeEuler(float pitch, float yaw, float roll)
        {
            
        }

        static Matrix4 MakeEuler(Vector3 rot)
        {
            
        }

        static Matrix4 MakeScale(float xScale, float yScale, float zScale)
        {
            
        }

        static Matrix4 MakeScale(Vector3 scale)
        {
            
        }

        std::string ToString() const
        {
            std::string str = std::to_string(v[0]);
            for (size_t i = 1; i < 16; ++i)
            {
                str += ", " + std::to_string(v[i]);
            }
            return str;
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

        operator float* () {  }
        operator const float* () const {  }
    };
}