#include <iostream>
#include "Lorry.h"
using namespace std;

Lorry::Lorry()
{
}

// parameterized constructor for creating a lorry
Lorry::Lorry(std::string regNumIn, int maxLoadIn, float lengthIn, int vehicleTypeIn) {
	setRegisterationNumber(regNumIn);
	setMaxLoad(maxLoadIn);
	setLength(lengthIn);
	vehicleType = vehicleTypeIn;
}

Lorry::~Lorry()
{
}

void Lorry::setMaxLoad(int maxLoadIn) {
	maxLoad = maxLoadIn;
}

int Lorry::getMaxLoad() {
	return maxLoad;
}

void Lorry::showReport() { // virtual function to print derived class details
	Vehicles::showReport();
	cout << "Max load: " << maxLoad << "kg" << endl;
}