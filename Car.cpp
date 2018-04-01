#include <iostream>
#include "Car.h"
using namespace std;

Car::Car()
{
}

Car::Car(string regNumIn, int seatsIn, float lengthIn, int vehicleTypeIn) { // parameterized constructor for creating a car
	setRegisterationNumber(regNumIn);
	setSeats(seatsIn);
	setLength(lengthIn);
	vehicleType = vehicleTypeIn;
}

Car::~Car()
{
}

int Car::getSeats() {
	return seats;
}

void Car::setSeats(int seatsIn) {
	seats = seatsIn;
}

void Car::showReport() { // virtual function to print derived class details
	Vehicles::showReport();
	cout << "Seats: " << seats << endl;
}