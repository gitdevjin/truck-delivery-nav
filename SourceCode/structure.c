#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "mapping.h"
#include "structure.h"

struct Shipment readShipInfo(struct Truck trks[], struct Map* map, struct Depot* storage)
{
	double weight, size;
	int row;
	int iter = 1;
	char column;
	struct Shipment result = {0};

	/***************User Input Validation********************/
	while (iter) {
		weight = 0.0;
		size = 0.0;
		row = 0;
		column = ' ';
		
		printf("Enter shipment weight, box size and destination (0 0 x to stop): ");
		scanf("%lf %lf %d", &weight, &size, &row);
		scanf("%c", &column);
		if (weight == 0 && size == 0 && (column == 'x' || column == 'X')) {
			result.deliveryTruck = -1;
			return result;
		}

		if (weight <= MAX_WEIGHT && weight > 0) // fixed
		{
			if (size <= MAX_SIZE && size > 0) // fixed
			{
				if ((row >= 1 && row <= getNumRows(map)) && // check validation fo row input
					((column >= 65 && column <= getNumCols(map) + 65) // check validation of column input (Upperlatter)
						|| (column >= 97 && column <= getNumCols(map) + 97))) // check validation of column input (Lowerlatter)
					iter = 0; // if valid, turn flag to false to stop while loop.
				else printf("Invalid destination\n");
			}
			else printf("Invalid size\n");

		}
		else printf("Invalid weight (must be 1-1000 Kg.)");
		int c;
		while ((c = getchar()) != '\n');

		/******************Destination bug fixing *****************/
		int temp_column;
		if (isupper(column)) temp_column = column - 'A';
		else if (islower(column)) temp_column = column - 'a';
		int temp_row = row - 1;

		if (map->squares[temp_row][temp_column] == 1) {
			printf("This is a building\n");
			result.deliveryTruck = -1;
			iter = 1;
		}
	}

	/*************Available Truck Weight Validation**********/
	int goodWeight = 0;
	int i;
	for (i = 0; i < 3; i++) {
		if (weight + trks[i].weightAdded <= MAX_WEIGHT) goodWeight = 1;
	}
	
	/*************Available Truck Size Validation***********/
	int goodSize = 0;
	for (i = 0; i < 3 && goodWeight; i++){
		if (size + trks[i].sizeAdded <= MAX_SIZE) goodSize = 1;
	}

	/*********If Avaiable return Shipment, Otherwise store it in the storage and return result.delivertruck as -1 ************/
	if (goodSize && goodWeight){		
		result.weight = weight;
		result.size = size;
		result.destination.row = row - 1; // -l since User input row is 1 bigger than index
		result.destination.col = (column >= 65 && column <= 89) ? column - 65 : column - 97; //alphabet -> number
																 //(Lowercase :Uppercase);
	} else{
		printf("No Available Truck Today");
		storage->shipments[storage->numOfShipment].size = size;
		storage->shipments[storage->numOfShipment].weight = weight;
		storage->shipments[storage->numOfShipment].destination.row = row - 1;
		storage->shipments[storage->numOfShipment].destination.col = (column >= 65 && column <= 89) ? column - 65 : column - 97;
		storage->numOfShipment++;
		result.deliveryTruck = -1;
	}

	return result;
}


int getSuitableTruck(struct Truck trks[], struct Shipment* package) {
	int i, numTruck = 0;
	int theTruck; // truckID
	int trucks[3] = { 0 };
	int index[3] = { 0 };
	double distances[3] = { 0 };
	double min;
	// Finding available truck when it comes to weight and size;
	for (i = 0; i < 3; i++) {
		if ((package->weight + trks[i].weightAdded <= MAX_WEIGHT) && (package->size + trks[i].sizeAdded <= MAX_SIZE)) {
			trucks[numTruck++] = trks[i].truckColor / 4; // if truckColor is blue(2), it will be 0, which indicates BLUETRUCK(macro)
		}
	}
	// Finding Closest Point index for each available truck
	for (i = 0; i < numTruck; i++) index[i] = getClosestPoint(&trks[trucks[i]].allRoutes, package->destination);
	
	// Calculating the Closest distance for each truck
	for (i = 0; i < numTruck; i++) distances[i] = distance(&trks[trucks[i]].allRoutes.points[index[i]], &package->destination);

	// Finding the Closest Truck;
	min = distances[0];
	theTruck = 0;
	for (i = 0; i < numTruck; i++) {
		if (distances[i] < min) {
			min = distances[i];
			theTruck = i;
		}
	}
	return trucks[theTruck];
}


void loadShipmentToTruck(struct Truck trks[], struct Shipment* package, int truckId) {
	trks[truckId].sizeAdded += package->size;
	trks[truckId].weightAdded += package->weight;
	trks[truckId].numOfshipment++;
	package->deliveryTruck = truckId;
}


void showMapAndRoute(struct Map* basemap, struct Shipment* package, int truckId) {

	struct Route route = { 0 };
	int closestIndex;

	if (truckId == BLUETRUCK) {
		route = getBlueRoute();
	}
	else if (truckId == GREENTRUCK) {
		route = getGreenRoute();
	}
	else if (truckId == YELLOWTRUCK) {
		route = getYellowRoute();
	}

	closestIndex = getClosestPoint(&route, package->destination);
	package->diversion = shortestPath(basemap, route.points[closestIndex], package->destination);
	struct Map routeMap = addRoute(basemap, &route);
	routeMap = addRoute(&routeMap, &package->diversion);
	printMap(&routeMap, 1, 1);
}


void displayShipmentInfo(struct Shipment* package) {
	int i;
	if (package->deliveryTruck == 0) printf("Ship on BLUE LINE, ");
	else if (package->deliveryTruck == 1) printf("Ship on GREEN LINE, ");
	else if (package->deliveryTruck == 2) printf("Ship on YELLOW LINE, ");

	if (package->diversion.numPoints) {
		printf("divert: ");
		for (i = 0; i < package->diversion.numPoints; i++) {
			printf("%d", package->diversion.points[i].row + 1);
			printf("%c", package->diversion.points[i].col + 65);
			if (package->diversion.numPoints > i + 1) printf(", ");
		}
		printf("\n");
	}
	else  printf("no diversion\n"); 
}