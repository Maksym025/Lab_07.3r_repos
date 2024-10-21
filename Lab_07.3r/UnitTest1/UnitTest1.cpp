#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_07.3r/Lab_07.3r.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			const int k = 2;
			const int n = 2;


			int** a = new int* [n];
			for (int i = 0; i < n; i++)
				a[i] = new int[n];


			a[0][0] = 12;
			a[0][1] = -4;
			a[1][0] = -4;
			a[1][1] = 12;


			int sum = SumRowsWithNegative(a, n);


			Assert::AreEqual(16, sum);


			for (int i = 0; i < n; i++)
				delete[] a[i];
			delete[] a;
		}
	};
}
