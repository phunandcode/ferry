#include <iostream>
#include "Digger.h"
using namespace std;

Digger::Digger()
{
}

// parameterized constructor for creating a digger
Digger::Digger(std::string regNumIn, int trackCountIt, float lengthIn, int vehicleTypeIn) {
	setRegisterationNumber(regNumIn);
	setTrackCount(trackCountIt);
	setLength(lengthIn);
	vehicleType = vehicleTypeIn;
}

Digger::~Digger()
{
}

void Digger::setTrackCount(int trackCountIn) {
	trackCount = trackCountIn;
}

int Digger::getTrackCount() {
	return trackCount;
}

void Digger::showReport() { // virtual function to print derived class details
	Vehicles::showReport();
	cout << "Track count: " << trackCount << endl;
}