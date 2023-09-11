#include "pch.h"
#include <iostream>
#include "CppUnitTest.h"
#include "header_r.h"

///*******************UNIT TEST FOR NEW FUNCTIONS*********************
//* Tester Name : Hyunjin Shin
//* Test Date : 2023/03/27
//* Description : WHITE BOX Unit Test for New Functions in structure.h
//********************************************************************/
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{

	/******************** Whitebox testing ********************************
	* Function
	* int getSuitableTruck(struct Truck trks[], struct Shipment* package);
	***********************************************************************/

	TEST_CLASS(UnitTest6)
	{
		/*****************************************************************/
		/*TEST ID : WT001-01
		* TEST DATA: with invalid size of truck array and valid Shipment structure
		* Shipment.destination : 6, 23
		* Expected result: program breaks
		*****************************************************************/
	public:
		TEST_METHOD(TestMethod1)
		{
			struct Truck trucks[1] = {
				BLUE,
				0.0,
				0.0,
				0,
				getBlueRoute()
			};
			struct Shipment shipment = { 0, 10.0, 10.0, {6, 23}, {0} };
			int truckId = 2;
			int result = getSuitableTruck(trucks, &shipment);
			int good = (result == 1);
			Assert::IsTrue(good);
		};
	};

	
	/******************** Whitebox testing ********************************
	* Function
	* void loadShipmentToTruck(struct Truck trks[], struct Shipment* package, int truckId);
	***********************************************************************/

	TEST_CLASS(UnitTest7)
	{
		/*****************************************************************/
		/*TEST ID : WT002-01
		* TEST DATA: with valid truck array and valid Shipment structure
		* Shipment.destination : 6, 23
		* Expected result: program breaks
		*****************************************************************/
	public:
		TEST_METHOD(TestMethod1)
		{
			TEST_METHOD(TestMethod1) {
				struct Truck trucks[3] =
				{
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
		};
	};


		/******************** Whitebox testing ********************************
		* Function
		* void showMapAndRoute(struct Map* basemap, struct Shipment* package, int truckId);
		***********************************************************************/
	TEST_CLASS(UnitTest8)
	{
		/*******************************************************************************/
		/*TEST ID : WT003-01
		* TEST DATA: Testing for when package.truckId is different from truckId
		* Expected result : the route showed on the screen will be according to truckId, not package.truckId
		********************************************************************************/
		TEST_METHOD(TestMethod1)
		{
			struct Map basemap = populateMap();
			struct Shipment shipment =
			{
				1, //index of truck; ex) 0,1,2
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


		/******************** Whitebox testing ********************************
		* Function
		* void displayShipmentInfo(struct Shipment* package);
		***********************************************************************/

	TEST_CLASS(UnitTest4)
	{
		/*******************************************************************************/
		/*TEST ID : WT004-01
		* TEST DATA: Shipment with invalid member deliveryTruck
		* Expected result : the program will not display "Shipment on BLUELINE" (or GREENLINE or YELLOWLINE")
		********************************************************************************/
		TEST_METHOD(TestMethod1) {

			struct Shipment shipment =
			{
				4, //index of truck; ex) 0,1,2
				10.0, // weight
				10.0, // size
				{6,23}, // destination row, column
				{0} // deversion routes
			};
			displayShipmentInfo(&shipment);
			Logger::WriteMessage("Not tested");
		};
	};
		
		
		
		/******************** Whitebox testing ********************************
		* Function
		* struct Shipment readShipInfo(struct Truck trks[], struct Map* map, struct Depot* storage);
		***********************************************************************/

	TEST_CLASS(UnitTest5)
	{
		/*******************************************************************************/
		/*TEST ID : WT005-01
		* TEST DATA: valid truck array, valid map, valid storage, invalid user input
		* Expected result :the program will keep requiring until all the scanf will get data for the values
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
			// USER Enter : 12345
			/*************DATA ENTRY(USER INPUT)*************/
			Logger::WriteMessage("Not Tested Here");
		};

		/*******************************************************************************/
		/*TEST ID : WT005-02
		* TEST DATA: valid truck array, valid map, valid storage, invalid user input;
		* Expected result : the program will keep requiring until all the scanf will get data for the values
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

			struct Map map = populateMap();
			struct Depot storage[10] = { 0, {0} };
			struct Shipment result = readShipInfo(trucks, &map, storage);
			struct Shipment test = { 0 };
			test.weight = 10;
			test.size = 10;
			test.destination.row = 9;
			test.destination.row = 22;

			/*************DATA ENTRY(USER INPUT)*************/
			// USER Enter : '\n'
			/*************DATA ENTRY(USER INPUT)*************/
			
			Logger::WriteMessage("Not Tested Here");
		};
