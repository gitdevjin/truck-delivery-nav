#include "pch.h"
#include <iostream>
#include "CppUnitTest.h"
#include "header_r.h"
#include <structure.h>
#include <structure.c>


/***********************Acceptance Testing**************************
* Tester Name : Jeremy
* Description : Acceptance Testing
********************************************************************/

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Acceptance
{
	TEST_CLASS(A_T001)
	{
	public:
		TEST_METHOD(A_T001_1)
		{
			int assert_check = false;
			int check = 1;

			struct Truck trucks[3] =
			{
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

			struct Depot storage =
			{
				0, // number of shipments
				{0} // array of shipments(package)
			};

			while (check == 1){
				struct Map baseMap = populateMap();
				struct Shipment package = readShipInfo(trucks, &baseMap, &storage);
				//USER INPUTS: 20 .5 28x

				if (package.deliveryTruck != -1){
					int truckId = getSuitableTruck(trucks, &package);
					loadShipmentToTruck(trucks, &package, truckId);
					showMapAndRoute(&baseMap, &package, truckId);
					displayShipmentInfo(&package);
				}
				else check = 0;
				assert_check = true;
			}

			//FPRINTF CORRECT OUTPUT TO LOG FILE TO CHECK
			char* output = "Invalid destination";
			
			//INPUT DETECTED, COMPARE INPUT WITH CORRECT_INPUT
			char* correct_output = "Invalid destination";
			if (strcmp(output, correct_output) == 1){
				check = true;
			}
			else{
				check = false;
			}
			Assert::IsTrue(check);
		}

		TEST_METHOD(A_T001_2)
		{
			int assert_check = false;
			int check = 1;

			struct Truck trucks[3] ={
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

			struct Depot storage ={
				0, // number of shipments
				{0} // array of shipments(package)
			};

			while (check == 1){
				struct Map baseMap = populateMap();
				struct Shipment package = readShipInfo(trucks, &baseMap, &storage);
				//USER INPUTS: 20 2 12L

				if (package.deliveryTruck != -1)
				{
					int truckId = getSuitableTruck(trucks, &package);
					loadShipmentToTruck(trucks, &package, truckId);
					showMapAndRoute(&baseMap, &package, truckId);
					displayShipmentInfo(&package);
				}
				else check = 0;
				assert_check = true;
			}

			//FPRINTF CORRECT OUTPUT TO LOG FILE TO CHECK
			char* output = "Invalid size";

			//INPUT DETECTED, COMPARE INPUT WITH CORRECT_INPUT
			char* correct_output = "Invalid size";
			if (strcmp(output, correct_output) == 1){
				check = true;
			}
			else{
				check = false;
			}
			Assert::IsTrue(check);
		}

		TEST_METHOD(A_T001_3)
		{
			int assert_check = false;
			int check = 1;

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
				0, // number of shipments
				{0} // array of shipments(package)
			};

			while (check == 1) {
				struct Map baseMap = populateMap();
				struct Shipment package = readShipInfo(trucks, &baseMap, &storage);
				//USER INPUTS: 20 .5 12L

				if (package.deliveryTruck != -1)
				{
					int truckId = getSuitableTruck(trucks, &package);
					loadShipmentToTruck(trucks, &package, truckId);
					showMapAndRoute(&baseMap, &package, truckId);
					displayShipmentInfo(&package);
				}
				else check = 0;
				assert_check = true;
			}

			//FPRINTF CORRECT OUTPUT TO LOG FILE TO CHECK
			char* output = "Invalid weight (must be 1-1000 Kg.)";

			//INPUT DETECTED, COMPARE INPUT WITH CORRECT_INPUT
			char* correct_output = "Invalid weight (must be 1-1000 Kg.)";
			if (strcmp(output, correct_output) == 1){
				check = true;
			}
			else{
				check = false;
			}
			Assert::IsTrue(check);
		}

		TEST_METHOD(A_T001_4)
		{
			int assert_check = false;
			int check = 1;

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
				0, // number of shipments
				{0} // array of shipments(package)
			};

			while (check == 1) {
				struct Map baseMap = populateMap();
				struct Shipment package = readShipInfo(trucks, &baseMap, &storage);
				//USER INPUTS: 200 1.0 8Y

				if (package.deliveryTruck != -1)
				{
					int truckId = getSuitableTruck(trucks, &package);
					loadShipmentToTruck(trucks, &package, truckId);
					showMapAndRoute(&baseMap, &package, truckId);
					displayShipmentInfo(&package);
				}
				else check = 0;
				assert_check = true;
			}

			//FPRINTF CORRECT OUTPUT TO LOG FILE TO CHECK
			char* output = "Ship on BLUE LINE, no diversion";

			//INPUT DETECTED, COMPARE INPUT WITH CORRECT_INPUT
			char* correct_output = "Ship on BLUE LINE, no diversion";
			if (strcmp(output, correct_output) == 1) {
				check = true;
			}
			else {
				check = false;
			}
			Assert::IsTrue(check);
		}

		TEST_METHOD(A_T001_5)
		{
			int assert_check = false;
			int check = 1;

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
				0, // number of shipments
				{0} // array of shipments(package)
			};

			while (check == 1) {
				struct Map baseMap = populateMap();
				struct Shipment package = readShipInfo(trucks, &baseMap, &storage);
				//USER INPUTS: 500 1.5 8Y

				if (package.deliveryTruck != -1)
				{
					int truckId = getSuitableTruck(trucks, &package);
					loadShipmentToTruck(trucks, &package, truckId);
					showMapAndRoute(&baseMap, &package, truckId);
					displayShipmentInfo(&package);
				}
				else check = 0;
				assert_check = true;
			}

			//FPRINTF CORRECT OUTPUT TO LOG FILE TO CHECK
			char* output = "Ship on GREEN LINE, divert: 7T, 7U, 7V, 7W, 7X, 7Y, 8Y";

			//INPUT DETECTED, COMPARE INPUT WITH CORRECT_INPUT
			char* correct_output = "Ship on GREEN LINE, divert: 7T, 7U, 7V, 7W, 7X, 7Y, 8Y";
			if (strcmp(output, correct_output) == 1) {
				check = true;
			}
			else {
				check = false;
			}
			Assert::IsTrue(check);
		}

		TEST_METHOD(A_T001_6)
		{
			int assert_check = false;
			int check = 1;

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
				0, // number of shipments
				{0} // array of shipments(package)
			};

			while (check == 1) {
				struct Map baseMap = populateMap();
				struct Shipment package = readShipInfo(trucks, &baseMap, &storage);
				//USER INPUTS: 500 1.0 8Y

				if (package.deliveryTruck != -1)
				{
					int truckId = getSuitableTruck(trucks, &package);
					loadShipmentToTruck(trucks, &package, truckId);
					showMapAndRoute(&baseMap, &package, truckId);
					displayShipmentInfo(&package);
				}
				else check = 0;
				assert_check = true;
			}

			//FPRINTF CORRECT OUTPUT TO LOG FILE TO CHECK
			char* output = "Ship on BLUE LINE, divert 18V, 17V, 16V, 15V, 14V, 13V, 12V, 11V, 10V, 9V, 8V, 7V, 7W, 7X, 7Y, 8Y";

			//INPUT DETECTED, COMPARE INPUT WITH CORRECT_INPUT
			char* correct_output = "Ship on BLUE LINE, divert 18V, 17V, 16V, 15V, 14V, 13V, 12V, 11V, 10V, 9V, 8V, 7V, 7W, 7X, 7Y, 8Y";
			if (strcmp(output, correct_output) == 1) {
				check = true;
			}
			else {
				check = false;
			}
			Assert::IsTrue(check);
		}

		TEST_METHOD(A_T001_7)
		{
			int assert_check = false;
			int check = 1;

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
				0, // number of shipments
				{0} // array of shipments(package)
			};

			while (check == 1) {
				struct Map baseMap = populateMap();
				struct Shipment package = readShipInfo(trucks, &baseMap, &storage);
				//USER INPUTS: 0 0 x

				if (package.deliveryTruck != -1)
				{
					int truckId = getSuitableTruck(trucks, &package);
					loadShipmentToTruck(trucks, &package, truckId);
					showMapAndRoute(&baseMap, &package, truckId);
					displayShipmentInfo(&package);
				}
				else check = 0;
				assert_check = true;
			}

			//FPRINTF CORRECT OUTPUT TO LOG FILE TO CHECK
			char* output = "Thanks for shipping with Seneca!";

			//INPUT DETECTED, COMPARE INPUT WITH CORRECT_INPUT
			char* correct_output = "Thanks for shipping with Seneca!";
			if (strcmp(output, correct_output) == 1) {
				check = true;
			}
			else {
				check = false;
			}
			Assert::IsTrue(check);
		}
	};
}