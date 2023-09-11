#ifndef STRUCTURE_H
#define STRUCTURE_H
#include "mapping.h"

#define MAX_WEIGHT 1000.0
#define MAX_SIZE 1000.0
#define MAX_DEPOT 10

#define BLUETRUCK 0 // index of blue truck
#define GREENTRUCK 1 // index of green truck
#define YELLOWTRUCK 2 // index of yellow truck

struct Truck 
{
	int truckColor;
	double weightAdded;
	double sizeAdded;
	int numOfshipment;
	struct Route allRoutes; // this will be assigned by each truck route;
};

struct Shipment
{
	int deliveryTruck; //index of truck; ex) 0,1,2
	double weight;
	double size;
	struct Point destination;
	struct Route diversion; 
};

struct Depot {
	int numOfShipment;
	struct Shipment shipments[MAX_DEPOT];
};


/**
* Prompt the user to enter shipment information and
* check the validation of input, if not valid
* store it in the depot.
* @param trks[] - available trks, based on which we validate the user input.
* @param map - based on which, the validation of input is decided.
* @param storage - the Depot to add shipments to
* @returns a copy of shipment information from user.
*/
struct Shipment readShipInfo(struct Truck trks[], struct Map* map ,struct Depot* storage);


/**
* Find the most sutiable truck for the shipment
* based on their weight and size availability, and distance to the destination
* @param trks[] - All the trucks among which, we find the best one.
* @param package - the shipment information.
* @returns truckID.
*/
int getSuitableTruck(struct Truck trks[], struct Shipment* package);


/**
* add shipment size and weight to a truck,
* and assign to package a truck that will deliver it.
* @param trks[] - available trks, based on which we add a shipment
* @param package - to add to a truck
* @param truckID - indicates which truck we will add a shipment to
*/
void loadShipmentToTruck(struct Truck trks[], struct Shipment* package, int truckId);


/**
* add a truck route and diversion route to a map and print it.
* @param basemap - a map to add routes
* @param package - diversion of which will be added to a map
* @param truckID - indicates which truck we will add a shipment to
*/
void showMapAndRoute(struct Map* basemap, struct Shipment* package, int truckId);

/**
* print a diversion route of a package in a sentence
* @param package - diversion of which will be printed on output stream
*/
void displayShipmentInfo(struct Shipment* package);

#endif