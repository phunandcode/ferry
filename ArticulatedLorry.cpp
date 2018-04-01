#include <iostream>
#include "ArticulatedLorry.h"
using namespace std;

ArticulatedLorry::ArticulatedLorry()
{
}

// parameterized constructor for creating an articulated lorry
ArticulatedLorry::ArticulatedLorry(std::string regNumIn, float cabLengthIn, float trailerLengthIn, float lengthIn, int vehicleTypeIn) {
	setRegisterationNumber(regNumIn);
	setCabLength(cabLengthIn);
	setTrailerLength(trailerLengthIn);
	setLength(lengthIn);
	vehicleType = vehicleTypeIn;
}

ArticulatedLorry::~ArticulatedLorry()
{
}

void ArticulatedLorry::setCabLength(float cabLengthIn) {
	cabLength = cabLengthIn;
}

float ArticulatedLorry::getCabLength() {
	return cabLength;
}

void ArticulatedLorry::setTrailerLength(float trailerLengthIn) {
	trailerLength = trailerLengthIn;
}

float ArticulatedLorry::getTrailerLength() {
	return trailerLength;
}

void ArticulatedLorry::showReport() { // virtual function to print derived class details
	Vehicles::showReport();
	cout << "Cabin length: " << cabLength << "m" << "\t";
	cout << "Trailer length: " << trailerLength << "m" << endl;
}