#include "pch.h"
#include "CppUnitTest.h"
#include "..\lab6.3.2\lab6.3.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest632
{
	TEST_CLASS(UnitTest632)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int a[] = { 1,2,3 };
			int max = 10;
			int tmp = Max(a, 3, max, 0);
			Assert::AreEqual(10, tmp);
		}
	};
}
