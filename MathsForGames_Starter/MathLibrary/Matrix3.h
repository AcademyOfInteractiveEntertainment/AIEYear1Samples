#pragma once

#include <cmath>
#include <cassert>

#include <string>

// OPTIONAL

#include "Utils.h"
#include "Vector3.h"

namespace aie
{
    struct Matrix3
    {
        union
        {
            struct
            {
                float m1, m2, m3, m4, m5, m6, m7, m8, m9;
            };

            float v[9];
            float mm[3][3];
            Vector3 axis[3];
        };

        Matrix3()
        {

            m9 = 0;
        }

        Matrix3(float inM1, float inM2, float inM3, float inM4, float inM5, float inM6, float inM7, float inM8, float inM9)
        {

        }

        Matrix3(float * inArr)
        {

        }

        Vector3 operator *(Vector3 rhs) const
        {

        }

        Matrix3 operator *(Matrix3 rhs) const
        {
            
        }

        Matrix3& operator *=(Matrix3 rhs)
        {
            
        }

        bool operator == (const Matrix3& rhs) const
        {

        }

        bool operator != (const Matrix3& rhs) const
        {
            
        }

        //
        // Utility
        //

        Matrix3 Transposed() const
        {
            
        }

        //
        // Transform Factory Methods
        //

        static Matrix3 MakeIdentity()
        {
            
        }

        static Matrix3 MakeTranslation(float x, float y, float z)
        {

        }

        static Matrix3 MakeTranslation(Vector3 vec)
        {

        }

        static Matrix3 MakeRotateX(float a)
        {

        }

        static Matrix3 MakeRotateY(float a)
        {

        }

        static Matrix3 MakeRotateZ(float a)
        {

        }

        static Matrix3 MakeEuler(float pitch, float yaw, float roll)
        {

        }

        static Matrix3 MakeEuler(Vector3 rot)
        {

        }

        static Matrix3 MakeScale(float xScale, float yScale)
        {

        }

        static Matrix3 MakeScale(float xScale, float yScale, float zScale)
        {

        }

        static Matrix3 MakeScale(Vector3 scale)
        {

        }

        std::string ToString() const
        {
            std::string str = std::to_string(v[0]);
            for (size_t i = 1; i < 9; ++i)
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
    };
}