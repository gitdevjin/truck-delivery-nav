#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "mapping.h"
#include "structure.h"

int main(void)
{
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
	int good = 1;
	while (good) {
		struct Map baseMap = populateMap();
		struct Shipment package = readShipInfo(&trucks, &baseMap, &storage);

		if (package.deliveryTruck != -1) {
			int truckId = getSuitableTruck(trucks, &package);
			loadShipmentToTruck(trucks, &package, truckId);
			showMapAndRoute(&baseMap, &package, truckId);
			displayShipmentInfo(&package);
		}
		else good = 0; // When there is no available truck;
	}
	printf("\nThanks for shipping with Seneca!");

	return 0;
}

//***************************** How the program works (STEP BY STEP) *******************************************/
//STEP 1
// Find the colosest point for each route of the trucks
//int blueClosestIndex = getClosestPoint(&trucks[BLUETRUCK].allRoutes, package.destination);
//int greenClosestIndex = getClosestPoint(&trucks[GREENTRUCK].allRoutes, package.destination);
//int yellowClosestIndex = getClosestPoint(&trucks[YELLOWTRUCK].allRoutes, package.destination);

//STEP 2
// Find the distance between destination and closest point from each route in order to compare which route is the best 
//double blueDistance = distance(&trucks[BLUETRUCK].allRoutes.points[blueClosestIndex], &package.destination);
//double greenDistance = distance(&trucks[GREENTRUCK].allRoutes.points[greenClosestIndex], &package.destination);
//double yellowdistance = distance(&trucks[YELLOWTRUCK].allRoutes.points[yellowClosestIndex], &package.destination);

//STEP 3
// Find the shortest path based on distance; //comparing distance is skipped here.
// package.diversion = shortestPath(&routeMap, trucks[GREENTRUCK].allRoutes.points[greenClosestIndex], package.destination); //3
		

//STEP 4;
// ADD basemap and the truck route and diversion route
//struct Route blueRoute = getBlueRoute(); // 1
//struct Map routeMap = addRoute(&baseMap, &blueRoute); // 2
//package.diversion = shortestPath(&routeMap, trucks[GREENTRUCK].allRoutes.points[greenClosestIndex], package.destination); //3


		/*********************SAMPLE TEST***************************/
		//struct Route blueRoute = getBlueRoute(); // 1
		//struct Map routeMap = addRoute(&baseMap, &blueRoute); // 2
		//routeMap = addRoute(&routeMap, &trucks[GREENTRUCK].allRoutes);
		//routeMap = addRoute(&routeMap, &trucks[YELLOWTRUCK].allRoutes);
		//package.diversion = shortestPath(&routeMap, trucks[GREENTRUCK].allRoutes.points[greenClosestIndex], package.destination); //3
		//routeMap = addRoute(&routeMap, &package.diversion); //4
		//printMap(&routeMap, 1, 1);
		/****************************************************/