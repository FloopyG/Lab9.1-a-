#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab9.1(a).cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest91a
{
	TEST_CLASS(UnitTest91a)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int k = 1;
			Student* s = new Student[k];
			s->gradeMath = 0;
			s->gradePhys = 0;
			int t = goodMathPhys(s, k);
			Assert::AreEqual(t, 0);
		}
	};
}
