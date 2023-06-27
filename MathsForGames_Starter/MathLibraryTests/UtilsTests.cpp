#include "pch.h"
#include "CppUnitTest.h"

#include "Utils.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace aie;

namespace MathLibraryTests
{
	TEST_CLASS(UtilsTests)
	{
	public:
		TEST_METHOD(ApproxEquals)
		{
			Assert::IsTrue(ApproximatelyEquals(1.1f, 2.2f / 2.0f));
			Assert::IsFalse(ApproximatelyEquals(1.1f, 1.2f));
			Assert::IsFalse(ApproximatelyEquals(1.1f, 1.0f));
		}

		TEST_METHOD(CheckForMaxDelta)
		{
			Assert::AreEqual(0.00001f, aie::MAX_FLOAT_DELTA, L"Bad MAX_FLOAT_DELTA value - double check against tutorials/exercises");
		}
	};
}
