#include "pch.h"
#include "CppUnitTest.h"
#include "TestToString.h"

#include "Utils.h"
#include "Color.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using ::aie::Color;

namespace MathLibraryTests
{
	TEST_CLASS(ColorTests)
	{
	public:
		// default constructor
		TEST_METHOD(ColorDefaultConstructor)
		{
			Color actual;

			Assert::AreEqual(Color(0, 0, 0, 255), actual);
		}

		// parameterized constructor
		TEST_METHOD(ColorParamConstructor)
		{
			Color actual(32, 64, 0, 255);

			Assert::AreEqual(Color(32, 64, 0, 255), actual);
		}

		// setting r
		TEST_METHOD(SetRed)
		{
			Color actual(32, 64, 0, 255);

			actual.r = 128;

			Assert::AreEqual(Color(128, 64, 0, 255), actual);
		}
		
		// setting g
		TEST_METHOD(SetGreen)
		{
			Color actual(32, 64, 0, 255);

			actual.g = 128;


			Assert::AreEqual(Color(32, 128, 0, 255), actual);
		}

		// setting b
		TEST_METHOD(SetBlue)
		{
			Color actual(32, 64, 0, 255);

			actual.b = 128;

			Assert::AreEqual(Color(32, 64, 128, 255), actual);
		}

		// setting a
		TEST_METHOD(SetAlpha)
		{
			Color actual(32, 64, 0, 255);

			actual.a = 128;

			Assert::AreEqual(Color(32, 64, 0, 128), actual);
		}
	};
}
