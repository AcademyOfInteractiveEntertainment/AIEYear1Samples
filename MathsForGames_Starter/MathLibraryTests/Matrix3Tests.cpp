#include "pch.h"
#include "CppUnitTest.h"
#include "TestToString.h"

#include "Utils.h"
#include "Matrix3.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using ::aie::Matrix3;

namespace MathLibraryTests
{
	TEST_CLASS(Matrix3Tests)
	{
	public:
		// default constructor
		TEST_METHOD(Constructor)
		{
			Matrix3 mat;

			Assert::AreEqual(0.f, mat.m1);
			Assert::AreEqual(0.f, mat.m2);
			Assert::AreEqual(0.f, mat.m3);

			Assert::AreEqual(0.f, mat.m4);
			Assert::AreEqual(0.f, mat.m5);
			Assert::AreEqual(0.f, mat.m6);

			Assert::AreEqual(0.f, mat.m7);
			Assert::AreEqual(0.f, mat.m8);
			Assert::AreEqual(0.f, mat.m9);
		}
		// parameterized constructor (individual)
		TEST_METHOD(ConstructorParamFloats)
		{
			Matrix3 mat(1.f,2.f,3.f,
				4.f,5.f,6.f,
				7.f,8.f,9.f);

			Assert::AreEqual(1.f, mat.m1);
			Assert::AreEqual(2.f, mat.m2);
			Assert::AreEqual(3.f, mat.m3);

			Assert::AreEqual(4.f, mat.m4);
			Assert::AreEqual(5.f, mat.m5);
			Assert::AreEqual(6.f, mat.m6);

			Assert::AreEqual(7.f, mat.m7);
			Assert::AreEqual(8.f, mat.m8);
			Assert::AreEqual(9.f, mat.m9);
		}
		// parameterized constructor (array)
		TEST_METHOD(ConstructorParamArray)
		{
			float numbers[] =
			{
				1.f, 2.f, 3.f,
				4.f, 5.f, 6.f,
				7.f, 8.f, 9.f
			};
			Matrix3 mat(numbers);

			Assert::AreEqual(1.f, mat.m1);
			Assert::AreEqual(2.f, mat.m2);
			Assert::AreEqual(3.f, mat.m3);

			Assert::AreEqual(4.f, mat.m4);
			Assert::AreEqual(5.f, mat.m5);
			Assert::AreEqual(6.f, mat.m6);

			Assert::AreEqual(7.f, mat.m7);
			Assert::AreEqual(8.f, mat.m8);
			Assert::AreEqual(9.f, mat.m9);
		}
		// mat3 * vec
		TEST_METHOD(OperatorMultiplyMat3Vec3)
		{
			Matrix3 m3b(-0.188076824f, 0.f, 0.982154310f,
				0.f, 1.f, 0.f,
				-0.982154310f, 0.f, -0.188076824f);

			Vector3 v3a(13.5f, -48.23f, 862);
			Vector3 v3b = m3b * v3a;

			Assert::AreEqual(Vector3(-849.156067f, -48.23f, -148.863144f), v3b);
		}
		// mat3 * mat3
		TEST_METHOD(OperatorMultiplyMat3Mat3)
		{
			Matrix3 m3a(1, 3, 1, 2, 2, 2, 3, 1, 3);
			Matrix3 m3c(4, 6, 4, 5, 5, 6, 6, 4, 5);

			Matrix3 m3d = m3a * m3c;

			Assert::AreEqual(Matrix3(28, 28, 28, 33, 31, 33, 29, 31, 29), m3d);
		}
		// make identity
		TEST_METHOD(MakeIdentity)
		{
			Matrix3 mat = Matrix3::MakeIdentity();

			Assert::AreEqual(1.f, mat.m1);
			Assert::AreEqual(0.f, mat.m2);
			Assert::AreEqual(0.f, mat.m3);

			Assert::AreEqual(0.f, mat.m4);
			Assert::AreEqual(1.f, mat.m5);
			Assert::AreEqual(0.f, mat.m6);

			Assert::AreEqual(0.f, mat.m7);
			Assert::AreEqual(0.f, mat.m8);
			Assert::AreEqual(1.f, mat.m9);
		}
		// Tranposed
		TEST_METHOD(Transposed)
		{
			Matrix3 m3a(1, 2, 3,
				4, 5, 6,
				7, 8, 9);

			m3a = m3a.Transposed();

			Assert::AreEqual(Matrix3(1, 4, 7, 2, 5, 8, 3, 6, 9), m3a);
		}
	};
}
