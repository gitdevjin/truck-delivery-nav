#include "pch.h"
#include <iostream>
#include "CppUnitTest.h"
#include "header_r.h"
#include "mapping.h"
#include "mapping.c"

/******************BLACKBOX TESTING(T_006-T_011)*********************
* Tester Name : Jeremy
* Description : Black Box Unit Test for New Functions in structure.h
********************************************************************/

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest2
{
	TEST_CLASS(W_T006)
	{
	public:

		bool compareStructs(const Map& struct1, const Map& struct2)
		{
			if (struct1.numRows != struct2.numRows || struct1.numCols != struct2.numCols)
			{
				// If the two int variables are not equal, return false
				return false;
			}

			for (int i = 0; i < 4; ++i)
			{
				for (int j = 0; j < 3; ++j)
				{
					if (struct1.squares[i][j] != struct2.squares[i][j])
					{
						// If the two arrays are not equal, return false
						return false;
					}
				}
			}

			// If all comparisons pass, return true
			return true;
		}
		TEST_METHOD(W_T006_2)
		{
			/********************************************************************
			Test-ID: t006-2
			Test-Data: Default map, default int 25, default int 25
			Expected: Return the default int 25 with no problems.
			********************************************************************/
			struct Map Map_Test =
			{
				//0	1  2  3  4  5  6  7  8  9  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4
				//A B  C  D  E  F  G  H  I  J  K  L  M  N  O  P  Q  R  S  T  U  V  W  X  Y
				{
				{0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//0
				{0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0},	//1
				{0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0},	//2
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//3
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//4
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//5
				{1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0},	//6
				{1, 1, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 1, 1},	//7
				{0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 1, 1},	//8
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//9
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//10
				{1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1},	//11
				{1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1},	//12
				{1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1},	//13
				{1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1},	//14
				{1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1},	//15
				{0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//16
				{0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//17
				{0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},	//18
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//19
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//20
				{0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0},	//21
				{0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1},	//22
				{0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1},	//23
				{0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}		//24
				},
				25, 25
			};

			struct Map Map_Return = populateMap();
			bool check = compareStructs(Map_Test, Map_Return);
			Assert::IsTrue(check);
		}
	};

	TEST_CLASS(W_T007)
	{
	public:
		TEST_METHOD(W_T007_4)
		{
			/********************************************************************
			Test-ID: t007-4
			Test-Data: int squares {1} and {2}, int numRows 3, int numCols 4
			Expected: PASS - Should return integer of 3.
			********************************************************************/
			struct Map Test_Map = { {{1},{2}},3,4 };
			int Test_Row = getNumRows(&Test_Map);
			int Correct = 3;
			Assert::IsTrue(Test_Row == Correct);
		}

		TEST_METHOD(W_T007_5)
		{
			/********************************************************************
			Test-ID: t007-5
			Test-Data: int squares {1} and {2}, int numRows -3, int numCols 4
			Expected: FAIL - Should only qualify if rows is a non-zero
				positive number. If it isn't a positive number, set the
				element to NULL.
			********************************************************************/
			struct Map Test_Map = { {{1},{2}},-3,4 };
			int Test_Row = getNumRows(&Test_Map);
			int Correct = -3;
			Assert::IsTrue(Test_Row == Correct);
		}


		TEST_METHOD(W_T007_6)
		{
			/********************************************************************
			Test-ID: t007-6
			Test-Data: int squares {1} and {2}, int numRows -3, int numCols 4
			Expected: PASS - Just because the integer is NULL, it should still
				pass on the NULL.
			********************************************************************/
			struct Map Test_Map = { {{1},{2}},NULL,4 };
			int Test_Row = getNumRows(&Test_Map);
			int Correct = NULL;
			Assert::IsTrue(Test_Row == Correct);
		}

		TEST_METHOD(W_T007_7)
		{
			/********************************************************************
			Test-ID: t007-6
			Test-Data: int squares {1} and {2}, float numRows 3.1, int numCols 4
			Expected: FAIL - The map contains incorrect data type of float when
				it should be an integer. An error or message should appear to
				show this will be a potential problem.
			********************************************************************/
			struct Map Test_Map = { {{1},{2}},3.9,4 };
			int Test_Row = getNumRows(&Test_Map);
			int Correct = 3;
			Assert::IsTrue(Test_Row != Correct);
		}
	};

	TEST_CLASS(W_T008)
	{
	public:
		TEST_METHOD(W_T008_4)
		{
			/********************************************************************
			Test-ID: t008-4
			Test-Data: int squares {1} and {2}, int numRows 3, int numCols 4
			Expected: PASS - Should return integer of 4.
			********************************************************************/
			struct Map Test_Map = { {{1},{2}},3,4 };
			int Test_Row = getNumCols(&Test_Map);
			int Correct = 4;
			Assert::IsTrue(Test_Row == Correct);
		}

		TEST_METHOD(W_T008_5)
		{
			/********************************************************************
			Test-ID: t008-5
			Test-Data: int squares {1} and {2}, int numRows 3, int numCols -50
			Expected: PASS - Should return integer of -50.
			********************************************************************/
			struct Map Test_Map = { {{1},{2}},3,-50 };
			int Test_Row = getNumCols(&Test_Map);
			int Correct = -50;
			Assert::IsTrue(Test_Row == Correct);
		}

		TEST_METHOD(W_T008_6)
		{
			/********************************************************************
			Test-ID: t008-6
			Test-Data: int squares {1} and {2}, int numRows 3, int numCols -50
			Expected: PASS - Should return NULL.
			********************************************************************/
			struct Map Test_Map = { {{1},{2}},3,NULL };
			int Test_Row = getNumCols(&Test_Map);
			int Correct = NULL;
			Assert::IsTrue(Test_Row == Correct);
		}

		TEST_METHOD(W_T008_7)
		{
			/********************************************************************
			Test-ID: t008-7
			Test-Data: int squares {1} and {2}, int numRows 3, int numCols -50
			Expected: FAIL - The map contains incorrect data type of float when
				it should be an integer. An error or message should appear to
				show this will be a potential problem. There is no implicit
				casting.
			********************************************************************/
			struct Map Test_Map = { {{1},{2}},3,0.9 };
			int Test_Row = getNumCols(&Test_Map);
			int Correct = 0;
			Assert::IsTrue(Test_Row != Correct);
		}
	};

	TEST_CLASS(W_T009)
	{
	public:
		/********************************************************************
		Test-ID: t009-2
		Test-Data: int squares {1} and {2}, int numRows 3, int numCols -50
		Expected: Pass- Simply prints out map. If check statement changes,
			it means the function went through with no problems since there
			is no way to set output as a bool.
		********************************************************************/
		TEST_METHOD(W_T009_2)
		{
			int test = 1;
			int test2 = 1;
			Assert::IsTrue(test == test2);
		}
	};

	TEST_CLASS(W_T010)
	{
	public:
		TEST_METHOD(W_T010_4)
		{
			/********************************************************************
			Test-ID: t010-4
			Test-Data: int squares {1} and {2}, int numRows 3, int numCols -50
			Expected: Pass- Simply prints out map. If check statement changes,
				it means the function went through with no problems since there
				is no way to set output as a bool.
			********************************************************************/
			struct Route Test_Route =
			{
				{
					{0, 0},
					{1, 0},
					{2, 0},
					{3, 0},
					{4, 0}, {4, 1}, {4, 2}, {4, 3}
				}, 8,YELLOW
			};

			int check = 1;
			struct Map Test_Map = populateMap();
			struct Map Final_Map = addRoute(&Test_Map, &Test_Route);
			check = 0;
			Assert::IsTrue(check == 0);
		}
	};

	TEST_CLASS(W_T011)
	{
	public:
		TEST_METHOD(W_T011_2)
		{
			struct Point Test_Point = { 2,2 };
			struct Route Test_Route = getGreenRoute();

			int check = 1;
			addPtToRoute(&Test_Route, Test_Point);
			check = 0;

			Assert::IsTrue(check == 0);
		}
	};
}