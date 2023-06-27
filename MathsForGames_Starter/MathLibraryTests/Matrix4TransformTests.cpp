#include "pch.h"
#include "CppUnitTest.h"
#include "TestToString.h"

#include "Utils.h"
#include "Matrix4.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using ::aie::Matrix4;

namespace MathLibraryTests
{
	TEST_CLASS(Matrix4TransformTests)
	{
	public:
		// make trans from floats
		TEST_METHOD(MakeTranslationFloats)
		{
			Matrix4 actual = Matrix4::MakeTranslation(2.0f, 3.0f, 4.0f);

			Assert::AreEqual(
				Matrix4(1, 0, 0, 0,
					0, 1, 0, 0,
					0, 0, 1, 0,
					2.f, 3.f, 4.f, 1), actual);
		}
		// make trans from vector
		TEST_METHOD(MakeTranslationVector)
		{
			Matrix4 actual = Matrix4::MakeTranslation(Vector3(2.0f, 3.0f, 4.0f));

			Assert::AreEqual(
				Matrix4(1, 0, 0, 0,
					0, 1, 0, 0,
					0, 0, 1, 0,
					2.f, 3.f, 4.f, 1), actual);
		}
		// make rotX from float
		TEST_METHOD(MakeRotateXFloat)
		{
			Matrix4 actual = Matrix4::MakeRotateX(4.5f);

			Assert::AreEqual(
				Matrix4(1, 0, 0, 0,
				0, -0.210796f, 0.97753f, 0,
				0, -0.97753f, -0.210796f, 0,
				0, 0, 0, 1), actual);
		}
		// make rotY from float
		TEST_METHOD(MakeRotateYFloat)
		{
			Matrix4 actual = Matrix4::MakeRotateY(-2.6f);

			Assert::AreEqual(
				Matrix4(-0.856889f, 0, -0.515501f, 0,
				0, 1, 0, 0,
				0.515501f, 0, -0.856889f, 0,
				0, 0, 0, 1), actual);
		}
		// make rotZ from float
		TEST_METHOD(MakeRotateZFloat)
		{
			Matrix4 actual = Matrix4::MakeRotateZ(0.72f);

			Assert::AreEqual(
				Matrix4(0.751806f, 0.659385f, 0, 0,
					-0.659385f, 0.751806f, 0, 0,
					0, 0, 1, 0,
					0, 0, 0, 1), actual);
		}
		// make rot from euler (floats)
		TEST_METHOD(MakeRotateEulerFloat)
		{
			Matrix4 actual = Matrix4::MakeEuler(Vector3(1.0f, 2.0f, 3.0f));

			Assert::AreEqual(
				Matrix4(0.411982f, -0.058727f, 0.909297f, 0.0f,
					-0.833738f, -0.426918f, 0.350175f, 0.0f,
					0.367630f, -0.902382f, -0.224845f,
					0.0f, 0.0f, 0.0f, 0.0f, 1.0f),
				actual);
		}
		// make rot from euler (vector)
		TEST_METHOD(MakeRotateEulerVector)
		{
			Matrix4 actual = Matrix4::MakeEuler(Vector3(1.0f, 2.0f, 3.0f));

			Assert::AreEqual(
				Matrix4(0.411982f, -0.058727f, 0.909297f, 0.0f,
					-0.833738f, -0.426918f, 0.350175f, 0.0f,
					0.367630f, -0.902382f, -0.224845f,
					0.0f, 0.0f, 0.0f, 0.0f, 1.0f),
				actual);
		}
		// make scale from floats
		TEST_METHOD(MakeScaleFloat3D)
		{
			Matrix4 actual = Matrix4::MakeScale(2.0f, 3.0f, 4.0f);

			Assert::AreEqual(
				Matrix4(2.0f, 0, 0, 0,
				0, 3.0f, 0, 0,
				0, 0, 4.0f, 0,
				0, 0, 0, 1), actual);

		}
		// make scale from vector
		TEST_METHOD(MakeScaleVector3)
		{
			Matrix4 actual = Matrix4::MakeScale(Vector3(2.0f, 3.0f, 4.0f));

			Assert::AreEqual(
				Matrix4(2.0f, 0, 0, 0,
					0, 3.0f, 0, 0,
					0, 0, 4.0f, 0,
					0, 0, 0, 1), actual);
		}
	};
}
