#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_13/defs.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace UnitTest1
{
	TEST_CLASS(ComparingTest)
	{
	public:
		
		TEST_METHOD(ComparingMethod1)
		{
			char str1[Max_Length] = "Строка.";
			char str2[Max_Length] = "Строка.";

			Assert::AreEqual(str_cmp(str1, str2), 0);
		}


		TEST_METHOD(ComparingMethod2)
		{
			char str1[Max_Length] = "АБВГД";  // char '\0' = int 0
			char str2[Max_Length] = "АБВГД.";  // char '.' = int 46

			Assert::AreEqual(str_cmp(str1, str2), -1);
		}


		TEST_METHOD(ComparingMethod3)
		{
			char str1[Max_Length] = "ABCD";  // char 'D' = int 68
			char str2[Max_Length] = "ABC";  // char '\0' = int 0

			Assert::AreEqual(str_cmp(str1, str2), 1);
		}


		TEST_METHOD(ComparingMethod4)
		{
			char str1[Max_Length] = "Строки";  // char 'и' = int 53432
			char str2[Max_Length] = "Строка";  // char 'а' = int 53424

			Assert::AreEqual(str_cmp(str1, str2), 1);
		}


		TEST_METHOD(ComparingMethod5)
		{
			char str1[Max_Length] = "Вода";  // char 'а' = int 53424
			char str2[Max_Length] = "Воды";  // char 'ы' = int 53643

			Assert::AreEqual(str_cmp(str1, str2), -1);
		}
	};



	TEST_CLASS(WordsCountTest)
	{
	public:

		TEST_METHOD(WordsCountMethod1)
		{
			char str[Max_Length] = "What's strong enough to smash ships but still fears the sun?";

			Assert::AreEqual(word_count(str), 11);
		}


		TEST_METHOD(WordsCountMethod2)
		{
			char str[Max_Length] = "     Я крепка как скала,    но рушусь об  слова.   Что я?     ";

			Assert::AreEqual(word_count(str), 10);
		}


		TEST_METHOD(WordsCountMethod3)
		{
			char str[Max_Length] = "          ";

			Assert::AreEqual(word_count(str), 0);
		}
	};


		
	TEST_CLASS(CharSearchTest)
	{
	public:

		TEST_METHOD(CharSearchMethod1)
		{
			char str[Max_Length] = "Aa Bb Cc Dd Ee";

			Assert::AreEqual(str_chr(str, 'b'), "b Cc Dd Ee");
		}


		TEST_METHOD(CharSearchMethod2)
		{
			char str[Max_Length] = "Aa Bb Cc Dd Ee";

			Assert::AreEqual(str_chr(str, 'E'), "Ee");
		}


		TEST_METHOD(CharSearchMethod3)
		{
			char str[Max_Length] = "Aa Bb Cc Dd Ee";

			Assert::AreEqual(str_chr(str, 'H'), nullptr);
		}
	};



	TEST_CLASS(CharDeletingTest)
	{
	public:

		TEST_METHOD(CharDeletingMethod1)
		{
			char str[Max_Length] = "ABRACADABRA";
			char res[Max_Length] = "BRCDBR";
			remove_chr(str, 'A');
			Assert::AreEqual(str, res);
		}


		TEST_METHOD(CharDeletingMethod2)
		{
			char str[Max_Length] = "ABRACADABRA";
			char res[Max_Length] = "ABRACADABRA";
			remove_chr(str, 'T');
			Assert::AreEqual(str, res);
		}
	};



	TEST_CLASS(SubstrTest)
	{
	public:

		TEST_METHOD(SubstrMethod1)
		{
			char str1[Max_Length] = "Маша купила _ и побежала домой.";
			char str2[Max_Length] = "банку варенья";
			char res[Max_Length] = "Маша купила _банку варенья и побежала домой.";
			insert_str(str1, str2, '_');
			Assert::AreEqual(str1, res);
		}


		TEST_METHOD(SubstrMethod2)
		{
			auto func = [] { 
				char str1[Max_Length] = "Маша купила и побежала домой.";
				char str2[Max_Length] = "банку варенья";
				insert_str(str1, str2, '_'); 
			};
			Assert::ExpectException<char*>(func);
		}
	};
}
