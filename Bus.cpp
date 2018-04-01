#include <iostream>
#include "Bus.h"
using namespace std;

Bus::Bus()
{
}

// parameterized constructor for creating a bus
Bus::Bus(string regNumIn, int psvNumberIn, int maxPassengersIn, float lengthIn, int vehicleTypeIn) {
	setRegisterationNumber(regNumIn);
	setPsvNumber(psvNumberIn);
	setMaxPassengers(maxPassengersIn);
	setLength(lengthIn);
	vehicleType = vehicleTypeIn;
}

Bus::~Bus()
{
}

void Bus::setPsvNumber(int psvNumberIn) {
	psvNumber = psvNumberIn;
}

int Bus::getPsvNumber() {
	return psvNumber;
}

void Bus::setMaxPassengers(int maxPassengersIn) {
	maxPassengers = maxPassengersIn;
}

int Bus::getMaxPassengers() {
	return maxPassengers;
}

void Bus::showReport() { // virtual function to print derived class details
	Vehicles::showReport();
	cout << "Public Service Vehicle number: " << psvNumber << "\t" << "\t";
	cout << "Max passengers: " << maxPassengers << endl;
}