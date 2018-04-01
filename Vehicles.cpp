#include <iostream>
#include "Vehicles.h"
using namespace std;

Vehicles::Vehicles()
{
}

Vehicles::~Vehicles()
{
}

void Vehicles::setRegisterationNumber(string regNumIn) {
	registerationNumber = regNumIn;
}

void Vehicles::setLength(float lengthIn) {
	length = lengthIn;
}

std::string Vehicles::getRegisterationNumber() {
	return registerationNumber;
}

float Vehicles::getLength() {
	return length;
}

void Vehicles::showReport() { // has access to derived classes' variables because of virtual functions
	cout << "registeration number: " << registerationNumber << "\t";
	cout << "length: " << length << "\t";
}