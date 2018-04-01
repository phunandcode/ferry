#pragma once
#include "Vehicles.h"

class FerryBoat
{
private:
	int capacity; // capacity of ferry
	int capacityUsed = capacity - capacityFree;
	int capacityFree;
	Vehicles* vehicle[15]; // an array of Vehicle pointers to implement the association between FerryBoat and Vehicles
public:
	FerryBoat();
	FerryBoat(int startCapacity); // parameterized constructor to initialize software
	~FerryBoat();

	int numberOfVehicles = 0; // vehicles on ferry

	void mainMenu();
	void addVehicle();
	void listVehicles(); // list vehicles for edit vehicle function
	void editVehicle(int listNumber, int vehicleTypeIn);
	void addCar(Vehicles*);
	void addBus(Vehicles*);
	void addLorry(Vehicles*);
	void addArticulatedLorry(Vehicles*);
	void addDigger(Vehicles*);
	void ferryProperties();
	void switchCapacity();
	void showReport(); // function to access derived class variables
	void ferryReset(); // delete dynamic objects (added vehicles)
	int getCapacityFree();
	int getCapacityUsed();
};