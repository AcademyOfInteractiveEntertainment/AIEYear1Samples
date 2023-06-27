#include "pch.h"
#include "CppUnitTest.h"
#include "TestToString.h"

#include "Utils.h"
#include "Vector4.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using ::aie::Vector4;

namespace MathLibraryTests
{
	TEST_CLASS(Vector4Tests)
	{
	public:
		TEST_METHOD(DefaultConstructor)
		{
			Vector4 vec;
			Assert::AreEqual(0.f, vec.x);
			Assert::AreEqual(0.f, vec.y);
			Assert::AreEqual(0.f, vec.z);
			Assert::AreEqual(0.f, vec.w);
		}

		TEST_METHOD(SpecializedConstructor)
		{
			Vector4 vec(1.f, 2.f, 3.f, 4.f);
			Assert::AreEqual(1.f, vec.x);
			Assert::AreEqual(2.f, vec.y);
			Assert::AreEqual(3.f, vec.z);
			Assert::AreEqual(4.f, vec.w);
		}

		TEST_METHOD(Magnitude)
		{
			Vector4 v4a(13.5f, -48.23f, 862, 0);
			float mag4 = v4a.Magnitude();

			Assert::AreEqual(863.453735352f, mag4);
		}

		TEST_METHOD(Normalised)
		{
			Vector4 v4a(243, -48.23f, 862, 22.2f);
			Vector4 v4b = v4a.Normalised();

			Assert::AreEqual(Vector4(0.270852f, -0.053758f, 0.960800f, 0.024745f), v4b);
		}

		TEST_METHOD(Normalise)
		{
			Vector4 v4a(243, -48.23f, 862, 22.2f);
			v4a.Normalise();

			Assert::AreEqual(Vector4(0.270852f, -0.053758f, 0.960800f, 0.024745f), v4a);
		}

		TEST_METHOD(Dot)
		{
			Vector4 v4a(13.5f, -48.23f, 862, 0);
			Vector4 v4b(5, 3.99f, -12, 1);
			float dot4 = v4a.Dot(v4b);

			Assert::AreEqual(-10468.9375f, dot4, 0.0001f);
		}

		TEST_METHOD(Cross)
		{
			Vector4 v4a(13.5f, -48.23f, 862, 0);
			Vector4 v4b(5, 3.99f, -12, 1);
			Vector4 v4c = v4a.Cross(v4b);

			Assert::AreEqual(Vector4(-2860.62011719f, 4472.00000000f, 295.01498413f, 0), v4c);
		}

		TEST_METHOD(Add)
		{
			Vector4 v4a(13.5f, -48.23f, 862, 0);
			Vector4 v4b(5, 3.99f, -12, 1);
			Vector4 v4c = v4a + v4b;

			Assert::AreEqual(Vector4(18.5f, -44.24f, 850, 1), v4c);
		}

		TEST_METHOD(Subtract)
		{
			Vector4 v4a(13.5f, -48.23f, 862, 0);
			Vector4 v4b(5, 3.99f, -12, 1);
			Vector4 v4c = v4a - v4b;

			Assert::AreEqual(Vector4(8.5f, -52.22f, 874, -1), v4c);
		}

		TEST_METHOD(MultiplyScalarPost)
		{
			Vector4 v4a(13.5f, -48.23f, 862, 0);
			Vector4 v4c = v4a * 4.89f;

			Assert::AreEqual(Vector4(66.0149993896f, -235.844696045f, 4215.1796875f, 0), v4c);
		}

		TEST_METHOD(MultiplyScalarPre)
		{
			Vector4 v4a(13.5f, -48.23f, 862, 0);
			Vector4 v4c = 4.89f * v4a;

			Assert::AreEqual(Vector4(66.0149993896f, -235.844696045f, 4215.1796875f, 0), v4c);
		}

		TEST_METHOD(DivideScalar)
		{
			Vector4 v4a(13.5f, -48.23f, 862, 344.2f);
			Vector4 v4c = v4a / 0.256f;

			Assert::AreEqual(Vector4(52.734371f, -188.398422f, 3367.187256f, 1344.531250f), v4c);
		}

		TEST_METHOD(Equality)
		{
			Vector4 v4a(13.5f, -48.23f, 862, 344.2f);
			Vector4 v4b(13.5f, -48.23f, 862, 344.2f);

			Assert::IsTrue(v4a == v4b);
		}

		TEST_METHOD(Inequality)
		{
			Vector4 v4a(13.5f, -48.23f, 862, 344.2f);
			Vector4 v4b(0.0f, 0.0f, 0.0f, 0.0f);

			Assert::IsTrue(v4a != v4b && !(v4a == v4b));
		}

		// TODO: implement tests for compound operators
	};
}
