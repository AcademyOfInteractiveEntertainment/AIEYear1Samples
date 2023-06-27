#pragma once

#include "CppUnitTestAssert.h"

namespace aie { namespace test {

	using Microsoft::VisualStudio::CppUnitTestFramework::__LineInfo;

	class Assert
	{
	public:
		// Verify that two objects are equal using a custom comparer.
		template<typename T> static void AreEqualComparer(const T& expected, const T& actual, bool(*comparer)(const T& a, const T& b), const wchar_t* message = NULL, const __LineInfo* pLineInfo = NULL)
		{
			FailOnCondition(comparer(expected,actual), EQUALS_MESSAGE(expected, actual, message), pLineInfo);
		}
	};
} }