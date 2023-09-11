#include "pch.h"
#include <iostream>
#include "CppUnitTest.h"
#include "header_r.h"

/*******************UNIT TEST FOR NEW FUNCTIONS*********************
* Tester Name : Hyunjin Shin
* Test Date : 2023/03/21
* Description : Black Box Unit Test for New Functions in structure.h
********************************************************************/
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
		/******************** Blackbox testing ********************************
		* Function
		*int getSuitableTruck(struct Truck trks[], struct Shipment* package);
		***********************************************************************/
	public:

		/*TEST ID : T001-01
		* TEST DATA: with valid truck array and valid Shipment structure
		*			 Shipment.destination : 6, 23
		* Expected return value : 1
		*****************************************************************/
		TEST_METHOD(TestMethod1)
		{
			struct Truck trucks[3] = {
			   { BLUE, // truckColor
			   0.0, // weightAdded
			   0.0, // sizeAdded
			   0, // numberOfShipments
			   getBlueRoute() },// blueRoute

			   { GREEN, // truckColor
			   0.0, // weightAdded
			   0.0, // sizeAdded
			   0, // numberOfShipments
			   getGreenRoute() }, // greenRoute

			   { YELLOW, // truckColor
			   0.0, // weightAdded
			   0.0, // sizeAdded
			   0, // numberOfShipments
			   getYellowRoute() }// yellowRoute
			};

			struct Shipment shipment =
			{
				0, //index of truck; ex) 0,1,2
				10.0, // weight
				10.0, // size
				{5,23}, // destination row, column
				{0} // deversion routes
			};

			int result = getSuitableTruck(trucks, &shipment);
			int good = (result == 1);
			Assert::IsTrue(good);
		}


		/*******************************************************************************/
		/*TEST ID : T001-02
		* TEST DATA: with valid truck array and valid Shipment structure
		*			 Shipment.Destination : 11, 12
		* Expected return value : 0
		*****/
		TEST_METHOD(TestMethod2)
		{
			struct Truck trucks[3] = {
			   { BLUE, // truckColor
			   0.0, // weightAdded
			   0.0, // sizeAdded
			   0, // numberOfShipments
			   getBlueRoute() },// blueRoute

			   { GREEN, // truckColor
			   0.0, // weightAdded
			   0.0, // sizeAdded
			   0, // numberOfShipments
			   getGreenRoute() }, // greenRoute

			   { YELLOW, // truckColor
			   0.0, // weightAdded
			   0.0, // sizeAdded
			   0, // numberOfShipments
			   getYellowRoute() }// yellowRoute
			};

			struct Shipment shipment =
			{
				0, //index of truck; ex) 0,1,2
				10.0, // weight
				10.0, // size
				{11,12}, // destination row, column
				{0} // deversion routes
			};

			int result = getSuitableTruck(trucks, &shipment);
			int good = (result == 0);
			Assert::IsTrue(good);
		}



		/*******************************************************************************/
		/*TEST ID : T001-03
		* TEST DATA: with valid truck array and valid Shipment structure
		*			 Shipment.Destination : 21, 3
		* Expected return value : 2
		********************************************************************************/
		TEST_METHOD(TestMethod3)
		{
			struct Truck trucks[3] = {
			   { BLUE, // truckColor
			   0.0, // weightAdded
			   0.0, // sizeAdded
			   0, // numberOfShipments
			   getBlueRoute() },// blueRoute

			   { GREEN, // truckColor
			   0.0, // weightAdded
			   0.0, // sizeAdded
			   0, // numberOfShipments
			   getGreenRoute() }, // greenRoute

			   { YELLOW, // truckColor
			   0.0, // weightAdded
			   0.0, // sizeAdded
			   0, // numberOfShipments
			   getYellowRoute() }// yellowRoute
			};

			struct Shipment shipment =
			{
				0, //index of truck; ex) 0,1,2
				10.0, // weight
				10.0, // size
				{21,3}, // destination row, column
				{0} // deversion routes
			};

			int result = getSuitableTruck(trucks, &shipment);
			int good = (result == 2);
			Assert::IsTrue(good);
		}
		/********************************************************************************/


		/*******************************************************************************/
		/*TEST ID : T001-04
		* TEST DATA: With valid truck array and invalid Shipment destination
		*			 Shipment.Destination : 100, 100
		* Expected return value : 0 or 1 or 2
		********************************************************************************/
		TEST_METHOD(TestMethod4)
		{
			struct Truck trucks[3] = {
			   { BLUE, // truckColor
			   0.0, // weightAdded
			   0.0, // sizeAdded
			   0, // numberOfShipments
			   getBlueRoute() },// blueRoute

			   { GREEN, // truckColor
			   0.0, // weightAdded
			   0.0, // sizeAdded
			   0, // numberOfShipments
			   getGreenRoute() }, // greenRoute

			   { YELLOW, // truckColor
			   0.0, // weightAdded
			   0.0, // sizeAdded
			   0, // numberOfShipments
			   getYellowRoute() }// yellowRoute
			};

			struct Shipment shipment =
			{
				0, //index of truck; ex) 0,1,2
				10.0, // weight
				10.0, // size
				{100,100}, // destination row, column
				{0} // deversion routes
			};

			int result = getSuitableTruck(trucks, &shipment);
			int good = (result <= 2 && result >= 0);
			Assert::IsTrue(good);
		}
		/********************************************************************************/


		/*******************************************************************************/
		/*TEST ID : T001-05
		* TEST DATA: truck array with invalid route and Shipment with valid values
		*			 Shipment.Destination : 6, 23
		* Expected result : 0 or 1 or 2
		********************************************************************************/
		TEST_METHOD(TestMethod5)
		{
			struct Truck trucks[3] = {
			   { BLUE, // truckColor
			   0.0, // weightAdded
			   0.0, // sizeAdded
			   0, // numberOfShipments
			   {0} // blueRoute
				},

			   { GREEN, // truckColor
			   0.0, // weightAdded
			   0.0, // sizeAdded
			   0, // numberOfShipments
			   {0}// greenRoute
				},

			   { YELLOW, // truckColor
			   0.0, // weightAdded
			   0.0, // sizeAdded
			   0, // numberOfShipments
			   {0} // yellowRoute
				},
			};

			struct Shipment shipment =
			{
				0, //index of truck; ex) 0,1,2
				10.0, // weight
				10.0, // size
				{100,100}, // destination row, column
				{0} // deversion routes
			};

			int result = getSuitableTruck(trucks, &shipment);
			int good = (result <= 2 || result >= 0);
			Assert::IsTrue(good);
		}
		/********************************************************************************/


		/*******************************************************************************/
		/*TEST ID : T001-06
		* TEST DATA: With wrong truck color and invalid Shipment destination
		*			 Shipment.Destination : 11, 12
		* Expected return value : 10
		********************************************************************************/
		TEST_METHOD(TestMethod6)
		{
			struct Truck trucks[3] = {
			   {40, // truckColor
			   0.0, // weightAdded
			   0.0, // sizeAdded
			   0, // numberOfShipments
			   getBlueRoute() },// blueRoute

			   { GREEN, // truckColor
			   0.0, // weightAdded
			   0.0, // sizeAdded
			   0, // numberOfShipments
			   getGreenRoute() }, // greenRoute

			   { YELLOW, // truckColor
			   0.0, // weightAdded
			   0.0, // sizeAdded
			   0, // numberOfShipments
			   getYellowRoute() }// yellowRoute
			};

			struct Shipment shipment =
			{
				100, //index of truck; ex) 0,1,2
				10.0, // weight
				10.0, // size
				{11,12}, // destination row, column
				{0} // deversion routes
			};

			int result = getSuitableTruck(trucks, &shipment);
			int good = (result == 10);
			Assert::IsTrue(good);
		}
		/********************************************************************************/

		/*******************************************************************************/
		/*TEST ID : T001-07
		* TEST DATA: With empty truck routes and valid Shipment destination
		*			 Shipment.Destination : 6, 23
		* Expected return value : 0 or 1 or 2
		********************************************************************************/
		TEST_METHOD(TestMethod7)
		{
			struct Truck trucks[3] = { 0 };

			struct Shipment shipment =
			{
				100, //index of truck; ex) 0,1,2
				10.0, // weight
				10.0, // size
				{6,23}, // destination row, column
				{0} // deversion routes
			};

			int result = getSuitableTruck(trucks, &shipment);
			int good = (result <= 2 && result >= 0);
			Assert::IsTrue(good);
		}
		/********************************************************************************/
	};

	TEST_CLASS(UnitTest2)
	{
		/******************** Blackbox testing ********************************
		* Function
		* void loadShipmentToTruck(struct Truck trks[], struct Shipment* package, int truckId);
		/*******************************************************************************/
		/*TEST ID : T002-01
		* TEST DATA: with valid truck array and valid Shipment structure and valid truckId
		*			 truck id : 0
		* Expected result : shipment data will be correctly applied to truck array
		********************************************************************************/
		TEST_METHOD(TestMethod1) {
			struct Truck trucks[3] =
			{
			   { BLUE, // truckColor
			   0.0, // weightAdded
			   0.0, // sizeAdded
			   0, // numberOfShipments
			   getBlueRoute(), // blueRoute
				},

			   { GREEN, // truckColor
			   0.0, // weightAdded
			   0.0, // sizeAdded
			   0, // numberOfShipments
			   getGreenRoute(),// greenRoute
				},

			   { YELLOW, // truckColor
			   0.0, // weightAdded
			   0.0, // sizeAdded
			   0, // numberOfShipments
			   getYellowRoute() // yellowRoute
				},
			};

			struct Shipment shipment =
			{
				0, //index of truck; ex) 0,1,2
				10.0, // weight
				10.0, // size
				{5,23}, // destination row, column
				{0} // deversion routes
			};

			int truckId = 0;
			int good = 0;
			loadShipmentToTruck(trucks, &shipment, truckId);
			if ((trucks[truckId].weightAdded >= shipment.weight
				|| trucks[truckId].weightAdded <= shipment.weight)
				&& trucks[truckId].sizeAdded >= shipment.size
				&& trucks[truckId].sizeAdded <= shipment.size
				&& trucks[truckId].numOfshipment == 1) good = 1;
			Assert::IsTrue(good);
		};

		/*******************************************************************************/
		/*TEST ID : T002-02
		* TEST DATA: with valid truck array and valid Shipment structure and invalid truckId
		* truck id : 10
		* Expected result : the program will make a runtime error due to a wrong index value
		********************************************************************************/
		TEST_METHOD(TestMethod2) {
			struct Truck trucks[3] =
			{
			   { BLUE, // truckColor
			   0.0, // weightAdded
			   0.0, // sizeAdded
			   0, // numberOfShipments
			   getBlueRoute(), // blueRoute
				},

			   { GREEN, // truckColor
			   0.0, // weightAdded
			   0.0, // sizeAdded
			   0, // numberOfShipments
			   getGreenRoute()// greenRoute
				},

			   { YELLOW, // truckColor
			   0.0, // weightAdded
			   0.0, // sizeAdded
			   0, // numberOfShipments
			   {0} // yellowRoute
				},
			};

			struct Shipment shipment =
			{
				0, //index of truck; ex) 0,1,2
				10.0, // weight
				10.0, // size
				{5,23}, // destination row, column
				{0} // deversion routes
			};

			int truckId = 10;
			int good = 0;
		
				loadShipmentToTruck(trucks, &shipment, truckId);
				if ((trucks[truckId].weightAdded >= shipment.weight
					|| trucks[truckId].weightAdded <= shipment.weight)
					&& trucks[truckId].sizeAdded >= shipment.size
					&& trucks[truckId].sizeAdded <= shipment.size
					&& trucks[truckId].numOfshipment == 1)
					good = 1;
			
			Assert::IsTrue(good);
		};


		/*******************************************************************************/
		/*TEST ID : T002-03
		* TEST DATA: with invalid truck array size and empty Shipment structure and valid truckId
		* empty shipment
		* Expected result :shipment data will be correctly applied to truck array
		********************************************************************************/
		TEST_METHOD(TestMethod3) {
			struct Truck trucks[3] =
			{
			   { BLUE, // truckColor
			   0.0, // weightAdded
			   0.0, // sizeAdded
			   0, // numberOfShipments
			   getBlueRoute(), // blueRoute
				},

			   { GREEN, // truckColor
			   0.0, // weightAdded
			   0.0, // sizeAdded
			   0, // numberOfShipments
			   getGreenRoute(),// greenRoute
				},

			   { YELLOW, // truckColor
			   0.0, // weightAdded
			   0.0, // sizeAdded
			   0, // numberOfShipments
			   getYellowRoute(), // yellowRoute
				},
			};

			struct Shipment shipment = { 0 };

			int truckId = 0;
			int good = 0;
			loadShipmentToTruck(trucks, &shipment, truckId);
			if ((trucks[truckId].weightAdded >= shipment.weight
				|| trucks[truckId].weightAdded <= shipment.weight)
				&& trucks[truckId].sizeAdded >= shipment.size
				&& trucks[truckId].sizeAdded <= shipment.size
				&& trucks[truckId].numOfshipment == 1) good = 1;
			Assert::IsTrue(good);
		};

		/*******************************************************************************/
		/*TEST ID : T002-04
		* TEST DATA: truck array with full weight and valid Shipment structure and valid truckId
		* truck.addedWeight : 1000.0
		* Expected result : shipment data will be correctly applied to truck array
		********************************************************************************/
		TEST_METHOD(TestMethod4) {
			struct Truck trucks[3] =
			{
			   { BLUE, // truckColor
			   1000.0, // weightAdded
			   0.0, // sizeAdded
			   0, // numberOfShipments
			   getBlueRoute(), // blueRoute
				},

			   { GREEN, // truckColor
			   1000.0, // weightAdded
			   0.0, // sizeAdded
			   0, // numberOfShipments
			   getGreenRoute(),// greenRoute
				},

			   { YELLOW, // truckColor
			   1000.0, // weightAdded
			   0.0, // sizeAdded
			   0, // numberOfShipments
			    getYellowRoute(),// yellowRoute
				},
			};

			struct Shipment shipment =
			{
				0, //index of truck; ex) 0,1,2
				10.0, // weight
				10.0, // size
				{5,23}, // destination row, column
				{0} // deversion routes
			};

			int truckId = 0;
			int good = 0;
			loadShipmentToTruck(trucks, &shipment, truckId);
			if ((trucks[truckId].weightAdded - 1000.0 >= shipment.weight
				|| trucks[truckId].weightAdded - 1000.0 <= shipment.weight)
				&& trucks[truckId].sizeAdded >= shipment.size
				&& trucks[truckId].sizeAdded <= shipment.size
				&& trucks[truckId].numOfshipment == 1) good = 1;
			Assert::IsTrue(good);
		};

		/*******************************************************************************/
		/*TEST ID : T002-05
		* TEST DATA: truck array with full weight and valid Shipment structure and valid truckId
		* truck.addedSize : 1000.0
		* Expected result : shipment data will be correctly applied to truck array
		********************************************************************************/
		TEST_METHOD(TestMethod5) {
			struct Truck trucks[3] =
			{
			   { BLUE, // truckColor
			   0.0, // weightAdded
			   1000.0, // sizeAdded
			   0, // numberOfShipments
			   getBlueRoute(), // blueRoute
				},

			   { GREEN, // truckColor
			   0.0, // weightAdded
			   1000.0, // sizeAdded
			   0, // numberOfShipments
			   getGreenRoute(),// greenRoute
				},

			   { YELLOW, // truckColor
			   0.0, // weightAdded
			   1000.0, // sizeAdded
			   0, // numberOfShipments
			   getYellowRoute(), // yellowRoute
				},
			};

			struct Shipment shipment =
			{
				0, //index of truck; ex) 0,1,2
				10.0, // weight
				10.0, // size
				{5,23}, // destination row, column
				{0} // deversion routes
			};

			int truckId = 0;
			int good = 0;
			loadShipmentToTruck(trucks, &shipment, truckId);
			if ((trucks[truckId].weightAdded >= shipment.weight
				|| trucks[truckId].weightAdded <= shipment.weight)
				&& trucks[truckId].sizeAdded - 1000.0 >= shipment.size
				&& trucks[truckId].sizeAdded - 1000.0 <= shipment.size
				&& trucks[truckId].numOfshipment == 1) good = 1;
			Assert::IsTrue(good);
		};
	};


	TEST_CLASS(UnitTest3)
	{
		/******************** Blackbox testing ********************************
		* Function
		* void showMapAndRoute(struct Map* basemap, struct Shipment* package, int truckId);
		***********************************************************************/

		/*******************************************************************************/
		/*TEST ID : T003-01
		* TEST DATA: valid map and valid Shipment structure and valid truckId
		* Expected result : pass
		********************************************************************************/
		TEST_METHOD(TestMethod1) {

			struct Map basemap = populateMap();
			struct Shipment shipment =
			{
				0, //index of truck; ex) 0,1,2
				10.0, // weight
				10.0, // size
				{6,23}, // destination row, column
				{0} // deversion routes
			};

			int truckId = 0;
			int good = 0;
			showMapAndRoute(&basemap, &shipment, truckId);
			//Assert::IsTrue(good);
		};
	};

	TEST_CLASS(UnitTest4)
	{
		/******************** Blackbox testing ********************************
		* Function
		* void displayShipmentInfo(struct Shipment* package);
		***********************************************************************/

		/*******************************************************************************/
		/*TEST ID : T004-01
		* TEST DATA: valid input and valid truckId
		* Expected result : correct shipment route will be displayed
		********************************************************************************/
		TEST_METHOD(TestMethod1) {

			struct Shipment shipment =
			{
				0, //index of truck; ex) 0,1,2
				10.0, // weight
				10.0, // size
				{6,23}, // destination row, column
				{0} // deversion routes
			};
			displayShipmentInfo(&shipment);
			Logger::WriteMessage("Not tested");
		};


		/*******************************************************************************/
		/*TEST ID : T004-02
		* TEST DATA: Testing a Function with empty Shipment
		* Expected result : "no diversion " will be printed
		********************************************************************************/
		TEST_METHOD(TestMethod2) {

			struct Shipment shipment ={0};
			displayShipmentInfo(&shipment);
			Logger::WriteMessage("Not tested");
		};



		/*******************************************************************************/
		/*TEST ID : T004-03
		* TEST DATA: Testing a Function with Shipment with invalid destination
		* Expected result : it will still display some shipment routes but different from the correct routes
		********************************************************************************/
		TEST_METHOD(TestMethod3) {

			struct Shipment shipment =
			{
				0, //index of truck; ex) 0,1,2
				10.0, // weight
				10.0, // size
				{100,100}, // destination row, column
				{0} // deversion routes
			};
			displayShipmentInfo(&shipment);
			Logger::WriteMessage("Not tested");
		};


		/*******************************************************************************/
		/*TEST ID : T004-04
		* TEST DATA: Testing a Function with Shipment with invalid member deliveryTruc
		* truckDelivery : -1
		* Expected result : the program will break
		********************************************************************************/

		TEST_METHOD(TestMethod4) {
			struct Shipment shipment = {
				-1,
				10.0,
				10.0,
				{6, 23},
				//shortestPath(&basemap, route.points[closestIndex], package->destination)};
			};
			displayShipmentInfo(&shipment);
			Logger::WriteMessage("Not tested");
		};

		/*******************************************************************************/
		/*TEST ID : T004-05
		* TEST DATA: Testing a Function with valid Shipment with invalid diversion
		* truckId : 1
		* Expected result : the program will break
		********************************************************************************/
		TEST_METHOD(TestMethod5) {
			struct Shipment shipment =
			{
				1, //index of truck; ex) 0,1,2
				10.0, // weight
				10.0, // size
				{6,23}, // destination row, column
				{-1, -1, -1, -1, -1, -1, -1, -1, 1, -1 , -1} // deversion routes
			};
			displayShipmentInfo(&shipment);
			Logger::WriteMessage("Not tested");
		};


		/*******************************************************************************/
		/*TEST ID : T004-06
		* TEST DATA: Testing  NULL as argument
		* Expected result : the program will break
		********************************************************************************/
		TEST_METHOD(TestMethod6) {
			int good = 0;
			char e[9] = "C0000005";
			try {
				displayShipmentInfo(NULL);
			}
			catch (char* e) {
				std::cout << e << std::endl;
				
			}
			
		};
		
	};


	TEST_CLASS(UnitTest5)
	{
		/******************** Blackbox testing ********************************
		* Function
		* struct Shipment readShipInfo(struct Truck trks[], struct Map* map, struct Depot* storage);
		***********************************************************************/

		/*******************************************************************************/
		/*TEST ID : T005-01
		* TEST DATA: valid truck array, valid map, valid storage, valid user input;
		* Expected result : It will return correct shipment structure 
		********************************************************************************/
		TEST_METHOD(TestMethod1) {
			struct Truck trucks[3] =
			{
				{
					BLUE,
					0.0,
					0.0,
					0,
					getBlueRoute()
				},
				{
					GREEN,
					0.0,
					0.0,
					0,
					getGreenRoute()
				},
				{ YELLOW,
					0.0,
					0.0,
					0,
					getYellowRoute()
				}
			};
			
			int good = false;
			struct Map map = populateMap();
			struct Depot storage[10] = { 0, {0} };
			struct Shipment result = readShipInfo(trucks, &map, storage);
			struct Shipment test = { 0 };
			test.weight = 10;
			test.size = 10;
			test.destination.row = 9;
			test.destination.row = 22;

			/*************DATA ENTRY(USER INPUT)*************/
			// USER Enter : 10 10 6x
			/*************DATA ENTRY(USER INPUT)*************/

			if (test.weight == result.weight && test.size == result.size &&
				test.destination.row == result.destination.row && test.destination.col == result.destination.col)
				good = true;
			Assert::IsTrue(good);
		};

		/*******************************************************************************/
		/*TEST ID : T005-02
		* TEST DATA: valid truck array, empty map, valid storage, valid user input;
		* Expected result : It will return wrong shipment structure 
		********************************************************************************/
		TEST_METHOD(TestMethod2) {
			struct Truck trucks[3] =
			{
				{
					BLUE,
					0.0,
					0.0,
					0,
					getBlueRoute()
				},
				{
					GREEN,
					0.0,
					0.0,
					0,
					getGreenRoute()
				},
				{ YELLOW,
					0.0,
					0.0,
					0,
					getYellowRoute()
				}
			};

			struct Map map = {0};
			struct Depot storage[10] = { 0, {0} };
			struct Shipment result = readShipInfo(trucks, &map, storage);
			struct Shipment test = { 0 };
			test.weight = 10;
			test.size = 10;
			test.destination.row = 9;
			test.destination.row = 22;

			/*************DATA ENTRY(USER INPUT)*************/
			// USER Enter : 10 10 6x
			/*************DATA ENTRY(USER INPUT)*************/

			int good = false;
			if (test.weight == result.weight && test.size == result.size &&
				test.destination.row == result.destination.row && test.destination.col == result.destination.col)
				good = true;
			Assert::IsTrue(good);
		};

		/*******************************************************************************/
		/*TEST ID : T005-03
		* TEST DATA: valid truck array, a map full of buildings, valid storage, valid user input;
		* Expected result : It will return correct shipment structure 
		********************************************************************************/
		TEST_METHOD(TestMethod3) {
			struct Truck trucks[3] =
			{
				{
					BLUE,
					0.0,
					0.0,
					0,
					getBlueRoute()
				},
				{
					GREEN,
					0.0,
					0.0,
					0,
					getGreenRoute()
				},
				{ YELLOW,
					0.0,
					0.0,
					0,
					getYellowRoute()
				}
			};
			struct Map map = {
				//0    1  2  3  4  5  6  7  8  9  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4
				//A B  C  D  E  F  G  H  I  J  K  L  M  N  O  P  Q  R  S  T  U  V  W  X  Y
				{
				{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},    //0
				{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},    //1
				{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},    //2
				{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},    //3
				{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},    //4
				{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},    //5
				{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},    //6
				{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},    //7
				{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},    //8
				{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},    //9
				{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},    //10
				{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},    //11
				{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},    //12
				{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},    //13
				{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},    //14
				{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},    //15
				{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},    //16
				{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},    //17
				{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},    //18
				{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},    //19
				{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},    //20
				{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},    //21
				{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},    //22
				{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},    //23
				{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},       //24
				},
				MAP_ROWS, MAP_COLS
			};
			struct Depot storage[10] = { 0, {0} };
			struct Shipment result = readShipInfo(trucks, &map, storage);
			struct Shipment test = { 0 };
			test.weight = 10;
			test.size = 10;
			test.destination.row = 9;
			test.destination.row = 22;

			/*************DATA ENTRY(USER INPUT)*************/
			// USER Enter : 10 10 6x
			/*************DATA ENTRY(USER INPUT)*************/

			int good = false;
			if (test.weight == result.weight && test.size == result.size &&
				test.destination.row == result.destination.row && test.destination.col == result.destination.col)
				good = true;
			Assert::IsTrue(good);
		};


		/*******************************************************************************/
		/*TEST ID : T005-04
		* TEST DATA: truck array with already full weight, valid map, valid storage, valid user input;
		* Expected result : The program will end
		********************************************************************************/
		TEST_METHOD(TestMethod4) {
			struct Truck trucks[3] =
			{
				{
					BLUE,
					1000.0,
					0.0,
					0,
					getBlueRoute()
				},
				{
					GREEN,
					1000.0,
					0.0,
					0,
					getGreenRoute()
				},
				{ YELLOW,
					1000.0,
					0.0,
					0,
					getYellowRoute()
				}
			};

			struct Map map = populateMap();
			struct Depot storage[10] = { 0, {0} };
			struct Shipment result = readShipInfo(trucks, &map, storage);
			struct Shipment test = { 0 };
			test.weight = 10;
			test.size = 10;
			test.destination.row = 9;
			test.destination.row = 22;

			/*************DATA ENTRY(USER INPUT)*************/
			// USER Enter : 10 10 6x
			/*************DATA ENTRY(USER INPUT)*************/

			int good = false;
			if (test.weight == result.weight && test.size == result.size &&
				test.destination.row == result.destination.row && test.destination.col == result.destination.col)
				good = true;
			Assert::IsFalse(good);
		};

		/*******************************************************************************/
		/*TEST ID : T005-05
		* TEST DATA: truck array with already full weight and size, valid map, full storage, valid user input;
		* Expected result : The program will end
		********************************************************************************/
		TEST_METHOD(TestMethod5) {
			struct Truck trucks[3] =
			{
				{
					BLUE,
					1000.0,
					1000.0,
					0,
					getBlueRoute()
				},
				{
					GREEN,
					1000.0,
					1000.0,
					0,
					getGreenRoute()
				},
				{ YELLOW,
					1000.0,
					1000.0,
					0,
					getYellowRoute()
				}
			};

			struct Map map = populateMap();
			struct Depot storage[10] = { 10, {0} };
			struct Shipment result = readShipInfo(trucks, &map, storage);
			struct Shipment test = { 0 };
			test.weight = 10;
			test.size = 10;
			test.destination.row = 9;
			test.destination.row = 22;

			/*************DATA ENTRY(USER INPUT)*************/
			// USER Enter : 10 10 6x
			/*************DATA ENTRY(USER INPUT)*************/

			int good = false;
			if (test.weight == result.weight && test.size == result.size &&
				test.destination.row == result.destination.row && test.destination.col == result.destination.col)
				good = true;
			Assert::IsFalse(good);
		};


		/*******************************************************************************/
		/*TEST ID : T005-6
		* TEST DATA: valid truck array, valid map, valid storage, invalid weight data entry;
		* Expected result : The program require correct input
		********************************************************************************/
		TEST_METHOD(TestMethod6) {
			struct Truck trucks[3] = {
				{
					BLUE,
					0.0,
					0.0,
					0,
					getBlueRoute()
				},
				{
					GREEN,
					0.0,
					0.0,
					0,
					getGreenRoute()
				},
				{ YELLOW,
					0.0,
					0.0,
					0,
					getYellowRoute()
				}
			};
			struct Map map = populateMap();
			struct Depot storage[10] = { 0, {0} };
			struct Shipment result = readShipInfo(trucks, &map, storage);
			struct Shipment test = { 0 };
			test.weight = 1001;
			test.size = 10;
			test.destination.row = 9;
			test.destination.row = 22;

			/*************DATA ENTRY(USER INPUT)*************/
			// USER Enter : 1001 10 6x
			/*************DATA ENTRY(USER INPUT)*************/

			int good = false;
			if (test.weight == result.weight && test.size == result.size &&
				test.destination.row == result.destination.row && test.destination.col == result.destination.col)
				good = true;
			Assert::IsTrue(good);
		};


		/*******************************************************************************/
		/*TEST ID : T005-7
		* TEST DATA: valid truck array, valid map, valid storage, invalid size data entry;
		* Expected result : The program require correct input
		********************************************************************************/
		TEST_METHOD(TestMethod7) {
			struct Truck trucks[3] = {
				{
					BLUE,
					0.0,
					0.0,
					0,
					getBlueRoute()
				},
				{
					GREEN,
					0.0,
					0.0,
					0,
					getGreenRoute()
				},
				{ YELLOW,
					0.0,
					0.0,
					0,
					getYellowRoute()
				}
			};
			struct Map map = populateMap();
			struct Depot storage[10] = { 0, {0} };
			struct Shipment result = readShipInfo(trucks, &map, storage);

			struct Shipment test = { 0 };
			test.weight = 10;
			test.size = 1001;
			test.destination.row = 9;
			test.destination.row = 22;

			/*************DATA ENTRY(USER INPUT)*************/
			// USER Enter : 10 1001 6x
			/*************DATA ENTRY(USER INPUT)*************/

			int good = false;
			if (test.weight == result.weight && test.size == result.size &&
				test.destination.row == result.destination.row && test.destination.col == result.destination.col)
				good = true;
		
			Assert::IsFalse(good);
		};

		/*******************************************************************************/
		/*TEST ID : T005-8
		* TEST DATA: valid truck array, valid map, valid storage, invalid destination data entry;
		* Expected result : The program require correct input
		********************************************************************************/
		TEST_METHOD(TestMethod8) {
			struct Truck trucks[3] = {
				{
					BLUE,
					0.0,
					0.0,
					0,
					getBlueRoute()
				},
				{
					GREEN,
					0.0,
					0.0,
					0,
					getGreenRoute()
				},
				{ YELLOW,
					0.0,
					0.0,
					0,
					getYellowRoute()
				}
			};
			int good = false;
			struct Map map = populateMap();
			struct Depot storage[10] = { 0, {0} };
			struct Shipment result = { 0 };


			try {
				 result = readShipInfo(trucks, &map, storage);
			} 
			catch (const std::exception& ex)
			{
				good = true;
			}
			
			struct Shipment test = { 0 };
			test.weight = 10;
			test.size = 10;
			test.destination.row = 100;
			test.destination.row = 24;

			/*************DATA ENTRY(USER INPUT)*************/
			// USER Enter : 10 10 100z
			/*************DATA ENTRY(USER INPUT)*************/

			
			if (test.weight == result.weight && test.size == result.size &&
				test.destination.row == result.destination.row && test.destination.col == result.destination.col)
				good = true;

			Assert::IsFalse(good);
			
		};

		/*******************************************************************************/
		/*TEST ID : T005-9
		* TEST DATA: valid truck array, valid map, valid storage, edge weight and edge size data;
		* Expected result : It will return correct shipment structure
		********************************************************************************/
		TEST_METHOD(TestMethod9) {
			struct Truck trucks[3] = {
				{
					BLUE,
					0.0,
					0.0,
					0,
					getBlueRoute()
				},
				{
					GREEN,
					0.0,
					0.0,
					0,
					getGreenRoute()
				},
				{ YELLOW,
					0.0,
					0.0,
					0,
					getYellowRoute()
				}
			};
			struct Map map = populateMap();
			struct Depot storage[10] = { 0, {0} };
			struct Shipment result = readShipInfo(trucks, &map, storage);
			struct Shipment test = {0};
			test.weight = 10;
			test.size = 10;
			test.destination.row = 100;
			test.destination.row = 24;

			/*************DATA ENTRY(USER INPUT)*************/
			// USER Enter : 1000 1000 6x
			/*************DATA ENTRY(USER INPUT)*************/

			//stringstream() >> myint;
			int good = false;
			if (test.weight == result.weight && test.size == result.size &&
				test.destination.row == result.destination.row && test.destination.col == result.destination.col)
				good = true;

			Assert::IsFalse(good);
		};
	};
}
