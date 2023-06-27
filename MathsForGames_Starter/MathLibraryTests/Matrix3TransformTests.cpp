#include "pch.h"
#include "CppUnitTest.h"
#include "TestToString.h"

#include "Utils.h"
#include "Matrix3.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using ::aie::Matrix3;

namespace MathLibraryTests
{
	TEST_CLASS(Matrix3TransformTests)
	{
	public:
		// make trans from floats
		TEST_METHOD(MakeTranslationFloats)
		{
			Matrix3 actual = Matrix3::MakeTranslation(1.2f, 3.4f, 1.0f);

			Assert::AreEqual(
				Matrix3(
					1.0f, 0.0f, 0.0f,
					0.0f, 1.0f, 0.0f,
					1.2f, 3.4f, 1.0f),
				actual);
		}
		// make trans from vector
		TEST_METHOD(MakeTranslationVector)
		{
			Matrix3 actual = Matrix3::MakeTranslation(Vector3(1.2f, 3.4f, 1.0f));

			Assert::AreEqual(
				Matrix3(1.0f, 0.0f, 0.0f,
					0.0f, 1.0f, 0.0f,
					1.2f, 3.4f, 1.0f),
				actual);
		}
		// make rotX from float
		TEST_METHOD(MakeRotateXFloat)
		{
			Matrix3 actual = Matrix3::MakeRotateX(3.98f);

			Assert::AreEqual(
				Matrix3(
					1, 0, 0,
					0, -0.668648f, 0.743579f,
					0, -0.743579f, -0.668648f),
				actual);
		}
		// make rotY from float
		TEST_METHOD(MakeRotateYFloat)
		{
			Matrix3 actual = Matrix3::MakeRotateY(1.76f);

			Assert::AreEqual(
				Matrix3(
					-0.188077f, 0, 0.982154f,
					0, 1, 0,
					-0.982154f, 0, -0.188077f),
				actual);
		}
		// make rotZ from float
		TEST_METHOD(MakeRotateZFloat)
		{
			Matrix3 actual = Matrix3::MakeRotateZ(9.62f);

			Assert::AreEqual(
				Matrix3(
					-0.981005f, -0.193984f, 0,
					0.193984f, -0.981005f, 0,
					0, 0, 1),
				actual);
		}
		// make rot from euler (floats)
		TEST_METHOD(MakeRotateEulerFloat)
		{
			Matrix3 actual = Matrix3::MakeEuler(1.0f, 2.0f, 3.0f);

			Assert::AreEqual(
				Matrix3(
					0.411982f, -0.058727f, 0.909297f,
					-0.833738f, -0.426918f, 0.350175f,
					0.367630f, -0.902382f, -0.224845f),
				actual);
		}
		// make rot from euler (vector)
		TEST_METHOD(MakeRotateEulerVector)
		{
			Matrix3 actual = Matrix3::MakeEuler(Vector3(1.0f, 2.0f, 3.0f));

			Assert::AreEqual(
				Matrix3(
					0.411982f, -0.058727f, 0.909297f,
					-0.833738f, -0.426918f, 0.350175f,
					0.367630f, -0.902382f, -0.224845f),
				actual);

		}
		// make scale from floats
		TEST_METHOD(MakeScaleFloat2D)
		{
			Matrix3 actual = Matrix3::MakeScale(2.0f, 3.0f);

			Assert::AreEqual(
				Matrix3(2.0f, 0.0f, 0.0f,
						0.0f, 3.0f, 0.0f,
						0.0f, 0.0f, 1.0f), actual);
		}
		// make scale from floats
		TEST_METHOD(MakeScaleFloat3D)
		{
			Matrix3 actual = Matrix3::MakeScale(2.0f, 3.0f, 4.0f);

			Assert::AreEqual(
				Matrix3(2.0f, 0.0f, 0.0f,
					0.0f, 3.0f, 0.0f,
					0.0f, 0.0f, 4.0f), actual);
		}
		// make scale from vector
		TEST_METHOD(MakeScaleVector3)
		{
			Matrix3 actual = Matrix3::MakeScale(Vector3(2.0f, 3.0f, 4.0f));

			Assert::AreEqual(
				Matrix3(2.0f, 0.0f, 0.0f,
					0.0f, 3.0f, 0.0f,
					0.0f, 0.0f, 4.0f), actual);
		}
	};
}
