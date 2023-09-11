#include "pch.h"
#include <iostream>
#include "CppUnitTest.h"
#include "header_r.h"

/*******************Integration Test FOR NEW FUNCTIONS*********************
* Tester Name : Hyunjin Shin
* Test Date : 2023/04/01
* Description : Integration Test for New Functions in structure.h
				plus some of given functions used to call the new functions
********************************************************************/
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(IntegrationTest1)
	{
		TEST_METHOD(TestMethod1) {
			/******************** Integration testing ********************************
			* TEST ID : IT001-01
			* Functions
			* struct Route getBlueRoute();
			* struct getGreenRoute();
			* struct getYellowRoute();
			* struct Map populateMap();
			* struct Shipment readShipInfo(struct Truck trks[], struct Map* map, struct Depot* storage);
			* USER Enter : 10 10 5x
			* purpose: to test if the functions can generate truck routes and
			*		   generates a proper map and get user input
			*		   most importantly if it returns a valid shipment;
			***********************************************************************/
			struct Truck trucks[3] = {
			{ BLUE, // truckColor
			0.0, // weightAdded
			0.0, // sizeAdded
			0, // numberOfShipments
			getBlueRoute()},// blueRoute

			{ GREEN, // truckColor
			0.0, // weightAdded
			0.0, // sizeAdded
			0, // numberOfShipments
			getGreenRoute()}, // greenRoute

			{ YELLOW, // truckColor
			0.0, // weightAdded
			0.0, // sizeAdded
			0, // numberOfShipments
			getYellowRoute()}// yellowRoute
			};

			int good = 1;
			struct Map basemap = populateMap();
			struct Depot storage = {
				0,
				{0}
			};
			struct Shipment pacakge = readShipInfo(trucks, &basemap, &storage);

			/*************DATA ENTRY(USER INPUT)*************/
			// USER Enter : 10 10 5x
			/*************DATA ENTRY(USER INPUT)*************/
			Assert::IsTrue(good);
		}


		TEST_METHOD(TestMethod2) {
			/******************** Integration testing ********************************
			* TEST ID : IT001-02
			* Functions
			* struct Route getBlueRoute();
			* struct getGreenRoute();
			* struct getYellowRoute();
			* struct Map populateMap();
			* struct Shipment readShipInfo(struct Truck trks[], struct Map* map, struct Depot* storage);
			* USER Enter : 0 0 5x
			* purpose: to test if the functions can generate truck routes and
			*		   generates a proper map and get user input and
					   most importantly if it returns a valid shipment;
			***********************************************************************/
			struct Truck trucks[3] = {
			{ BLUE, // truckColor
			0.0, // weightAdded
			0.0, // sizeAdded
			0, // numberOfShipments
			getBlueRoute()},// blueRoute

			{ GREEN, // truckColor
			0.0, // weightAdded
			0.0, // sizeAdded
			0, // numberOfShipments
			getGreenRoute()}, // greenRoute

			{ YELLOW, // truckColor
			0.0, // weightAdded
			0.0, // sizeAdded
			0, // numberOfShipments
			getYellowRoute()}// yellowRoute
			};

			int good = 1;
			struct Map basemap = populateMap();
			struct Depot storage = {
				0,
				{0}
			};
			struct Shipment pacakge = readShipInfo(trucks, &basemap, &storage);
			/*************DATA ENTRY(USER INPUT)*************/
			// USER Enter : 0 0 5x
			/*************DATA ENTRY(USER INPUT)*************/
			Assert::IsTrue(good);
		}

		TEST_METHOD(TestMethod3) {
			/******************** Integration testing ********************************
			* TEST ID : IT001-03
			* Functions
			* struct Route getBlueRoute();
			* struct getGreenRoute();
			* struct getYellowRoute();
			* struct Map populateMap();
			* struct Shipment readShipInfo(struct Truck trks[], struct Map* map, struct Depot* storage);
			* USER Enter : -1 -1 5x
			* purpose: to test if the functions can generate truck routes and
			*		   generates a proper map and get user input and
					   most importantly if it returns a valid shipment;
			***********************************************************************/
			struct Truck trucks[3] = {
			{ BLUE, // truckColor
			0.0, // weightAdded
			0.0, // sizeAdded
			0, // numberOfShipments
			getBlueRoute()},// blueRoute

			{ GREEN, // truckColor
			0.0, // weightAdded
			0.0, // sizeAdded
			0, // numberOfShipments
			getGreenRoute()}, // greenRoute

			{ YELLOW, // truckColor
			0.0, // weightAdded
			0.0, // sizeAdded
			0, // numberOfShipments
			getYellowRoute()}// yellowRoute
			};

			int good = 1;
			struct Map basemap = populateMap();
			struct Depot storage = {
				0,
				{0}
			};
			struct Shipment pacakge = readShipInfo(trucks, &basemap, &storage);
			/*************DATA ENTRY(USER INPUT)*************/
			// USER Enter : 0 0 5x
			/*************DATA ENTRY(USER INPUT)*************/
			Assert::IsTrue(good);
		}

		TEST_METHOD(TestMethod4) {
			/******************** Integration testing ********************************
			* TEST ID : IT001-04
			* Functions
			* struct Route getBlueRoute();
			* struct getGreenRoute();
			* struct getYellowRoute();
			* struct Map populateMap();
			* struct Shipment readShipInfo(struct Truck trks[], struct Map* map, struct Depot* storage);
			* USER Enter : -1 -1 100z
			* purpose: to test if the functions can generate truck routes and
			*		   generates a proper map and get user input and
					   most importantly if it returns a valid shipment;
			***********************************************************************/
			struct Truck trucks[3] = {
			{ BLUE, // truckColor
			0.0, // weightAdded
			0.0, // sizeAdded
			0, // numberOfShipments
			getBlueRoute()},// blueRoute

			{ GREEN, // truckColor
			0.0, // weightAdded
			0.0, // sizeAdded
			0, // numberOfShipments
			getGreenRoute()}, // greenRoute

			{ YELLOW, // truckColor
			0.0, // weightAdded
			0.0, // sizeAdded
			0, // numberOfShipments
			getYellowRoute()}// yellowRoute
			};

			int good = 1;
			struct Map basemap = populateMap();
			struct Depot storage = {
				0,
				{0}
			};
			struct Shipment pacakge = readShipInfo(trucks, &basemap, &storage);
			/*************DATA ENTRY(USER INPUT)*************/
			// USER Enter : 0 0 5x
			/*************DATA ENTRY(USER INPUT)*************/
			Assert::IsTrue(good);
		}

		TEST_METHOD(TestMethod5) {
			/******************** Integration testing ********************************
			* TEST ID : IT001-05
			* Functions
			* struct Route getBlueRoute();
			* struct getGreenRoute();
			* struct getYellowRoute();
			* struct Map populateMap();
			* struct Shipment readShipInfo(struct Truck trks[], struct Map* map, struct Depot* storage);
			* USER Enter : -1 -1 100z
			* purpose: to test if the functions can display proper truck routes and shipment diversions on the map
			***********************************************************************/
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

			int good = 1;
			struct Map basemap = populateMap();
			struct Depot storage = {
				0,
				{0}
			};
			struct Shipment pacakge = readShipInfo(trucks, &basemap, &storage);

			/*************DATA ENTRY(USER INPUT)*************/
			// USER Enter : 0 0 5x
			/*************DATA ENTRY(USER INPUT)*************/
			Assert::IsTrue(good);
		}
	};

	TEST_CLASS(IntegrationTest2)
	{
		TEST_METHOD(TestMethod1)
		{
		/******************** Integration testing ********************************
		* TEST ID : IT002-01
		* Functions
		* struct Shipment readShipInfo(struct Truck trks[], struct Map* map, struct Depot* storage);
		* int getSuitableTruck(struct Truck trks[], struct Shipment* package)
		* void loadShipmentToTruck(struct Truck trks[], struct Shipment* package, int truckId)
		* void showMapAndRoute(struct Map* basemap, struct Shipment* package, int truckId)
		* USER Enter : 10 10 5x
		* purpose: to test if the functions can display proper truck routes and shipment diversions on the map
		***********************************************************************/
			struct Truck trucks[3] = {
			{ BLUE, // truckColor
			0.0, // weightAdded
			0.0, // sizeAdded
			0, // numberOfShipments
			getBlueRoute()},// blueRoute

			{ GREEN, // truckColor
			0.0, // weightAdded
			0.0, // sizeAdded
			0, // numberOfShipments
			getGreenRoute()}, // greenRoute

			{ YELLOW, // truckColor
			0.0, // weightAdded
			0.0, // sizeAdded
			0, // numberOfShipments
			getYellowRoute()}// yellowRoute
			};

			struct Depot storage = {
				0,
				{0}
			};

			struct Map baseMap = populateMap();
			struct Shipment package = readShipInfo(trucks, &baseMap, &storage);
			if (package.deliveryTruck != -1) {
				int truckId = getSuitableTruck(trucks, &package);
				loadShipmentToTruck(trucks, &package, truckId);
				showMapAndRoute(&baseMap, &package, truckId);
			}
			/*************DATA ENTRY(USER INPUT)*************/
			// USER Enter : 10 10 5x
			/*************DATA ENTRY(USER INPUT)*************/
		}



			
		TEST_METHOD(TestMethod2)
		{
			/******************** Integration testing ********************************
			* TEST ID : IT002-02
			* Functions
			* struct Shipment readShipInfo(struct Truck trks[], struct Map* map, struct Depot* storage);
			* int getSuitableTruck(struct Truck trks[], struct Shipment* package)
			* void loadShipmentToTruck(struct Truck trks[], struct Shipment* package, int truckId)
			* void showMapAndRoute(struct Map* basemap, struct Shipment* package, int truckId)
			* USER Enter : 0 0 x
			* purpose: to test if the functions can display proper truck routes and shipment diversions on the map
			***********************************************************************/
			struct Truck trucks[3] = {
			{ BLUE, // truckColor
			0.0, // weightAdded
			0.0, // sizeAdded
			0, // numberOfShipments
			getBlueRoute()},// blueRoute

			{ GREEN, // truckColor
			0.0, // weightAdded
			0.0, // sizeAdded
			0, // numberOfShipments
			getGreenRoute()}, // greenRoute

			{ YELLOW, // truckColor
			0.0, // weightAdded
			0.0, // sizeAdded
			0, // numberOfShipments
			getYellowRoute()}// yellowRoute
			};

			struct Depot storage = {
				0,
				{0}
			};

			struct Map baseMap = populateMap();
			struct Shipment package = readShipInfo(trucks, &baseMap, &storage);
			if (package.deliveryTruck != -1) {
				int truckId = getSuitableTruck(trucks, &package);
				loadShipmentToTruck(trucks, &package, truckId);
				showMapAndRoute(&baseMap, &package, truckId);
			}


			/*************DATA ENTRY(USER INPUT)*************/
			// USER Enter : 0 0 5x
			/*************DATA ENTRY(USER INPUT)*************/
		}



		TEST_METHOD(TestMethod3)
		{
			/******************** Integration testing ********************************
			* TEST ID : IT002-03
			* Function
			* struct Shipment readShipInfo(struct Truck trks[], struct Map* map, struct Depot* storage);
			* int getSuitableTruck(struct Truck trks[], struct Shipment* package)
			* void loadShipmentToTruck(struct Truck trks[], struct Shipment* package, int truckId)
			* void showMapAndRoute(struct Map* basemap, struct Shipment* package, int truckId)
			* USER Enter : 10 10 2b
			* purpose: to test if the functions can display proper truck routes and shipment diversions on the map
			***********************************************************************/

			struct Truck trucks[3] = {
			{ BLUE, // truckColor
			0.0, // weightAdded
			0.0, // sizeAdded
			0, // numberOfShipments
			getBlueRoute()},// blueRoute

			{ GREEN, // truckColor
			0.0, // weightAdded
			0.0, // sizeAdded
			0, // numberOfShipments
			getGreenRoute()}, // greenRoute

			{ YELLOW, // truckColor
			0.0, // weightAdded
			0.0, // sizeAdded
			0, // numberOfShipments
			getYellowRoute()}// yellowRoute
			};

			struct Depot storage = {
				0,
				{0}
			};

			struct Map baseMap = populateMap();
			struct Shipment package = readShipInfo(trucks, &baseMap, &storage);
			if (package.deliveryTruck != -1) {
				int truckId = getSuitableTruck(trucks, &package);
				loadShipmentToTruck(trucks, &package, truckId);
				showMapAndRoute(&baseMap, &package, truckId);
			}

			/*************DATA ENTRY(USER INPUT)*************/
			// USER Enter : 10 10 2b
			/*************DATA ENTRY(USER INPUT)*************/
		}




		TEST_METHOD(TestMethod4)
		{
			/******************** Integration testing ********************************
			* TEST ID : IT002-04
			* Functions
			* struct Shipment readShipInfo(struct Truck trks[], struct Map* map, struct Depot* storage);
			* int getSuitableTruck(struct Truck trks[], struct Shipment* package)
			* void loadShipmentToTruck(struct Truck trks[], struct Shipment* package, int truckId)
			* void showMapAndRoute(struct Map* basemap, struct Shipment* package, int truckId)
			* USER Enter : 10 10 5x
			* purpose: to test if the functions can display proper truck routes and shipment diversions on the map
			***********************************************************************/
			struct Truck trucks[3] = {
			{ BLUE, // truckColor
			1000.0, // weightAdded
			1000.0, // sizeAdded
			0, // numberOfShipments
			getBlueRoute()},// blueRoute

			{ GREEN, // truckColor
			1000.0, // weightAdded
			1000.0, // sizeAdded
			0, // numberOfShipments
			getGreenRoute()}, // greenRoute

			{ YELLOW, // truckColor
			1000.0, // weightAdded
			1000.0, // sizeAdded
			0, // numberOfShipments
			getYellowRoute()}// yellowRoute
			};

			struct Depot storage = {
				0,
				{0}
			};

			struct Map baseMap = populateMap();
			struct Shipment package = readShipInfo(trucks, &baseMap, &storage);
			if (package.deliveryTruck != -1) {
				int truckId = getSuitableTruck(trucks, &package);
				loadShipmentToTruck(trucks, &package, truckId);
				showMapAndRoute(&baseMap, &package, truckId);
			}
			/*************DATA ENTRY(USER INPUT)*************/
			// USER Enter : 10 10 5x
			/*************DATA ENTRY(USER INPUT)*************/
		}
	};

	TEST_CLASS(IntegrationTest3)
	{

		TEST_METHOD(TestMethod1) {
			/******************** Integration testing ********************************
			* TEST ID : IT003-01
			* Functions
			* int getSuitableTruck(struct Truck trks[], struct Shipment* package)
			* void loadShipmentToTruck(struct Truck trks[], struct Shipment* package, int truckId)
			* void showMapAndRoute(struct Map* basemap, struct Shipment* package, int truckId)
			* void displayShipmentInfo(struct Shipment* package)
			* purpose: to test if the functions can display proper truck routes and shipment diversions on the map,
						and to test if the shipment diversion texts are printed on the screen properly
			***********************************************************************/
			struct Truck trucks[3] = {
				{ BLUE, // truckColor
				0.0, // weightAdded
				0.0, // sizeAdded
				0, // numberOfShipments
				getBlueRoute()},// blueRoute

				{ GREEN, // truckColor
				0.0, // weightAdded
				0.0, // sizeAdded
				0, // numberOfShipments
				getGreenRoute()}, // greenRoute

				{ YELLOW, // truckColor
				0.0, // weightAdded
				0.0, // sizeAdded
				0, // numberOfShipments
				getYellowRoute()}// yellowRoute
			};

			struct Map baseMap = populateMap();
			struct Shipment package =
			{
				0, //index of truck; ex) 0,1,2
				10.0, // valid weight
				10.0, // valid size
				{5,7}, // valid destination row, column
				{
					{{5,7}},
					1,
					BLUE
				}
			};

			if (package.deliveryTruck != -1) {
				int truckId = getSuitableTruck(trucks, &package);
				loadShipmentToTruck(trucks, &package, truckId);
				showMapAndRoute(&baseMap, &package, truckId);
				displayShipmentInfo(&package);
			}

			int good = 1;
			Assert::IsTrue(good);
		};



		TEST_METHOD(TestMethod2) {
			/******************** Integration testing ********************************
			* TEST ID : IT003-02
			* Functions
			* int getSuitableTruck(struct Truck trks[], struct Shipment* package)
			* void loadShipmentToTruck(struct Truck trks[], struct Shipment* package, int truckId)
			* void showMapAndRoute(struct Map* basemap, struct Shipment* package, int truckId)
			* void displayShipmentInfo(struct Shipment* package)
			* purpose: to test if the functions can display proper truck routes and shipment diversions on the map,
						and to test if the shipment diversion texts are printed on the screen properly
			***********************************************************************/
			struct Truck trucks[3] = {
				{ BLUE, // truckColor
				0.0, // weightAdded
				0.0, // sizeAdded
				0, // numberOfShipments
				getBlueRoute()},// blueRoute

				{ GREEN, // truckColor
				0.0, // weightAdded
				0.0, // sizeAdded
				0, // numberOfShipments
				getGreenRoute()}, // greenRoute

				{ YELLOW, // truckColor
				0.0, // weightAdded
				0.0, // sizeAdded
				0, // numberOfShipments
				getYellowRoute()}// yellowRoute
			};

			struct Map baseMap = populateMap();
			struct Shipment package =
			{
				0, //index of truck; ex) 0,1,2
				10.0, // valid weight
				10.0, // valid size
				{21,23}, // valid destination row, column
				{
					{{21, 23}},
					1,
					YELLOW
				}
			};

			if (package.deliveryTruck != -1) {
				int truckId = getSuitableTruck(trucks, &package);
				loadShipmentToTruck(trucks, &package, truckId);
				showMapAndRoute(&baseMap, &package, truckId);
				displayShipmentInfo(&package);
			}

			int good = 1;
			Assert::IsTrue(good);
		};


		TEST_METHOD(TestMethod3) {
			/******************** Integration testing ********************************
			* TEST ID : IT003-03
			* Functions
			* int getSuitableTruck(struct Truck trks[], struct Shipment* package)
			* void loadShipmentToTruck(struct Truck trks[], struct Shipment* package, int truckId)
			* void showMapAndRoute(struct Map* basemap, struct Shipment* package, int truckId)
			* void displayShipmentInfo(struct Shipment* package)
			* purpose: to test if the functions can display proper truck routes and shipment diversions on the map,
						and to test if the shipment diversion texts are printed on the screen properly
			***********************************************************************/
			struct Truck trucks[3] = {
				{ BLUE, // truckColor
				0.0, // weightAdded
				0.0, // sizeAdded
				0, // numberOfShipments
				getBlueRoute()},// blueRoute

				{ GREEN, // truckColor
				0.0, // weightAdded
				0.0, // sizeAdded
				0, // numberOfShipments
				getGreenRoute()}, // greenRoute

				{ YELLOW, // truckColor
				0.0, // weightAdded
				0.0, // sizeAdded
				0, // numberOfShipments
				getYellowRoute()}// yellowRoute
			};

			struct Map baseMap = populateMap();
			struct Shipment package =
			{
				0, //index of truck; ex) 0,1,2
				10.0, // valid weight
				10.0, // valid size
				{5,7}, // valid destination row, column
				{
					{{5,7}},
					1,
					BLUE
				}
			};

			if (package.deliveryTruck != -1) {
				int truckId = getSuitableTruck(trucks, &package);
				loadShipmentToTruck(trucks, &package, truckId);
				showMapAndRoute(&baseMap, &package, truckId);
				displayShipmentInfo(&package);
			}

			int good = 1;
			Assert::IsTrue(good);

		};
	};
}