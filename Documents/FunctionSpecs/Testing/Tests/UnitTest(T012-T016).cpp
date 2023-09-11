#include "pch.h"
#include <stdio.h>
#include <iostream>
#include "CppUnitTest.h"
#include "header_r.h"
#include "mapping.h"
#include "mapping.c"
#include "structure.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;


/*******************************************************************************/
/*								BLACK BOX TESTING
/*******************************************************************************/

namespace BlackBoxUnitTest
{
	/*******************************************************************************/
	/*TEST T012						 getBlueRoute
	/*******************************************************************************/
	TEST_CLASS(BlueRouteUnitTest)
	{
	public:

		/*******************************************************************************/
		/* TEST ID: T012-01
		/* TEST DESCRIPTION: If building on map not return in function
		/* Expected result : pass
		/*******************************************************************************/
		TEST_METHOD(BlueRouteTest1)
		{
			struct Route test = getBlueRoute();
			struct Map map = populateMap();

			int result;

			for (int i = 0; i < test.numPoints; i++) {
				if (map.squares[test.points[i].row][test.points[i].col] == 1) {
					result = true;
				}
				else {
					result = false;
				}
			}

			int good = (result = true);
			Assert::IsTrue(good);
		}
		/*******************************************************************************/
		/* TEST ID: T012-02
		/* TEST DESCRIPTION: If getBlueRoute bounds are less than 0,0
		/* Expected result : pass
		/*******************************************************************************/

		TEST_METHOD(BlueRouteTest2)
		{
			struct Route test = getBlueRoute();
			struct Map map = populateMap();

			int result;

			for (int i = 0; i < test.numPoints; i++) {
				if ((test.points[i].row < 0) || (test.points[i].col < 0)) {
					result = false;
				}
				else {
					result = true;
				}
			}

			int good = (result = true);
			Assert::IsTrue(good);
		}
		/*******************************************************************************/
		/* TEST ID: T012-03
		/* TEST DESCRIPTION: If getBlueRoute bounds are greater than map
		/* Expected result : pass
		/*******************************************************************************/

		TEST_METHOD(BlueRouteTest3)
		{
			struct Route test = getBlueRoute();
			struct Map map = populateMap();

			int result;

			for (int i = 0; i < test.numPoints; i++) {
				if ((test.points[i].row > MAX_ROUTE) || (test.points[i].col > MAX_ROUTE)) {
					result = false;
				}
				else {
					result = true;
				}
			}

			int good = (result = true);
			Assert::IsTrue(good);
		}


	};

	/*******************************************************************************/
	/*TEST T013						 getGreenRoute
	/*******************************************************************************/
	TEST_CLASS(GreenRouteUnitTest)
	{
	public:

		/*******************************************************************************/
		/* TEST ID: T013-01
		/* TEST DESCRIPTION: If building on map not return in function
		/* Expected result : pass
		/*******************************************************************************/
		TEST_METHOD(GreenRouteTest1)
		{
			struct Route test = getGreenRoute();
			struct Map map = populateMap();

			int result;

			for (int i = 0; i < test.numPoints; i++) {
				if (map.squares[test.points[i].row][test.points[i].col] == 1) {
					result = true;
				}
				else {
					result = false;
				}
			}

			int good = (result = true);
			Assert::IsTrue(good);
		}
		/*******************************************************************************/
		/* TEST ID: T013-02
		/* TEST DESCRIPTION: If getGreenRoute bounds are less than 0,0
		/* Expected result : pass
		/*******************************************************************************/

		TEST_METHOD(GreenRouteTest2)
		{
			struct Route test = getGreenRoute();
			struct Map map = populateMap();

			int result;

			for (int i = 0; i < test.numPoints; i++) {
				if ((test.points[i].row < 0) || (test.points[i].col < 0)) {
					result = false;
				}
				else {
					result = true;
				}
			}

			int good = (result = true);
			Assert::IsTrue(good);
		}
		/*******************************************************************************/
		/* TEST ID: T013-03
		/* TEST DESCRIPTION: If getGreenRoute bounds are greater than map
		/* Expected result : pass
		/*******************************************************************************/

		TEST_METHOD(GreenRouteTest3)
		{
			struct Route test = getGreenRoute();
			struct Map map = populateMap();

			int result;

			for (int i = 0; i < test.numPoints; i++) {
				if ((test.points[i].row > MAX_ROUTE) || (test.points[i].col > MAX_ROUTE)) {
					result = false;
				}
				else {
					result = true;
				}
			}

			int good = (result = true);
			Assert::IsTrue(good);
		}


	};


	/*******************************************************************************/
	/*TEST T014						 getYellowRoute
	/*******************************************************************************/
	TEST_CLASS(YellowRouteUnitTest)
	{
	public:

		/*******************************************************************************/
		/* TEST ID: T014-01
		/* TEST DESCRIPTION: If building on map not return in function
		/* Expected result : pass
		/*******************************************************************************/
		TEST_METHOD(YellowRouteTest1)
		{
			struct Route test = getYellowRoute();
			struct Map map = populateMap();

			int result;

			for (int i = 0; i < test.numPoints; i++) {
				if (map.squares[test.points[i].row][test.points[i].col] == 1) {
					result = true;
				}
				else {
					result = false;
				}
			}

			int good = (result = true);
			Assert::IsTrue(good);
		}
		/*******************************************************************************/
		/* TEST ID: T014-02
		/* TEST DESCRIPTION: If getYellowRoute bounds are less than 0,0
		/* Expected result : pass
		/*******************************************************************************/

		TEST_METHOD(YellowRouteTest2)
		{
			struct Route test = getYellowRoute();
			struct Map map = populateMap();

			int result;

			for (int i = 0; i < test.numPoints; i++) {
				if ((test.points[i].row < 0) || (test.points[i].col < 0)) {
					result = false;
				}
				else {
					result = true;
				}
			}

			int good = (result = true);
			Assert::IsTrue(good);
		}
		/*******************************************************************************/
		/* TEST ID: T014-03
		/* TEST DESCRIPTION: If getYellowRoute bounds are greater than map
		/* Expected result : pass
		/*******************************************************************************/

		TEST_METHOD(YellowRouteTest3)
		{
			struct Route test = getYellowRoute();
			struct Map map = populateMap();

			int result;

			for (int i = 0; i < test.numPoints; i++) {
				if ((test.points[i].row > MAX_ROUTE) || (test.points[i].col > MAX_ROUTE)) {
					result = false;
				}
				else {
					result = true;
				}
			}

			int good = (result = true);
			Assert::IsTrue(good);
		}


	};

	/*******************************************************************************/
	/*TEST T015						 getClosestPoint
	/*******************************************************************************/
	TEST_CLASS(ClosestPointUnitTest)
	{
	public:
		/*******************************************************************************/
		/* TEST ID: T015-01
		/* TEST DESCRIPTION: If getClosestPoint return valid parameter Route and Points
		/* Expected result : pass
		/*******************************************************************************/
		TEST_METHOD(TestClosestPoint1)
		{
			struct Route route = getBlueRoute();
			struct Point pt;
			int result;

			pt.row = 0;
			pt.col = 2;
			int closestidx = getClosestPoint(&route, pt);

			if (closestidx >= 0) {
				result = true;
			}

			else {
				result = false;
			}
			int good = (result = true);
			Assert::IsTrue(good);
		}

		/*******************************************************************************/
		/* TEST ID: T015-02
		/* TEST DESCRIPTION: If getClosestPoint return parameter with valid Route and invalid Points
		/* Expected result : fail
		/*******************************************************************************/
		TEST_METHOD(TestClosestPoint2)
		{
			struct Route route = getBlueRoute();
			struct Point pt;
			int result;

			pt.row = 0.5;
			pt.col = 2;
			int closestidx = getClosestPoint(&route, pt);

			if (closestidx >= 0) {
				result = true;
			}

			else {
				result = false;
			}
			int good = (result = true);
			Assert::IsTrue(good);
		}

		/*******************************************************************************/
		/* TEST ID: T015-03
		/* TEST DESCRIPTION: If getClosestPoint return parameter with invalid Route and invalid Points
		/* Expected result : fail
		/*******************************************************************************/
		TEST_METHOD(TestClosestPoint3)
		{
			struct Route route = getBlueRoute();
			struct Point pt;
			int result;

			pt.row = 0.5;
			pt.col = 2;
			int closestidx = getClosestPoint(&route, pt);

			if (closestidx < 0) {
				result = true;
			}

			else {
				result = false;
			}
			int good = (result = true);
			Assert::IsTrue(good);
		}
		/*******************************************************************************/
		/* TEST ID: T015-04
		/* TEST DESCRIPTION: If getClosestPoint return parameter with invalid Route and valid Points
		/* Expected result : pass
		/*******************************************************************************/
		TEST_METHOD(TestClosestPoint4)
		{
			struct Route route = getBlueRoute();
			struct Point pt;
			int result;

			pt.row = 0;
			pt.col = 2;
			int closestidx = getClosestPoint(&route, pt);

			if (closestidx < 0) {
				result = true;
			}

			else {
				result = false;
			}
			int good = (result = true);
			Assert::IsTrue(good);
		}
		/*******************************************************************************/
		/* TEST ID: T015-05
		/* TEST DESCRIPTION: If getClosestPoint return with Points outside of bounds
		/* Expected result : fail
		/*******************************************************************************/
		TEST_METHOD(TestClosestPoint5)
		{
			struct Route route = getBlueRoute();
			struct Point pt;
			int result;

			pt.row = 50;
			pt.col = 2;
			int closestidx = getClosestPoint(&route, pt);

			if (closestidx >= 0) {
				result = true;
			}

			else {
				result = false;
			}
			int good = (result = true);
			Assert::IsTrue(good);
		}
		/*******************************************************************************/
		/* TEST ID: T015-06
		/* TEST DESCRIPTION: If getClosestPoint return with Points outside of bounds
		/* Expected result : fail
		/*******************************************************************************/
		TEST_METHOD(TestClosestPoint6)
		{
			struct Route route = getBlueRoute();
			struct Point pt;
			int result;

			pt.row = 0;
			pt.col = 50;
			int closestidx = getClosestPoint(&route, pt);

			if (closestidx >= 0) {
				result = true;
			}

			else {
				result = false;
			}
			int good = (result = true);
			Assert::IsTrue(good);

		}

	};
	/*******************************************************************************/
	/*TEST T016							 eqPt
	/*******************************************************************************/

	TEST_CLASS(eqPtUnitTest)
	{
	public:

		/*******************************************************************************/
		/* TEST ID: T016-01
		/* TEST DESCRIPTION: Test if same char paramters will function return true
		/* Expected result : pass
		/*******************************************************************************/

		TEST_METHOD(TesteqPt1)
		{
			struct Point test1 = { 'c','h' };
			struct Point test2 = { 'c','h' };
			bool result = eqPt(test1, test2);

			Assert::IsTrue(result);

		}

		/*******************************************************************************/
		/* TEST ID: T016-02
		/* TEST DESCRIPTION: Test if different char paramters will function return as false
		/* Expected result : fail
		/*******************************************************************************/

		TEST_METHOD(TesteqPt2)
		{

			struct Point test1 = { 'd','h' };
			struct Point test2 = { 'c','h' };
			bool result = eqPt(test1, test2);

			Assert::IsFalse(result);

		}



		/*******************************************************************************/
		/* TEST ID: T016-03
		/* TEST DESCRIPTION: Test if int parameters will function return as true
		/* Expected result : pass
		/*******************************************************************************/

		TEST_METHOD(TesteqPt3)
		{

			struct Point test1 = { 1,2 };
			struct Point test2 = { 1,2 };
			bool result = eqPt(test1, test2);

			Assert::IsTrue(result);

		}


		/*******************************************************************************/
		/* TEST ID: T016-04
		/* TEST DESCRIPTION: Test if char parameter and int parameter will return with same value
		/* Expected result : fail
		/*******************************************************************************/

		TEST_METHOD(TesteqPt4)
		{

			struct Point test1 = { '1','2' };
			struct Point test2 = { 1,2 };
			bool result = eqPt(test1, test2);

			Assert::IsFalse(result);

		}



		/*******************************************************************************/
		/* TEST ID: T016-05
		/* TEST DESCRIPTION: Test if two same negative paramter will return as true
		/* Expected result : true
		/*******************************************************************************/

		TEST_METHOD(TesteqPt5)
		{

			struct Point test1 = { -1,2 };
			struct Point test2 = { -1,2 };
			bool result = eqPt(test1, test2);

			Assert::IsTrue(result);
		}

		/*******************************************************************************/
		/* TEST ID: T016-06
		/* TEST DESCRIPTION: Test if long string parameter of same variable will return true
		/* Expected result : true
		/*******************************************************************************/

		TEST_METHOD(TesteqPt6)
		{

			struct Point test1 = { '1a','2b' };
			struct Point test2 = { '1a','2b' };
			bool result = eqPt(test1, test2);

			Assert::IsTrue(result);
		}

	};
}