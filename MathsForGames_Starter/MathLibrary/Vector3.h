#pragma once

#include <cmath>
#include <cassert>

// OPTIONAL
#include <string>

#include "Utils.h"

namespace aie
{
    struct Vector3
    {
        union
        {
            struct
            {
                float x, y, z;
            };

            float v[3];
        };

        Vector3()
        {
        }

        Vector3(float inX, float inY, float inZ)
        {

        }

        float Magnitude() const
        {
        }

        float Dot(const Vector3 &rhs) const
        {
        }

        static float Dot(const Vector3& first, const Vector3& second)
        {
        }

        Vector3 Cross(const Vector3 &rhs) const
        {
        }

        static Vector3 Cross(const Vector3 &first, const Vector3 &second)
        {
        }

        void Normalise()
        {
        }

        Vector3 Normalised() const
        {

        }

        // returns a new Vector containing the summed value of each component
        Vector3 operator +(const Vector3 &rhs) const
        {
        }

        // assigns this Vector the value of this vector added to the other vector
        Vector3& operator +=(const Vector3& rhs)
        {

        }

        // returns a new Vector containing the subtracted value of each component
        Vector3 operator -(const Vector3 &rhs) const
        {
            
        }

        // assigns this Vector the value of this vector subtracted from the other vector
        Vector3& operator -=(const Vector3& rhs)
        {
            
        }

        // returns a new Vector where each component is scaled by the scalar value
        Vector3 operator *(float rhs) const
        {
            
        }

        // assigns this Vector the value of this vector where each component is scaled by the scalar value
        Vector3& operator *=(float rhs)
        {
            
        }

        // NOTE: (float * Vector3) implemented as a free-function below

        // returns a new Vector where each component is divided by the scalar value
        Vector3 operator /(float rhs) const
        {
            
        }

        // returns true if every component is approximately equal to the other in the other vector
        bool operator == (const Vector3 &rhs) const
        {

        }

        // returns true if any component is approximately NOT equal to the other in the other vector
        bool operator != (const Vector3 &rhs) const
        {

        }

        std::string ToString() const
        {
            return std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z);
        }

        //
        // OPTIONAL
        //

        // returns a new Vector where each component is multiplied by the component from the other vector
        Vector3 operator *(const Vector3 & rhs) const
        {
            
        }

        // assigns this Vector the value of this vector multiplied by the other vector
        Vector3 & operator *=(const Vector3 & rhs)
        {
            
        }

        // returns a new Vector where each component is divided by the component from the other vector
        Vector3 operator /(const Vector3 & rhs) const
        {
            
        }

        // assigns this Vector the value of this vector divided by the other vector
        Vector3 & operator /=(const Vector3 & rhs)
        {
            
        }

        Vector3 operator -() const
        {
            
        }
        
        float & operator [](int dim)
        {

        }

        const float & operator [](int dim) const
        {

        }

        float MagnitudeSqr() const
        {

        }

        float Distance(const Vector3 &other) const
        {

        }

        float DistanceSqr(const Vector3& other) const
        {

        }

        static float Distance(const Vector3& start, const Vector3& end)
        {

        }

        static float DistanceSqr(const Vector3& start, const Vector3& end)
        {

        }

        float AngleBetween(const Vector3 &other) const
        {

        }
    };

    inline Vector3 operator*(float scalar, const Vector3& vector)
    {

    }
}