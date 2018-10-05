#include "stdafx.h"
#include "CppUnitTest.h"
#include "../TestTask/Prime.h"
#include "../TestTask/Reader.h"
#include "../TestTask/Writer.h"
#include "../TestTask/Prime.cpp"
#include "../TestTask/Reader.cpp"
#include "../TestTask/Writer.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TrueReadExistingFile)
		{
			Reader r;
			r.readFromFile("../TestTask/TestFiles/TrueTest.txt");
		}
		TEST_METHOD(FailReadNotExistingFile)
		{
			Reader r;
			r.readFromFile("../TestTask/NotTrue.txt");
		}	
		TEST_METHOD(TrueChekPrimeNum)
		{
			Prime p;
			Assert::IsTrue(p.isPrime(139));
		}	
		TEST_METHOD(FalseChekPrimeNum)
		{
			Prime p;
			Assert::IsFalse(p.isPrime(22));
		}		
		TEST_METHOD(FalseFindRangeNumbers)
		{
			Prime p;
			std::mutex mutex;
			p.findPrimeNumbers(125, 1, mutex);
			Assert::IsFalse((p.getPrimeNumbers().size() > 0));
		}	
		TEST_METHOD(TrueFindRangeNumbers)
		{
			Prime p;
			std::mutex mutex;
			p.findPrimeNumbers(1, 125, mutex);
			Assert::IsTrue((p.getPrimeNumbers().size() > 0));
		}
	};
}
