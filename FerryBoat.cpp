#include <iostream>
#include <string>
#include "FerryBoat.h".
#include "Vehicles.h"
#include "Car.h"
#include "Bus.h"
#include "Lorry.h"
#include "ArticulatedLorry.h"
#include "Digger.h"
using namespace std;

FerryBoat::FerryBoat()
{
}

FerryBoat::FerryBoat(int startCapacity) { // parameterized constructor to start initialize software
	capacity = startCapacity; // set the ferry's capacity to the parameter value
	capacityFree = startCapacity; // reset space for beginning
	for (int i = 0; i < 15; i++) { // set all pointers null
		vehicle[i] = NULL;
	}
	// FerryBoat* vehicleSpace[10]; // declare and initialize an array of vehicle spaces (pointers of the FerryBoat class)
	mainMenu(); // initialize main menu
}


FerryBoat::~FerryBoat()
{
}

void FerryBoat::mainMenu() {
	int menuChoice = 0;
	do {
		cout << "Welcome to Ferry management software!" << "\t" << "Free space: "<< capacityFree << "/" << capacity << endl;
		cout << "Main menu: " << endl;
		cout << "1. Add vehicle" << endl;
		cout << "2. Edit current load" << endl;
		cout << "3. Print report" << endl;
		cout << "4. Ferry properties" << endl;
		cout << "5. Reset ferry load" << endl;
		cout << "6. Quit" << endl;
		cout << endl;
		cout << "Navigate menu by entering a number: ";
		cin >> menuChoice;
		cout << endl;
		switch(menuChoice) {
		case 1:
			addVehicle();
			break;
		case 2:
			listVehicles();
			break;
		case 3:
			showReport();
			break;
		case 4:
			ferryProperties();
			break;
		case 5:
			ferryReset();
			break;
		}
	} while (menuChoice != 6);
}

void FerryBoat::addVehicle() {
	if (capacityFree > 0) {
		int menuChoice = 0;
		cout << "Choose type of vehicle to add onto ferry:" << endl;
		cout << "1. Car" << endl;
		cout << "2. Bus" << endl;
		cout << "3. Lorry" << endl;
		cout << "4. Articulated lorry" << endl;
		cout << "5. Digger" << endl;
		cout << "6. Go back to main menu" << endl;
		cin >> menuChoice;
		switch(menuChoice) {
		case 1: 
			addCar(new Vehicles);
			break;
		case 2:
			addBus(new Vehicles);
			break;
		case 3:
			addLorry(new Vehicles);
			break;
		case 4:
			addArticulatedLorry(new Vehicles);
			break;
		case 5:
			addDigger(new Vehicles);
			break;
		case 6:
			mainMenu();
			break;
		}
	}
	else {
		cout << "No space left on ferry!" << endl;
	}
	mainMenu();
}

void FerryBoat::addCar(Vehicles* new_vehicle) {
	string tempRegNum;
	int tempSeatNum;
	float tempLength;
	
	cout << "Enter registeration number: ";
	cin >> tempRegNum;
	cout << "Enter number of seats: ";
	cin >> tempSeatNum;
	cout << "Enter car length: ";
	cin >> tempLength;
	if (tempLength > capacityFree) { // check if there is space on the ferry
		cout << "Vehicle too long!" << endl;
		mainMenu();
	}
	
	numberOfVehicles++;
	vehicle[numberOfVehicles - 1] = new Car(tempRegNum, tempSeatNum, tempLength, 1); // create new dynamic object (car)
	capacityFree = capacityFree - tempLength; // update free capacity
}

void FerryBoat::addBus(Vehicles*) {
	string tempRegNum;
	int tempPsvNum;
	int tempMaxPassengers;
	float tempLength;

	cout << "Enter registeration number: ";
	cin >> tempRegNum;
	cout << "Enter Public Service Vehicle number: ";
	cin >> tempPsvNum;
	cout << "Enter max passengers: ";
	cin >> tempMaxPassengers;
	cout << "Enter bus length: ";
	cin >> tempLength;
	if (tempLength > capacityFree) {
		cout << "Vehicle too long!" << endl;
		mainMenu();
	}

	numberOfVehicles++;
	vehicle[numberOfVehicles - 1] = new Bus(tempRegNum, tempPsvNum, tempMaxPassengers, tempLength, 2);
	capacityFree = capacityFree - tempLength;
}

void FerryBoat::addLorry(Vehicles*) {
	string tempRegNum;
	int tempMaxLoad;
	float tempLength;

	cout << "Enter registeration number: ";
	cin >> tempRegNum;
	cout << "Enter max load for lorry (in kg): ";
	cin >> tempMaxLoad;
	cout << "Enter lorry length: ";
	cin >> tempLength;
	if (tempLength > capacityFree) {
		cout << "Vehicle too long!" << endl;
		mainMenu();
	}

	numberOfVehicles++;
	vehicle[numberOfVehicles - 1] = new Lorry(tempRegNum, tempMaxLoad, tempLength, 3);
	capacityFree = capacityFree - tempLength;
}

void FerryBoat::addArticulatedLorry(Vehicles*) {
	string tempRegNum;
	float tempCabLength;
	float tempTrailerLength;
	float tempLength;

	cout << "Enter registeration number: ";
	cin >> tempRegNum;
	cout << "Enter cabin length: ";
	cin >> tempCabLength;
	cout << "Enter trailer length: ";
	cin >> tempTrailerLength;
	tempLength = tempCabLength + tempTrailerLength;
	if (tempLength > capacityFree) {
		cout << "Vehicle too long!" << endl;
		mainMenu();
	}

	numberOfVehicles++;
	vehicle[numberOfVehicles - 1] = new ArticulatedLorry(tempRegNum, tempCabLength, tempTrailerLength, tempLength, 4);
	capacityFree = capacityFree - tempLength;
}

void FerryBoat::addDigger(Vehicles*) {
	string tempRegNum;
	int tempTrackCount;
	float tempLength;

	cout << "Enter registeration number: ";
	cin >> tempRegNum;
	cout << "Enter track count: ";
	cin >> tempTrackCount;
	cout << "Enter digger length: ";
	cin >> tempLength;
	if (tempLength > capacityFree) {
		cout << "Vehicle too long!" << endl;
		mainMenu();
	}

	numberOfVehicles++;
	vehicle[numberOfVehicles - 1] = new Digger(tempRegNum, tempTrackCount, tempLength, 5);
	capacityFree = capacityFree - tempLength;
}

void FerryBoat::listVehicles() {
	if (numberOfVehicles == 0) {
		cout << "Ferry is empty!" << endl;
	}
	if (numberOfVehicles > 0) {
		for (int i = 0; i < 15; i++) {
			if (vehicle[i] != NULL) { // if a vehicle is present display its details
				cout << i + 1 << ". " << vehicle[i]->getRegisterationNumber() << endl;
			}
		}
		cout << "Edit vehicle values by typing in corresponding number: ";
		int menuChoice = 0;
		cin >> menuChoice;
		int vehicleRealNumber = menuChoice - 1; // array starts from 0
		editVehicle(vehicleRealNumber, vehicle[vehicleRealNumber]->vehicleType); // send selected array element with vehicle type to edit function
	}
}

void FerryBoat::editVehicle(int listNumber, int vehicleTypeIn) {
	string tempRegNum;
	float tempLength;
	int oldCapacityFree = capacityFree; // save previous capacity if edit fails
	capacityFree = capacityFree + vehicle[listNumber]->getLength(); // reset free capacity to value before the vehicle currently being edited
	cout << "Enter new registeration number: ";
	cin >> tempRegNum;
	cout << "Enter new length: ";
	cin >> tempLength;
	if (tempLength > capacityFree) {
		cout << "Vehicle too long!" << endl;
		mainMenu();
	}
	if (vehicleTypeIn == 1) { // car
		int tempSeatNum;
		cout << "Enter new number of seats: ";
		cin >> tempSeatNum;
		vehicle[listNumber] = new Car(tempRegNum, tempSeatNum, tempLength, 1); // update dynamic object with new values
	}
	if (vehicleTypeIn == 2) { // bus
		int tempPsvNum;
		int tempMaxPassengers;
		cout << "Enter new Public Service Vehicle number: ";
		cin >> tempPsvNum;
		cout << "Enter new max passengers: ";
		cin >> tempMaxPassengers;
		vehicle[listNumber] = new Bus(tempRegNum, tempPsvNum, tempMaxPassengers, tempLength, 2);
	}
	if (vehicleTypeIn == 3) { // lorry
		int tempMaxLoad;
		cout << "Enter new max load: ";
		cin >> tempMaxLoad;
		vehicle[listNumber] = new Lorry(tempRegNum, tempMaxLoad, tempLength, 3);
	}
	if (vehicleTypeIn == 4) { // articulated lorry
		int tempCabLength;
		int tempTrailerLength;
		cout << "Enter new cabin length: ";
		cin >> tempCabLength;
		cout << "Enter new trailer length: ";
		cin >> tempTrailerLength;
		if (tempCabLength + tempTrailerLength != tempLength) {
			cout << "Vehicle lengths incorrect!" << endl;
			capacityFree = oldCapacityFree;
			mainMenu();
		}
		vehicle[listNumber] = new ArticulatedLorry(tempRegNum, tempCabLength, tempTrailerLength, tempLength, 4);
	}
	if (vehicleTypeIn == 5) { // digger
		int tempTrackCount;
		cout << "Enter new track count: ";
		cin >> tempTrackCount;
		vehicle[listNumber] = new Digger(tempRegNum, tempTrackCount, tempLength, 5);
	}
	capacityFree = capacityFree - tempLength; // update free capacity
}

void FerryBoat::ferryProperties() { // option menu to change ferry properties
	int menuChoice = 0;
	cout << "1 - Change capacity" << endl;
	cout << "0 - Go back to main menu" << endl;
	cout << endl;
	cout << "Navigate menu by entering a number: " << endl;
	cin >> menuChoice;
	cout << endl;
	if (menuChoice == 1) {
		switchCapacity();
	}
	mainMenu();
}

void FerryBoat::switchCapacity() { // switch capacity after ferry initialization
	cout << "Current capacity for ferry is: " << capacity << endl;
	cout << "To change capacity type 'Y' or to go back type 'N': ";
	char proceed;
	do {
		cin >> proceed;
		if (proceed == 'Y' || proceed == 'y') {
			cout << "Type new capacity in meters (for example '25' for 25m): ";
			int newCapacity;
			cin >> newCapacity;
			if (capacityUsed - newCapacity < 0) {
				cout << "New capacity is too small for current load, old capacity maintained!" << endl;
				mainMenu();
			}
			capacity = newCapacity;
			capacityFree = newCapacity;
			cout << endl;
			cout << "Ferry capacity changed!" << endl;
			cout << endl;
		}
		else if ((proceed == 'N' || proceed == 'n')) {
			cout << "You chose to cancel the procedure!" << endl;
		}
		mainMenu();
	} while (proceed != 'Y' || proceed != 'y' || proceed != 'N' || proceed != 'n');
}

void FerryBoat::showReport() {
	if (numberOfVehicles == 0) {
		cout << "No vehicles added!" << endl;
	}
	if (numberOfVehicles > 0) {
		for (int i = 0; i < 15; i++) {
			if (vehicle[i] != NULL) { // if a vehicle is present display its details
				cout << endl;
				if (vehicle[i]->vehicleType == 1) {
					cout << "CAR" << endl;
					vehicle[i]->showReport(); // call showReport virtual function
				}
				else if (vehicle[i]->vehicleType == 2) {
					cout << "BUS" << endl;
					vehicle[i]->showReport();
				}
				else if (vehicle[i]->vehicleType == 3) {
					cout << "LORRY" << endl;
					vehicle[i]->showReport();
				}
				else if (vehicle[i]->vehicleType == 4) {
					cout << "ARTICULATED LORRY" << endl;
					vehicle[i]->showReport();
				}
				else if (vehicle[i]->vehicleType == 5) {
					cout << "DIGGER" << endl;
					vehicle[i]->showReport();
				}
			}
		}
		cout << endl;
		cout << endl;
	}
}

void FerryBoat::ferryReset() { // delete all vehicles
	if (capacityFree == capacity) {
		cout << "Ferry is already empty!" << endl;
	}
	else {
		cout << "Are you sure you want to reset the ferry? 'Y' or 'N': ";
		char proceed;
		do {
			cin >> proceed;
			if (proceed == 'Y' || proceed == 'y') {
				for (int i = 0; i < 15; i++) {
					delete vehicle[i]; // delete dynamic object
					vehicle[i] = NULL; // set pointer value to NULL
				}
				cout << "Ferry load reset!" << endl;
				cout << endl;
				capacityFree = capacity;
				capacityUsed = 0;
				numberOfVehicles = 0;
			}
			else if ((proceed == 'N' || proceed == 'n')) {
				cout << "You chose to cancel the procedure!" << endl;
			}
			mainMenu();
		} while (proceed != 'Y' || proceed != 'y' || proceed != 'N' || proceed != 'n');
	}
}