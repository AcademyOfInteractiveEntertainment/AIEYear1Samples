/* Easings.cs
*
* Copyright 2019 Chris Dill
*
* Release under zLib License.
* See LICENSE for details.
*/

using System;

namespace Raylib
{
    public static partial class Raylib
    {
        // Linear Easing functions
        public static float EaseLinearNone(float t, float b, float c, float d)
        {
            return (c * t / d + b);
        }

        public static float EaseLinearIn(float t, float b, float c, float d)
        {
            return (c * t / d + b);
        }

        public static float EaseLinearOut(float t, float b, float c, float d)
        {
            return (c * t / d + b);
        }

        public static float EaseLinearInOut(float t, float b, float c, float d)
        {
            return (c * t / d + b);
        }

        // Sine Easing functions
        public static float EaseSineIn(float t, float b, float c, float d)
        {
            return (-c * (float)Math.Cos(t / d * ((float)Math.PI / 2)) + c + b);
        }

        public static float EaseSineOut(float t, float b, float c, float d)
        {
            return (c * (float)Math.Sin(t / d * ((float)Math.PI / 2)) + b);
        }

        public static float EaseSineInOut(float t, float b, float c, float d)
        {
            return (-c / 2 * ((float)Math.Cos((float)Math.PI * t / d) - 1) + b);
        }

        // Circular Easing functions
        public static float EaseCircIn(float t, float b, float c, float d)
        {
            return (-c * ((float)Math.Sqrt(1 - (t /= d) * t) - 1) + b);
        }

        public static float EaseCircOut(float t, float b, float c, float d)
        {
            return (c * (float)Math.Sqrt(1 - (t = t / d - 1) * t) + b);
        }

        public static float EaseCircInOut(float t, float b, float c, float d)
        {
            if ((t /= d / 2) < 1)
            {
                return (-c / 2 * ((float)Math.Sqrt(1 - t * t) - 1) + b);
            }
            return (c / 2 * ((float)Math.Sqrt(1 - t * (t -= 2)) + 1) + b);
        }

        // Cubic Easing functions
        public static float EaseCubicIn(float t, float b, float c, float d)
        {
            return (c * (t /= d) * t * t + b);
        }

        public static float EaseCubicOut(float t, float b, float c, float d)
        {
            return (c * ((t = t / d - 1) * t * t + 1) + b);
        }

        public static float EaseCubicInOut(float t, float b, float c, float d)
        {
            if ((t /= d / 2) < 1)
            {
                return (c / 2 * t * t * t + b);
            }
            return (c / 2 * ((t -= 2) * t * t + 2) + b);
        }

        // Quadratic Easing functions
        public static float EaseQuadIn(float t, float b, float c, float d)
        {
            return (c * (t /= d) * t + b);
        }

        public static float EaseQuadOut(float t, float b, float c, float d)
        {
            return (-c * (t /= d) * (t - 2) + b);
        }

        public static float EaseQuadInOut(float t, float b, float c, float d)
        {
            if ((t /= d / 2) < 1)
            {
                return (((c / 2) * (t * t)) + b);
            }
            return (-c / 2 * (((t - 2) * (--t)) - 1) + b);
        }

        // Exponential Easing functions
        public static float EaseExpoIn(float t, float b, float c, float d)
        {
            return (t == 0) ? b : (c * (float)Math.Pow(2, 10 * (t / d - 1)) + b);
        }

        public static float EaseExpoOut(float t, float b, float c, float d)
        {
            return (t == d) ? (b + c) : (c * (-(float)Math.Pow(2, -10 * t / d) + 1) + b);
        }

        public static float EaseExpoInOut(float t, float b, float c, float d)
        {
            if (t == 0)
            {
                return b;
            }
            if (t == d)
            {
                return (b + c);
            }
            if ((t /= d / 2) < 1)
            {
                return (c / 2 * (float)Math.Pow(2, 10 * (t - 1)) + b);
            }
            return (c / 2 * (-(float)Math.Pow(2, -10 * --t) + 2) + b);
        }

        // Back Easing functions
        public static float EaseBackIn(float t, float b, float c, float d)
        {
            float s = 1.70158f;
            float postFix = t /= d;
            return (c * (postFix) * t * ((s + 1) * t - s) + b);
        }

        public static float EaseBackOut(float t, float b, float c, float d)
        {
            float s = 1.70158f;
            return (c * ((t = t / d - 1) * t * ((s + 1) * t + s) + 1) + b);
        }

        public static float EaseBackInOut(float t, float b, float c, float d)
        {
            float s = 1.70158f;
            if ((t /= d / 2) < 1)
            {
                return (c / 2 * (t * t * (((s *= (1.525f)) + 1) * t - s)) + b);
            }

            float postFix = t -= 2;
            return (c / 2 * ((postFix) * t * (((s *= (1.525f)) + 1) * t + s) + 2) + b);
        }

        // Bounce Easing functions
        public static float EaseBounceOut(float t, float b, float c, float d)
        {
            if ((t /= d) < (1 / 2.75f))
            {
                return (c * (7.5625f * t * t) + b);
            }
            else if (t < (2 / 2.75f))
            {
                float postFix = t -= (1.5f / 2.75f);
                return (c * (7.5625f * (postFix) * t + 0.75f) + b);
            }
            else if (t < (2.5 / 2.75))
            {
                float postFix = t -= (2.25f / 2.75f);
                return (c * (7.5625f * (postFix) * t + 0.9375f) + b);
            }
            else
            {
                float postFix = t -= (2.625f / 2.75f);
                return (c * (7.5625f * (postFix) * t + 0.984375f) + b);
            }
        }

        public static float EaseBounceIn(float t, float b, float c, float d)
        {
            return (c - EaseBounceOut(d - t, 0, c, d) + b);
        }

        public static float EaseBounceInOut(float t, float b, float c, float d)
        {
            if (t < d / 2)
            {
                return (EaseBounceIn(t * 2, 0, c, d) * 0.5f + b);
            }
            else
            {
                return (EaseBounceOut(t * 2 - d, 0, c, d) * 0.5f + c * 0.5f + b);
            }
        }

        // Elastic Easing functions
        public static float EaseElasticIn(float t, float b, float c, float d)
        {
            if (t == 0)
            {
                return b;
            }
            if ((t /= d) == 1)
            {
                return (b + c);
            }

            float p = d * 0.3f;
            float a = c;
            float s = p / 4;
            float postFix = a * (float)Math.Pow(2, 10 * (t -= 1));

            return (-(postFix * (float)Math.Sin((t * d - s) * (2 * (float)Math.PI) / p)) + b);
        }

        public static float EaseElasticOut(float t, float b, float c, float d)
        {
            if (t == 0)
            {
                return b;
            }
            if ((t /= d) == 1)
            {
                return (b + c);
            }

            float p = d * 0.3f;
            float a = c;
            float s = p / 4;

            return (a * (float)Math.Pow(2, -10 * t) * (float)Math.Sin((t * d - s) * (2 * (float)Math.PI) / p) + c + b);
        }

        public static float EaseElasticInOut(float t, float b, float c, float d)
        {
            if (t == 0)
            {
                return b;
            }
            if ((t /= d / 2) == 2)
            {
                return (b + c);
            }

            float p = d * (0.3f * 1.5f);
            float a = c;
            float s = p / 4;

            float postFix = 0f;
            if (t < 1)
            {
                postFix = a * (float)Math.Pow(2, 10 * (t -= 1));
                return -0.5f * (postFix * (float)Math.Sin((t * d - s) * (2 * (float)Math.PI) / p)) + b;
            }

            postFix = a * (float)Math.Pow(2, -10 * (t -= 1));

            return (postFix * (float)Math.Sin((t * d - s) * (2 * (float)Math.PI) / p) * 0.5f + c + b);
        }
    }
}
