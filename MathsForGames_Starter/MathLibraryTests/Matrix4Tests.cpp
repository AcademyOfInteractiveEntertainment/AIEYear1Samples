#include "pch.h"
#include "CppUnitTest.h"
#include "TestToString.h"

#include "Utils.h"
#include "Matrix4.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using ::aie::Matrix4;

namespace MathLibraryTests
{
	TEST_CLASS(Matrix4Tests)
	{
	public:
		// default constructor
		TEST_METHOD(Constructor)
		{
			Matrix4 mat;

			Assert::AreEqual(0.f, mat.m1);
			Assert::AreEqual(0.f, mat.m2);
			Assert::AreEqual(0.f, mat.m3);
			Assert::AreEqual(0.f, mat.m4);

			Assert::AreEqual(0.f, mat.m5);
			Assert::AreEqual(0.f, mat.m6);
			Assert::AreEqual(0.f, mat.m7);
			Assert::AreEqual(0.f, mat.m8);

			Assert::AreEqual(0.f, mat.m9);
			Assert::AreEqual(0.f, mat.m10);
			Assert::AreEqual(0.f, mat.m11);
			Assert::AreEqual(0.f, mat.m12);


			Assert::AreEqual(0.f, mat.m13);
			Assert::AreEqual(0.f, mat.m14);
			Assert::AreEqual(0.f, mat.m15);
			Assert::AreEqual(0.f, mat.m16);
		}
		// parameterized constructor (individual)
		TEST_METHOD(ConstructorParamFloats)
		{
			Matrix4 mat(1.0f, 2.0f, 3.0f, 4.0f,
				5.0f, 6.0f, 7.0f, 8.0f,
				9.0f, 10.0f, 11.0f, 12.0f,
				13.0f, 14.0f, 15.0f, 16.0f);

			Assert::AreEqual(1.f, mat.m1);
			Assert::AreEqual(2.f, mat.m2);
			Assert::AreEqual(3.f, mat.m3);
			Assert::AreEqual(4.f, mat.m4);

			Assert::AreEqual(5.f, mat.m5);
			Assert::AreEqual(6.f, mat.m6);
			Assert::AreEqual(7.f, mat.m7);
			Assert::AreEqual(8.f, mat.m8);

			Assert::AreEqual(9.f, mat.m9);
			Assert::AreEqual(10.f, mat.m10);
			Assert::AreEqual(11.f, mat.m11);
			Assert::AreEqual(12.f, mat.m12);
			
			Assert::AreEqual(13.f, mat.m13);
			Assert::AreEqual(14.f, mat.m14);
			Assert::AreEqual(15.f, mat.m15);
			Assert::AreEqual(16.f, mat.m16);
		}
		// parameterized constructor (array)
		TEST_METHOD(ConstructorParamArray)
		{
			float numbers[] =
			{
				1.f, 2.f, 3.f, 4.f,
				5.f, 6.f, 7.f, 8.f,
				9.f, 10.f, 11.f, 12.f,
				13.f, 14.f, 15.f, 16.f
			};
			Matrix4 mat(numbers);

			Assert::AreEqual(1.f, mat.m1);
			Assert::AreEqual(2.f, mat.m2);
			Assert::AreEqual(3.f, mat.m3);
			Assert::AreEqual(4.f, mat.m4);

			Assert::AreEqual(5.f, mat.m5);
			Assert::AreEqual(6.f, mat.m6);
			Assert::AreEqual(7.f, mat.m7);
			Assert::AreEqual(8.f, mat.m8);

			Assert::AreEqual(9.f, mat.m9);
			Assert::AreEqual(10.f, mat.m10);
			Assert::AreEqual(11.f, mat.m11);
			Assert::AreEqual(12.f, mat.m12);

			Assert::AreEqual(13.f, mat.m13);
			Assert::AreEqual(14.f, mat.m14);
			Assert::AreEqual(15.f, mat.m15);
			Assert::AreEqual(16.f, mat.m16);
		}
		// mat4 * vec4
		TEST_METHOD(OperatorMultiplyMat4Vec4)
		{
			// homogeneous point translation
			Matrix4 m4b(1, 0, 0, 0,
				0, 1, 0, 0,
				0, 0, 1, 0,
				55, 44, 99, 1);

			Vector4 v4a(13.5f, -48.23f, -54, 1);

			Vector4 actual = m4b * v4a;
			Assert::AreEqual(Vector4(68.5f, -4.23f, 45, 1), actual);
		}
		// mat4 * mat4
		TEST_METHOD(OperatorMultiplyMat4Mat4)
		{
			Matrix4 m4a(1, 4, 1, 7,
				2, 3, 2, 8,
				3, 2, 3, 9,
				4, 1, 4, 1);

			Matrix4 m4b(4, 7, 3, 4,
				5, 6, 4, 6,
				6, 5, 6, 8,
				7, 4, 5, 2);

			Matrix4 actual = m4a * m4b;
			
			Assert::AreEqual(Matrix4(43, 47, 43, 115,
				53, 52, 53, 125,
				66, 59, 66, 144,
				38, 52, 38, 128),
				actual);
		}
		// make identity
		TEST_METHOD(MakeIdentity)
		{
			Matrix4 mat = Matrix4::MakeIdentity();

			Assert::AreEqual(1.f, mat.m1);
			Assert::AreEqual(0.f, mat.m2);
			Assert::AreEqual(0.f, mat.m3);
			Assert::AreEqual(0.f, mat.m4);

			Assert::AreEqual(0.f, mat.m5);
			Assert::AreEqual(1.f, mat.m6);
			Assert::AreEqual(0.f, mat.m7);
			Assert::AreEqual(0.f, mat.m8);

			Assert::AreEqual(0.f, mat.m9);
			Assert::AreEqual(0.f, mat.m10);
			Assert::AreEqual(1.f, mat.m11);
			Assert::AreEqual(0.f, mat.m12);


			Assert::AreEqual(0.f, mat.m13);
			Assert::AreEqual(0.f, mat.m14);
			Assert::AreEqual(0.f, mat.m15);
			Assert::AreEqual(1.f, mat.m16);
		}
	};
}
